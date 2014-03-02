#ifndef TIMEPOINTEVALUATOR_HPP
#define TIMEPOINTEVALUATOR_HPP

#include "multiscale/verification/spatial-temporal/visitor/SpatialEntityEvaluator.hpp"


namespace multiscale {

    namespace verification {

        //! Class used to evaludate timepoints
        class TimePointEvaluator {

            public:

                //! Return the spatial measure values for all considered spatial entities in the given timepoint
                /*!
                 * \param timePoint         The considered timepoint
                 * \param spatialMeasure    The considered spatial measure
                 */
                static std::vector<double> getSpatialMeasureValues(const TimePoint &timePoint,
                                                                   const SpatialMeasureType &spatialMeasure) {
                    std::vector<double> spatialMeasureValues;

                    std::vector<SpatialEntity> consideredSpatialEntities = timePoint.getConsideredSpatialEntities();

                    getSpatialMeasureValues(consideredSpatialEntities, spatialMeasureValues, spatialMeasure);

                    return spatialMeasureValues;
                }

                //! Return the spatial measure values for all considered spatial entities in the given timepoint
                /*!
                 * \param spatialMeasure    The considered spatial measure
                 */
                static void getSpatialMeasureValues(const std::vector<SpatialEntity> &consideredSpatialEntities,
                                                    std::vector<double> &spatialMeasureValues,
                                                    const SpatialMeasureType &spatialMeasure) {
                    double spatialMeasureValue = 0;

                    for (const auto &spatialEntity : consideredSpatialEntities) {
                        spatialMeasureValue = SpatialEntityEvaluator::evaluate(spatialEntity, spatialMeasure);

                        spatialMeasureValues.push_back(spatialMeasureValue);
                    }
                }

        };

    };

};



#endif
