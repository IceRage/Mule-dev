#ifndef NUMERICSTATEVARIABLETRACETEST_HPP
#define NUMERICSTATEVARIABLETRACETEST_HPP

/******************************************************************************
 *
 * WARNING! AUTO-GENERATED FILE.
 *
 * PLEASE DO NOT UPDATE THIS FILE MANUALLY. 
 * USE THE PYTHON GENERATOR SCRIPTS FOR ANY MODIFICATIONS.
 *
 *****************************************************************************/

#include "TraceEvaluationTest.hpp"

using namespace multiscale;
using namespace multiscaletest;


namespace multiscaletest {

    //! Class for testing evaluation of numeric state variable-only traces
    class NumericStateVariableTraceTest : public TraceEvaluationTest {

        protected:
            
            double clustersClusterednessMinValue;  /*!< The minimum clusteredness value for the cluster spatial entity type */
            
        private:

           //! Initialise the trace
           virtual void InitialiseTrace() override;

    };

    void NumericStateVariableTraceTest::InitialiseTrace() {
        // Initialise private class fields
        nrOfTimePoints = 12;
        
        bConstantValue = 3;
        aMinValue = 1;
        
        clustersClusterednessMinValue = 1;
        
        // Initialise timepoints
        trace.clear();

        std::vector<TimePoint> timePoints;

        // Add timepoints containing the numeric state variable "B" to the collection of timepoints
        for (std::size_t i = 0; i < nrOfTimePoints; i++) {
            timePoints.push_back(TimePoint(i));
            timePoints[i].addNumericStateVariable("B", bConstantValue);
        }

        // Add a second numeric state variable to the collection of timepoints
        for (std::size_t i = 0; i < nrOfTimePoints; i++) {
            if (i % 4 == 0) {
                timePoints[i].addNumericStateVariable("A", aMinValue);
            } else {
                timePoints[i].addNumericStateVariable("A", aMinValue + i);
            }
        }

        // Initialise the aMaxValue field
        for (std::size_t i = 0; i < nrOfTimePoints; i++) {
            aMaxValue = std::max(aMaxValue, timePoints[i].getNumericStateVariable("A"));
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

TEST_F(NumericStateVariableTraceTest, BinaryNumericFilter) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(clusteredness(filter(clusters, clusteredness < subtract(clusteredness, 0.0001)))) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, BinaryNumericMeasureAdd) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [{A} <= add(" + StringManipulator::toString<double>(aMaxValue) + ", 0.0111)]"));
}

TEST_F(NumericStateVariableTraceTest, BinaryNumericMeasureDiv) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A} <= div(2, 3)]"));
}

TEST_F(NumericStateVariableTraceTest, BinaryNumericMeasureLog) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A} <= log(4.33333, 9.12312312)]"));
}

TEST_F(NumericStateVariableTraceTest, BinaryNumericMeasureMod) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [{A} <= mod(1.001, 8)]"));
}

TEST_F(NumericStateVariableTraceTest, BinaryNumericMeasureMultiply) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [{A} < multiply(2, 0.51)]"));
}

TEST_F(NumericStateVariableTraceTest, BinaryNumericMeasurePower) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [{A} <= power(2, 0)]"));
}

TEST_F(NumericStateVariableTraceTest, BinaryNumericMeasureSubtract) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A} <= subtract(3, 2.0001)]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryNumericNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, BinaryNumericNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [avg([0, 3] multiply({A}, 2)) <= add(9, 1)]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryNumericTemporal
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, BinaryNumericTemporal) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [subtract({A}, 1) >= add(-0.9999, 1)]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, BinaryStatisticalMeasure) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [covar(clusteredness(clusters), clusteredness(clusters)) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, BinaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [covar(clusteredness(clusters), clusteredness(clusters)) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalQuantileMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, BinaryStatisticalQuantileMeasurePercentile) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [percentile(clusteredness(clusters), 4.3) < 1]"));
}

