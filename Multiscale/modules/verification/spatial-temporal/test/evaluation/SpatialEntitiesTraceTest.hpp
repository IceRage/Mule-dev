#ifndef SPATIALENTITIESTRACETEST_HPP
#define SPATIALENTITIESTRACETEST_HPP

/******************************************************************************
 *
 * WARNING! AUTO-GENERATED FILE.
 *
 * PLEASE DO NOT UPDATE THIS FILE MANUALLY. 
 * USE THE PYTHON GENERATOR SCRIPTS FOR ANY MODIFICATIONS.
 *
 *****************************************************************************/

#include "TraceEvaluationTest.hpp"

#include "multiscale/verification/spatial-temporal/model/Cluster.hpp"
#include "multiscale/verification/spatial-temporal/model/Region.hpp"
 
using namespace multiscale;
using namespace multiscaletest;


namespace multiscaletest {

    //! Class for testing evaluation of spatial entities-only traces
    class SpatialEntitiesTraceTest : public TraceEvaluationTest {

        protected:
            
            double clustersClusterednessMinValue;  /*!< The minimum clusteredness value for the cluster spatial entity type */
            double clustersClusterednessMaxValue;  /*!< The maximum clusteredness value for the cluster spatial entity type */
            
        private:

           //! Initialise the trace
           virtual void InitialiseTrace() override;

    };

    void SpatialEntitiesTraceTest::InitialiseTrace() {
        // Initialise protected class fields
        nrOfTimePoints = 12;
        
        clustersClusterednessMinValue = 1;
        
        // Initialise timepoints
        trace.clear();

        std::vector<TimePoint> timePoints;

        // Add timepoints to the trace
        for (std::size_t i = 0; i < nrOfTimePoints; i++) {
            timePoints.push_back(TimePoint(i));
        }

        // Add spatial entities to each timepoint
        for (std::size_t i = 0; i < nrOfTimePoints; i++) {

            // Add clusters to the timepoint
            for (std::size_t j = ((((i + 1) % 4) == 0) ? (i - 1) : 0); j <= i; j++) {
                std::shared_ptr<SpatialEntity> cluster = std::make_shared<Cluster>();

                clustersClusterednessMaxValue = std::max(clustersClusterednessMaxValue, static_cast<double>((j * 2.4) + clustersClusterednessMinValue));
                
                cluster->setSpatialMeasureValue(SpatialMeasureType::Clusteredness, static_cast<double>((j * 2.4) + clustersClusterednessMinValue));
                cluster->setSpatialMeasureValue(SpatialMeasureType::Density, static_cast<double>(1E+37 - 0) / 2);
                cluster->setSpatialMeasureValue(SpatialMeasureType::Area, static_cast<double>(1E+37 - 0) / 2);
                cluster->setSpatialMeasureValue(SpatialMeasureType::Perimeter, static_cast<double>(1E+37 - 0) / 2);
                cluster->setSpatialMeasureValue(SpatialMeasureType::DistanceFromOrigin, static_cast<double>(1E+37 - 0) / 2);
                cluster->setSpatialMeasureValue(SpatialMeasureType::Angle, static_cast<double>(360 - 0) / 2);
                cluster->setSpatialMeasureValue(SpatialMeasureType::TriangleMeasure, static_cast<double>(1 - 0) / 2);
                cluster->setSpatialMeasureValue(SpatialMeasureType::RectangleMeasure, static_cast<double>(1 - 0) / 2);
                cluster->setSpatialMeasureValue(SpatialMeasureType::CircleMeasure, static_cast<double>(1 - 0) / 2);
                cluster->setSpatialMeasureValue(SpatialMeasureType::CentroidX, static_cast<double>(1E+37 - 0) / 2);
                cluster->setSpatialMeasureValue(SpatialMeasureType::CentroidY, static_cast<double>(1E+37 - 0) / 2);
                cluster->setSemanticType(0);

                timePoints[i].addSpatialEntity(cluster, SubsetSpecificType::Clusters);
            }
            
            // Add regions to the timepoint
            for (std::size_t k = 0; k <= i; k++) {
                    std::shared_ptr<SpatialEntity> region = std::make_shared<Region>();

                    region->setSpatialMeasureValue(SpatialMeasureType::Clusteredness, static_cast<double>((k * 0.3) + 0.7));
                    region->setSpatialMeasureValue(SpatialMeasureType::Density, static_cast<double>(1E+37 - 0) / 3);
                    region->setSpatialMeasureValue(SpatialMeasureType::Area, static_cast<double>(1E+37 - 0) / 3);
                    region->setSpatialMeasureValue(SpatialMeasureType::Perimeter, static_cast<double>(1E+37 - 0) / 3);
                    region->setSpatialMeasureValue(SpatialMeasureType::DistanceFromOrigin, static_cast<double>(1E+37 - 0) / 3);
                    region->setSpatialMeasureValue(SpatialMeasureType::Angle, static_cast<double>(360 - 0) / 3);
                    region->setSpatialMeasureValue(SpatialMeasureType::TriangleMeasure, static_cast<double>(1 - 0) / 3);
                    region->setSpatialMeasureValue(SpatialMeasureType::RectangleMeasure, static_cast<double>(1 - 0) / 3);
                    region->setSpatialMeasureValue(SpatialMeasureType::CircleMeasure, static_cast<double>(1 - 0) / 3);
                    region->setSpatialMeasureValue(SpatialMeasureType::CentroidX, static_cast<double>(1E+37 - 0) / 3);
                    region->setSpatialMeasureValue(SpatialMeasureType::CentroidY, static_cast<double>(1E+37 - 0) / 3);
                    region->setSemanticType(0);

                    timePoints[i].addSpatialEntity(region, SubsetSpecificType::Regions);
                }
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
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(clusteredness(filter(clusters, clusteredness < subtract(clusteredness, 0.0001)))) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryNumericMeasureAdd) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= add(" + StringManipulator::toString<double>(aMinValue) + ", 0.0111)]"));
}

