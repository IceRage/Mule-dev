#ifndef CONSTRAINTVISITOR_HPP
#define CONSTRAINTVISITOR_HPP

#include "multiscale/verification/spatial-temporal/visitor/ConstraintEvaluator.hpp"


namespace multiscale {

    namespace verification {

        //! Class used to evaluate constraints
        class ConstraintVisitor : public boost::static_visitor<TimePoint> {

            private:

                TimePoint initialTimePoint;     /*!< A copy of the initial timepoint */
                TimePoint constraintTimePoint;  /*!< The currently obtained constraint timepoint */

            public:

                ConstraintVisitor(const TimePoint &initialTimePoint, const TimePoint &constraintTimePoint) {
                    this->initialTimePoint = initialTimePoint;
                    this->constraintTimePoint = constraintTimePoint;
                }

                //! Overloading the "()" operator for the Nil alternative
                /*!
                 * \param constraint     The constraint
                 */
                TimePoint operator() (const Nil &constraint) const {
                    return initialTimePoint;
                }

                //! Overloading the "()" operator for the ConstraintAttribute alternative
                /*!
                 * \param constraint     The constraint
                 */
                TimePoint operator() (const ConstraintAttribute &constraint) const {
                    TimePoint timePoint = evaluate(constraint.firstConstraint, constraintTimePoint);

                    return evaluateNextConstraints(constraint, timePoint);
                }

                //! Overloading the "()" operator for the OrConstraintAttribute alternative
                /*!
                 * \param constraint     The constraint
                 */
                TimePoint operator() (const OrConstraintAttribute &constraint) const {
                    TimePoint timePoint = evaluate(constraint.constraint, constraintTimePoint);

                    timePoint.timePointUnion(constraintTimePoint);

                    return timePoint;
                }

                //! Overloading the "()" operator for the AndConstraintAttribute alternative
                /*!
                 * \param constraint     The constraint
                 */
                TimePoint operator() (const AndConstraintAttribute &constraint) const {
                    TimePoint timePoint = evaluate(constraint.constraint, constraintTimePoint);

                    timePoint.timePointIntersection(constraintTimePoint);

                    return timePoint;
                }

                //! Overloading the "()" operator for the ImplicationConstraintAttribute alternative
                /*!
                 * \param constraint     The constraint
                 */
                TimePoint operator() (const ImplicationConstraintAttribute &constraint) const {
                    TimePoint timePoint = evaluate(constraint.constraint, constraintTimePoint);
                    TimePoint initialTimePointCopy(initialTimePoint);

                    // (p => q)
                    initialTimePointCopy.timePointDifference(constraintTimePoint);
                    initialTimePointCopy.timePointUnion(timePoint);

                    return initialTimePointCopy;
                }

                //! Overloading the "()" operator for the EquivalenceConstraintAttribute alternative
                /*!
                 * \param constraint     The constraint
                 */
                TimePoint operator() (const EquivalenceConstraintAttribute &constraint) const {
                    TimePoint timePoint = evaluate(constraint.constraint, constraintTimePoint);
                    TimePoint forwardImplication(initialTimePoint);
                    TimePoint reverseImplication(initialTimePoint);

                    // (p => q)
                    forwardImplication.timePointDifference(constraintTimePoint);
                    forwardImplication.timePointUnion(timePoint);

                    // (q => p)
                    reverseImplication.timePointDifference(timePoint);
                    reverseImplication.timePointUnion(constraintTimePoint);

                    // (p => q) ^ (q => p)
                    forwardImplication.timePointIntersection(reverseImplication);

                    return forwardImplication;
                }

                //! Overloading the "()" operator for the PrimaryConstraintAttribute alternative
                /*!
                 * \param primaryConstraint The primary constraint
                 */
                TimePoint operator() (const PrimaryConstraintAttribute &primaryConstraint) const {
                    return evaluate(primaryConstraint.primaryConstraint, constraintTimePoint);
                }

