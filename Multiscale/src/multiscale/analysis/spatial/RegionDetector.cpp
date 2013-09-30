#include "multiscale/analysis/spatial/MatFactory.hpp"
#include "multiscale/analysis/spatial/factory/RectangularMatFactory.hpp"
#include "multiscale/analysis/spatial/RegionDetector.hpp"
#include "multiscale/util/NumericRangeManipulator.hpp"
#include "multiscale/util/Geometry2D.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace multiscale::analysis;


RegionDetector::RegionDetector(bool debugMode) : Detector(debugMode) {
    avgDensity = 0;
    avgClusterednessDegree = 0;

    alpha = 0;
    beta = 0;
    blurKernelSize = 0;
    morphologicalCloseIterations = 0;
    epsilon = 0;
    regionAreaThresh = 0;
    thresholdValue = 0;
}

RegionDetector::~RegionDetector() {}

int RegionDetector::getAlpha() {
    return alpha;
}

int RegionDetector::getBeta() {
    return beta;
}

int RegionDetector::getBlurKernelSize() {
    return blurKernelSize;
}

int RegionDetector::getMorphologicalCloseIterations() {
    return morphologicalCloseIterations;
}

int RegionDetector::getEpsilon() {
    return epsilon;
}

int RegionDetector::getRegionAreaThresh() {
    return regionAreaThresh;
}

int RegionDetector::getOriginXCoordinate() {
    return origin.x;
}

int RegionDetector::getOriginYCoordinate() {
    return origin.y;
}

int RegionDetector::getThresholdValue() {
    return thresholdValue;
}

vector<Region> const &RegionDetector::getRegions() {
    return regions;
}

void RegionDetector::setAlpha(int alpha) {
    if (!detectorSpecificFieldsInitialised) {
        detectorSpecificFieldsInitialised = true;
    }

    this->alpha = alpha;
}

void RegionDetector::setBeta(int beta) {
    if (!detectorSpecificFieldsInitialised) {
        detectorSpecificFieldsInitialised = true;
    }

    this->beta = beta;
}

void RegionDetector::setBlurKernelSize(int blurKernelSize) {
    if (!detectorSpecificFieldsInitialised) {
        detectorSpecificFieldsInitialised = true;
    }

    this->blurKernelSize = blurKernelSize;
}

void RegionDetector::setEpsilon(int epsilon) {
    if (!detectorSpecificFieldsInitialised) {
        detectorSpecificFieldsInitialised = true;
    }

    this->epsilon = epsilon;
}

void RegionDetector::setMorphologicalCloseIterations(int morphologicalCloseIterations) {
    if (!detectorSpecificFieldsInitialised) {
        detectorSpecificFieldsInitialised = true;
    }

    this->morphologicalCloseIterations = morphologicalCloseIterations;
}

void RegionDetector::setOriginXCoordinate(int originXCoordinate) {
    if (!detectorSpecificFieldsInitialised) {
        detectorSpecificFieldsInitialised = true;
    }

    this->origin.x = originXCoordinate;
}

void RegionDetector::setOriginYCoordinate(int originYCoordinate) {
    if (!detectorSpecificFieldsInitialised) {
        detectorSpecificFieldsInitialised = true;
    }

    this->origin.y = originYCoordinate;
}

void RegionDetector::setRegionAreaThresh(int regionAreaThresh) {
    if (!detectorSpecificFieldsInitialised) {
        detectorSpecificFieldsInitialised = true;
    }

    this->regionAreaThresh = regionAreaThresh;
}

void RegionDetector::setThresholdValue(int thresholdValue) {
    if (!detectorSpecificFieldsInitialised) {
        detectorSpecificFieldsInitialised = true;
    }

    this->thresholdValue = thresholdValue;
}

void RegionDetector::initialiseDetectorSpecificFields() {
    alpha = 750;
    beta = 0;
    blurKernelSize = 15;
    morphologicalCloseIterations = 1;
    epsilon = 1;
    regionAreaThresh = 30000;
    thresholdValue = 100;
}

void RegionDetector::initialiseDetectorSpecificImageDependentFields() {}