TEST_F(SpatialEntitiesTraceTest, BinaryNumericMeasureDiv) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) < div(2, 3)]"));
}

TEST_F(SpatialEntitiesTraceTest, BinaryNumericMeasureLog) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) >= log(4.33333, 9.12312312)]"));
}

TEST_F(SpatialEntitiesTraceTest, BinaryNumericMeasureMod) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= mod(1.00001, 8)]"));
}

TEST_F(SpatialEntitiesTraceTest, BinaryNumericMeasureMultiply) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= multiply(2, 0.50001)]"));
}

TEST_F(SpatialEntitiesTraceTest, BinaryNumericMeasurePower) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= power(2, 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, BinaryNumericMeasureSubtract) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(filter(clusters, clusteredness > 1))) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryNumericNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryNumericNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [median([0, 10] add(count(clusteredness(clusters)), 2)) < 7.0001]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryNumericTemporal
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryNumericTemporal) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [div(count(clusteredness(clusters)), 2) > 0.49]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryStatisticalMeasure) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [covar(clusteredness(clusters), clusteredness(clusters)) >= 0.001]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [covar(clusteredness(clusters), clusteredness(clusters)) >= 0.00034]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalQuantileMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryStatisticalQuantileMeasurePercentile) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [X[4] percentile(clusteredness(clusters), 4.3) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, BinaryStatisticalQuantileMeasureQuartile) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [X[4] quartile(clusteredness(clusters), 4.3) <= 0.5]"), NumericException);
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalQuantileNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryStatisticalQuantileNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [percentile(clusteredness(clusters), 4.3) > 0.9999]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalQuantileSpatial
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryStatisticalQuantileSpatial) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [min([0, 10] percentile(clusteredness(clusters), 4.3)) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalSpatial
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, BinaryStatisticalSpatial) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [min([0, 4] covar(clusteredness(clusters), clusteredness(clusters))) > 0.000001]"));
}


/////////////////////////////////////////////////////////
//
//
// ChangeMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, ChangeMeasureDifference) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [d(max(clusteredness(clusters))) <= 2.41]"));
}

