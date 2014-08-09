#ifndef DETECTOR_HPP
#define DETECTOR_HPP

#include "multiscale/analysis/spatial/SpatialEntityPseudo3D.hpp"

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

#include <fstream>

namespace pt = boost::property_tree;

using namespace cv;
using namespace std;


namespace multiscale {

    namespace analysis {

        //! Abstract class for detecting entities of interest in images
        class Detector {

            protected:

                double avgClusterednessDegree;      /*!< For regions:
                                                         Average degree of clusteredness of all regions

                                                         For clusters:
                                                         Index of clusteredness for all clusters */
                double avgDensity;                  /*!< For regions:
                                                         Average density of all regions

                                                         For clusters:
                                                         Average pile up degree of all clusters */

                Mat image;                      /*!< Input image */
                string outputFilepath;          /*!< Path of the output file */
                bool debugMode;                 /*!< Flag for indicating if debug mode is set */

                Mat outputImage;                /*!< Image for displaying the results */

                bool detectMethodCalled;                /*!< Flag for indicating if the detect method was called */
                bool detectorSpecificFieldsInitialised; /*!< Flag for indicating if the parameters were */

                Point origin;                   /*!< The point representing the origin */

            public:

                Detector(bool debugMode = false);
                virtual ~Detector();

                //! Run the detection procedure on the given image
                /*!
                 * \param inputImage The input image
                 */
                void detect(const Mat &inputImage);

                //! Output the results to the given file
                /*!
                 * \param outputFilepath Path to the output file
                 */
                void outputResults(const string &outputFilepath);

            protected:

                //! Initialisation function for the class
                void initialise();

                //! Initialisation of the detector specific values in case they were not set
                void initialiseDetectorSpecificFieldsIfNotSet();

                //! Set the detector specific fields initialisation flag to true
                void setDetectorSpecificFieldsInitialisationFlag(bool flag = true);

                //! Initialisation of the detector specific values
                virtual void initialiseDetectorSpecificFields() = 0;

                //! Initialisation of the image dependent values
                void initialiseImageDependentFields();

                //! Initialisation of the detector specific image dependent values
                virtual void initialiseDetectorSpecificImageDependentFields() = 0;

                // Initialisation function for the image origin
                void initialiseImageOrigin();

                //! Check if the image is valid
                /*!
                 * Check if the number of dimensions = 2,  if the
                 * number of rows and number of columns is greater than one
                 * and if the image is of type CV_8UC1
                 *
                 * \param inputImage The input image
                 */
                bool isValidInputImage(const Mat& inputImage);

                //! Get the type of the employed detector as a string
                virtual string getDetectorTypeAsString() = 0;

                //! Run the detection procedure
                void detect();

                //! Run the detection procedure when in debug mode
                void detectInDebugMode();

                //! Run the detection procedure when in release mode (i.e. non-debug mode)
                void detectInReleaseMode();

                //! Compute the angle of the polygon
                /*! Compute the angle determined by the closest point to the origin and the points P1 and P2.
                 * These points are obtained from the intersection of the polygon with the line  which is
                 * orthogonal to the line AB where:
                 *      - Point A is the polygon point closest to the origin;
                 *      - Point B is the centre point of the bounding rotated rectangle.
                 *
                 *  \param polygon              Given polygon
                 *  \param closestPointIndex    Index of the closest point to the origin from the set of points defining the polygon
                 */
                double polygonAngle(const vector<Point> &polygon, unsigned int closestPointIndex);

                //! Compute the angle of the polygon
                /*! Compute the angle determined by the closest point to the origin and the points P1 and P2.
                 * These points are obtained from the intersection of the convex hull with the line AB, determined
                 * by points A and B. Points A and B are the middle points of the sides of the rotated rectangle enclosing
                 * the polygon that are orthogonal to the line which is the nearest to the closestPoint.
                 *
                 *  \param polygonConvexHull    Convex hull of polygon
                 *  \param closestPoint         Closest point to the origin from the set of points defining the polygon
                 */
                double polygonAngle(const vector<Point> &polygonConvexHull, const Point &closestPoint);

                //! Get the centre of the minimum area bounding rectangle
                /*!
                 * \param polygon   The polygon
                 * \param centre    The centre of the bounding rectangle
                 */
                void minAreaRectCentre(const vector<Point> &polygon, Point &centre);

                //! Find the points for determining the angle of the polygon
                /*!
                 *  \param polygonConvexHull    Convex hull of polygon
                 *  \param boundingRectCentre   Centre of the rotated rectangle enclosing the polygon convex hull
                 *  \param closestPoint         Closest point to the origin from the set of points defining the polygon
                 *  \param goodPointsForAngle   The points which are relevant for computing the angle
                 */
                void findGoodPointsForAngle(const vector<Point> &polygonConvexHull, const Point &boundingRectCentre,
                                            const Point &closestPoint, vector<Point> &goodPointsForAngle);

                //! Find good intersection points for computing the angle of the polygon
                /*!
                 * \param polygonConvexHull     The convex hull of the polygon
                 * \param edgePointA            Point A on the edge
                 * \param edgePointB            Point B on the edge
                 * \param goodPointsForAngle    The "good" points for computing the angle
                 */
                void findGoodIntersectionPoints(const vector<Point> &polygonConvexHull, const Point &edgePointA,
                                                const Point &edgePointB, vector<Point> &goodPointsForAngle);


                //! Display the results in a window
                void displayResultsInWindow();

                //! Output the results to file(s)
                void outputResultsToFile();

                //! Output the results to an image
                virtual void outputResultsToImage() = 0;

                //! Store the image with the output results on disk
                void storeOutputImageOnDisk();

                //! Output the results to a csv file
                void outputResultsToCsvFile();

