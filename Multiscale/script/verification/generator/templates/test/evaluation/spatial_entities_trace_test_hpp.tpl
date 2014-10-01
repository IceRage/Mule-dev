#ifndef SPATIALENTITIESTRACETEST_HPP
#define SPATIALENTITIESTRACETEST_HPP

/******************************************************************************
/*{% for line in auto_generated_warning %}*/
 /*{{ line }}*/
/*{% endfor %}*/
 *****************************************************************************/

#include "TraceEvaluationTest.hpp"

/*{% for spatial_entity in spatial_entities %}*/
#include "multiscale/verification/spatial-temporal/model//*{{ spatial_entity.name|first_to_upper }}*/.hpp"
/*{% endfor %}*/
 
using namespace multiscale;
using namespace multiscaletest;


namespace multiscaletest {

    //! Class for testing evaluation of spatial entities-only traces
    class SpatialEntitiesTraceTest : public TraceEvaluationTest {

        protected:
            
            double /*{{ spatial_entities[0].name }}*/s/*{{ spatial_measures[0].name|first_to_upper }}*/MinValue;  /*!< The minimum /*{{ spatial_measures[0].name }}*/ value for the /*{{ spatial_entities[0].name }}*/ spatial entity type */
            double /*{{ spatial_entities[0].name }}*/s/*{{ spatial_measures[0].name|first_to_upper }}*/MaxValue;  /*!< The maximum /*{{ spatial_measures[0].name }}*/ value for the /*{{ spatial_entities[0].name }}*/ spatial entity type */
            
        private:

           //! Initialise the trace
           virtual void InitialiseTrace() override;

    };

    void SpatialEntitiesTraceTest::InitialiseTrace() {
        // Initialise protected class fields
        nrOfTimePoints = 12;
        
        /*{{ spatial_entities[0].name }}*/s/*{{ spatial_measures[0].name|first_to_upper }}*/MinValue = 1;
        
        // Initialise timepoints
        trace.clear();

        std::vector<TimePoint> timePoints;

        // Add timepoints to the trace
        for (std::size_t i = 0; i < nrOfTimePoints; i++) {
            timePoints.push_back(TimePoint(i));
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
            // Add /*{{ spatial_entity.name }}*/s with semantic type "0" to the timepoint
            for (std::size_t k = 0; k <= i; k++) {
                std::shared_ptr<SpatialEntity> /*{{ spatial_entity.name }}*/ = std::make_shared</*{{ spatial_entity.name|first_to_upper }}*/>();

                /*{{ spatial_entity.name }}*/->setSpatialMeasureValue(SpatialMeasureType::/*{{ spatial_measures[0].name|first_to_upper }}*/, static_cast<double>((k * 0.3) + 0.7));
            /*{% for spatial_measure in spatial_measures[1:] %}*/
                /*{{ spatial_entity.name }}*/->setSpatialMeasureValue(SpatialMeasureType::/*{{ spatial_measure.name|first_to_upper }}*/, static_cast<double>(/*{{ spatial_measure.max_value }}*/ - /*{{ spatial_measure.min_value }}*/) / 3);
            /*{% endfor %}*/
                /*{{ spatial_entity.name }}*/->setSemanticType(0);

                timePoints[i].addSpatialEntity(/*{{ spatial_entity.name }}*/, SubsetSpecificType::/*{{ spatial_entity.name|first_to_upper }}*/s);
            }
            
            // Add /*{{ spatial_entity.name }}*/s with semantic type "1" to the timepoint
            for (std::size_t k = 0; k <= i; k++) {
                std::shared_ptr<SpatialEntity> /*{{ spatial_entity.name }}*/ = std::make_shared</*{{ spatial_entity.name|first_to_upper }}*/>();

                /*{{ spatial_entity.name }}*/->setSpatialMeasureValue(SpatialMeasureType::/*{{ spatial_measures[0].name|first_to_upper }}*/, static_cast<double>((k * 0.3) + 0.7));
            /*{% for spatial_measure in spatial_measures[1:] %}*/
                /*{{ spatial_entity.name }}*/->setSpatialMeasureValue(SpatialMeasureType::/*{{ spatial_measure.name|first_to_upper }}*/, static_cast<double>(/*{{ spatial_measure.max_value }}*/ - /*{{ spatial_measure.min_value }}*/) / 3);
            /*{% endfor %}*/
                /*{{ spatial_entity.name }}*/->setSemanticType(1);

                timePoints[i].addSpatialEntity(/*{{ spatial_entity.name }}*/, SubsetSpecificType::/*{{ spatial_entity.name|first_to_upper }}*/s);
            }
        /*{% endfor %}*/
        }

        // Add all timepoints to the trace
        for (TimePoint &timePoint : timePoints) {
            trace.addTimePoint(timePoint);
        }
    }

};