TEST_F(SpatialEntitiesTraceTest, ChangeMeasureRatio) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [r(max(clusteredness(clusters))) < 3.4]"));
}


/////////////////////////////////////////////////////////
//
//
// ChangeTemporalNumericCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, ChangeTemporalNumericCollection) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [max(r([0, 11] min(clusteredness(clusters)))) = 25]"));
}


/////////////////////////////////////////////////////////
//
//
// ChangeTemporalNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, ChangeTemporalNumericMeasure) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [r(max(clusteredness(clusters))) < 3.41]"));
}


/////////////////////////////////////////////////////////
//
//
// Comparator
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, ComparatorGreaterThan) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(clusters)) > 1]"));
}

TEST_F(SpatialEntitiesTraceTest, ComparatorLessThan) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(clusters)) < 1]"));
}

TEST_F(SpatialEntitiesTraceTest, ComparatorGreaterThanOrEqual) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(clusters)) >= 1]"));
}

TEST_F(SpatialEntitiesTraceTest, ComparatorLessThanOrEqual) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(clusters)) <= 1]"));
}

TEST_F(SpatialEntitiesTraceTest, ComparatorEqual) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(clusters)) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// CompoundConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, CompoundConstraint) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 1.0001) ^ (clusteredness = 0.1)))) <= 1]"));
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 1.0001) V (clusteredness = 0.3)))) = 0]"));
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 1.0001) => (clusteredness = 0.1)))) > 1]"));
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 1.0001) <=> (clusteredness = 0.1)))) < 1]"));
}

TEST_F(SpatialEntitiesTraceTest, CompoundConstraintMultiple) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 1.0001) ^ (clusteredness = 0.1) ^ (~ clusteredness > 1)))) < 1]"));
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 1.0001) V (clusteredness = 0.1) V (~ clusteredness > 1)))) <= 1]"));
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 1.0001) => (clusteredness = 0.1) => (~ clusteredness > 1)))) = 1]"));
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 1.0001) <=> (clusteredness = 0.1) <=> (~ clusteredness > 1)))) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// CompoundLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, CompoundLogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(avg(clusteredness(clusters)) >= 1) ^ (count(clusteredness(clusters)) >= 1)]"));
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(avg(clusteredness(clusters)) >= 1) V (count(clusteredness(clusters)) < 1)]"));
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [(avg(clusteredness(clusters)) >= 1) => (count(clusteredness(clusters)) > 1)]"));
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(avg(clusteredness(clusters)) >= 1) <=> (count(clusteredness(clusters)) <= 1)]"));
}

TEST_F(SpatialEntitiesTraceTest, CompoundLogicPropertyMultiple) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [(avg(clusteredness(clusters)) >= 1) ^ (count(clusteredness(clusters)) < 1) ^ 3 = 3]"));
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(avg(clusteredness(clusters)) >= 1) V (count(clusteredness(clusters)) < 1) V 3 = 3]"));
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(avg(clusteredness(clusters)) >= 1) => (count(clusteredness(clusters)) < 1) => 3 = 3]"));
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [(avg(clusteredness(clusters)) >= 1) <=> (count(clusteredness(clusters)) < 1) <=> 3 = 3]"));
}


/////////////////////////////////////////////////////////
//
//
// ConstraintEnclosedByParentheses
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, ConstraintEnclosedByParentheses) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness < 1.00001)))) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, ConstraintEnclosedByParenthesesDoubled) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, ((clusteredness < 1.00001))))) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, ConstraintEnclosedByParenthesesQuadrupled) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, ((((clusteredness < 1.00001))))))) >= 1]"));
}


/////////////////////////////////////////////////////////
//
//
// Constraint
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, Constraint) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, clusteredness > 10000 V clusteredness < 1.001))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// FilterNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, FilterNumericMeasure) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(clusteredness(filter(clusters, clusteredness > 0.5 ^ clusteredness < 1.0001))) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// FilterSubset
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, FilterSubset) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(filter(clusters, clusteredness > 1))) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// FutureLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, FutureLogicProperty) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [2, 3] (count(clusteredness(clusters)) >= 4)]"));
}


