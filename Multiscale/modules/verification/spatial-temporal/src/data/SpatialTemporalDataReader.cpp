#include "multiscale/exception/InvalidInputException.hpp"
#include "multiscale/exception/RuntimeException.hpp"
#include "multiscale/util/Filesystem.hpp"
#include "multiscale/util/XmlValidator.hpp"
#include "multiscale/verification/spatial-temporal/data/SpatialTemporalDataReader.hpp"
#include "multiscale/verification/spatial-temporal/model/SemanticType.hpp"

#include <iostream>
#include <iterator>
#include <limits>
#include <memory>

using namespace multiscale::verification;

namespace pt = boost::property_tree;


SpatialTemporalDataReader::SpatialTemporalDataReader(const std::string &folderPath) {
    initialise(folderPath);
}

SpatialTemporalDataReader::~SpatialTemporalDataReader() {
    processedInputFiles.clear();
    unprocessedInputFiles.clear();
}

bool
SpatialTemporalDataReader::hasNext() {
    return hasValidNext();
}

void
SpatialTemporalDataReader::refresh() {
    updateInputFilesSets();
}

SpatialTemporalTrace
SpatialTemporalDataReader::getNextSpatialTemporalTrace() {
    if (!hasNext()) {
        MS_throw(RuntimeException, ERR_NO_VALID_INPUT_FILES_REMAINING);
    }

    return generateSpatialTemporalTrace();
}

SpatialTemporalTrace
SpatialTemporalDataReader::getNextSpatialTemporalTrace(std::string &tracePath) {
    if (!hasNext()) {
        MS_throw(RuntimeException, ERR_NO_VALID_INPUT_FILES_REMAINING);
    }

    return generateSpatialTemporalTrace(tracePath);
}

void
SpatialTemporalDataReader::initialise(const std::string &folderPath) {
    validateFolderPath(folderPath);

    this->folderPath = folderPath;

    initialise();
}

void
SpatialTemporalDataReader::initialise() {
    clearInputFilesSets();
    updateInputFilesSets();
}

void
SpatialTemporalDataReader::clearInputFilesSets() {
    processedInputFiles.clear();
    unprocessedInputFiles.clear();
}

bool
SpatialTemporalDataReader::hasValidNext() {
    auto it = unprocessedInputFiles.begin();

    while (it != unprocessedInputFiles.end()) {
        if (isValidInputFile(*it)) {
            return true;
        }

        it = processInvalidInputFile(it);
    }

    return false;
}

std::set<std::string>::iterator
SpatialTemporalDataReader::processInvalidInputFile(const std::set<std::string>::iterator
                                                   &invalidInputFileIterator) {
    // Add it to processed files because it is invalid
    processedInputFiles.insert(*invalidInputFileIterator);

    // Remove the invalid file from the set of unprocessed files
    return unprocessedInputFiles.erase(invalidInputFileIterator);
}

SpatialTemporalTrace
SpatialTemporalDataReader::generateSpatialTemporalTrace() {
    auto unprocessedInputFilepath = getRandomValidUnprocessedInputFilepath();
    SpatialTemporalTrace trace = constructSpatialTemporalTrace(*unprocessedInputFilepath);

    processValidInputFile(unprocessedInputFilepath);

    return trace;
}

SpatialTemporalTrace
SpatialTemporalDataReader::generateSpatialTemporalTrace(std::string &tracePath) {
    auto unprocessedInputFilepath = getRandomValidUnprocessedInputFilepath();
    tracePath = *unprocessedInputFilepath;

    SpatialTemporalTrace trace = constructSpatialTemporalTrace(tracePath);

    processValidInputFile(unprocessedInputFilepath);

    return trace;
}

SpatialTemporalTrace
SpatialTemporalDataReader::constructSpatialTemporalTrace(const std::string &inputFilepath) {
    pt::ptree propertyTree;

    read_xml(inputFilepath, propertyTree, pt::xml_parser::trim_whitespace);

    return constructSpatialTemporalTrace(propertyTree);
}

SpatialTemporalTrace
SpatialTemporalDataReader::constructSpatialTemporalTrace(const pt::ptree &tree) {
    SpatialTemporalTrace trace;

    for (const auto &timePointTreePair : tree.get_child(LABEL_EXPERIMENT)) {
        addTimePointToTrace(timePointTreePair.second, trace);
    }

    return trace;
}