TEST_F(NumericStateVariableTraceTest, BinaryStatisticalQuantileMeasureQuartile) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [quartile(clusteredness(clusters), 4.3) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalQuantileNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, BinaryStatisticalQuantileNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [percentile(clusteredness(clusters), 4.3) <= 1]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalQuantileSpatial
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, BinaryStatisticalQuantileSpatial) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [mode([0, 3] percentile(clusteredness(clusters), 4.3)) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalSpatial
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, BinaryStatisticalSpatial) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [min([0, 7] covar(clusteredness(clusters), clusteredness(clusters))) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// ChangeMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, ChangeMeasureDifference) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [d({A}) >= 1]"));
}

TEST_F(NumericStateVariableTraceTest, ChangeMeasureRatio) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [r({B}) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// ChangeTemporalNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, ChangeTemporalNumericMeasure) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [d({A}) <= 3]"));
}


/////////////////////////////////////////////////////////
//
//
// Comparator
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, ComparatorGreaterThan) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(clusters)) > 0]"));
}

TEST_F(NumericStateVariableTraceTest, ComparatorLessThan) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(clusters)) < {A}]"));
}

TEST_F(NumericStateVariableTraceTest, ComparatorGreaterThanOrEqual) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(clusters)) >= {A}]"));
}

TEST_F(NumericStateVariableTraceTest, ComparatorLessThanOrEqual) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [{A} < 1]"));
}

TEST_F(NumericStateVariableTraceTest, ComparatorEqual) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [{A} = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// CompoundConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, CompoundConstraint) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 1) ^ (clusteredness = 0.1)))) <= 0]"));
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 1) V (clusteredness = 0.1)))) > 0]"));
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 1) => (clusteredness = 0.1)))) < 1]"));
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 1) <=> (clusteredness = 0.1)))) = 0]"));
}

TEST_F(NumericStateVariableTraceTest, CompoundConstraintMultiple) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= {A}) ^ (clusteredness = 0.1) ^ (~ clusteredness >= 4000)))) = 0]"));
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= {A}) V (clusteredness = 0.1) V (~ clusteredness >= 4000)))) <= 0]"));
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= {A}) => (clusteredness = 0.1) => (~ clusteredness >= 4000)))) > 0]"));
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= {A}) <=> (clusteredness = 0.1) <=> (~ clusteredness >= 4000)))) < 1]"));
}


/////////////////////////////////////////////////////////
//
//
// CompoundLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, CompoundLogicProperty) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [({A} > 1) ^ (count(clusteredness(clusters)) >= 1)]"));
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [({A} > 1) V (count(clusteredness(clusters)) > 0)]"));
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [({A} > 1) => (count(clusteredness(clusters)) >= 1)]"));
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [({A} > 1) <=> (count(clusteredness(clusters)) >= 0)]"));
}

TEST_F(NumericStateVariableTraceTest, CompoundLogicPropertyMultiple) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [({A} > 1) ^ (count(clusteredness(clusters)) <= 0) ^ {B} = 3]"));
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [({A} > 1) V (count(clusteredness(clusters)) <= 0) V {B} = 3]"));
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [({A} > 1) => (count(clusteredness(clusters)) <= 0) => {B} = 3]"));
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [({A} > 1) <=> (count(clusteredness(clusters)) <= 0) <=> {B} = 3]"));
}


/////////////////////////////////////////////////////////
//
//
// ConstraintEnclosedByParentheses
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, ConstraintEnclosedByParentheses) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 1)))) <= 0]"));
}

TEST_F(NumericStateVariableTraceTest, ConstraintEnclosedByParenthesesDoubled) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, ((clusteredness <= 1))))) = 0]"));
}

TEST_F(NumericStateVariableTraceTest, ConstraintEnclosedByParenthesesQuadrupled) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, ((((clusteredness <= 1))))))) < 1]"));
}


/////////////////////////////////////////////////////////
//
//
// Constraint
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, Constraint) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, clusteredness > 10000 V clusteredness <= 1))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// FilterNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, FilterNumericMeasure) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(clusteredness(filter(clusters, clusteredness < subtract(clusteredness, 2.5) ^ clusteredness > clusteredness))) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// FilterSubset
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, FilterSubset) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(filter(clusters, clusteredness >= 0))) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// FutureLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, FutureLogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [F [2, 3] ({A} >= 4)]"));
}