/////////////////////////////////////////////////////////
//
//
// GlobalLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, GlobalLogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [G [2, 3] (count(clusteredness(clusters)) < 4)]"));
}


/////////////////////////////////////////////////////////
//
//
// HeterogeneousTimeseriesComponent
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, HeterogeneousTimeseriesComponentPeak) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [max(enteringValue(peak, [0, 11] max(clusteredness(clusters)))) > 27.39]"));
}

TEST_F(SpatialEntitiesTraceTest, HeterogeneousTimeseriesComponentValley) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [median(enteringValue(valley, [0, 11] count(clusteredness(clusters)))) < 2]"));
}


/////////////////////////////////////////////////////////
//
//
// HomogeneousHomogeneousTimeseriesMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, HomogeneousHomogeneousTimeseriesMeasure) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [max(value(plateau, [0, 11] count(clusteredness(clusters)))) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// HomogeneousTimeseriesComponent
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, HomogeneousTimeseriesComponentAscent) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [min(value(ascent, [0, 11] count(clusteredness(clusters)))) > 1]"));
}

TEST_F(SpatialEntitiesTraceTest, HomogeneousTimeseriesComponentDescent) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [avg(duration(descent, [0, 11] count(clusteredness(clusters)))) = 2]"));
}

TEST_F(SpatialEntitiesTraceTest, HomogeneousTimeseriesComponentPlateu) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [mode(value(plateau, [0, 11] count(clusteredness(clusters)))) > 0]"));
}

TEST_F(SpatialEntitiesTraceTest, HomogeneousTimeseriesComponentUniformAscent) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [max(value(uniformAscent, [0, 11] count(clusteredness(clusters)))) = 11]"));
}

TEST_F(SpatialEntitiesTraceTest, HomogeneousTimeseriesComponentUniformDescent) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [avg(value(uniformDescent, [0, 11] avg(clusteredness(clusters)))) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// HomogeneousTimeseriesMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, HomogeneousTimeseriesMeasureDuration) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [max(duration(ascent, [0, 11] count(clusteredness(clusters)))) > 4]"));
}

TEST_F(SpatialEntitiesTraceTest, HomogeneousTimeseriesMeasureValue) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [min(value(descent, [0, 11] count(clusteredness(clusters)))) = 2]"));
}


/////////////////////////////////////////////////////////
//
//
// LogicPropertyEnclosedByParentheses
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, LogicPropertyEnclosedByParentheses) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(count(clusteredness(clusters)) >= 0.99)]"));
}

TEST_F(SpatialEntitiesTraceTest, LogicPropertyEnclosedByParenthesesDoubled) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [((count(clusteredness(clusters)) >= 0.99))]"));
}

TEST_F(SpatialEntitiesTraceTest, LogicPropertyEnclosedByParenthesesQuadrupled) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [((((count(clusteredness(clusters)) >= 0.99))))]"));
}


/////////////////////////////////////////////////////////
//
//
// LogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, LogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) >= 0.99999]"));
}


/////////////////////////////////////////////////////////
//
//
// MultipleLogicProperties
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, MultipleLogicProperties1) {
    EXPECT_FALSE(RunEvaluationTest("P > 0.1234 [( d(4) >=  count(clusteredness(clusters)) ) ^ ( covar(clusteredness(clusters), clusteredness(clusters)) >= {A} ) V ( {B} = sqrt(add({B}, {C})) )]"));
}

