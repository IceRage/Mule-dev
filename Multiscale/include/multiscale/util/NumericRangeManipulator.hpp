#ifndef NUMERICRANGEMANIPULATOR_HPP_
#define NUMERICRANGEMANIPULATOR_HPP_

namespace multiscale {

    //! Operations for ranges of numeric values
    class NumericRangeManipulator {

        public:

            //! Convert a value from an old range to a new one
            /*!
             * \param oldRangeMin The minimum of the old range
             * \param oldRangeMax The maximum of the old range
             * \param newRangeMin The minimum of the new range
             * \param newRangeMax The maximum of the new range
             * \param oldValue    The old value
             */
            template <class T, class U>
            static U convertFromRange(T oldRangeMin, T oldRangeMax, U newRangeMin, U newRangeMax, T oldValue) {
                double normalisedValue = ((double)(oldValue - oldRangeMin)) / (oldRangeMax - oldRangeMin);

                return (newRangeMin + normalisedValue * (newRangeMax - newRangeMin));
            }

    };

};

#endif