/////////////////////////////////////////////////////////
//
//
// GlobalLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, GlobalLogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [G [2, 3] ({A} >= 3)]"));
}


/////////////////////////////////////////////////////////
//
//
// LogicPropertyEnclosedByParentheses
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, LogicPropertyEnclosedByParentheses) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [({A} >= 1)]"));
}

TEST_F(NumericStateVariableTraceTest, LogicPropertyEnclosedByParenthesesDoubled) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(({A} >= 1))]"));
}

TEST_F(NumericStateVariableTraceTest, LogicPropertyEnclosedByParenthesesQuadrupled) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [(((({A} >= 1))))]"));
}


/////////////////////////////////////////////////////////
//
//
// LogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, LogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [{A} > 0.9999]"));
}


/////////////////////////////////////////////////////////
//
//
// MultipleLogicProperties
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, MultipleLogicProperties1) {
    EXPECT_FALSE(RunEvaluationTest("P > 0.1234 [( d(4) >=  count(clusteredness(clusters)) ) ^ ( covar(clusteredness(clusters), clusteredness(clusters)) >= {A} ) V ( {B} = sqrt(add({B}, {C})) )]"));
}

TEST_F(NumericStateVariableTraceTest, MultipleLogicProperties2) {
    EXPECT_FALSE(
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

TEST_F(NumericStateVariableTraceTest, NextKLogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [X [3] ({A} >= 4)]"));
}


/////////////////////////////////////////////////////////
//
//
// NextLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, NextLogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [X ({A} < 2.0005)]"));
}


/////////////////////////////////////////////////////////
//
//
// NotConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, NotConstraint) {
    EXPECT_TRUE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, ~ (clusteredness <= 1)))) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// NotLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, NotLogicProperty) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [~({A} >= 1.0001)]"));
}


/////////////////////////////////////////////////////////
//
//
// NumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, NumericMeasure) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [min([0, 5] count(clusteredness(clusters))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// NumericMeasureCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, NumericMeasureCollection) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [product(clusteredness(clusters)) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// NumericSpatialMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, NumericSpatialMeasure) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [geomean(clusteredness(clusters)) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// NumericStateVariable
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, NumericStateVariable1) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A} <= 0.999]"));
}

TEST_F(NumericStateVariableTraceTest, NumericStateVariable2) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{a2#0f-} <= 3]"));
}

