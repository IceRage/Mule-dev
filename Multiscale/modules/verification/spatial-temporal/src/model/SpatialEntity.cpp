#include "multiscale/verification/spatial-temporal/model/SpatialEntity.hpp"
#include "multiscale/util/Numeric.hpp"
#include "multiscale/util/StringManipulator.hpp"

using namespace multiscale;
using namespace multiscale::verification;
using namespace multiscale::verification::spatialmeasure;


SpatialEntity::SpatialEntity() {
    semanticType         = 0;
    spatialMeasureValues = std::vector<double>(NR_SPATIAL_MEASURE_TYPES, 0);
}

unsigned long SpatialEntity::getSemanticType() const {
    return semanticType;
}

void SpatialEntity::setSemanticType(unsigned long semanticType) {
    this->semanticType = semanticType;
}

double SpatialEntity::getSpatialMeasureValue(const SpatialMeasureType &spatialMeasureType) const {
    std::size_t spatialMeasureTypeIndex = computeSpatialMeasureTypeIndex(spatialMeasureType);

    return spatialMeasureValues[spatialMeasureTypeIndex];
}

void SpatialEntity::setSpatialMeasureValue(const SpatialMeasureType &spatialMeasureType,
                                           double spatialMeasureValue) {
    validateSpatialMeasureValue(spatialMeasureValue, spatialMeasureType);

    std::size_t spatialMeasureTypeIndex = computeSpatialMeasureTypeIndex(spatialMeasureType);

    spatialMeasureValues[spatialMeasureTypeIndex] = spatialMeasureValue;
}

bool SpatialEntity::operator<(const SpatialEntity &rhsSpatialEntity) const {
    // Return true if lhs.semanticType < rhs.semanticType
    if (this->semanticType < rhsSpatialEntity.semanticType) {
        return true;
    }

    // Return true if lhs.spatialMeasureValue < rhs.spatialMeasureValue
    for (std::size_t i = 0; i < NR_SPATIAL_MEASURE_TYPES; i++) {
        if (this->spatialMeasureValues[i] < rhsSpatialEntity.spatialMeasureValues[i]) {
            return true;
        }
    }

    // Otherwise, return false
    return false;
}

std::string SpatialEntity::toString() const {
    std::string outputString = StringManipulator::toString<unsigned long>(semanticType);

    // Add all spatial measure values to the output string
    for (std::size_t i = 0; i < NR_SPATIAL_MEASURE_TYPES; i++) {
        outputString += (OUTPUT_SPATIAL_MEASURE_VALUE_SEPARATOR +
                         StringManipulator::toString<double>(spatialMeasureValues[i]));
    }

    return outputString;
}

void SpatialEntity::validateSpatialMeasureValue(double spatialMeasureValue,
                                                const SpatialMeasureType &spatialMeasureType) {
    spatialmeasure::validateSpatialMeasureType(spatialMeasureType);

    if ((spatialMeasureValue < spatialmeasure::getMinValidSpatialMeasureValue(spatialMeasureType)) ||
        (spatialMeasureValue > spatialmeasure::getMaxValidSpatialMeasureValue(spatialMeasureType))) {
        MS_throw(SpatialTemporalException,
                 ERR_INVALID_SPATIAL_MEASURE_BEGIN +
                 StringManipulator::toString<double>(spatialMeasureValue) +
                 ERR_INVALID_SPATIAL_MEASURE_MIDDLE +
                 StringManipulator::toString<SpatialMeasureType>(spatialMeasureType) +
                 ERR_INVALID_SPATIAL_MEASURE_END
        );
    }
}


// Constants
const std::string SpatialEntity::OUTPUT_SPATIAL_MEASURE_VALUE_SEPARATOR = ", ";

const std::string SpatialEntity::ERR_INVALID_SPATIAL_MEASURE_BEGIN  = "The provided spatial measure value (";
const std::string SpatialEntity::ERR_INVALID_SPATIAL_MEASURE_MIDDLE = "is invalid for the given spatial measure type (";
const std::string SpatialEntity::ERR_INVALID_SPATIAL_MEASURE_END    = "). Please change.";
