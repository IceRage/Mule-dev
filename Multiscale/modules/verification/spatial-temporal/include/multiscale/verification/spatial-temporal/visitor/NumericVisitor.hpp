#ifndef NUMERICVISITOR_HPP
#define NUMERICVISITOR_HPP

#include "multiscale/verification/spatial-temporal/attribute/NumericMeasureAttribute.hpp"
#include "multiscale/verification/spatial-temporal/visitor/ComparatorEvaluator.hpp"
#include "multiscale/verification/spatial-temporal/visitor/NumericEvaluator.hpp"
#include "multiscale/verification/spatial-temporal/visitor/TimePointEvaluator.hpp"

#include <boost/variant.hpp>
#include <string>


namespace multiscale {

    namespace verification {

        //! Class for evaluating numeric measures
        class NumericVisitor : public boost::static_visitor<double> {

            private:

                const TimePoint &timePoint;  /*!< The considered timepoint */

            public:

                NumericVisitor(const TimePoint &timePoint) : timePoint(timePoint) {}

                //! Overloading the "()" operator for the NumericMeasureAttribute alternative
                /*!
                 * \param numericMeasure  The numeric measure
                 */
                double operator()(const NumericMeasureAttribute &numericMeasure) const {
                    return evaluate(numericMeasure.numericMeasure);
                }

                //! Overloading the "()" operator for the PrimaryNumericMeasureAttribute alternative
                /*!
                 * \param primaryNumericMeasure The primary numeric measure
                 */
                double operator()(const PrimaryNumericMeasureAttribute &primaryNumericMeasure) const {
                    return evaluatePrimaryNumericMeasure(primaryNumericMeasure.primaryNumericMeasure);
                }

                //! Overloading the "()" operator for the real number alternative
                /*!
                 * \param realNumber The real number
                 */
                double operator()(double realNumber) const {
                    return realNumber;
                }

                //! Overloading the "()" operator for the NumericStateVariableAttribute alternative
                /*!
                 * \param numericStateVariable  The numeric state variable
                 */
                double operator()(const NumericStateVariableAttribute &numericStateVariable) const {
                    std::string name = numericStateVariable.stateVariable.name;

                    return timePoint.getNumericStateVariable(name);
                }

                //! Overloading the "()" operator for the NumericSpatialAttribute alternative
                /*!
                 * \param numericSpatialMeasure  The numeric spatial measure attribute
                 */
                double operator()(const NumericSpatialAttribute &numericSpatialMeasure) const {
                    return evaluateNumericSpatialMeasure(numericSpatialMeasure.numericSpatialMeasure);
                }

                //! Overloading the "()" operator for the UnaryNumericNumericAttribute alternative
                /*!
                 * \param unaryNumericNumericMeasure  The unary numeric numeric measure
                 */
                double operator()(const UnaryNumericNumericAttribute &unaryNumericNumericMeasure) const {
                    UnaryNumericMeasureType unaryNumericMeasureType = unaryNumericNumericMeasure.
                                                                      unaryNumericMeasure.
                                                                      unaryNumericMeasureType;

                    double numericMeasure = evaluate(unaryNumericNumericMeasure.numericMeasure);

                    return NumericEvaluator::evaluate(unaryNumericMeasureType, numericMeasure);
                }

                //! Overloading the "()" operator for the BinaryNumericNumericAttribute alternative
                /*!
                 * \param binaryNumericNumericMeasure  The binary numeric numeric measure
                 */
                double operator()(const BinaryNumericNumericAttribute &binaryNumericNumericMeasure) const {
                    BinaryNumericMeasureType binaryNumericMeasureType = binaryNumericNumericMeasure.
                                                                        binaryNumericMeasure.
                                                                        binaryNumericMeasureType;

                    double firstNumericMeasure  = evaluate(binaryNumericNumericMeasure.firstNumericMeasure);
                    double secondNumericMeasure = evaluate(binaryNumericNumericMeasure.secondNumericMeasure);

                    return NumericEvaluator::evaluate(binaryNumericMeasureType, firstNumericMeasure, secondNumericMeasure);
                }

                //! Overloading the "()" operator for the UnarySubsetAttribute alternative
                /*!
                 * \param unarySubset  The unary subset
                 */
                double operator()(const UnarySubsetAttribute &unarySubset) const;

                //! Overloading the "()" operator for the BinarySubsetAttribute alternative
                /*!
                 * \param binarySubset  The binary subset
                 */
                double operator()(const BinarySubsetAttribute &binarySubset) const;