void
SpatialTemporalDataReader::addTimePointToTrace(const pt::ptree &timePointTree, SpatialTemporalTrace &trace) {
    TimePoint timePoint;

    convertTimePointPropertyTreeToTrace(timePointTree, timePoint);

    trace.addTimePoint(timePoint);
}

void
SpatialTemporalDataReader::convertTimePointPropertyTreeToTrace(const pt::ptree &timePointTree,
                                                               TimePoint &timePoint) {
    setTimePointValue(timePointTree, timePoint);
    addEntitiesToTimePoint(timePointTree, timePoint);
}

void
SpatialTemporalDataReader::setTimePointValue(const pt::ptree &timePointTree, TimePoint &timePoint) {
    unsigned long timePointValue;

    if (timePointHasValue(timePointTree, timePointValue)) {
        timePoint.setValue(timePointValue);
    } else {
        timePoint.setValue(std::numeric_limits<unsigned long>::max());
    }
}

bool
SpatialTemporalDataReader::timePointHasValue(const pt::ptree &propertyTree, unsigned long &value) {
    boost::optional<unsigned long> timePointValue = propertyTree.get_optional<unsigned long>(
                                                        LABEL_TIMEPOINT_VALUE
                                                    );

    if (timePointValue.is_initialized()) {
        value = *timePointValue;

        return true;
    }

    return false;
}

void
SpatialTemporalDataReader::addEntitiesToTimePoint(const pt::ptree &timePointTree,
                                                       TimePoint &timePoint) {
    for (const auto &entityTree : timePointTree) {
        if (entityTree.first.compare(LABEL_NUMERIC_STATE_VARIABLE) == 0) {
            addNumericStateVariableToTimePoint(entityTree.second, timePoint);
        } else if (entityTree.first.compare(LABEL_SPATIAL_ENTITY) == 0) {
            addSpatialEntityToTimePoint(entityTree.second, timePoint);
        }
    }
}

void
SpatialTemporalDataReader::addNumericStateVariableToTimePoint(const pt::ptree &numericStateVariableTree,
                                                                   TimePoint &timePoint) {
    std::string name
        = numericStateVariableTree.get<std::string>(LABEL_NUMERIC_STATE_VARIABLE_NAME);
    boost::optional<std::string> semanticType
        = numericStateVariableTree.get_optional<std::string>(LABEL_NUMERIC_STATE_VARIABLE_SEMANTIC_TYPE);
    double value
        = numericStateVariableTree.get<double>(LABEL_NUMERIC_STATE_VARIABLE_VALUE);

    NumericStateVariableId numericStateVariableId(
        name,
        semanticType.get_value_or(SemanticType::DEFAULT_VALUE)
    );

    timePoint.addNumericStateVariable(numericStateVariableId, value);
}

void
SpatialTemporalDataReader::addSpatialEntityToTimePoint(const pt::ptree &spatialEntityTree,
                                                            TimePoint &timePoint) {
    std::shared_ptr<SpatialEntity>  spatialEntity;
    SubsetSpecificType              spatialEntityType;

    createDerivedSpatialEntity(spatialEntityTree, spatialEntity, spatialEntityType);
    setSpatialEntitySemanticTypeValue(spatialEntityTree, spatialEntity);
    setSpatialEntityMeasureValues(spatialEntityTree, spatialEntity);

    timePoint.addSpatialEntityAndType(spatialEntity, spatialEntityType);
}

void
SpatialTemporalDataReader::setSpatialEntitySemanticTypeValue(const pt::ptree &spatialEntityTree,
                                                             const std::shared_ptr<SpatialEntity> &spatialEntity) {
    boost::optional<std::string> semanticTypeValue = spatialEntityTree.get_optional<std::string>(
                                                         LABEL_SPATIAL_ENTITY_SEMANTIC_TYPE
                                                     );

    spatialEntity->setSemanticType(
        semanticTypeValue.get_value_or(SemanticType::DEFAULT_VALUE)
    );
}