TEST_F(SpatialEntitiesTraceTest, MultipleLogicProperties2) {
    EXPECT_TRUE(
        RunEvaluationTest(""
            "P <= 0.85934 ["
            "   (~ "
            "       F [2, 3] ( "
            "           max("
            "               clusteredness("
            "                   filter("
            "                       clusters, "
            "                       clusteredness <= 10"
            "                   )"
            "               )"
            "           ) >= 2 "
            "       ) "
            "   ) => ( "
            "       G [4, 5] ("
            "           X ("
            "               X [5] ( "
            "                   percentile("
            "                       clusteredness("
            "                           clusters"
            "                       ), "
            "                       0.4"
            "                   ) = 0.7 "
            "               )"
            "           )"
            "       ) "
            "   ) <=> ( "
            "       count("
            "           clusteredness("
            "               filter("
            "                   clusters, "
            "                   (clusteredness <= 2) ^ "
            "                   (clusteredness >= 6) V "
            "                   (clusteredness >= 30) => "
            "                   (clusteredness <= 2) <=> "
            "                   (clusteredness >= 4)"
            "               ) "
            "           )"
            "       ) >= 1"
            "   ) U [3, 7] ( "
            "       kurt("
            "           clusteredness("
            "               clusters"
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
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [X [3] (max(clusteredness(clusters)) >= 8.1999)]"));
}


/////////////////////////////////////////////////////////
//
//
// NextLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NextLogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [X (max(clusteredness(clusters)) <= 3.5)]"));
}


/////////////////////////////////////////////////////////
//
//
// NotConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NotConstraint) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, ~ (clusteredness <= 1)))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// NotLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NotLogicProperty) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [~(count(clusteredness(clusters)) >= 1)]"));
}


/////////////////////////////////////////////////////////
//
//
// NumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NumericMeasure) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [avg([0, 3] count(clusteredness(clusters))) = 2]"));
}


/////////////////////////////////////////////////////////
//
//
// NumericMeasureCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NumericMeasureCollection) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [min(clusteredness(clusters)) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// NumericSpatialMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, NumericSpatialMeasure) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [geomean(clusteredness(clusters)) = 1]"));
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
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A}(type = 0) <= {C}(type = 1)]"));
}

TEST_F(SpatialEntitiesTraceTest, NumericStateVariableOneNumericStateVariable) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{C}(type = 1) = 12]"));
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
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A}(type = 1) <= {B}]"));
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
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [X min([0, 5] count(clusteredness(clusters))) <= 1]"));
}


/////////////////////////////////////////////////////////
//
//
// ProbabilisticLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, ProbabilisticLogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.4 [count(clusteredness(clusters)) >= 1]"));
}


/////////////////////////////////////////////////////////
//
//
// SimilarityMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SimilarityMeasureAntiSimilar) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [antiSimilar([0, 11] count(clusteredness(clusters)), [0, 11] subtract(0, count(clusteredness(clusters))), 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, SimilarityMeasureSimilar) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [similar(r([0, 11] count(clusteredness(clusters))), r([0, 11] multiply(avg(clusteredness(clusters)), 2)), 0)]"));
}


/////////////////////////////////////////////////////////
//
//
// SimilarityTemporalNumericCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SimilarityTemporalNumericCollection) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [similar([0, 11] count(clusteredness(clusters)), [0, 11] 6, 6)]"));
}


/////////////////////////////////////////////////////////
//
//
// SpatialMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SpatialMeasureClusteredness) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, clusteredness > 0))) >= 1]"));
}

TEST_F(SpatialEntitiesTraceTest, SpatialMeasureDensity) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, density > 0))) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, SpatialMeasureArea) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, area > 0))) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, SpatialMeasurePerimeter) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, perimeter > 0))) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, SpatialMeasureDistanceFromOrigin) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, distanceFromOrigin > 0))) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, SpatialMeasureAngle) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, angle > 0))) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, SpatialMeasureTriangleMeasure) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, triangleMeasure > 0))) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, SpatialMeasureRectangleMeasure) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, rectangleMeasure > 0))) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, SpatialMeasureCircleMeasure) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, circleMeasure > 0))) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, SpatialMeasureCentroidX) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, centroidX > 0))) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, SpatialMeasureCentroidY) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, centroidY > 0))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// SpatialMeasureCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SpatialMeasureCollection) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] avg(clusteredness(clusters)) > 26.21]"));
}


/////////////////////////////////////////////////////////
//
//
// Subset
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, Subset) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// SubsetOperation
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SubsetOperationDifference) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(clusteredness(difference(clusters, filter(clusters, clusteredness < 1)))) >= 1]"));
}

