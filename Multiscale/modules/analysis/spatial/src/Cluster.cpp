#include "multiscale/analysis/spatial/CircularityMeasure.hpp"
#include "multiscale/analysis/spatial/Cluster.hpp"
#include "multiscale/exception/InvalidInputException.hpp"
#include "multiscale/util/Geometry2D.hpp"
#include "multiscale/util/MinEnclosingTriangleFinder.hpp"
#include "multiscale/util/StringManipulator.hpp"

using namespace multiscale::analysis;


Cluster::Cluster() {
    initialise();
}

Cluster::~Cluster() {}

void Cluster::addEntity(const Entity &entity) {
    entities.push_back(entity);

    updateFlag = true;
}

vector<Point2f> Cluster::getMinAreaEnclosingTriangle() {
    updateMeasuresIfRequired();

    return minAreaEnclosingTriangle;
}

RotatedRect Cluster::getMinAreaEnclosingRect() {
    updateMeasuresIfRequired();

    return minAreaEnclosingRect;
}

Point2f Cluster::getMinAreaEnclosingCircleCentre() {
    updateMeasuresIfRequired();

    return minAreaEnclosingCircleCentre;
}

float Cluster::getMinAreaEnclosingCircleRadius() {
    updateMeasuresIfRequired();

    return minAreaEnclosingCircleRadius;
}

vector<Entity> Cluster::getEntities() const {
    return entities;
}

vector<Point2f> Cluster::getEntitiesConvexHull() {
    vector<Point2f> entitiesContourPoints = getEntitiesContourPoints();
    vector<Point2f> entitiesConvexHull;

    if (entities.size() > 0) {
        convexHull(entitiesContourPoints, entitiesConvexHull, CONVEX_HULL_CLOCKWISE);
    }

    return entitiesConvexHull;
}

void Cluster::setOriginDependentMembers(double distanceFromOrigin, double angleWrtOrigin) {
    validateOriginDependentValues(distanceFromOrigin, angleWrtOrigin);

    this->distanceFromOrigin = distanceFromOrigin;
    this->angle = angleWrtOrigin;
}

void Cluster::initialise() {
    this->clusterednessDegree = 0;
    this->density = 0;

    this->distanceFromOrigin = 0;
    this->angle = 0;

    this->minAreaEnclosingCircleRadius = 0;

    this->updateFlag = false;

    minAreaEnclosingTriangle.clear();
    entities.clear();
}

vector<Point2f> Cluster::getEntitiesCentrePoints() {
    vector<Point2f> centrePoints;

    for (const Entity& entity : entities) {
        centrePoints.push_back(entity.getCentre());
    }

    return centrePoints;
}

vector<Point2f> Cluster::getEntitiesContourPoints() {
    vector<Point2f> contourPoints;

    for (const Entity& entity : entities) {
        vector<Point2f> entityContourPoints = entity.getContourPoints();

        contourPoints.insert(contourPoints.begin(), entityContourPoints.begin(), entityContourPoints.end());
    }

    return contourPoints;
}

void Cluster::updateClusterednessDegree() {
    double totalAvgDistance = 0;

    for (Entity &e1 : entities) {
        double avgDistance = 0;

        for (Entity &e2 : entities) {
            avgDistance += e1.distanceTo(e2);
        }

        totalAvgDistance += (entities.size() == 1) ? 0
                                                   : avgDistance / (entities.size());
    }

    totalAvgDistance /= (entities.size());

    clusterednessDegree = (totalAvgDistance != 0) ? (1 / totalAvgDistance)
                                                  : 1;
}

void Cluster::updateDensity() {
    density = 0;

    for (const Entity &entity : entities) {
        density += entity.getPileUpDegree();
    }

    density /= (entities.size());
}

void Cluster::updateArea() {
    area = 0;

    for (const Entity &entity : entities) {
        area += entity.getArea();
    }
}

void Cluster::updatePerimeter() {
    vector<Point2f> entitiesConvexHull = getEntitiesConvexHull();

    perimeter = arcLength(entitiesConvexHull, true);
}

void Cluster::updateCentrePoint() {
    centre *= 0;

    for (const Entity &entity : entities) {
        centre += entity.getCentre();
    }

    centre.x /= entities.size();
    centre.y /= entities.size();
}

double Cluster::isTriangularMeasure() {
    vector<Point2f> entitiesConvexHull = getEntitiesConvexHull();

    double triangleArea = MinEnclosingTriangleFinder().find(entitiesConvexHull, minAreaEnclosingTriangle);

    return normalisedShapeMeasure(triangleArea);
}

double Cluster::isRectangularMeasure() {
    vector<Point2f> entitiesContourPoints = getEntitiesContourPoints();

    minAreaEnclosingRect = minAreaRect(entitiesContourPoints);

    // Compute the area of the minimum area enclosing rectangle
    double rectangleArea = minAreaEnclosingRect.size.height * minAreaEnclosingRect.size.width;

    return normalisedShapeMeasure(rectangleArea);
}

double Cluster::isCircularMeasure() {
    vector<Point2f> entitiesContourPoints = getEntitiesContourPoints();

    minEnclosingCircle(entitiesContourPoints, minAreaEnclosingCircleCentre, minAreaEnclosingCircleRadius);

    // Compute the area of the minimum area enclosing circle
    double circleArea = Geometry2D::PI * minAreaEnclosingCircleRadius * minAreaEnclosingCircleRadius;

    return normalisedShapeMeasure(circleArea);
}

SpatialEntityPseudo3DType Cluster::type() {
    return SpatialEntityPseudo3DType::Cluster;
}

void Cluster::validateOriginDependentValues(double distanceFromOrigin, double angleWrtOrigin) {
    if (!areValidOriginDependentValues(distanceFromOrigin, angleWrtOrigin)) {
        MS_throw(InvalidInputException, ERR_ORIGIN_DEPENDENT_VALUES);
    }
}

bool Cluster::areValidOriginDependentValues(double distanceFromOrigin, double angleWrtOrigin) {
    return (
      (Numeric::greaterOrEqual(distanceFromOrigin, 0)) &&
      (Numeric::greaterOrEqual(angleWrtOrigin, 0))
    );
}


// Constants
const string Cluster::ERR_UNDEFINED_SHAPE         = "The shape of the given cluster is undefined.";
const string Cluster::ERR_ORIGIN_DEPENDENT_VALUES = "The origin dependent values are invalid (i.e. negative).";
