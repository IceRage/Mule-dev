#ifndef REGION_HPP_
#define REGION_HPP_

#include "opencv2/imgproc/imgproc.hpp"

#include <vector>

using namespace cv;
using namespace std;

#define OUTPUT_SEPARATOR ","


namespace multiscale {

    namespace analysis {

        //! Class for representing a region
        class Region {

            private:

                double area;                /*!< Area of the region */
                double distanceFromOrigin;  /*!< Distance from the origin  */
                double angle;               /*!< Angle of the region */

                vector<Point> polygon;      /*!< Polygon defining the region */

            public:
                
                Region(double area, double distanceFromOrigin,
                       double angle, const vector<Point> &polygon);
                ~Region();

                //! Get the angle
                double getAngle() const;

                //! Get the area
                double getArea() const;

                //! Get the distance from the origin
                double getDistanceFromOrigin() const;

                //! Get the polygon defining the region
                const vector<Point>& getPolygon() const;

                //! Get a string representation of all the field names except polygon
                string fieldNamesToString();

                //! Get a string representation of all the field values except polygon
                string toString();

        };

    };

};

#endif