/////////////////////////////////////////////////////////
//
//
// BinaryNumericFilter
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryNumericFilter) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ < subtract(/*{{ spatial_measures[0].name }}*/, 0.0001)))) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryNumericMeasureAdd) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) <= add(" + StringManipulator::toString<double>(aMinValue) + ", 0.0111)]"));
}

TEST_F(SpatialEntitiesTraceTest, BinaryNumericMeasureDiv) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) < div(2, 3)]"));
}

TEST_F(SpatialEntitiesTraceTest, BinaryNumericMeasureLog) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= log(4.33333, 9.12312312)]"));
}

TEST_F(SpatialEntitiesTraceTest, BinaryNumericMeasureMod) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) <= mod(1.00001, 8)]"));
}

TEST_F(SpatialEntitiesTraceTest, BinaryNumericMeasureMultiply) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) <= multiply(2, 0.50001)]"));
}

TEST_F(SpatialEntitiesTraceTest, BinaryNumericMeasurePower) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) <= power(2, 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, BinaryNumericMeasureSubtract) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ > 1))) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryNumericNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryNumericNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [median([0, 10] add(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), 2)) < 7.0001]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryNumericTemporal
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryNumericTemporal) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [div(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), 2) > 0.49]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryStatisticalMeasure) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [covar(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), /*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 0.001]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [covar(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), /*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 0.00034]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalQuantileMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryStatisticalQuantileMeasurePercentile) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [X[4] percentile(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), 4.3) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, BinaryStatisticalQuantileMeasureQuartile) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [X[4] quartile(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), 4.3) <= 0.5]"), NumericException);
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalQuantileNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryStatisticalQuantileNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [percentile(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), 4.3) > 0.9999]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalQuantileSpatial
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryStatisticalQuantileSpatial) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [min([0, 10] percentile(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), 4.3)) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalSpatial
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryStatisticalSpatial) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [min([0, 4] covar(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), /*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) > 0.000001]"));
}


/////////////////////////////////////////////////////////
//
//
// ChangeMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, ChangeMeasureDifference) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [d(max(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) <= 2.41]"));
}

TEST_F(SpatialEntitiesTraceTest, ChangeMeasureRatio) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [r(max(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) < 3.4]"));
}


/////////////////////////////////////////////////////////
//
//
// ChangeTemporalNumericCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, ChangeTemporalNumericCollection) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [max(r([0, 11] min(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) = 25]"));
}


/////////////////////////////////////////////////////////
//
//
// ChangeTemporalNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, ChangeTemporalNumericMeasure) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [r(max(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) < 3.41]"));
}


/////////////////////////////////////////////////////////
//
//
// Comparator
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, ComparatorGreaterThan) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) > 1]"));
}

TEST_F(SpatialEntitiesTraceTest, ComparatorLessThan) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) < 1]"));
}

TEST_F(SpatialEntitiesTraceTest, ComparatorGreaterThanOrEqual) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 1]"));
}

TEST_F(SpatialEntitiesTraceTest, ComparatorLessThanOrEqual) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) <= 1]"));
}

TEST_F(SpatialEntitiesTraceTest, ComparatorEqual) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// CompoundConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, CompoundConstraint) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, (/*{{ spatial_measures[0].name }}*/ <= 1.0001) ^ (/*{{ spatial_measures[0].name }}*/ = 0.1)))) <= 1]"));
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, (/*{{ spatial_measures[0].name }}*/ <= 1.0001) V (/*{{ spatial_measures[0].name }}*/ = 0.3)))) = 0]"));
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, (/*{{ spatial_measures[0].name }}*/ <= 1.0001) => (/*{{ spatial_measures[0].name }}*/ = 0.1)))) > 1]"));
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, (/*{{ spatial_measures[0].name }}*/ <= 1.0001) <=> (/*{{ spatial_measures[0].name }}*/ = 0.1)))) < 1]"));
}