TEST_F(SpatialEntitiesTraceTest, SubsetOperationDifferenceRegion) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(clusteredness(difference(regions, clusters))) > 12]"));
}

TEST_F(SpatialEntitiesTraceTest, SubsetOperationIntersection) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(clusteredness(intersection(clusters, filter(clusters, clusteredness <= 1)))) >= 2]"));
}

TEST_F(SpatialEntitiesTraceTest, SubsetOperationIntersectionRegion) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(clusteredness(intersection(clusters, filter(regions, clusteredness > 0.5)))) > 0]"));
}

TEST_F(SpatialEntitiesTraceTest, SubsetOperationUnion) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(clusteredness(union(filter(clusters, clusteredness < 20), filter(clusters, clusteredness >= 20)))) > 0]"));
}

TEST_F(SpatialEntitiesTraceTest, SubsetOperationUnionRegion) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(clusteredness(union(clusters, regions))) >= 2]"));
}


/////////////////////////////////////////////////////////
//
//
// SubsetSpecific
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SubsetSpecificClusters) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) > 0]"));
}

TEST_F(SpatialEntitiesTraceTest, SubsetSpecificRegions) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(clusteredness(regions)) < 1]"));
}



/////////////////////////////////////////////////////////
//
//
// SubsetSubsetOperation
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, SubsetSubsetOperation) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(clusteredness(union(clusters, clusters))) >= 4.3]"));
}


/////////////////////////////////////////////////////////
//
//
// TemporalNumericCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TemporalNumericCollection) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [min([0, 11] max(clusteredness(clusters))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// TemporalNumericComparison
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TemporalNumericComparison) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [max(clusteredness(clusters)) >= 1.0001]"));
}


/////////////////////////////////////////////////////////
//
//
// TemporalNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TemporalNumericMeasure) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(count(clusteredness(clusters)) = 1)]"));
}


/////////////////////////////////////////////////////////
//
//
// TemporalNumericMeasureCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TemporalNumericMeasureCollection) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [min([0, 11] count(clusteredness(clusters))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// TimeseriesMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TimeseriesMeasureEnteringTime) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [min(enteringTime(descent, [0, 11] count(clusteredness(clusters)))) < 2]"));
}

TEST_F(SpatialEntitiesTraceTest, TimeseriesMeasureEnteringValue) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [min(enteringValue(uniformDescent, [0, 11] max(clusteredness(clusters)))) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// TimeseriesMeasureHeterogeneous
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TimeseriesMeasureHeterogeneous) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [median(enteringTime(peak, [0, 11] count(clusteredness(clusters)))) = 6]"));
}


/////////////////////////////////////////////////////////
//
//
// TimeseriesMeasureHomogeneous
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TimeseriesMeasureHomogeneous) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [median(enteringValue(uniformAscent, [0, 11] count(clusteredness(clusters)))) < 5]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericFilter
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryNumericFilter) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(clusteredness(filter(clusters, clusteredness <= round(clusteredness)))) > 1]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryNumericMeasureAbs) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= abs(-1)]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryNumericMeasureCeil) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) = ceil(0.3)]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryNumericMeasureFloor) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) = floor(0.49)]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryNumericMeasureRound) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) = round(0.50001)]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryNumericMeasureSign) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= sign(21.1)]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryNumericMeasureSqrt) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) >= sqrt(0.9)]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryNumericMeasureTrunc) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= trunc(1.1)]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryNumericNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [max([0, 11] count(clusteredness(clusters))) < 11]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericTemporal
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryNumericTemporal) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) >= 0.9999]"));
}