TEST_F(NumericStateVariableTraceTest, NumericStateVariable3) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{`1234567890-=~!@#$%^&*()_+qwertyuiop[]asdfghjkl;'\\<zxcvbnm,./QWERTYUIOPASDFGHJKL:\"|>ZXCVBNM<>?} <= 3]"));
}


/////////////////////////////////////////////////////////
//
//
// NumericStatisticalMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, NumericStatisticalMeasure) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [X min([1, 5] count(clusteredness(clusters))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// ProbabilisticLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, ProbabilisticLogicProperty) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// SpatialMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, SpatialMeasureClusteredness) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, clusteredness <= 2))) > 0]"));
}

TEST_F(NumericStateVariableTraceTest, SpatialMeasureDensity) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, density > 1E+37))) = 1]"));
}

TEST_F(NumericStateVariableTraceTest, SpatialMeasureArea) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, area > 1E+37))) = 1]"));
}

TEST_F(NumericStateVariableTraceTest, SpatialMeasurePerimeter) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, perimeter > 1E+37))) = 1]"));
}

TEST_F(NumericStateVariableTraceTest, SpatialMeasureDistanceFromOrigin) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, distanceFromOrigin > 1E+37))) = 1]"));
}

TEST_F(NumericStateVariableTraceTest, SpatialMeasureAngle) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, angle > 360))) = 1]"));
}

TEST_F(NumericStateVariableTraceTest, SpatialMeasureTriangleMeasure) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, triangleMeasure > 1))) = 1]"));
}

TEST_F(NumericStateVariableTraceTest, SpatialMeasureRectangleMeasure) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, rectangleMeasure > 1))) = 1]"));
}

TEST_F(NumericStateVariableTraceTest, SpatialMeasureCircleMeasure) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, circleMeasure > 1))) = 1]"));
}

TEST_F(NumericStateVariableTraceTest, SpatialMeasureCentroidX) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, centroidX > 1E+37))) = 1]"));
}

TEST_F(NumericStateVariableTraceTest, SpatialMeasureCentroidY) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, centroidY > 1E+37))) = 1]"));
}



/////////////////////////////////////////////////////////
//
//
// SpatialMeasureCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, SpatialMeasureCollection) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] avg(clusteredness(clusters)) > 1]"));
}


/////////////////////////////////////////////////////////
//
//
// Subset
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, Subset) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= subtract({B}, subtract({B}, " + StringManipulator::toString<double>(bConstantValue) + "))]"));
}


/////////////////////////////////////////////////////////
//
//
// SubsetOperation
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, SubsetOperationDifference) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(clusteredness(difference(clusters, clusters))) = 0]"));
}

TEST_F(NumericStateVariableTraceTest, SubsetOperationDifferenceRegion) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(clusteredness(difference(regions, clusters))) = 12]"));
}

TEST_F(NumericStateVariableTraceTest, SubsetOperationIntersection) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(clusteredness(intersection(clusters, filter(clusters, clusteredness > 24.999)))) >= 2]"));
}

TEST_F(NumericStateVariableTraceTest, SubsetOperationIntersectionRegion) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [G [0, 11] count(clusteredness(intersection(clusters, regions))) = 0]"));
}

TEST_F(NumericStateVariableTraceTest, SubsetOperationUnion) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(clusteredness(union(filter(clusters, clusteredness < 20), filter(clusters, clusteredness >= 20)))) > 10]"));
}

TEST_F(NumericStateVariableTraceTest, SubsetOperationUnionRegion) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(clusteredness(union(clusters, regions))) = 22]"));
}


/////////////////////////////////////////////////////////
//
//
// SubsetSpecific
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, SubsetSpecificClusters) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) > 0]"));
}

TEST_F(NumericStateVariableTraceTest, SubsetSpecificRegions) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(regions)) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// SubsetSubsetOperation
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, SubsetSubsetOperation) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(clusteredness(union(clusters, clusters))) >= 4.3]"));
}


/////////////////////////////////////////////////////////
//
//
// TemporalNumericComparison
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, TemporalNumericComparison) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A} >= 4.2]"));
}


/////////////////////////////////////////////////////////
//
//
// TemporalNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, TemporalNumericMeasure) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// TemporalNumericMeasureCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, TemporalNumericMeasureCollection) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [max([0, 11] count(clusteredness(clusters))) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericFilter
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, UnaryNumericFilter) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(clusteredness(filter(clusters, clusteredness <= round(clusteredness)))) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, UnaryNumericMeasureAbs) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [1 <= abs(count(clusteredness(clusters)))]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryNumericMeasureCeil) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [1.0001 <= ceil(count(clusteredness(clusters)))]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryNumericMeasureFloor) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [subtract({A}, subtract({A}, 1)) > floor(count(clusteredness(clusters)))]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryNumericMeasureRound) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [add({A}, 0.00005) <= round(count(clusteredness(clusters)))]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryNumericMeasureSign) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [subtract({A}, -1) <= sign(count(clusteredness(clusters)))]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryNumericMeasureSqrt) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [{A} > sqrt(count(clusteredness(clusters)))]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryNumericMeasureTrunc) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A} <= trunc(div(count(clusteredness(clusters)), 2))]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, UnaryNumericNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [max([0, 11] {A}) > 12]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericTemporal
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, UnaryNumericTemporal) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [{A} <= abs(0.909)]"));
}


/////////////////////////////////////////////////////////
//
//
// UnarySpatialConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, UnarySpatialConstraint) {
    EXPECT_FALSE(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, clusteredness <= 1))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryStatisticalMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalMeasureAvg) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [avg(clusteredness(clusters)) < 0.45]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalMeasureCount) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) < 1]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalMeasureGeomean) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [geomean(clusteredness(clusters)) = 0]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalMeasureHarmean) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [harmean(clusteredness(clusters)) >= 0]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalMeasureKurt) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [kurt(clusteredness(clusters)) <= 0]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalMeasureMax) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [max(clusteredness(clusters)) > 1]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalMeasureMedian) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [median(clusteredness(clusters)) = 0.75]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalMeasureMin) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [min(clusteredness(clusters)) = 0]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalMeasureMode) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [mode(clusteredness(clusters)) > 1]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalMeasureProduct) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [product(clusteredness(clusters)) = 0]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalMeasureSkew) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [skew(clusteredness(clusters)) < 0.05]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalMeasureStdev) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [stdev(clusteredness(clusters)) < 1]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalMeasureSum) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [sum(clusteredness(clusters)) >= 0]"));
}

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalMeasureVar) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [var(clusteredness(clusters)) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryStatisticalNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) > 0]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryStatisticalSpatial
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, UnaryStatisticalSpatial) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [max([0, 5] count(clusteredness(clusters))) = 0]"));
}


/////////////////////////////////////////////////////////
//
//
// UnaryTypeConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, UnaryTypeConstraint) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [F [0, 11] count(clusteredness(filter(clusters, type = 0))) = 1]"));
}


/////////////////////////////////////////////////////////
//
//
// UntilLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, UntilLogicProperty) {
    EXPECT_FALSE(RunEvaluationTest("P >= 0.3 [({A} >= 4) U [2, 3] (count(clusteredness(clusters)) >= 4)]"));
}

TEST_F(NumericStateVariableTraceTest, UntilLogicPropertyMultiple) {
    EXPECT_TRUE(RunEvaluationTest("P >= 0.3 [({A} >= 1) U [2, 3] (count(clusteredness(clusters)) <= 4) <=> {B} = 3]"));
}


/////////////////////////////////////////////////////////
//
//
// Constant value
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, GlobalConstantValueReal) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(2) = 0)]"));
}

TEST_F(NumericStateVariableTraceTest, GlobalConstantValueNumericStateVariable) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d({A}) = 0)]"));
}

TEST_F(NumericStateVariableTraceTest, GlobalConstantValueUnaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [G [1, 10] (d(round(count(clusteredness(clusters)))) = 0)]"));
}

TEST_F(NumericStateVariableTraceTest, GlobalConstantValueBinaryNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(add(count(clusteredness(clusters)), 2)) = 0)]"));
}

TEST_F(NumericStateVariableTraceTest, GlobalConstantValueUnaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(count(clusteredness(clusters))) = 0)]"));
}

TEST_F(NumericStateVariableTraceTest, GlobalConstantValueBinaryStatisticalNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(covar(clusteredness(filter(clusters, clusteredness < 1)), clusteredness(clusters))) = 0)]"));
}

TEST_F(NumericStateVariableTraceTest, GlobalConstantValueBinaryStatisticalQuantileNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(quartile(clusteredness(clusters), 50)) = 0)]"));
}


/////////////////////////////////////////////////////////
//
//
// Increasing value
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, FutureIncreasingValueReal) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(2) > 0)]"));
}

TEST_F(NumericStateVariableTraceTest, FutureIncreasingValueNumericStateVariable) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] (d({A}) > 0)]"));
}

TEST_F(NumericStateVariableTraceTest, FutureIncreasingValueUnaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(round(count(clusteredness(clusters)))) > 0)]"));
}

TEST_F(NumericStateVariableTraceTest, FutureIncreasingValueBinaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(add(count(clusteredness(clusters)), 1)) > 0)]"));
}

TEST_F(NumericStateVariableTraceTest, FutureIncreasingValueUnaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(count(clusteredness(clusters))) > 0)]"));
}

TEST_F(NumericStateVariableTraceTest, FutureIncreasingValueBinaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(covar(clusteredness(clusters), clusteredness(clusters))) > 0)]"));
}

TEST_F(NumericStateVariableTraceTest, FutureIncreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [F [0, 10] (d(quartile(clusteredness(clusters), 50)) > 0)]"));
}


/////////////////////////////////////////////////////////
//
//
// Decreasing value
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, GlobalDecreasingValueReal) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(2) < 0)]"));
}

TEST_F(NumericStateVariableTraceTest, GlobalDecreasingValueNumericStateVariable) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d({A}) < 0)]"));
}

TEST_F(NumericStateVariableTraceTest, GlobalDecreasingValueUnaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(round({A})) < 0)]"));
}

TEST_F(NumericStateVariableTraceTest, GlobalDecreasingValueBinaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(add({A}, {B})) < 0)]"));
}

TEST_F(NumericStateVariableTraceTest, GlobalDecreasingValueUnaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(count(clusteredness(clusters))) < 0)]"));
}

TEST_F(NumericStateVariableTraceTest, GlobalDecreasingValueBinaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(covar(clusteredness(clusters), clusteredness(clusters))) < 0)]"));
}

TEST_F(NumericStateVariableTraceTest, GlobalDecreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 10] (d(quartile(clusteredness(clusters), 50)) < 0)]"));
}


/////////////////////////////////////////////////////////
//
//
// Increasing and then decreasing value
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, IncreasingUntilDecreasingValueReal) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d(2) > 0) U [0, 10] (d(2) < 0)]"));
}

TEST_F(NumericStateVariableTraceTest, IncreasingUntilDecreasingValueNumericStateVariable) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d({A}) > 0) U [0, 10] (d({A}) < 0)]"));
}

TEST_F(NumericStateVariableTraceTest, IncreasingUntilDecreasingValueNumericStateVariable2) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d({A}) > 0) U [0, 10] (d(count(clusteredness(clusters))) < 0)]"));
}

TEST_F(NumericStateVariableTraceTest, IncreasingUntilDecreasingValueUnaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d(count(clusteredness(clusters))) >= 0) U [0, 10] (d(count(clusteredness(clusters))) < 0)]"));
}

TEST_F(NumericStateVariableTraceTest, IncreasingUntilDecreasingValueBinaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(count(clusteredness(clusters)) > 0) U [0, 10] (d(add({A}, {B})) < 0)]"));
}

TEST_F(NumericStateVariableTraceTest, IncreasingUntilDecreasingValueUnaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d(power(count(clusteredness(clusters)), 1)) > 0) U [0, 10] (d(power(count(clusteredness(clusters)), 1)) < 0)]"));
}

TEST_F(NumericStateVariableTraceTest, IncreasingUntilDecreasingValueBinaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d(covar(clusteredness(clusters), clusteredness(clusters))) >= 0) U [0, 10] (d(avg(clusteredness(filter(clusters, clusteredness > 5 V clusteredness < 10000)))) < 0)]"));
}

TEST_F(NumericStateVariableTraceTest, IncreasingUntilDecreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d(percentile(clusteredness(clusters), 80)) >= 0) U [0, 10] (d(quartile(clusteredness(clusters), 50)) < 0)]"));
}


/////////////////////////////////////////////////////////
//
//
// Decreasing and then increasing value
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, DecreasingUntilIncreasingValueReal) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d(2) < 0) U [0, 10] (d(4) > 0)]"));
}

TEST_F(NumericStateVariableTraceTest, DecreasingUntilIncreasingValueNumericStateVariable) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d({A}) < 0) U [0, 10] (d({A}) > 0)]"));
}

TEST_F(NumericStateVariableTraceTest, DecreasingUntilIncreasingValueUnaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d(count(clusteredness(clusters))) < 0) U [0, 10] (d(count(clusteredness(clusters))) > 0)]"));
}

TEST_F(NumericStateVariableTraceTest, DecreasingUntilIncreasingValueBinaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(count(clusteredness(clusters)) < 0) U [0, 10] (d(add(count(clusteredness(clusters)), 2)) > 0)]"));
}

TEST_F(NumericStateVariableTraceTest, DecreasingUntilIncreasingValueUnaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d(power(count(clusteredness(clusters)), 1)) < 0) U [0, 10] (d(power(count(clusteredness(clusters)), 1)) > 0)]"));
}

TEST_F(NumericStateVariableTraceTest, DecreasingUntilIncreasingValueBinaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(d(covar(clusteredness(clusters), clusteredness(clusters))) < 0) U [0, 10] (d(covar(clusteredness(clusters), clusteredness(clusters))) > 0)]"));
}

TEST_F(NumericStateVariableTraceTest, DecreasingUntilIncreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [(d(percentile(clusteredness(clusters), 80)) < 0) U [0, 10] (d(quartile(clusteredness(clusters), 50)) >= 0)]"));
}


/////////////////////////////////////////////////////////
//
//
// Oscillations
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, OscillationValueNumericStateVariable) {
    EXPECT_TRUE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d({A}) >= 0) ^ F [0, 10] ( (d({A}) <= 0) ^ F [0, 10] (d({A}) >= 0) ) )]"));
}

TEST_F(NumericStateVariableTraceTest, OscillationsValueUnaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(abs(count(clusteredness(clusters)))) > 0) ^ F [0, 10] ( (d(abs(count(clusteredness(clusters)))) < 0) ^ F [0, 10] (d(abs(count(clusteredness(clusters)))) > 0) ) )]"));
}

TEST_F(NumericStateVariableTraceTest, OscillationsValueBinaryNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(add(count(clusteredness(clusters)), 2)) > 0) ^ F [0, 10] ( (d(add(count(clusteredness(clusters)), 2)) < 0) ^ F [0, 10] (d(add(count(clusteredness(clusters)), 2)) > 0) ) )]"));
}

TEST_F(NumericStateVariableTraceTest, OscillationsValueUnaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(count(clusteredness(clusters))) > 0) ^ F [0, 10] ( (d(count(clusteredness(clusters))) < 0) ^ F [0, 10] (d(count(clusteredness(clusters))) > 0) ) )]"));
}

TEST_F(NumericStateVariableTraceTest, OscillationsValueBinaryStatisticalNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(covar(clusteredness(clusters), clusteredness(clusters))) > 0) ^ F [0, 10] ( (d(covar(clusteredness(clusters), clusteredness(clusters))) < 0) ^ F [0, 10] (d(covar(clusteredness(clusters), clusteredness(clusters))) > 0) ) )]"));
}

TEST_F(NumericStateVariableTraceTest, OscillationsValueBinaryStatisticalQuantileNumeric) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(quartile(clusteredness(clusters), 50)) > 0) ^ F [0, 10] ( (d(quartile(clusteredness(clusters), 50)) < 0) ^ F [0, 10] (d(quartile(clusteredness(clusters), 50)) > 0) ) )]"));
}


/////////////////////////////////////////////////////////
//
//
// Enclosing composed statements differently with parentheses
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, EnclosingWithParenthesesDifferently1) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [((avg(clusteredness(clusters)) > {B})) ^ (count(clusteredness(clusters)) > 100)]"));
}

TEST_F(NumericStateVariableTraceTest, EnclosingWithParenthesesDifferently2) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [(avg(clusteredness(clusters)) > {B}) ^ ((count(clusteredness(clusters)) > 100))]"));
}


/////////////////////////////////////////////////////////
//
//
// Time interval exceeds trace time at start or end
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, TimeIntervalExceedsTraceEndTime) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 1000] (count(clusteredness(clusters)) > {B})]"));
}

TEST_F(NumericStateVariableTraceTest, TimeIntervalExceedsTraceStartTime) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [5, 10] (count(clusteredness(clusters)) > {B})]"));
}


/////////////////////////////////////////////////////////
//
//
// Different constraints combinations
//
//
/////////////////////////////////////////////////////////

TEST_F(NumericStateVariableTraceTest, ConstraintsCombinationUnary) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 5] (count(clusteredness(filter(clusters, clusteredness > 5))) > {B})]"));
}

TEST_F(NumericStateVariableTraceTest, ConstraintsCombinationBinary) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 5] (count(clusteredness(filter(clusters, clusteredness > {B} ^ clusteredness > 1000))) > 10)]"));
}

TEST_F(NumericStateVariableTraceTest, ConstraintsCombinationNary) {
    EXPECT_FALSE(RunEvaluationTest("P < 0.9 [G [0, 5] (count(clusteredness(filter(clusters, (clusteredness > {B}) ^ ((clusteredness > 1000) V (clusteredness > 100 V clusteredness < 210))))) > 10)]"));
}


#endif