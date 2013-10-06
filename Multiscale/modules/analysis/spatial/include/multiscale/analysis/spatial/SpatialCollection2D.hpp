#ifndef SPATIALCOLLECTION2D_HPP
#define SPATIALCOLLECTION2D_HPP

#include "multiscale/analysis/spatial/Shape2D.hpp"

#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;


namespace multiscale {

    namespace analysis {

        //! Class for representing a collection of objects in 2D space
        class SpatialCollection2D {

            protected:

                double clusterednessDegree;     /*!< Degree of clusteredness */

                double area;                    /*!< Area of the spatial collection */
                double perimeter;               /*!< Perimeter of the spatial collection */

                double distanceFromOrigin;      /*!< Distance from the origin  */
                double angle;                   /*!< Angle of the region wrt the origin */

                double triangularMeasure;       /*!< Measure ([0, 1]) indicating that the shape of the spatial collection is triangular */
                double rectangularMeasure;      /*!< Measure ([0, 1]) indicating that the shape of the spatial collection is rectangular */
                double circularMeasure;         /*!< Measure ([0, 1]) indicating that the shape of the spatial collection is circular */

                Shape2D shape;                  /*!< Shape of the spatial collection */
                Point2f centre;                 /*!< Point defining the centre of the spatial collection */

                bool updateFlag;                /*!< Flag indicating if the field values dependent on the
                                                     collection of entities need to be updated. This flag is
                                                     used for lazy evaluation purposes, such that new field
                                                     values are computed only when required*/

            public:

                SpatialCollection2D();
                virtual ~SpatialCollection2D();

                //! Get the clusteredness degree
                double getClusterednessDegree();

                //! Get the area
                double getArea();

                //! Get the perimeter
                double getPerimeter();

                //! Get the distance from the origin
                double getDistanceFromOrigin();

                //! Get the angle
                double getAngle();

                //! Get the shape best fitting the spatial collection
                Shape2D getShape();

                //! Get the point defining the centre of the entity
                Point2f getCentre();

                //! Get the string representation of all field values
                string toString();

            protected:

                //! Update the values of all measures if required
                void updateMeasuresIfRequired();

                //! Update the values of all measures
                void updateMeasures();

                //! Update the values of all measures specific to the derived classes
                virtual void updateSpatialCollectionSpecificValues() = 0;

                //! Update the value of the clusteredness degree
                virtual void updateClusterednessDegree() = 0;

                //! Update the value of the area
                virtual void updateArea() = 0;

                //! Update the value of the perimeter
                virtual void updatePerimeter() = 0;

                //! Update the shape of the cluster
                void updateShape();

                //! Update the point defining the centre of the cluster
                virtual void updateCentrePoint() = 0;

                //! Get the measure that the cluster has a triangular shape
                virtual double isTriangularMeasure() = 0;

                //! Get the measure that the cluster has a rectangular shape
                virtual double isRectangularMeasure() = 0;

                //! Get the measure that the cluster has a circular shape
                virtual double isCircularMeasure() = 0;

                //! Return the shape of the cluster as a string
                string shapeAsString();

                //! Return the values of the fields as a string
                virtual string fieldValuesToString() = 0;

                //! Convert the collection of points from type Point to type Point2f
                /*!
                 * \param points Collection of points
                 */
                vector<Point2f> convertPoints(const vector<Point> &points);

            private:

                //! Initialisation function for the class
                void initialise();

            protected:

                // Constants
                static const string STR_TRIANGLE;
                static const string STR_RECTANGLE;
                static const string STR_CIRCLE;
                static const string STR_UNDEFINED;

                static const string OUTPUT_SEPARATOR;

                static const string ERR_INPUT;

                static const bool CONVEX_HULL_CLOCKWISE;

        };

    };

};

#endif