                //! Overloading the "()" operator for the NotConstraintAttribute alternative
                /*!
                 * \param primaryConstraint The primary constraint
                 */
                TimePoint operator() (const NotConstraintAttribute &primaryConstraint) const {
                    TimePoint constrainedTimePoint = evaluate(primaryConstraint.constraint, constraintTimePoint);
                    TimePoint notTimePoint(initialTimePoint);

                    notTimePoint.timePointDifference(constrainedTimePoint);

                    return notTimePoint;
                }

                //! Overloading the "()" operator for the UnaryConstraintAttribute alternative
                /*!
                 * \param primaryConstraint The primary constraint
                 */
                TimePoint operator() (const UnaryConstraintAttribute &primaryConstraint) const {
                    ComparatorType comparatorType = primaryConstraint.comparator.comparatorType;
                    double numericMeasure = evaluateNumericMeasure(primaryConstraint.numericMeasure, constraintTimePoint);

                    return evaluateUnaryConstraint(primaryConstraint.spatialMeasure.spatialMeasureType,
                                                   comparatorType, numericMeasure, constraintTimePoint);
                }

            private:

                //! Evaluate the constraint considering the given timepoint
                /*!
                 * \param constraint    The given constraint
                 * \param timePoint     The given timepoint
                 */
                TimePoint evaluate(const ConstraintAttributeType &constraint, const TimePoint &timePoint) const {
                    return boost::apply_visitor(ConstraintVisitor(initialTimePoint, timePoint), constraint);
                }

                //! Evaluate the primary constraint considering the given timepoints
                /*!
                 * \param primaryConstraint The given primary constraint
                 * \param timePoint         The given timepoint
                 */
                TimePoint evaluate(const PrimaryConstraintAttributeType &primaryConstraint, const TimePoint &timePoint) const {
                    return boost::apply_visitor(ConstraintVisitor(initialTimePoint, timePoint), primaryConstraint);
                }

                //! Evaluate the next constraints
                /*!
                 * Evaluate the next constraints considering the given constraint and timepoints
                 *
                 * \param constraint    The given constraint
                 * \param timePoint     The resulting timepoint after applying the first constraint to the initial timepoint
                 */
                TimePoint evaluateNextConstraints(const ConstraintAttribute &constraint, const TimePoint &timePoint) const {
                    TimePoint constrainedTimePoint = timePoint;

                    for (const auto &nextConstraint : constraint.nextConstraints) {
                        constrainedTimePoint = boost::apply_visitor(ConstraintVisitor(initialTimePoint, constrainedTimePoint),
                                                                    nextConstraint);
                    }

                    return constrainedTimePoint;
                }

                //! Evaluate the unary constraint considering the given spatial measure, comparator, numeric measure and timepoint
                /*!
                 * \param spatialMeasure    The spatial measure type
                 * \param comparator        The comparator type
                 * \param numericMeasure    The value of the numeric measure
                 * \param timePoint         The considered timepoint
                 */
                TimePoint evaluateUnaryConstraint(const SpatialMeasureType &spatialMeasure, const ComparatorType &comparator,
                                                  double numericMeasure, const TimePoint &timePoint) const {
                    TimePoint unaryConstraintTimePoint(timePoint);

                    ConstraintEvaluator::filter(unaryConstraintTimePoint, spatialMeasure, comparator, numericMeasure);

                    return unaryConstraintTimePoint;
                }

                //! Evaluate the numeric measure considering the given timepoint
                /*!
                 * \param numericMeasure    The numeric measure
                 * \param timePoint         The given timepoint
                 */
                double evaluateNumericMeasure(const NumericMeasureAttributeType &numericMeasure,
                                              const TimePoint &timePoint) const {
                    return boost::apply_visitor(NumericVisitor(timePoint), numericMeasure);
                }

        };

    };

};

#endif