TEST_F(SpatialEntitiesTraceTest, CompoundConstraintMultiple) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, (/*{{ spatial_measures[0].name }}*/ <= 1.0001) ^ (/*{{ spatial_measures[0].name }}*/ = 0.1) ^ (~ /*{{ spatial_measures[0].name }}*/ > 1)))) < 1]"));
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, (/*{{ spatial_measures[0].name }}*/ <= 1.0001) V (/*{{ spatial_measures[0].name }}*/ = 0.1) V (~ /*{{ spatial_measures[0].name }}*/ > 1)))) <= 1]"));
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, (/*{{ spatial_measures[0].name }}*/ <= 1.0001) => (/*{{ spatial_measures[0].name }}*/ = 0.1) => (~ /*{{ spatial_measures[0].name }}*/ > 1)))) = 1]"));
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, (/*{{ spatial_measures[0].name }}*/ <= 1.0001) <=> (/*{{ spatial_measures[0].name }}*/ = 0.1) <=> (~ /*{{ spatial_measures[0].name }}*/ > 1)))) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// CompoundLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, CompoundLogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 1) ^ (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 1)]"));
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 1) V (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) < 1)]"));
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [(avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 1) => (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) > 1)]"));
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 1) <=> (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) <= 1)]"));
}

TEST_F(SpatialEntitiesTraceTest, CompoundLogicPropertyMultiple) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [(avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 1) ^ (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) < 1) ^ 3 = 3]"));
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 1) V (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) < 1) V 3 = 3]"));
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 1) => (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) < 1) => 3 = 3]"));
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [(avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 1) <=> (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) < 1) <=> 3 = 3]"));
}


/////////////////////////////////////////////////////////
//
//
// ConstraintEnclosedByParentheses
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, ConstraintEnclosedByParentheses) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, (/*{{ spatial_measures[0].name }}*/ < 1.00001)))) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, ConstraintEnclosedByParenthesesDoubled) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, ((/*{{ spatial_measures[0].name }}*/ < 1.00001))))) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, ConstraintEnclosedByParenthesesQuadrupled) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, ((((/*{{ spatial_measures[0].name }}*/ < 1.00001))))))) >= 1]"));
}


/////////////////////////////////////////////////////////
//
//
// Constraint
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, Constraint) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ > 10000 V /*{{ spatial_measures[0].name }}*/ < 1.001))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// FilterNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, FilterNumericMeasure) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ > 0.5 ^ /*{{ spatial_measures[0].name }}*/ < 1.0001))) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// FilterSubset
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, FilterSubset) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ > 1))) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// FutureLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, FutureLogicProperty) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [2, 3] (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 4)]"));
}


/////////////////////////////////////////////////////////
//
//
// GlobalLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, GlobalLogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [G [2, 3] (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) < 4)]"));
}


/////////////////////////////////////////////////////////
//
//
// HeterogeneousTimeseriesComponent
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, HeterogeneousTimeseriesComponentPeak) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [max(enteringValue(peak, [0, 11] avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) > 16.59]"));
}

