#ifndef EMPTYTRACETEST_HPP
#define EMPTYTRACETEST_HPP

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

    //! Class for testing evaluation of empty traces
    class EmptyTraceTest : public TraceEvaluationTest {

        private:

           //! Initialise the trace
           virtual void InitialiseTrace() override;

    };

    void EmptyTraceTest::InitialiseTrace() {
        // Empty trace
    }

};


/////////////////////////////////////////////////////////
//
//
// BinaryNumericFilter
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, BinaryNumericFilter) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [G [0, 11] count(clusteredness(filter(clusters, clusteredness < subtract(clusteredness, 2.5)))) > 0]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// BinaryNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, BinaryNumericMeasureAdd) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [{A} <= add(" + StringManipulator::toString<double>(aMaxValue) + ", 0.0001)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, BinaryNumericMeasureDiv) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [{A} <= div(2, 3)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, BinaryNumericMeasureLog) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [{A} <= log(4.33333, 9.12312312)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, BinaryNumericMeasureMod) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [{A} <= mod(4, 8)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, BinaryNumericMeasureMultiply) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [{A} <= multiply(2, 3)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, BinaryNumericMeasurePower) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [{A} <= power(2, 3)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, BinaryNumericMeasureSubtract) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [{A} <= subtract(3, 6)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// BinaryNumericNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, BinaryNumericNumeric) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [min([0, 3] power({B}, 1.3)) <= add(2, 3)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// BinaryNumericTemporal
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, BinaryNumericTemporal) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [power({B}, 1.3) <= add(2, 3)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, BinaryStatisticalMeasure) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [covar(clusteredness(clusters), clusteredness(clusters)) >= 0.001]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, BinaryStatisticalNumeric) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [covar(clusteredness(clusters), clusteredness(clusters)) >= 0.0005]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalQuantileMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, BinaryStatisticalQuantileMeasurePercentile) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [percentile(clusteredness(clusters), 4.3) <= 0.5]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, BinaryStatisticalQuantileMeasureQuartile) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [quartile(clusteredness(clusters), 4.3) <= 0.5]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalQuantileNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, BinaryStatisticalQuantileNumeric) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [percentile(clusteredness(clusters), 4.3) <= 0.5]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalQuantileSpatial
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, BinaryStatisticalQuantileSpatial) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [avg([0, 1] percentile(clusteredness(clusters), 4.3)) <= 0.5]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// BinaryStatisticalSpatial
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, BinaryStatisticalSpatial) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [mode([0, 10] covar(clusteredness(clusters), clusteredness(clusters))) >= 0.0005]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// ChangeMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, ChangeMeasureDifference) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [d(max(clusteredness(clusters))) >= 2]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, ChangeMeasureRatio) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [r(max(clusteredness(clusters))) >= 4]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// ChangeTemporalNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, ChangeTemporalNumericMeasure) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [d(max(clusteredness(clusters))) <= 3]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// Comparator
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, ComparatorGreaterThan) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(clusters)) > 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, ComparatorLessThan) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(clusters)) < 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, ComparatorGreaterThanOrEqual) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(clusters)) >= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, ComparatorLessThanOrEqual) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(clusters)) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, ComparatorEqual) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(clusters)) = 3]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// CompoundConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, CompoundConstraint) {
    const static std::vector<std::string> CONSTRAINTS_BINARY_OPERATORS = std::vector<std::string>({"^", "V", "=>", "<=>"});

    for (auto &binaryOperator : CONSTRAINTS_BINARY_OPERATORS) {
        EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 30.2) " + binaryOperator + " (clusteredness = 0.1)))) <= 3]"), SpatialTemporalException);
    }
}

TEST_F(EmptyTraceTest, CompoundConstraintMultiple) {
    const static std::vector<std::string> CONSTRAINTS_BINARY_OPERATORS = std::vector<std::string>({"^", "V", "=>", "<=>"});

    for (auto &binaryOperator : CONSTRAINTS_BINARY_OPERATORS) {
        EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 30.2) " + binaryOperator + " (clusteredness = 0.1) " + binaryOperator + " (~ clusteredness >= 4000)))) <= 3]"), SpatialTemporalException);
    }
}