void RegionDetector::createDetectorSpecificTrackbars() {
    createTrackbar(TRACKBAR_ALPHA, WIN_OUTPUT_IMAGE, &alpha, ALPHA_MAX, nullptr, nullptr);
    createTrackbar(TRACKBAR_BETA, WIN_OUTPUT_IMAGE, &beta, BETA_MAX, nullptr, nullptr);
    createTrackbar(TRACKBAR_KERNEL, WIN_OUTPUT_IMAGE, &blurKernelSize, KERNEL_MAX, nullptr, nullptr);
    createTrackbar(TRACKBAR_MORPH, WIN_OUTPUT_IMAGE, &morphologicalCloseIterations, ITER_MAX, nullptr, nullptr);
    createTrackbar(TRACKBAR_EPSILON, WIN_OUTPUT_IMAGE, &epsilon, EPSILON_MAX, nullptr, nullptr);
    createTrackbar(TRACKBAR_REGION_AREA_THRESH, WIN_OUTPUT_IMAGE, &regionAreaThresh, REGION_AREA_THRESH_MAX, nullptr, nullptr);
    createTrackbar(TRACKBAR_THRESHOLD, WIN_OUTPUT_IMAGE, &thresholdValue, THRESHOLD_MAX, nullptr, nullptr);
}

void RegionDetector::processImageAndDetect() {
    Mat processedImage, thresholdedImage;

    changeContrastAndBrightness(processedImage);
    morphologicalClose(processedImage);
    smoothImage(processedImage);
    thresholdImage(processedImage, thresholdedImage);
    findRegions(thresholdedImage, regions);

    computeAverageMeasures(regions);
}

void RegionDetector::changeContrastAndBrightness(Mat &processedImage) {
    image.convertTo(processedImage, -1, convertAlpha(alpha), convertBeta(beta));
}

void RegionDetector::smoothImage(Mat &image) {
    if (blurKernelSize % 2) {
        GaussianBlur(image, image, Size(blurKernelSize, blurKernelSize), 0);
    } else {
        GaussianBlur(image, image, Size(blurKernelSize + 1, blurKernelSize + 1), 0);
    }
}

void RegionDetector::morphologicalClose(Mat &image) {
    if (morphologicalCloseIterations > 0) {
        morphologyEx(image, image, MORPH_CLOSE, Mat(), Point(-1, -1), morphologicalCloseIterations);
    }
}

void RegionDetector::thresholdImage(const Mat &image, Mat &thresholdedImage) {
    threshold(image, thresholdedImage, thresholdValue, THRESHOLD_MAX, THRESH_BINARY);
}

void RegionDetector::findRegions(const Mat &image, vector<Region> &regions) {
    vector<vector<Point> > contours = findContoursInImage(image);

    for (const vector<Point> &contour : contours) {
        if (!isValidRegion(contour)) {
            continue;
        }

        // Obtain the approximated polygon
        vector<Point> approxPolygon;

        approxPolyDP(contour, approxPolygon, epsilon, true);

        // Process and store information about the region
        regions.push_back(createRegionFromPolygon(approxPolygon));
    }
}

void RegionDetector::computeAverageMeasures(vector<Region> &regions) {
    avgClusterednessDegree = 0;
    avgDensity = 0;

    for (Region &region : regions) {
        avgClusterednessDegree += region.getClusterednessDegree();
        avgDensity += region.getDensity();
    }

    avgClusterednessDegree /= regions.size();
    avgDensity /= regions.size();
}