/////////////////////////////////////////////////////////
//
//
// UnarySpatialConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnarySpatialConstraint) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, clusteredness <= 0.4))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryStatisticalMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureAvg) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [avg(clusteredness(clusters)) < 1.00001]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureCount) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) > 1]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureGeomean) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [geomean(clusteredness(clusters)) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureHarmean) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [harmean(clusteredness(clusters)) > 1.000001]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureKurt) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [kurt(clusteredness(clusters)) > 0]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureMax) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [max(clusteredness(clusters)) = 0]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureMedian) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [median(clusteredness(clusters)) >= 1]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureMin) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [min(clusteredness(clusters)) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureMode) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [mode(clusteredness(clusters)) = 0]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureProduct) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [product(clusteredness(clusters)) < 1]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureSkew) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [skew(clusteredness(clusters)) = 0]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureStdev) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [stdev(clusteredness(clusters)) = 1]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureSum) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [sum(clusteredness(clusters)) = 0]"));
}

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalMeasureVar) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [var(clusteredness(clusters)) < 0.0001]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryStatisticalNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryStatisticalSpatial
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryStatisticalSpatial) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [max([0, 5] count(clusteredness(clusters))) > 6]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryTypeConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UnaryTypeConstraint) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(clusteredness(filter(clusters, type = 1))) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// UntilLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, UntilLogicProperty) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [(d(count(clusteredness(clusters))) >= 0) U [0, 3] {A} = 4]"));
}

TEST_F(SpatialEntitiesTraceTest, UntilLogicPropertyMultiple) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(d(count(clusteredness(clusters))) >= 0) U [0, 3] (count(clusteredness(clusters)) > 0) <=> (count(clusteredness(clusters)) = 3)]"));
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
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [1, 10] (d(round(count(clusteredness(clusters)))) = 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalConstantValueBinaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(add(count(clusteredness(clusters)), 2)) = 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalConstantValueUnaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(count(clusteredness(clusters))) = 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalConstantValueBinaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(covar(clusteredness(filter(clusters, clusteredness < 1)), clusteredness(clusters))) = 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalConstantValueBinaryStatisticalQuantileNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(quartile(clusteredness(clusters), 50)) = 0)]"));
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
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(round(count(clusteredness(clusters)))) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, FutureIncreasingValueBinaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(add(count(clusteredness(clusters)), 1)) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, FutureIncreasingValueUnaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(count(clusteredness(clusters))) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, FutureIncreasingValueBinaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(covar(clusteredness(clusters), clusteredness(clusters))) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, FutureIncreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(quartile(clusteredness(clusters), 50)) > 0)]"));
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
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(count(clusteredness(clusters))) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalDecreasingValueBinaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(covar(clusteredness(clusters), clusteredness(clusters))) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, GlobalDecreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(quartile(clusteredness(clusters), 50)) < 0)]"));
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
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d({A}) > 0) U [0, 10] (d(count(clusteredness(clusters))) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, IncreasingUntilDecreasingValueUnaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(count(clusteredness(clusters))) >= 0) U [0, 10] (d(count(clusteredness(clusters))) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, IncreasingUntilDecreasingValueBinaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(count(clusteredness(clusters))) > 0) U [0, 10] (d(add(count(clusteredness(clusters)), 2)) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, IncreasingUntilDecreasingValueUnaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(power(count(clusteredness(clusters)), 1)) > 0) U [0, 10] (d(power(count(clusteredness(clusters)), 1)) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, IncreasingUntilDecreasingValueBinaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d(covar(clusteredness(clusters), clusteredness(clusters))) >= 0) U [0, 10] (d(avg(clusteredness(filter(clusters, clusteredness > 5 V clusteredness < 10000)))) < 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, IncreasingUntilDecreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(percentile(clusteredness(clusters), 80)) >= 0) U [0, 10] (d(quartile(clusteredness(clusters), 50)) < 0)]"));
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
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d({C}(type = 1)) < 0) U [0, 10] (d({C}(type = 1)) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, DecreasingUntilIncreasingValueUnaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(count(clusteredness(clusters))) <= 0) U [0, 10] (d(count(clusteredness(clusters))) >= 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, DecreasingUntilIncreasingValueBinaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(count(clusteredness(clusters))) < 0) U [0, 10] (d(add(count(clusteredness(clusters)), 2)) >= 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, DecreasingUntilIncreasingValueUnaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(power(count(clusteredness(clusters)), 1)) < 0) U [0, 10] (d(power(count(clusteredness(clusters)), 1)) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, DecreasingUntilIncreasingValueBinaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(covar(clusteredness(clusters), clusteredness(clusters))) < 0) U [0, 10] (d(covar(clusteredness(clusters), clusteredness(clusters))) > 0)]"));
}