                //! Output the results to a file using the provided output file stream
                /*!
                 * \param fout Output file stream
                 */
                void outputResultsToCsvFile(ofstream &fout);

                //! Output the pseudo 3D spatial entities to a csv file
                /*!
                 * \param fout Output file stream
                 */
                void outputSpatialEntitiesToCsvFile(ofstream &fout);

                //! Output the averaged measures to a csv file
                /*!
                 * \param fout Output file stream
                 */
                void outputAveragedMeasuresToCsvFile(ofstream &fout);

                //! Output the results to an xml file
                void outputResultsToXMLFile();

                //! Output the clusters and averaged measures to an xml file
                /*!
                 * \param filepath Output file path
                 */
                void outputResultsToXMLFile(const string &filepath);

                //! Add the pseudo 3D spatial entities to the property tree
                /*!
                 * \param propertyTree The property tree
                 */
                void addSpatialEntitiesToPropertyTree(pt::ptree &propertyTree);

                //! Add the average clusteredness and average density to the property tree
                /*!
                 * \param propertyTree The property tree
                 */
                void addAverageMeasuresToPropertyTree(pt::ptree &propertyTree);

                //! Add a numeric state variable to the property tree
                /*!
                 * \param propertyTree  The property tree
                 * \param name          The name of the numeric state variable
                 * \param value         The value of the numeric state variable
                 */
                void addNumericStateVariableToPropertyTree(pt::ptree &propertyTree,
                                                           const string &name, double value);

                //! Construct the property tree corresponding to the given spatial entity
                /*!
                 * \param spatialEntity The spatial entity to be converted
                 */
                pt::ptree constructSpatialEntityPropertyTree(SpatialEntityPseudo3D &spatialEntity);

                //! Add the properties of the spatial entity to the property tree
                /*!
                 * \param spatialEntity Spatial entity
                 * \param propertyTree  Property tree
                 */
                void addSpatialEntityPropertiesToTree(SpatialEntityPseudo3D &spatialEntity, pt::ptree &propertyTree);

                //! Add the type of the spatial entity to the property tree
                /*!
                 * \param spatialEntity Spatial entity
                 * \param propertyTree  Property tree
                 */
                void addSpatialEntityTypeToPropertyTree(SpatialEntityPseudo3D &spatialEntity, pt::ptree &propertyTree);

                //! Get the collection of pseudo 3D entities detected in the image
                virtual vector<shared_ptr<SpatialEntityPseudo3D>> getCollectionOfSpatialEntityPseudo3D() = 0;

                //! Process the input image and detect objects/entities of interest
                virtual void processImageAndDetect() = 0;

                //! Clear the results from the previous detection
                virtual void clearPreviousDetectionResults() = 0;

                //! Create the trackbars which allow the user to change the values of the parameters
                void createTrackbars();

                //! Create the window in which the trackbars are placed
                void createTrackbarsWindow();

                //! Create the trackbars specific to the used detector
                virtual void createDetectorSpecificTrackbars() = 0;

                //! Process the request of the user by pressing the key
                /*!
                 * \param pressedKey Key pressed by the user, if a key was pressed, or "-1", otherwise
                 */
                void processPressedKeyRequest(char &pressedKey);

                //! Display an image in a particular window
                /*!
                 * \param image The image
                 * \param windowName The name of the window
                 */
                void displayImage(const Mat &image, const string &windowName);

                //! Print error message, because the detect method was not called before calling the output method
                void printOutputErrorMessage();

            protected:

                // Constants
                static const string OUTPUT_CLUSTEREDNESS;
                static const string OUTPUT_DENSITY;

                static const string ERR_OUTPUT_WITHOUT_DETECT;
                static const string ERR_OUTPUT_FILE;
                static const string ERR_INVALID_IMAGE;

                static const string CSV_EXTENSION;
                static const string IMG_EXTENSION;
                static const string XML_EXTENSION;

                static const string WIN_OUTPUT_IMAGE;

                static const int KEY_ESC;
                static const int KEY_SAVE;

                static const string LABEL_ATTRIBUTE;
                static const string LABEL_COMMENT;

                static const string LABEL_COMMENT_CONTENTS;

                static const string LABEL_EXPERIMENT_TIMEPOINT_NUMERIC_STATE_VARIABLE;
                static const string LABEL_EXPERIMENT_TIMEPOINT_SPATIAL_ENTITY;

                static const string LABEL_EXPERIMENT_TIMEPOINT_NUMERIC_STATE_VARIABLE_NAME;
                static const string LABEL_EXPERIMENT_TIMEPOINT_NUMERIC_STATE_VARIABLE_VALUE;

                static const string LABEL_SPATIAL_ENTITY_SPATIAL_TYPE;
                static const string LABEL_SPATIAL_ENTITY_CLUSTEREDNESS;
                static const string LABEL_SPATIAL_ENTITY_DENSITY;
                static const string LABEL_SPATIAL_ENTITY_AREA;
                static const string LABEL_SPATIAL_ENTITY_PERIMETER;
                static const string LABEL_SPATIAL_ENTITY_DISTANCE_FROM_ORIGIN;
                static const string LABEL_SPATIAL_ENTITY_ANGLE;
                static const string LABEL_SPATIAL_ENTITY_TRIANGLE_MEASURE;
                static const string LABEL_SPATIAL_ENTITY_RECTANGLE_MEASURE;
                static const string LABEL_SPATIAL_ENTITY_CIRCLE_MEASURE;
                static const string LABEL_SPATIAL_ENTITY_CENTROID_X;
                static const string LABEL_SPATIAL_ENTITY_CENTROID_Y;

                static const string LABEL_AVG_CLUSTEREDNESS;
                static const string LABEL_AVG_DENSITY;

        };

    };

};


#endif