TEST_F(SpatialEntitiesTraceTest, HeterogeneousTimeseriesComponentValley) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [median(enteringValue(valley, [0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) < 2]"));
}


/////////////////////////////////////////////////////////
//
//
// HomogeneousHomogeneousTimeseries
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, HomogeneousHomogeneousTimeseries) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [max(values(plateau, [0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// HomogeneousTimeseriesComponent
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, HomogeneousTimeseriesComponentAscent) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [min(values(ascent, [0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) > 1]"));
}

TEST_F(SpatialEntitiesTraceTest, HomogeneousTimeseriesComponentDescent) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [avg(timeSpan(descent, [0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, HomogeneousTimeseriesComponentPlateau) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [mode(values(plateau, [0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) > 0]"));
}

TEST_F(SpatialEntitiesTraceTest, HomogeneousTimeseriesComponentUniformAscent) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [max(values(uniformAscent, [0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) = 11]"));
}

TEST_F(SpatialEntitiesTraceTest, HomogeneousTimeseriesComponentUniformDescent) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [avg(values(uniformDescent, [0, 11] avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// HomogeneousTimeseriesMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, HomogeneousTimeseriesMeasureTimeSpan) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [max(timeSpan(ascent, [0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) > 4]"));
}

TEST_F(SpatialEntitiesTraceTest, HomogeneousTimeseriesMeasureValue) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [min(values(descent, [0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) = 2]"));
}


/////////////////////////////////////////////////////////
//
//
// LogicPropertyEnclosedByParentheses
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, LogicPropertyEnclosedByParentheses) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 0.99)]"));
}

TEST_F(SpatialEntitiesTraceTest, LogicPropertyEnclosedByParenthesesDoubled) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [((count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 0.99))]"));
}

TEST_F(SpatialEntitiesTraceTest, LogicPropertyEnclosedByParenthesesQuadrupled) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [((((count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 0.99))))]"));
}


/////////////////////////////////////////////////////////
//
//
// LogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, LogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 0.99999]"));
}


/////////////////////////////////////////////////////////
//
//
// MultipleLogicProperties
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, MultipleLogicProperties1) {
    EXPECT_FALSE(RunEvaluationTest("P > 0.1234 [( d(4) >=  count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) ) ^ ( covar(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), /*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= {A} ) V ( {B} = sqrt(add({B}, {C})) )]"));
}

TEST_F(SpatialEntitiesTraceTest, MultipleLogicProperties2) {
    EXPECT_TRUE(
        RunEvaluationTest(""
            "P <= 0.85934 ["
            "   (~ "
            "       F [2, 3] ( "
            "           max("
            "               /*{{ spatial_measures[0].name }}*/("
            "                   filter("
            "                       /*{{ spatial_entities[0].name }}*/s, "
            "                       /*{{ spatial_measures[0].name }}*/ <= 10"
            "                   )"
            "               )"
            "           ) >= 2 "
            "       ) "
            "   ) => ( "
            "       G [4, 5] ("
            "           X ("
            "               X [5] ( "
            "                   percentile("
            "                       /*{{ spatial_measures[0].name }}*/("
            "                           /*{{ spatial_entities[0].name }}*/s"
            "                       ), "
            "                       0.4"
            "                   ) = 0.7 "
            "               )"
            "           )"
            "       ) "
            "   ) <=> ( "
            "       count("
            "           /*{{ spatial_measures[0].name }}*/("
            "               filter("
            "                   /*{{ spatial_entities[0].name }}*/s, "
            "                   (/*{{ spatial_measures[0].name }}*/ <= 2) ^ "
            "                   (/*{{ spatial_measures[0].name }}*/ >= 6) V "
            "                   (/*{{ spatial_measures[0].name }}*/ >= 30) => "
            "                   (/*{{ spatial_measures[0].name }}*/ <= 2) <=> "
            "                   (/*{{ spatial_measures[0].name }}*/ >= 4)"
            "               ) "
            "           )"
            "       ) >= 1"
            "   ) U [3, 7] ( "
            "       kurt("
            "           /*{{ spatial_measures[0].name }}*/("
            "               /*{{ spatial_entities[0].name }}*/s"
            "           )"
            "       ) <= sqrt("
            "           sqrt("
            "               sqrt("
            "                   {A}"
            "               )"
            "           )"
            "       ) "
            "   ) "
            "]"
        )
    );
}


/////////////////////////////////////////////////////////
//
//
// NextKLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NextKLogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [X [3] (max(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 8.1999)]"));
}


/////////////////////////////////////////////////////////
//
//
// NextLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NextLogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [X (max(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) <= 3.5)]"));
}


/////////////////////////////////////////////////////////
//
//
// NotConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NotConstraint) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, ~ (/*{{ spatial_measures[0].name }}*/ <= 1)))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// NotLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NotLogicProperty) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [~(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 1)]"));
}


/////////////////////////////////////////////////////////
//
//
// NumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NumericMeasure) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [avg([0, 3] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) = 2]"));
}