/////////////////////////////////////////////////////////
//
//
// CompoundLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, CompoundLogicProperty) {
    const static std::vector<std::string> LOGIC_PROPERTIES_BINARY_OPERATORS = std::vector<std::string>({"^", "V", "=>", "<=>"});

    for (auto &binaryOperator : LOGIC_PROPERTIES_BINARY_OPERATORS) {
        EXPECT_THROW(RunEvaluationTest("P >= 0.3 [({A} >= 4) " + binaryOperator + " (count(clusteredness(clusters)) >= 0) ]"), SpatialTemporalException);
    }
}

TEST_F(EmptyTraceTest, CompoundLogicPropertyMultiple) {
    const static std::vector<std::string> LOGIC_PROPERTIES_BINARY_OPERATORS = std::vector<std::string>({"^", "V", "=>", "<=>"});

    for (auto &binaryOperator : LOGIC_PROPERTIES_BINARY_OPERATORS) {
        EXPECT_THROW(RunEvaluationTest("P >= 0.3 [({A} >= 4) " + binaryOperator + " (count(clusteredness(clusters)) <= 0) " + binaryOperator + " {B} = 3]"), SpatialTemporalException);
    }
}


/////////////////////////////////////////////////////////
//
//
// ConstraintEnclosedByParentheses
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, ConstraintEnclosedByParentheses) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, (clusteredness <= 30.2)))) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, ConstraintEnclosedByParenthesesDoubled) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, ((clusteredness <= 30.2))))) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, ConstraintEnclosedByParenthesesQuadrupled) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, ((((clusteredness <= 30.2))))))) <= 3]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// Constraint
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, Constraint) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, clusteredness > 10000 V clusteredness <= 1))) = 1]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// FilterNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, FilterNumericMeasure) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [G [0, 11] count(clusteredness(filter(clusters, clusteredness < subtract(clusteredness, 2.5) ^ clusteredness > clusteredness))) > 0]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// FilterSubset
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, FilterSubset) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(filter(clusters, clusteredness > 0))) <= 1]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// FutureLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, FutureLogicProperty) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [F [2, 3] ({A} >= 4)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// GlobalLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, GlobalLogicProperty) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [G [2, 3] ({A} >= 4)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// LogicPropertyEnclosedByParentheses
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, LogicPropertyEnclosedByParentheses) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [({A} >= 4)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, LogicPropertyEnclosedByParenthesesDoubled) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [(({A} >= 4))]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, LogicPropertyEnclosedByParenthesesQuadrupled) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [(((({A} >= 4))))]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// LogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, LogicProperty) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) >= 2]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// MultipleLogicProperties
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, MultipleLogicProperties1) {
    EXPECT_THROW(RunEvaluationTest("P > 0.1234 [( d(4) >=  count(clusteredness(clusters)) ) ^ ( covar(clusteredness(clusters), clusteredness(clusters)) >= {A} ) V ( {B} = sqrt(add({B}, {C})) )]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, MultipleLogicProperties2) {
    EXPECT_THROW(
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
        ), 
        SpatialTemporalException
    );
}


/////////////////////////////////////////////////////////
//
//
// NextKLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, NextKLogicProperty) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [X [3] ({A} >= 4)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// NextLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, NextLogicProperty) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [X ({A} >= 4)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// NotConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, NotConstraint) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, ~ (clusteredness <= -0.22)))) <= 1]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// NotLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, NotLogicProperty) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [~({A} >= 4.2)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// NumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, NumericMeasure) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [max([0, 5] count(clusteredness(clusters))) >= 4]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// NumericMeasureCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, NumericMeasureCollection) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [sum(clusteredness(clusters)) <= add(2, 3)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// NumericSpatialMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, NumericSpatialMeasure) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [geomean(clusteredness(clusters)) <= 0.5]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// NumericStateVariable
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, NumericStateVariable1) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [{A} <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, NumericStateVariable2) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [{a2#0f-} <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, NumericStateVariable3) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [{`1234567890-=~!@#$%^&*()_+qwertyuiop[]asdfghjkl;'\\<zxcvbnm,./QWERTYUIOPASDFGHJKL:\"|>ZXCVBNM<>?} <= 3]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// NumericStatisticalMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, NumericStatisticalMeasure) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [X min([0, 5] count(clusteredness(clusters))) >= 2]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// ProbabilisticLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, ProbabilisticLogicProperty) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) >= 1]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// SpatialMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, SpatialMeasureClusteredness) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, clusteredness <= 30.2))) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, SpatialMeasureDensity) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, density <= 30.2))) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, SpatialMeasureArea) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, area <= 30.2))) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, SpatialMeasurePerimeter) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, perimeter <= 30.2))) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, SpatialMeasureDistanceFromOrigin) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, distanceFromOrigin <= 30.2))) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, SpatialMeasureAngle) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, angle <= 30.2))) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, SpatialMeasureTriangleMeasure) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, triangleMeasure <= 30.2))) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, SpatialMeasureRectangleMeasure) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, rectangleMeasure <= 30.2))) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, SpatialMeasureCircleMeasure) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, circleMeasure <= 30.2))) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, SpatialMeasureCentroidX) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, centroidX <= 30.2))) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, SpatialMeasureCentroidY) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, centroidY <= 30.2))) <= 3]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// SpatialMeasureCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, SpatialMeasureCollection) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [F [0, 11] avg(clusteredness(clusters)) > 12]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// Subset
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, Subset) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= 3]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// SubsetOperation
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, SubsetOperationDifference) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(difference(clusters, clusters))) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, SubsetOperationIntersection) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(intersection(clusters, clusters))) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, SubsetOperationUnion) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(union(clusters, clusters))) <= 3]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// SubsetSpecific
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, SubsetSpecificClusters) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= 3]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, SubsetSpecificRegions) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(regions)) <= 3]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// SubsetSubsetOperation
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, SubsetSubsetOperation) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(difference(clusters, clusters))) <= 3]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// TemporalNumericComparison
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, TemporalNumericComparison) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [{A} >= 4.2]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// TemporalNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, TemporalNumericMeasure) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) >= 4]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// TemporalNumericMeasureCollection
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, TemporalNumericMeasureCollection) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [max([0, 11] count(clusteredness(clusters))) = 11]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericFilter
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, UnaryNumericFilter) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [F [0, 11] count(clusteredness(filter(clusters, clusteredness <= round(clusteredness)))) > 0]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, UnaryNumericMeasureAbs) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= abs(count(clusteredness(clusters)))]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryNumericMeasureCeil) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= ceil(count(clusteredness(clusters)))]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryNumericMeasureFloor) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= floor(count(clusteredness(clusters)))]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryNumericMeasureRound) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= round(count(clusteredness(clusters)))]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryNumericMeasureSign) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= sign(count(clusteredness(clusters)))]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryNumericMeasureSqrt) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= sqrt(count(clusteredness(clusters)))]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryNumericMeasureTrunc) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= trunc(count(clusteredness(clusters)))]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, UnaryNumericNumeric) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [max([0, 11] {A}) <= abs(3.0)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// UnaryNumericTemporal
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, UnaryNumericTemporal) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [{A} <= abs(1.0)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// UnarySpatialConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, UnarySpatialConstraint) {
    EXPECT_THROW(RunEvaluationTest("P <= 0.9 [count(clusteredness(filter(clusters, clusteredness <= 1))) >= 1]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// UnaryStatisticalMeasure
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, UnaryStatisticalMeasureAvg) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [avg(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryStatisticalMeasureCount) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryStatisticalMeasureGeomean) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [geomean(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryStatisticalMeasureHarmean) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [harmean(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryStatisticalMeasureKurt) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [kurt(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryStatisticalMeasureMax) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [max(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryStatisticalMeasureMedian) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [median(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryStatisticalMeasureMin) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [min(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryStatisticalMeasureMode) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [mode(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryStatisticalMeasureProduct) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [product(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryStatisticalMeasureSkew) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [skew(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryStatisticalMeasureStdev) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [stdev(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryStatisticalMeasureSum) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [sum(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UnaryStatisticalMeasureVar) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [var(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// UnaryStatisticalNumeric
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, UnaryStatisticalNumeric) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(clusters)) <= 2]"), SpatialTemporalException);
}

/////////////////////////////////////////////////////////
//
//
// UnaryStatisticalSpatial
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, UnaryStatisticalSpatial) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [max([0, 5] count(clusteredness(clusters))) < 6.01]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// UnaryTypeConstraint
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, UnaryTypeConstraint) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [count(clusteredness(filter(clusters, type = 0))) = 1]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// UntilLogicProperty
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, UntilLogicProperty) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [({A} >= 4) U [2, 3] (count(clusteredness(clusters)) >= 4)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, UntilLogicPropertyMultiple) {
    EXPECT_THROW(RunEvaluationTest("P >= 0.3 [({A} >= 4) U [2, 3] (count(clusteredness(clusters)) <= 4) <=> {B} = 3]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// Constant value
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, GlobalConstantValueReal) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 10] (d(2) = 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, GlobalConstantValueNumericStateVariable) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 10] (d({A}) = 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, GlobalConstantValueUnaryNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [1, 10] (d(round(count(clusteredness(clusters)))) = 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, GlobalConstantValueBinaryNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 10] (d(add(count(clusteredness(clusters)), 2)) = 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, GlobalConstantValueUnaryStatisticalNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 10] (d(count(clusteredness(clusters))) = 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, GlobalConstantValueBinaryStatisticalNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 10] (d(covar(clusteredness(filter(clusters, clusteredness < 1)), clusteredness(clusters))) = 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, GlobalConstantValueBinaryStatisticalQuantileNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 10] (d(quartile(clusteredness(clusters), 50)) = 0)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// Increasing value
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, FutureIncreasingValueReal) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [F [0, 10] (d(2) > 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, FutureIncreasingValueNumericStateVariable) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [F [0, 10] (d({A}) > 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, FutureIncreasingValueUnaryNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [F [0, 10] (d(round(count(clusteredness(clusters)))) > 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, FutureIncreasingValueBinaryNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [F [0, 10] (d(add(count(clusteredness(clusters)), 1)) > 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, FutureIncreasingValueUnaryStatisticalNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [F [0, 10] (d(count(clusteredness(clusters))) > 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, FutureIncreasingValueBinaryStatisticalNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [F [0, 10] (d(covar(clusteredness(clusters), clusteredness(clusters))) > 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, FutureIncreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [F [0, 10] (d(quartile(clusteredness(clusters), 50)) > 0)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// Decreasing value
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, GlobalDecreasingValueReal) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 10] (d(2) < 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, GlobalDecreasingValueNumericStateVariable) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 10] (d({A}) < 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, GlobalDecreasingValueUnaryNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 10] (d(round({A})) < 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, GlobalDecreasingValueBinaryNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 10] (d(add({A}, {B})) < 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, GlobalDecreasingValueUnaryStatisticalNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 10] (d(count(clusteredness(clusters))) < 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, GlobalDecreasingValueBinaryStatisticalNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 10] (d(covar(clusteredness(clusters), clusteredness(clusters))) < 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, GlobalDecreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 10] (d(quartile(clusteredness(clusters), 50)) < 0)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// Increasing and then decreasing value
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, IncreasingUntilDecreasingValueReal) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(d(2) > 0) U [0, 10] (d(2) < 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, IncreasingUntilDecreasingValueNumericStateVariable) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(d({A}) > 0) U [0, 10] (d({A}) < 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, IncreasingUntilDecreasingValueNumericStateVariable2) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(d({A}) > 0) U [0, 10] (d(count(clusteredness(clusters))) < 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, IncreasingUntilDecreasingValueUnaryNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(d(count(clusteredness(clusters))) >= 0) U [0, 10] (d(count(clusteredness(clusters))) < 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, IncreasingUntilDecreasingValueBinaryNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(count(clusteredness(clusters)) >= 0) U [0, 10] (d(add({A}, {B})) < 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, IncreasingUntilDecreasingValueUnaryStatisticalNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(d(power(count(clusteredness(clusters)), 1)) > 0) U [0, 10] (d(power(count(clusteredness(clusters)), 1)) < 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, IncreasingUntilDecreasingValueBinaryStatisticalNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(d(covar(clusteredness(clusters), clusteredness(clusters))) >= 0) U [0, 10] (d(avg(clusteredness(filter(clusters, clusteredness > 5 V clusteredness < 10000)))) < 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, IncreasingUntilDecreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(d(percentile(clusteredness(clusters), 80)) >= 0) U [0, 10] (d(quartile(clusteredness(clusters), 50)) < 0)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// Decreasing and then increasing value
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, DecreasingUntilIncreasingValueReal) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(d(2) < 0) U [0, 10] (d(4) >= 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, DecreasingUntilIncreasingValueNumericStateVariable) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(d({A}) < 0) U [0, 10] (d({A}) > 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, DecreasingUntilIncreasingValueUnaryNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(d(count(clusteredness(clusters))) <= 0) U [0, 10] (d(count(clusteredness(clusters))) >= 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, DecreasingUntilIncreasingValueBinaryNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(count(clusteredness(clusters)) <= 0) U [0, 10] (d(add(count(clusteredness(clusters)), 2)) >= 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, DecreasingUntilIncreasingValueUnaryStatisticalNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(d(power(count(clusteredness(clusters)), 1)) < 0) U [0, 10] (d(power(count(clusteredness(clusters)), 1)) > 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, DecreasingUntilIncreasingValueBinaryStatisticalNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(d(covar(clusteredness(clusters), clusteredness(clusters))) < 0) U [0, 10] (d(covar(clusteredness(clusters), clusteredness(clusters))) > 0)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, DecreasingUntilIncreasingValueBinaryStatisticalQuantileNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(d(percentile(clusteredness(clusters), 80)) < 0) U [0, 10] (d(quartile(clusteredness(clusters), 50)) >= 0)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// Oscillations
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, OscillationValueNumericStateVariable) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d({A}) >= 0) ^ F [0, 10] ( (d({A}) <= 0) ^ F [0, 10] (d({A}) >= 0) ) )]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, OscillationsValueUnaryNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(abs(count(clusteredness(clusters)))) >= 0) ^ F [0, 10] ( (d(abs(count(clusteredness(clusters)))) <= 0) ^ F [0, 10] (d(abs(count(clusteredness(clusters)))) >= 0) ) )]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, OscillationsValueBinaryNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(add(count(clusteredness(clusters)), 2)) >= 0) ^ F [0, 10] ( (d(add(count(clusteredness(clusters)), 2)) <= 0) ^ F [0, 10] (d(add(count(clusteredness(clusters)), 2)) >= 0) ) )]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, OscillationsValueUnaryStatisticalNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(count(clusteredness(clusters))) >= 0) ^ F [0, 10] ( (d(count(clusteredness(clusters))) <= 0) ^ F [0, 10] (d(count(clusteredness(clusters))) >= 0) ) )]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, OscillationsValueBinaryStatisticalNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(covar(clusteredness(clusters), clusteredness(clusters))) >= 0) ^ F [0, 10] ( (d(covar(clusteredness(clusters), clusteredness(clusters))) <= 0) ^ F [0, 10] (d(covar(clusteredness(clusters), clusteredness(clusters))) >= 0) ) )]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, OscillationsValueBinaryStatisticalQuantileNumeric) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [F [0, 10] ( (d(quartile(clusteredness(clusters), 50)) >= 0) ^ F [0, 10] ( (d(quartile(clusteredness(clusters), 50)) <= 0) ^ F [0, 10] (d(quartile(clusteredness(clusters), 50)) >= 0) ) )]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// Enclosing composed statements differently with parentheses
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, EnclosingWithParenthesesDifferently1) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [((avg(clusteredness(clusters)) > 10)) ^ (count(clusteredness(clusters)) > 100)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, EnclosingWithParenthesesDifferently2) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [(avg(clusteredness(clusters)) > 10) ^ ((count(clusteredness(clusters)) > 100))]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// Time interval exceeds trace time at start or end
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, TimeIntervalExceedsTraceEndTime) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 1000] (count(clusteredness(clusters)) > 10)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, TimeIntervalExceedsTraceStartTime) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [5, 10] (count(clusteredness(clusters)) > 10)]"), SpatialTemporalException);
}


/////////////////////////////////////////////////////////
//
//
// Different constraints combinations
//
//
/////////////////////////////////////////////////////////

TEST_F(EmptyTraceTest, ConstraintsCombinationUnary) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 5] (count(clusteredness(filter(clusters, clusteredness > 5))) > 10)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, ConstraintsCombinationBinary) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 5] (count(clusteredness(filter(clusters, clusteredness > 5 ^ clusteredness > 1000))) > 10)]"), SpatialTemporalException);
}

TEST_F(EmptyTraceTest, ConstraintsCombinationNary) {
    EXPECT_THROW(RunEvaluationTest("P < 0.9 [G [0, 5] (count(clusteredness(filter(clusters, (clusteredness > 5) ^ ((clusteredness > 1000) V (clusteredness > 100 V clusteredness < 210))))) > 10)]"), SpatialTemporalException);
}


#endif