TEST_F(SpatialEntitiesTraceTest, DecreasingUntilIncreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(percentile(clusteredness(clusters), 80)) < 0) U [0, 10] (d(quartile(clusteredness(clusters), 50)) >= 0)]"));
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
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(abs(count(clusteredness(clusters)))) >= 0) ^ F [0, 10] ( (d(abs(count(clusteredness(clusters)))) <= 0) ^ F [0, 10] (d(abs(count(clusteredness(clusters)))) >= 0) ) )]"));
}

TEST_F(SpatialEntitiesTraceTest, OscillationsValueBinaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(add(count(clusteredness(clusters)), 2)) >= 0) ^ F [0, 10] ( (d(add(count(clusteredness(clusters)), 2)) <= 0) ^ F [0, 10] (d(add(count(clusteredness(clusters)), 2)) >= 0) ) )]"));
}

TEST_F(SpatialEntitiesTraceTest, OscillationsValueUnaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(count(clusteredness(clusters))) >= 0) ^ F [0, 10] ( (d(count(clusteredness(clusters))) <= 0) ^ F [0, 10] (d(count(clusteredness(clusters))) >= 0) ) )]"));
}

TEST_F(SpatialEntitiesTraceTest, OscillationsValueBinaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(covar(clusteredness(clusters), clusteredness(clusters))) >= 0) ^ F [0, 10] ( (d(covar(clusteredness(clusters), clusteredness(clusters))) <= 0) ^ F [0, 10] (d(covar(clusteredness(clusters), clusteredness(clusters))) >= 0) ) )]"));
}

TEST_F(SpatialEntitiesTraceTest, OscillationsValueBinaryStatisticalQuantileNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(quartile(clusteredness(clusters), 50)) >= 0) ^ F [0, 10] ( (d(quartile(clusteredness(clusters), 50)) <= 0) ^ F [0, 10] (d(quartile(clusteredness(clusters), 50)) >= 0) ) )]"));
}


/////////////////////////////////////////////////////////
//
//
// Enclosing composed statements differently with parentheses
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, EnclosingWithParenthesesDifferently1) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [((avg(clusteredness(clusters)) > 10)) ^ (count(clusteredness(clusters)) > 100)]"));
}

TEST_F(SpatialEntitiesTraceTest, EnclosingWithParenthesesDifferently2) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(avg(clusteredness(clusters)) > 10) ^ ((count(clusteredness(clusters)) > 100))]"));
}


/////////////////////////////////////////////////////////
//
//
// Time interval exceeds trace time at start or end
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, TimeIntervalExceedsTraceEndTime) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 1000] (count(clusteredness(clusters)) > 10)]"));
}

TEST_F(SpatialEntitiesTraceTest, TimeIntervalExceedsTraceStartTime) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [5, 10] (count(clusteredness(clusters)) > 10)]"));
}


/////////////////////////////////////////////////////////
//
//
// Different constraints combinations
//
//
/////////////////////////////////////////////////////////

TEST_F(SpatialEntitiesTraceTest, ConstraintsCombinationUnary) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 5] (count(clusteredness(filter(clusters, clusteredness > 5))) > 10)]"));
}

TEST_F(SpatialEntitiesTraceTest, ConstraintsCombinationBinary) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 5] (count(clusteredness(filter(clusters, clusteredness > 5 ^ clusteredness > 1000))) > 10)]"));
}

TEST_F(SpatialEntitiesTraceTest, ConstraintsCombinationNary) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 5] (count(clusteredness(filter(clusters, (clusteredness > 5) ^ ((clusteredness > 1000) V (clusteredness > 100 V clusteredness < 210))))) > 10)]"));
}


#endif