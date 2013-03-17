#ifndef REGIONDETECTOR_HPP_
#define REGIONDETECTOR_HPP_

#include "multiscale/analysis/spatial/Region.hpp"

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

using namespace std;
using namespace cv;

#define WIN_ORIGINAL_IMAGE  "Original image"
#define WIN_PROCESSED_IMAGE "Processed image"
#define WIN_EDGES_IN_IMAGE  "Edges in image"
#define WIN_CONTOURS        "Contours"
#define WIN_POLYGONS        "Polygons"

#define TRACKBAR_ALPHA              "Alpha"
#define TRACKBAR_BETA               "Beta"
#define TRACKBAR_KERNEL             "Gaussian blur kernel size"
#define TRACKBAR_MORPH              "Morphological open, number of iterations"
#define TRACKBAR_CANNY              "Canny lower threshold"
#define TRACKBAR_EPSILON            "Epsilon"
#define TRACKBAR_SECTOR_AREA_THRESH "Sector area threshold"
#define TRACKBAR_THRESHOLD          "Threshold value"

#define USE_CANNY_L2            true
#define CONTOUR_AREA_ORIENTED   false

#define ALPHA_REAL_MIN          1.0
#define ALPHA_REAL_MAX          3.0
#define BETA_REAL_MIN           -100
#define BETA_REAL_MAX           100

#define ALPHA_MAX               1000
#define BETA_MAX                200
#define KERNEL_MAX              100
#define ITER_MAX                100
#define CANNY_THRESH_MAX        100
#define EPSILON_MAX             100
#define SECTOR_AREA_THRESH_MAX  500
#define THRESHOLD_MAX           255
#define INTENSITY_MAX           255

#define KEY_ESC 27

#define PI  3.141592


namespace multiscale {

    namespace analysis {

        //! Class for detecting regions of high intensity in grayscale images
        class RegionDetector {

            private:

                int alpha;                          /*!< Alpha for brightness and contrast adjustments */
                int beta;                           /*!< Beta for brightness and contrast adjustments */
                int blurKernelSize;                 /*!< Kernel size for Gaussian blur */
                int morphologicalCloseIterations;   /*!< Number of iterations for morphological close operator */
                int epsilon;                        /*!< Epsilon for polygon approximation */
                int regionAreaThresh;               /*!< Threshold for considering a region */
                int thresholdValue;                 /*!< Value of the threshold for the threshold filter */

                Point origin;           /*!< The point representing the origin */

                unsigned int nrOfRows;  /*!< The number of rows in the image */
                unsigned int nrOfCols;  /*!< The number of columns in the image */

                string inputFilepath;   /*!< Path of the input file */
                string outputFilepath;  /*!< Path of the output file */

                bool isDebugMode;       /*!< Flag for determining the mode in which the detector runs */

            public:

                RegionDetector(const string &inputFilepath,
                               const string &outputFilepath,
                               bool debugMode = false);
                ~RegionDetector();

                //! Detect the regions in the image and output the results
                void detect();

            private:

                //! Initialise the vision members
                void initialiseVisionMembers();

                //! Initialise the members dependent on the image
                /*!
                 * \param image The image
                 */
                void initialiseImageDependentMembers(const Mat &image);

                //! Create the trackbars
                void createTrackbars();

                //! Detect the regions in the provided image
                /*!
                 * \param image The image
                 */
                void detectRegions(const Mat& image);

                //! Detect the regions in the provided image in debug mode
                /*!
                 * \param image The image
                 */
                void detectRegionsInDebugMode(const Mat& image, vector<Region> &regions);

                //! Detect the regions in the provided image in normal mode
                /*!
                 * \param image The image
                 */
                void detectRegionsInNormalMode(const Mat& image, vector<Region>& regions);

                //! Process the given image
                /*! Apply filters to the image, threshold it, find its contours,
                 *  approximate the polygons from these contours. Afterwards, process the polygons
                 *  to find their distance from the origin, their area and the angle determined
                 *  by the points from the contour which are on the edge and the closest point to
                 *  the origin. Return all the polygons together with the processed information
                 *  as a vector of regions.
                 *
                 *  \param image The image
                 *  \param regions The regions from the image
                 */
                void processImage(const Mat &image, vector<Region> &regions);

                //! Change the contrast and brightness of the image
                /*! Change the contrast and brightness of the image by the factors
                 *  alpha and gamma
                 *
                 *  \param originalImage The original image
                 *  \param processedImage The processed image
                 */
                void changeContrastAndBrightness(const Mat &originalImage, Mat &processedImage);

                //! Smooth out differences in the image
                /*! Apply a Gaussian blur filter
                 *
                 * \param image The image
                 */
                void smoothImage(Mat &image);

                //! Apply the morphological close operator on the image
                /*!
                 * \param image The image
                 */
                void morphologicalClose(Mat &image);

                //! Apply the threshold filter on the image
                /*!
                 * \param image The image
                 * \param thresholdedImage The thresholded image
                 */
                void thresholdImage(const Mat &image, Mat &thresholdedImage);

                //! Find the regions in the image
                /*! Find the contours, approximate the polygons and extract the required
                 * information from them.
                 *
                 * \param image The image
                 */
                void findRegions(const Mat &image, vector<Region>& regions);

                //! Find contours in image
                /*!
                 * \param image The image
                 */
                vector<vector<Point> > findContoursInImage(const Mat &image);

                //! Create a new region from the given polygon
                /*! Process the polygon in order to get the required information and
                 *  create a region using this information
                 *
                 * \param polygon Polygon determining the region
                 */
                Region createRegionFromPolygon(const vector<Point> &polygon);

                //! Check if the region is valid
                /*! Check if the area of the region > regionAreaThreshold
                 *
                 * \param polygon The polygon defining the region
                 */
                bool isValidRegion(const vector<Point> &polygon);

                //! Compute the angle of the polygon
                /*! Compute the angle determined by the points from the contour which are
                 *  on the edge and the closest point to the origin.
                 *
                 *  \param polygon Polygon determining the region
                 *  \param closestPointIndex Index of the closest point to the origin from the set of points defining the polygon
                 */
                double regionAngle(const vector<Point> &polygon, unsigned int closestPointIndex);

                //! Output the regions
                /*!
                 * \param image The image from which the regions were extracted
                 * \param regions The regions
                 */
                void outputRegions(const Mat &image, const vector<Region> &regions);

                //! Output the regions as an XML file
                /*!
                 * \param regions The regions
                 */
                void outputRegionsAsXMLFile(const vector<Region> &regions);

                //! Output the regions as a plain text file
                /*!
                 * \param regions The regions
                 */
                void outputRegionsAsPlainTextFile(const vector<Region> &regions);

                //! Output the regions in debug mode
                /*! Overlay the regions with the original image and display them. Also provide
                 * different trackbars/sliders to adjust the parameters
                 *
                 * \param image The image
                 * \param regions The regions
                 */
                void outputRegionsInDebugMode(const Mat &image, const vector<Region> &regions);

                //! Display an image in a particular window
                /*!
                 * \param image The image
                 * \param windowName The name of the window
                 */
                void displayImage(const Mat &image, const string &windowName);

                //! Convert alpha from the range [0, ALPHA_MAX] to [ALPHA_REAL_MIN, ALPHA_REAL_MAX]
                /*!
                 * \param alpha Alpha
                 */
                double convertAlpha(int alpha);

                //! Convert beta from the range [0, BETA_MAX] to [BETA_REAL_MIN, BETA_REAL_MAX]
                /*!
                 * \param beta Beta
                 */
                int convertBeta(int beta);

        };

    };

};

#endif