vector<vector<Point> > RegionDetector::findContoursInImage(const Mat &image) {
    // Two extra pixels required for each dimension, because the contour detection
    // algorithm ignores the first and last lines and columns of the image matrix. In order
    // to consider the entire input image we add blank first and last lines and columns
    // to the image matrix
    Mat modifiedImage = Mat::zeros(image.rows + 2, image.cols + 2, image.type());
    vector<vector<Point> > contours;

    image.copyTo(modifiedImage(Rect(1, 1, image.cols, image.rows)));

    findContours(modifiedImage, contours, CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

    return contours;
}

Region RegionDetector::createRegionFromPolygon(const vector<Point> &polygon) {
    unsigned int minDistancePointIndex = Geometry2D::minimumDistancePointIndex(polygon, origin);

    double clusterednessDegree = regionClusterednessDegree(polygon);
    double density = regionDensity(polygon);
    double area = regionArea(polygon);
    double distance = Geometry2D::distanceBtwPoints(polygon[minDistancePointIndex], origin);
    double angle = polygonAngle(polygon, minDistancePointIndex);

    return Region(clusterednessDegree, density, area, distance, angle, polygon);
}

bool RegionDetector::isValidRegion(const vector<Point> &polygon) {
    double area = contourArea(polygon, CONTOUR_AREA_ORIENTED);

    return (area >= regionAreaThresh);
}

double RegionDetector::regionClusterednessDegree(const vector<Point> &polygon) {
    Mat mask(Mat::zeros(image.rows, image.cols, image.type()));
    Mat thresholdedImage;

    drawContours(mask, vector<vector<Point>>(1, polygon), -1, Scalar(INTENSITY_MAX, INTENSITY_MAX, INTENSITY_MAX), CV_FILLED);
    threshold(image, thresholdedImage, THRESHOLD_CLUSTEREDNESS, THRESHOLD_MAX, THRESH_BINARY);

    double averageIntensity = (mean(thresholdedImage, mask))[0];

    return (averageIntensity / static_cast<double>(INTENSITY_MAX));
}

double RegionDetector::regionDensity(const vector<Point> &polygon) {
    Mat mask(Mat::zeros(image.rows, image.cols, image.type()));

    drawContours(mask, vector<vector<Point>>(1, polygon), -1, Scalar(INTENSITY_MAX, INTENSITY_MAX, INTENSITY_MAX), CV_FILLED);

    double averageIntensity = (mean(image, mask))[0];

    return (averageIntensity / static_cast<double>(INTENSITY_MAX));
}

double RegionDetector::regionArea(const vector<Point> &polygon) {
    Mat mask(Mat::zeros(image.rows, image.cols, image.type()));
    Mat thresholdedImage, regionHoles;

    drawContours(mask, vector<vector<Point>>(1, polygon), -1, Scalar(INTENSITY_MAX), CV_FILLED);
    threshold(image, thresholdedImage, THRESHOLD_CLUSTEREDNESS, THRESHOLD_MAX, THRESH_BINARY);
    bitwise_not(thresholdedImage, regionHoles, mask);

    return (contourArea(polygon, CONTOUR_AREA_ORIENTED) - regionHolesArea(regionHoles));
}

double RegionDetector::regionHolesArea(const Mat &matrix) {
    vector<vector<Point> > contours = findContoursInImage(matrix);
    double area = 0;

    for (const vector<Point> &contour : contours) {
        area += contourArea(contour, CONTOUR_AREA_ORIENTED);
    }

    return area;
}

void RegionDetector::clearPreviousDetectionResults() {
    regions.clear();
}

void RegionDetector::outputResultsToCsvFile(ofstream &fout) {
    // Output header
    fout << Region::fieldNamesToString() << endl;

    if (!regions.empty()) {
        outputRegionsToCsvFile(fout);

        // Add an empty line between the region data and the averaged data
        fout << endl;

        outputAveragedMeasuresToCsvFile(fout);
    }
}

void RegionDetector::outputRegionsToCsvFile(ofstream &fout) {
    for (auto region : regions) {
        fout << region.toString() << endl;
    }
}

void RegionDetector::outputAveragedMeasuresToCsvFile(ofstream &fout) {
    fout << OUTPUT_CLUSTEREDNESS << avgClusterednessDegree << endl
         << OUTPUT_DENSITY << avgDensity << endl;
}

void RegionDetector::outputResultsToImage() {
    // Two extra pixels required for each dimension, because the contour detection
    // algorithm ignores the first and last lines and columns of the image matrix. In order
    // to consider the entire input image we add blank first and last lines and columns
    // to the image matrix
    Mat outputImage = Mat::zeros(image.rows + 2, image.cols + 2, image.type());

    image.copyTo(outputImage(Rect(1, 1, image.cols, image.rows)));

    cvtColor(outputImage, outputImage, CV_GRAY2BGR);

    for (Region &region : regions) {
        polylines(outputImage, region.getPolygon(), POLYGON_CLOSED, Scalar(INTENSITY_MAX, 0, 0), DISPLAY_LINE_THICKNESS);
    }

    outputImage(Rect(1, 1, image.cols, image.rows)).copyTo(this->outputImage);
}

double RegionDetector::convertAlpha(int alpha) {
    return NumericRangeManipulator::convertFromRange<int, double>(0, ALPHA_MAX, ALPHA_REAL_MIN, ALPHA_REAL_MAX, alpha);
}

int RegionDetector::convertBeta(int beta) {
    return NumericRangeManipulator::convertFromRange<int, int>(0, BETA_MAX, BETA_REAL_MIN, BETA_REAL_MAX, beta);
}

void convertVertices(const Point *src, vector<Point> &dst) {
    dst.clear();

    for (int i = 0; i < ENCLOSING_RECT_VERTICES; i++) {
      dst.push_back(src[i]);
    }
}
