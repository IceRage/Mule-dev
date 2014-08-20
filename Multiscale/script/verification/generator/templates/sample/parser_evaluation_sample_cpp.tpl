/******************************************************************************
/*{% for line in auto_generated_warning %}*/
 /*{{ line }}*/
/*{% endfor %}*/
 *****************************************************************************/

#include "multiscale/exception/ExceptionHandler.hpp"
#include "multiscale/exception/InvalidInputException.hpp"
#include "multiscale/verification/spatial-temporal/attribute/ProbabilisticLogicPropertyAttribute.hpp"
/*{% for spatial_entity in spatial_entities %}*/
#include "multiscale/verification/spatial-temporal/model//*{{ spatial_entity.name|first_to_upper }}*/.hpp"
/*{% endfor %}*/
#include "multiscale/verification/spatial-temporal/parsing/Parser.hpp"

#include <iostream>

using namespace multiscale;
using namespace multiscale::verification;


// Initialise the provided trace
void initialiseTrace(SpatialTemporalTrace &trace) {
    // Variables initialisation
    std::size_t nrOfTimePoints = 12;

    NumericStateVariableId aNumericStateVariableId("A", 0);
    NumericStateVariableId bNumericStateVariableId("B", 0);

    double aMinValue = 1;
    double aMaxValue = 0;

    double bConstantValue = 3;

    double /*{{ spatial_entities[0].name }}*/s/*{{ spatial_measures[0].name|first_to_upper }}*/MinValue = 1;
    double /*{{ spatial_entities[0].name }}*/s/*{{ spatial_measures[0].name|first_to_upper }}*/MaxValue = -1;

    // Initialise timepoints
    trace.clear();

    std::vector<TimePoint> timePoints;

    // Add timepoints containing the numeric state variable "B" to the collection of timepoints
    for (std::size_t i = 0; i < nrOfTimePoints; i++) {
        timePoints.push_back(TimePoint(i));
        timePoints[i].addNumericStateVariable(bNumericStateVariableId, bConstantValue);
    }

    // Add a second numeric state variable to the collection of timepoints
    for (std::size_t i = 0; i < nrOfTimePoints; i++) {
        if (i % 4 == 0) {
            timePoints[i].addNumericStateVariable(aNumericStateVariableId, aMinValue);
        } else {
            timePoints[i].addNumericStateVariable(aNumericStateVariableId, aMinValue + i);
        }
    }

    // Initialise the aMaxValue field
    for (std::size_t i = 0; i < nrOfTimePoints; i++) {
        aMaxValue = std::max(aMaxValue, timePoints[i].getNumericStateVariable(aNumericStateVariableId));
    }

    // Add spatial entities to each timepoint
    for (std::size_t i = 0; i < nrOfTimePoints; i++) {

        // Add /*{{ spatial_entities[0].name }}*/s to the timepoint
        for (std::size_t j = ((((i + 1) % 4) == 0) ? (i - 1) : 0); j <= i; j++) {
            std::shared_ptr<SpatialEntity> /*{{ spatial_entities[0].name }}*/ = std::make_shared</*{{ spatial_entities[0].name|first_to_upper }}*/>();

            /*{{ spatial_entities[0].name }}*/s/*{{ spatial_measures[0].name|first_to_upper }}*/MaxValue = std::max(/*{{ spatial_entities[0].name }}*/s/*{{ spatial_measures[0].name|first_to_upper }}*/MaxValue, static_cast<double>((j * 2.4) + /*{{ spatial_entities[0].name }}*/s/*{{ spatial_measures[0].name|first_to_upper }}*/MinValue));

            /*{{ spatial_entities[0].name }}*/->setSpatialMeasureValue(SpatialMeasureType::/*{{ spatial_measures[0].name|first_to_upper }}*/, static_cast<double>((j * 2.4) + /*{{ spatial_entities[0].name }}*/s/*{{ spatial_measures[0].name|first_to_upper }}*/MinValue));
        /*{% for spatial_measure in spatial_measures[1:] %}*/
            /*{{ spatial_entities[0].name }}*/->setSpatialMeasureValue(SpatialMeasureType::/*{{ spatial_measure.name|first_to_upper }}*/, static_cast<double>(/*{{ spatial_measure.max_value }}*/ - /*{{ spatial_measure.min_value }}*/) / 2);
        /*{% endfor %}*/
            /*{{ spatial_entities[0].name }}*/->setSemanticType(0);

            timePoints[i].addSpatialEntity(/*{{ spatial_entities[0].name }}*/, SubsetSpecificType::/*{{ spatial_entities[0].name|first_to_upper }}*/s);
        }

    /*{% for spatial_entity in spatial_entities[1:] %}*/
        // Add /*{{ spatial_entity.name }}*/s to the timepoint
        for (std::size_t k = 0; k <= i; k++) {
                std::shared_ptr<SpatialEntity> /*{{ spatial_entity.name }}*/ = std::make_shared</*{{ spatial_entity.name|first_to_upper }}*/>();

                /*{{ spatial_entity.name }}*/->setSpatialMeasureValue(SpatialMeasureType::/*{{ spatial_measures[0].name|first_to_upper }}*/, static_cast<double>((k * 0.3) + 0.7));
            /*{% for spatial_measure in spatial_measures[1:] %}*/
                /*{{ spatial_entity.name }}*/->setSpatialMeasureValue(SpatialMeasureType::/*{{ spatial_measure.name|first_to_upper }}*/, static_cast<double>(/*{{ spatial_measure.max_value }}*/ - /*{{ spatial_measure.min_value }}*/) / 3);
            /*{% endfor %}*/
                /*{{ spatial_entity.name }}*/->setSemanticType(0);

                timePoints[i].addSpatialEntity(/*{{ spatial_entity.name }}*/, SubsetSpecificType::/*{{ spatial_entity.name|first_to_upper }}*/s);
            }
    /*{% endfor %}*/
    }

    // Add all timepoints to the trace
    for (TimePoint &timePoint : timePoints) {
        trace.addTimePoint(timePoint);
    }
}

//  Main program
int main(int argc, char **argv) {
    std::string test;
    SpatialTemporalTrace trace;
    AbstractSyntaxTree result;

    initialiseTrace(trace);

    std::cout << "/////////////////////////////////////////////////////////\n\n";
    std::cout << "\tA multidimensional multiscale logical query parser and evaluator...\n\n";
    std::cout << "/////////////////////////////////////////////////////////\n\n";

    std::cout
        << "Please enter a multidimensional multiscale logical query (or \"q\" to exit):" << std::endl
        << std::endl;


    while (getline(std::cin, test)) {
        if (test.compare("q") == 0) {
            break;
        }

        Parser parser(test);

        try {
            if (parser.parse(result)) {
                std::cout << "-----------------------------------------------------" << std::endl;
                std::cout << " Parsing succeeded"
                          << " and the AST evaluates to " << (result.evaluate(trace) ? "true" : "false")
                          << "!" << std::endl;
                std::cout << "-----------------------------------------------------" << std::endl << std::endl;
            } else {
                std::cout << "-----------------------------------------------------" << std::endl;
                std::cout << " Parsing failed!" << std::endl;
                std::cout << "-----------------------------------------------------" << std::endl << std::endl;
            }
        } catch(const exception &e) {
            ExceptionHandler::printErrorMessage(e);

            return EXEC_ERR_CODE;
        } catch(...) {
            cerr << "Exception of unknown type!" << std::endl;
        }
    }

    return -1;
}