/////////////////////////////////////////////////////////
//
//
// NumericMeasureCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NumericMeasureCollection) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [min(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// NumericSpatialMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NumericSpatialMeasure) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [geomean(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// NumericStateVariable
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NumericStateVariableWithoutTypes) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A} <= {B}]"));
}

TEST_F(SpatialEntitiesTraceTest, NumericStateVariableTypeLeft) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A}(type = 0) <= {B}]"));
}

TEST_F(SpatialEntitiesTraceTest, NumericStateVariableTypeRight) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A} <= {B}(type = 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, NumericStateVariableBothTypes) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A}(type = 0) <= {B}(type = 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, NumericStateVariableBothTypesAndDifferentTypeValues) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A}(type = 0) <= {C}(type = Organ.Heart)]"));
}

TEST_F(SpatialEntitiesTraceTest, NumericStateVariableOneNumericStateVariable) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{C}(type = Organ.Heart) = 12]"));
}

TEST_F(SpatialEntitiesTraceTest, NumericStateVariableWrongRhsType) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A}(type = 0) <= {C}(type = 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, NumericStateVariableWrongName) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{a2#0f-} <= {B}]"));
}

TEST_F(SpatialEntitiesTraceTest, NumericStateVariableWrongLongName) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{`1234567890-=~!@#$%^&*()_+qwertyuiop[]asdfghjkl;'\\<zxcvbnm,./QWERTYUIOPASDFGHJKL:\"|>ZXCVBNM<>?} <= {B}]"));
}

TEST_F(SpatialEntitiesTraceTest, NumericStateVariableWrongTypeLhs) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A}(type = Organ.Heart) <= {B}]"));
}

TEST_F(SpatialEntitiesTraceTest, NumericStateVariableWrongTypeLhsLargerValue) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{B}(type = 213121) <= {B}]"));
}


/////////////////////////////////////////////////////////
//
//
// NumericStatisticalMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NumericStatisticalMeasure) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [X min([0, 5] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) <= 1]"));
}


/////////////////////////////////////////////////////////
//
//
// ProbabilisticLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, ProbabilisticLogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.4 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 1]"));
}


/////////////////////////////////////////////////////////
//
//
// SemanticType
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SemanticType) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.4 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, type = 0))) >= 1]"));
}


/////////////////////////////////////////////////////////
//
//
// SimilarityMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SimilarityMeasureAntiSimilar) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [opposite([0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), [0, 11] subtract(0, count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))), 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, SimilarityMeasureSimilar) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [similar(r([0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))), r([0, 11] multiply(avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), 2)), 0)]"));
}


/////////////////////////////////////////////////////////
//
//
// SimilarityTemporalNumericCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SimilarityTemporalNumericCollection) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [similar([0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), [0, 11] 6, 6)]"));
}


/////////////////////////////////////////////////////////
//
//
// SpatialMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SpatialMeasure/*{{ spatial_measures[0].name|first_to_upper }}*/) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ > 0))) >= 1]"));
}

/*{% for spatial_measure in spatial_measures[1:] %}*/
TEST_F(SpatialEntitiesTraceTest, SpatialMeasure/*{{ spatial_measure.name|first_to_upper }}*/) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measure.name }}*/ > /*{{ spatial_measure.min_value }}*/))) = 1]"));
}

/*{% endfor %}*/

/////////////////////////////////////////////////////////
//
//
// SpatialMeasureCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SpatialMeasureCollection) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) > 26.21]"));
}


/////////////////////////////////////////////////////////
//
//
// Subset
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, Subset) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// SubsetOperation
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SubsetOperationDifference) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(/*{{ spatial_measures[0].name }}*/(difference(/*{{ spatial_entities[0].name }}*/s, filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ < 1)))) >= 1]"));
}

/*{% for spatial_entity in spatial_entities[1:] %}*/
TEST_F(SpatialEntitiesTraceTest, SubsetOperationDifference/*{{ spatial_entity.name|first_to_upper }}*/) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(/*{{ spatial_measures[0].name }}*/(difference(/*{{ spatial_entity.name }}*/s, /*{{ spatial_entities[0].name }}*/s))) > 24]"));
}

/*{% endfor %}*/
TEST_F(SpatialEntitiesTraceTest, SubsetOperationIntersection) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(/*{{ spatial_measures[0].name }}*/(intersection(/*{{ spatial_entities[0].name }}*/s, filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ <= 1)))) >= 2]"));
}

/*{% for spatial_entity in spatial_entities[1:] %}*/
TEST_F(SpatialEntitiesTraceTest, SubsetOperationIntersection/*{{ spatial_entity.name|first_to_upper }}*/) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(/*{{ spatial_measures[0].name }}*/(intersection(/*{{ spatial_entities[0].name }}*/s, filter(/*{{ spatial_entity.name }}*/s, /*{{ spatial_measures[0].name }}*/ > 0.5)))) > 0]"));
}

/*{% endfor %}*/
TEST_F(SpatialEntitiesTraceTest, SubsetOperationUnion) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(/*{{ spatial_measures[0].name }}*/(union(filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ < 20), filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ >= 20)))) > 0]"));
}

/*{% for spatial_entity in spatial_entities[1:] %}*/
TEST_F(SpatialEntitiesTraceTest, SubsetOperationUnion/*{{ spatial_entity.name|first_to_upper }}*/) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(/*{{ spatial_measures[0].name }}*/(union(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_entity.name }}*/s))) >= 3]"));
}

/*{% endfor %}*/

/////////////////////////////////////////////////////////
//
//
// SubsetSpecific
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SubsetSpecific/*{{ spatial_entities[0].name|first_to_upper }}*/s) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) > 0]"));
}

/*{% for spatial_entity in spatial_entities[1:] %}*/
TEST_F(SpatialEntitiesTraceTest, SubsetSpecific/*{{ spatial_entity.name|first_to_upper }}*/s) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entity.name }}*/s)) < 2]"));
}

/*{% endfor %}*/


/////////////////////////////////////////////////////////
//
//
// SubsetSubsetOperation
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SubsetSubsetOperation) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(/*{{ spatial_measures[0].name }}*/(union(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_entities[0].name }}*/s))) >= 4.3]"));
}


/////////////////////////////////////////////////////////
//
//
// TemporalNumericCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TemporalNumericCollection) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [min([0, 11] max(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// TemporalNumericComparison
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TemporalNumericComparison) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [max(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 1.0001]"));
}


/////////////////////////////////////////////////////////
//
//
// TemporalNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TemporalNumericMeasure) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = 1)]"));
}


/////////////////////////////////////////////////////////
//
//
// TemporalNumericMeasureCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TemporalNumericMeasureCollection) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [min([0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// TimeseriesComponent
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TimeseriesComponent) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [median(enteringValue(uniformAscent, [0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) < 5]"));
}


/////////////////////////////////////////////////////////
//
//
// TimeseriesMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TimeseriesMeasureEnteringTime) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [min(enteringTime(descent, [0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) < 2]"));
}

TEST_F(SpatialEntitiesTraceTest, TimeseriesMeasureEnteringValue) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [min(enteringValue(uniformDescent, [0, 11] max(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// TimeseriesTimeseriesComponent
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TimeseriesTimeseriesComponent) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [median(enteringTime(peak, [0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) = 6]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericFilter
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryNumericFilter) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ <= round(/*{{ spatial_measures[0].name }}*/)))) > 1]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryNumericMeasureAbs) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) <= abs(-1)]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryNumericMeasureCeil) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = ceil(0.3)]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryNumericMeasureFloor) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = floor(0.49)]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryNumericMeasureRound) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = round(0.50001)]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryNumericMeasureSign) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) <= sign(21.1)]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryNumericMeasureSqrt) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= sqrt(0.9)]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryNumericMeasureTrunc) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) <= trunc(1.1)]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryNumericNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [max([0, 11] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) < 11]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericTemporal
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryNumericTemporal) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 0.9999]"));
}


/////////////////////////////////////////////////////////
//
//
// UnarySpatialConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnarySpatialConstraint) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ <= 0.4))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryStatisticalMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureAvg) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) < 1.00001]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureCount) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) > 1]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureGeomean) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [geomean(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureHarmean) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [harmean(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) > 1.000001]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureKurt) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [kurt(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) > 0]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureMax) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [max(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = 0]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureMedian) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [median(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) >= 1]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureMin) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [min(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureMode) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [mode(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = 0]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureProduct) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [product(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) < 1]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureSkew) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [skew(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = 0]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureStdev) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [stdev(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureSum) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [sum(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = 0]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureVar) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [var(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) < 0.0001]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryStatisticalNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryStatisticalSpatial
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalSpatial) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [max([0, 5] count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) > 6]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryTypeConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryTypeConstraint) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, type = Organ.Heart))) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// UntilLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UntilLogicProperty) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [(d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) >= 0) U [0, 3] {A} = 4]"));
}

TEST_F(SpatialEntitiesTraceTest, UntilLogicPropertyMultiple) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) >= 0) U [0, 3] (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) > 0) <=> (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) = 3)]"));
}


/////////////////////////////////////////////////////////
//
//
// Constant value
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, GlobalConstantValueReal) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(2) = 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalConstantValueNumericStateVariable) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d({A}) = 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalConstantValueUnaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [1, 10] (d(round(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) = 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalConstantValueBinaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(add(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), 2)) = 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalConstantValueUnaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) = 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalConstantValueBinaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(covar(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ < 1)), /*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) = 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalConstantValueBinaryStatisticalQuantileNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(quartile(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), 50)) = 0)]"));
}


/////////////////////////////////////////////////////////
//
//
// Increasing value
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, FutureIncreasingValueReal) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(2) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, FutureIncreasingValueNumericStateVariable) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [F [0, 10] (d({A}) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, FutureIncreasingValueUnaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(round(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, FutureIncreasingValueBinaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(add(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), 1)) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, FutureIncreasingValueUnaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, FutureIncreasingValueBinaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(covar(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), /*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, FutureIncreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(quartile(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), 50)) > 0)]"));
}


/////////////////////////////////////////////////////////
//
//
// Decreasing value
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, GlobalDecreasingValueReal) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(2) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalDecreasingValueNumericStateVariable) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d({A}) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalDecreasingValueUnaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(round({A})) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalDecreasingValueBinaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(add({A}, {B})) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalDecreasingValueUnaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalDecreasingValueBinaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(covar(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), /*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalDecreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(quartile(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), 50)) < 0)]"));
}


/////////////////////////////////////////////////////////
//
//
// Increasing and then decreasing value
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, IncreasingUntilDecreasingValueReal) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d(2) > 0) U [0, 10] (d(2) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, IncreasingUntilDecreasingValueNumericStateVariable) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d({A}) > 0) U [0, 10] (d({A}) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, IncreasingUntilDecreasingValueNumericStateVariable2) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d({A}) > 0) U [0, 10] (d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, IncreasingUntilDecreasingValueUnaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) >= 0) U [0, 10] (d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, IncreasingUntilDecreasingValueBinaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) > 0) U [0, 10] (d(add(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), 2)) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, IncreasingUntilDecreasingValueUnaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(power(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), 1)) > 0) U [0, 10] (d(power(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), 1)) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, IncreasingUntilDecreasingValueBinaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d(covar(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), /*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) >= 0) U [0, 10] (d(avg(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ > 5 V /*{{ spatial_measures[0].name }}*/ < 10000)))) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, IncreasingUntilDecreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(percentile(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), 80)) >= 0) U [0, 10] (d(quartile(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), 50)) < 0)]"));
}


/////////////////////////////////////////////////////////
//
//
// Decreasing and then increasing value
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, DecreasingUntilIncreasingValueReal) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d(2) < 0) U [0, 10] (d(4) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, DecreasingUntilIncreasingValueNumericStateVariable) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d({C}(type = Organ.Heart)) < 0) U [0, 10] (d({C}(type = Organ.Heart)) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, DecreasingUntilIncreasingValueUnaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) <= 0) U [0, 10] (d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) >= 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, DecreasingUntilIncreasingValueBinaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) < 0) U [0, 10] (d(add(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), 2)) >= 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, DecreasingUntilIncreasingValueUnaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(power(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), 1)) < 0) U [0, 10] (d(power(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), 1)) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, DecreasingUntilIncreasingValueBinaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(covar(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), /*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) < 0) U [0, 10] (d(covar(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), /*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, DecreasingUntilIncreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(percentile(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), 80)) < 0) U [0, 10] (d(quartile(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), 50)) >= 0)]"));
}


/////////////////////////////////////////////////////////
//
//
// Oscillations
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, OscillationValueNumericStateVariable) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d({A}) >= 0) ^ F [0, 10] ( (d({A}) <= 0) ^ F [0, 10] (d({A}) >= 0) ) )]"));
}

TEST_F(SpatialEntitiesTraceTest, OscillationsValueUnaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(abs(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) >= 0) ^ F [0, 10] ( (d(abs(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) <= 0) ^ F [0, 10] (d(abs(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)))) >= 0) ) )]"));
}

TEST_F(SpatialEntitiesTraceTest, OscillationsValueBinaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(add(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), 2)) >= 0) ^ F [0, 10] ( (d(add(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), 2)) <= 0) ^ F [0, 10] (d(add(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)), 2)) >= 0) ) )]"));
}

TEST_F(SpatialEntitiesTraceTest, OscillationsValueUnaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) >= 0) ^ F [0, 10] ( (d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) <= 0) ^ F [0, 10] (d(count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) >= 0) ) )]"));
}

TEST_F(SpatialEntitiesTraceTest, OscillationsValueBinaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(covar(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), /*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) >= 0) ^ F [0, 10] ( (d(covar(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), /*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) <= 0) ^ F [0, 10] (d(covar(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), /*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s))) >= 0) ) )]"));
}

TEST_F(SpatialEntitiesTraceTest, OscillationsValueBinaryStatisticalQuantileNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(quartile(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), 50)) >= 0) ^ F [0, 10] ( (d(quartile(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), 50)) <= 0) ^ F [0, 10] (d(quartile(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s), 50)) >= 0) ) )]"));
}


/////////////////////////////////////////////////////////
//
//
// Enclosing composed statements differently with parentheses
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, EnclosingWithParenthesesDifferently1) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [((avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) > 10)) ^ (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) > 100)]"));
}

TEST_F(SpatialEntitiesTraceTest, EnclosingWithParenthesesDifferently2) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(avg(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) > 10) ^ ((count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) > 100))]"));
}


/////////////////////////////////////////////////////////
//
//
// Time interval exceeds trace time at start or end
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TimeIntervalExceedsTraceEndTime) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 1000] (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) > 10)]"));
}

TEST_F(SpatialEntitiesTraceTest, TimeIntervalExceedsTraceStartTime) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [5, 10] (count(/*{{ spatial_measures[0].name }}*/(/*{{ spatial_entities[0].name }}*/s)) > 10)]"));
}


/////////////////////////////////////////////////////////
//
//
// Different constraints combinations
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, ConstraintsCombinationUnary) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 5] (count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ > 5))) > 10)]"));
}

TEST_F(SpatialEntitiesTraceTest, ConstraintsCombinationBinary) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 5] (count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, /*{{ spatial_measures[0].name }}*/ > 5 ^ /*{{ spatial_measures[0].name }}*/ > 1000))) > 10)]"));
}

TEST_F(SpatialEntitiesTraceTest, ConstraintsCombinationNary) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 5] (count(/*{{ spatial_measures[0].name }}*/(filter(/*{{ spatial_entities[0].name }}*/s, (/*{{ spatial_measures[0].name }}*/ > 5) ^ ((/*{{ spatial_measures[0].name }}*/ > 1000) V (/*{{ spatial_measures[0].name }}*/ > 100 V /*{{ spatial_measures[0].name }}*/ < 210))))) > 10)]"));
}


#endif