                //! Overloading the "()" operator for the TernarySubsetAttribute alternative
                /*!
                 * \param ternarySubset  The ternary subset
                 */
                double operator()(const TernarySubsetAttribute &ternarySubset) const;

                //! Overloading the "()" operator for the QuaternarySubsetAttribute alternative
                /*!
                 * \param quaternarySubset  The quaternary subset
                 */
                double operator()(const QuaternarySubsetAttribute &quaternarySubset) const;

            private:

                //! Evaluate the given numeric measure considering the timePoint field
                /*!
                 * \param numericMeasure    The given numeric measure
                 */
                double evaluate(const NumericMeasureAttributeType &numericMeasure) const {
                    return boost::apply_visitor(NumericVisitor(timePoint), numericMeasure);
                }

                //! Evaluate the given primary numeric measure considering the timePoint field
                /*!
                 * \param primaryNumericMeasure The given primary numeric measure
                 */
                double evaluatePrimaryNumericMeasure(const PrimaryNumericMeasureAttributeType &primaryNumericMeasure) const {
                    return boost::apply_visitor(NumericVisitor(timePoint), primaryNumericMeasure);
                }

                //! Evaluate the given numeric spatial measure considering the timePoint field
                /*!
                 * \param numericSpatialMeasure The given numeric spatial measure
                 */
                double evaluateNumericSpatialMeasure(const NumericSpatialAttributeType &numericSpatialMeasure) const {
                    return boost::apply_visitor(NumericVisitor(timePoint), numericSpatialMeasure);
                }

        };

    };

};


// NumericVisitor dependent includes

#include "multiscale/verification/spatial-temporal/visitor/ConstraintVisitor.hpp"
#include "multiscale/verification/spatial-temporal/visitor/SubsetVisitor.hpp"

// Implement NumericVisitor methods which are dependent on the ConstraintVisitor and SubsetVisitor classes

inline double multiscale::verification::NumericVisitor::operator()(const UnarySubsetAttribute &unarySubset) const {
    TimePoint subsetTimePoint(boost::apply_visitor(SubsetVisitor(timePoint), unarySubset.subset));

    return NumericEvaluator::evaluate(unarySubset.unarySubsetMeasure.unarySubsetMeasureType, subsetTimePoint);
}

inline double multiscale::verification::NumericVisitor::operator()(const BinarySubsetAttribute &binarySubset) const {
    TimePoint subsetTimePoint(boost::apply_visitor(SubsetVisitor(timePoint), binarySubset.subset));

    std::vector<double> spatialMeasureValues = TimePointEvaluator::getSpatialMeasureValues(subsetTimePoint,
                                                                                           binarySubset.spatialMeasure.spatialMeasureType);

    return NumericEvaluator::evaluate(binarySubset.binarySubsetMeasure.binarySubsetMeasureType, spatialMeasureValues);
}

inline double multiscale::verification::NumericVisitor::operator()(const TernarySubsetAttribute &ternarySubset) const {
    TimePoint subsetTimePoint(boost::apply_visitor(SubsetVisitor(timePoint), ternarySubset.subset));

    std::vector<double> spatialMeasureValues = TimePointEvaluator::getSpatialMeasureValues(subsetTimePoint,
                                                                                           ternarySubset.spatialMeasure.spatialMeasureType);

    return NumericEvaluator::evaluate(ternarySubset.ternarySubsetMeasure.ternarySubsetMeasureType,
                                      spatialMeasureValues, ternarySubset.parameter);
}

inline double multiscale::verification::NumericVisitor::operator()(const QuaternarySubsetAttribute &quaternarySubset) const {
    TimePoint firstSubsetTimePoint(boost::apply_visitor(SubsetVisitor(timePoint), quaternarySubset.firstSubset));

    std::vector<double> firstSpatialMeasureValues = TimePointEvaluator::getSpatialMeasureValues(firstSubsetTimePoint,
                                                                                                quaternarySubset.firstSpatialMeasure.spatialMeasureType);

    TimePoint secondSubsetTimePoint(boost::apply_visitor(SubsetVisitor(timePoint), quaternarySubset.secondSubset));

    std::vector<double> secondSpatialMeasureValues = TimePointEvaluator::getSpatialMeasureValues(secondSubsetTimePoint,
                                                                                                 quaternarySubset.firstSpatialMeasure.spatialMeasureType);


    return NumericEvaluator::evaluate(quaternarySubset.quaternarySubsetMeasure.quaternarySubsetMeasureType,
                                      firstSpatialMeasureValues, secondSpatialMeasureValues);
}


#endif
