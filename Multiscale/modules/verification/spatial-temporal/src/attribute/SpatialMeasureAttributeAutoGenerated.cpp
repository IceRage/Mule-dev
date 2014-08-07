/******************************************************************************
 *
 * WARNING! AUTO-GENERATED FILE.
 *
 * PLEASE DO NOT UPDATE THIS FILE MANUALLY. 
 * USE THE PYTHON GENERATOR SCRIPTS FOR ANY MODIFICATIONS.
 *
 *****************************************************************************/

#include "multiscale/exception/MultiscaleException.hpp"
#include "multiscale/verification/spatial-temporal/attribute/SpatialMeasureAttribute.hpp"
#include "multiscale/verification/spatial-temporal/exception/SpatialTemporalException.hpp"

#include <limits>

using namespace multiscale::verification;
using namespace multiscale::verification::spatialmeasure;


double
multiscale::verification::spatialmeasure::getMinValidSpatialMeasureValue(const SpatialMeasureType &spatialMeasureType) {
    switch (spatialMeasureType) {
        case SpatialMeasureType::Clusteredness:
            return 0;
            break;
            
        case SpatialMeasureType::Density:
            return 0;
            break;
            
        case SpatialMeasureType::Area:
            return 0;
            break;
            
        case SpatialMeasureType::Perimeter:
            return 0;
            break;
            
        case SpatialMeasureType::DistanceFromOrigin:
            return 0;
            break;
            
        case SpatialMeasureType::Angle:
            return 0;
            break;
            
        case SpatialMeasureType::TriangleMeasure:
            return 0;
            break;
            
        case SpatialMeasureType::RectangleMeasure:
            return 0;
            break;
            
        case SpatialMeasureType::CircleMeasure:
            return 0;
            break;
            
        case SpatialMeasureType::CentroidX:
            return 0;
            break;
            
        case SpatialMeasureType::CentroidY:
            return 0;
            break;
            
        default:
            MS_throw(SpatialTemporalException, multiscale::ERR_UNDEFINED_ENUM_VALUE);
    }

    // Line added to avoid "control reaches end of non-void function" warnings
    return 0.0;
}

double
multiscale::verification::spatialmeasure::getMaxValidSpatialMeasureValue(const SpatialMeasureType &spatialMeasureType) {
    switch (spatialMeasureType) {
        case SpatialMeasureType::Clusteredness:
            return 1E+37;
            break;
            
        case SpatialMeasureType::Density:
            return 1E+37;
            break;
            
        case SpatialMeasureType::Area:
            return 1E+37;
            break;
            
        case SpatialMeasureType::Perimeter:
            return 1E+37;
            break;
            
        case SpatialMeasureType::DistanceFromOrigin:
            return 1E+37;
            break;
            
        case SpatialMeasureType::Angle:
            return 360;
            break;
            
        case SpatialMeasureType::TriangleMeasure:
            return 1;
            break;
            
        case SpatialMeasureType::RectangleMeasure:
            return 1;
            break;
            
        case SpatialMeasureType::CircleMeasure:
            return 1;
            break;
            
        case SpatialMeasureType::CentroidX:
            return 1E+37;
            break;
            
        case SpatialMeasureType::CentroidY:
            return 1E+37;
            break;
            
        default:
            MS_throw(SpatialTemporalException, multiscale::ERR_UNDEFINED_ENUM_VALUE);
    }

    // Line added to avoid "control reaches end of non-void function" warnings
    return 0.0;
}

//! Overload the output stream operator for the SpatialMeasureType enumeration
std::ostream&
multiscale::verification::operator<<(std::ostream& out, const SpatialMeasureType &spatialMeasureType) {
    switch (spatialMeasureType) {
        case SpatialMeasureType::Clusteredness:
            out << "clusteredness";
            break;
            
        case SpatialMeasureType::Density:
            out << "density";
            break;
            
        case SpatialMeasureType::Area:
            out << "area";
            break;
            
        case SpatialMeasureType::Perimeter:
            out << "perimeter";
            break;
            
        case SpatialMeasureType::DistanceFromOrigin:
            out << "distanceFromOrigin";
            break;
            
        case SpatialMeasureType::Angle:
            out << "angle";
            break;
            
        case SpatialMeasureType::TriangleMeasure:
            out << "triangleMeasure";
            break;
            
        case SpatialMeasureType::RectangleMeasure:
            out << "rectangleMeasure";
            break;
            
        case SpatialMeasureType::CircleMeasure:
            out << "circleMeasure";
            break;
            
        case SpatialMeasureType::CentroidX:
            out << "centroidX";
            break;
            
        case SpatialMeasureType::CentroidY:
            out << "centroidY";
            break;
            
        default:
            out << "undefined";
    }

    return out;
}