std::set<std::string>::iterator
SpatialTemporalDataReader::getRandomValidUnprocessedInputFilepath() {
    if (!hasNext()) {
        MS_throw(RuntimeException, ERR_NO_VALID_INPUT_FILES_REMAINING);
    }

    // Obtain an iterator to a valid random position in the collection of
    // unprocessed input files
    auto it = getRandomUnprocessedInputFile();

    // While the chosen input file is invalid
    while (!isValidInputFile(*it)) {
        processInvalidInputFile(it);

        it = getRandomUnprocessedInputFile();
    }

    return it;
}

std::set<std::string>::iterator
SpatialTemporalDataReader::getRandomUnprocessedInputFile() {
    // Obtain an iterator to the beginning of the collection
    auto it = unprocessedInputFiles.begin();

    // Advance the iterator for a valid random number of positions
    std::advance(it, std::rand() % unprocessedInputFiles.size());

    return it;
}

void
SpatialTemporalDataReader::processValidInputFile(const std::set<std::string>::iterator &validInputFileIterator) {
    // Add the file to the list of processed files
    processedInputFiles.insert(*validInputFileIterator);

    // Remove the file from the list of unprocessed files
    unprocessedInputFiles.erase(validInputFileIterator);
}

void
SpatialTemporalDataReader::updateInputFilesSets() {
    std::vector<std::string> filesInFolder = getFilesInFolder();

    for (const std::string &file : filesInFolder) {
        if (processedInputFiles.find(file) == processedInputFiles.end()) {
            // Since this is a set each element will be added only if the set does not contain the element already
            unprocessedInputFiles.insert(file);
        }
    }
}

std::vector<std::string>
SpatialTemporalDataReader::getFilesInFolder() {
    return Filesystem::getFilesInFolder(folderPath, INPUT_FILES_EXTENSION);
}

bool
SpatialTemporalDataReader::isValidInputFile(const std::string &inputFilepath) {
    return (XmlValidator::isValidXmlFile(inputFilepath, INPUT_FILES_SCHEMA_PATH));
}

void
SpatialTemporalDataReader::validateFolderPath(const std::string &folderPath) {
    if (!Filesystem::isValidFolderPath(folderPath)) {
        MS_throw(InvalidInputException, ERR_INVALID_FOLDER_PATH);
    }
}


// Constants
const std::string SpatialTemporalDataReader::ERR_INVALID_FOLDER_PATH               = "The provided path does not point to a folder. Please change.";
const std::string SpatialTemporalDataReader::ERR_NO_VALID_INPUT_FILES_REMAINING    = "There are no valid unprocessed input files remaining.";
const std::string SpatialTemporalDataReader::ERR_UNDEFINED_SPATIAL_ENTITY_TYPE     = "The provided spatial entity type is invalid.";

const std::string SpatialTemporalDataReader::LABEL_EXPERIMENT                      = "experiment";
const std::string SpatialTemporalDataReader::LABEL_TIMEPOINT_VALUE                 = "<xmlattr>.value";

const std::string SpatialTemporalDataReader::LABEL_NUMERIC_STATE_VARIABLE               = "numericStateVariable";
const std::string SpatialTemporalDataReader::LABEL_NUMERIC_STATE_VARIABLE_SEMANTIC_TYPE = "<xmlattr>.semanticType";
const std::string SpatialTemporalDataReader::LABEL_NUMERIC_STATE_VARIABLE_NAME          = "name";
const std::string SpatialTemporalDataReader::LABEL_NUMERIC_STATE_VARIABLE_VALUE         = "value";

const std::string SpatialTemporalDataReader::LABEL_SPATIAL_ENTITY                  = "spatialEntity";
const std::string SpatialTemporalDataReader::LABEL_SPATIAL_ENTITY_SPATIAL_TYPE     = "<xmlattr>.spatialType";
const std::string SpatialTemporalDataReader::LABEL_SPATIAL_ENTITY_SEMANTIC_TYPE    = "<xmlattr>.semanticType";

const std::string SpatialTemporalDataReader::INPUT_FILES_EXTENSION      = ".xml";
const std::string SpatialTemporalDataReader::INPUT_FILES_SCHEMA_PATH    = "/usr/local/share/mule/config/verification/spatial-temporal/schema/MSTML_L1V1.xsd";
