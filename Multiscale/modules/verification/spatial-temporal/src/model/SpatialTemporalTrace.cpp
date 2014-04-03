#include "multiscale/util/Numeric.hpp"
#include "multiscale/util/StringManipulator.hpp"
#include "multiscale/verification/spatial-temporal/exception/SpatialTemporalException.hpp"
#include "multiscale/verification/spatial-temporal/model/SpatialTemporalTrace.hpp"

using namespace multiscale::verification;


SpatialTemporalTrace::SpatialTemporalTrace() {
    initialise();
}

SpatialTemporalTrace::SpatialTemporalTrace(const SpatialTemporalTrace &trace)
                                          : timePoints(trace.timePoints), lastTimePointValue(trace.lastTimePointValue),
                                            isLastTimePointValueInitialised(trace.isLastTimePointValueInitialised) {}

SpatialTemporalTrace::~SpatialTemporalTrace() {}

void SpatialTemporalTrace::addTimePoint(const TimePoint &timePoint) {
    validateTimePointValue(timePoint);

    timePoints.push_back(timePoint);

    updateLastTimePointValue(timePoints.back());
}

void SpatialTemporalTrace::clear() {
    initialise();
}

TimePoint SpatialTemporalTrace::getTimePoint(unsigned int index) const {
    validateIndex(index);

    return timePoints[index];
}

unsigned int SpatialTemporalTrace::length() const {
    return timePoints.size();
}

SpatialTemporalTrace SpatialTemporalTrace::subTrace(unsigned int startIndex) const {
    SpatialTemporalTrace subTrace;

    validateIndex(startIndex);
    addTimePointsToSubTrace(subTrace, startIndex, timePoints.size() - 1);

    return subTrace;
}

SpatialTemporalTrace SpatialTemporalTrace::subTrace(unsigned long startValue, unsigned long endValue) const {
    SpatialTemporalTrace subTrace;

    validateValues(startValue, endValue);
    getSubTrace(subTrace, startValue, endValue);

    return subTrace;
}

void SpatialTemporalTrace::initialise() {
    timePoints.clear();

    lastTimePointValue = 0;
    isLastTimePointValueInitialised = false;
}

void SpatialTemporalTrace::updateLastTimePointValue(TimePoint &timePoint) {
    unsigned long timePointValue = timePoint.getValue();

    if (timePointValue == numeric_limits<unsigned long>::max()) {
        timePoint.setValue(++lastTimePointValue);
    } else {
        lastTimePointValue = timePointValue;
    }
}

void SpatialTemporalTrace::validateTimePointValue(const TimePoint &timePoint) {
    unsigned long timePointValue = timePoint.getValue();

    validateTimePointValue(timePointValue);
}

void SpatialTemporalTrace::validateTimePointValue(unsigned long timePointValue) {
    if (isLastTimePointValueInitialised) {
        if (timePointValue <= lastTimePointValue) {
            MS_throw_detailed(SpatialTemporalException,
                              ERR_TIMEPOINT_VALUE_INVALID_START,
                              StringManipulator::toString<unsigned long>(timePointValue) +
                              ERR_TIMEPOINT_VALUE_INVALID_MIDDLE +
                              StringManipulator::toString<unsigned long>(lastTimePointValue),
                              ERR_TIMEPOINT_VALUE_INVALID_END);
        }
    } else {
        isLastTimePointValueInitialised = true;
    }
}

int SpatialTemporalTrace::indexOfFirstTimePointGreaterOrEqualToValue(unsigned long value) const {
    unsigned int nrOfTimePoints = timePoints.size();
    unsigned long currentValue = -1;

    for (unsigned int i = 0; i < nrOfTimePoints; i++) {
        currentValue = timePoints[i].getValue();

        if (currentValue >= value) {
            return i;
        }
    }

    return TIMEPOINT_INDEX_NOT_FOUND;
}

int SpatialTemporalTrace::indexOfLastTimePointLessOrEqualToValue(unsigned long value) const {
    unsigned int nrOfTimePoints = timePoints.size();
    unsigned long currentValue = -1;

    for (int i = (nrOfTimePoints - 1); i >= 0; i--) {
        currentValue = timePoints[i].getValue();

        if (currentValue <= value) {
            return i;
        }
    }

    return TIMEPOINT_INDEX_NOT_FOUND;
}

void SpatialTemporalTrace::getSubTrace(SpatialTemporalTrace &subTrace, unsigned long startValue,
                                       unsigned long endValue) const {
    int startIndex = indexOfFirstTimePointGreaterOrEqualToValue(startValue);
    int endIndex = indexOfLastTimePointLessOrEqualToValue(endValue);

    if (startIndex == TIMEPOINT_INDEX_NOT_FOUND) {
        // Do not add any timepoints to subTrace
    } else {
        if (endIndex == TIMEPOINT_INDEX_NOT_FOUND) {
            // Do not add any timepoints to subTrace
        } else {
            addTimePointsToSubTrace(subTrace, startIndex, timePoints.size() - 1);
        }
    }
}

void SpatialTemporalTrace::addTimePointsToSubTrace(SpatialTemporalTrace &subTrace,
                                                   int startIndex, int endIndex) const {
    for (int i = startIndex; i <= endIndex; i++) {
        subTrace.addTimePoint(timePoints[i]);
    }
}

void SpatialTemporalTrace::validateValues(unsigned long startValue, unsigned long endValue) const {
    validateValue(startValue);
    validateValue(endValue);

    if (endValue < startValue) {
        MS_throw_detailed(SpatialTemporalException, ERR_TIMEPOINT_END_START,
                          StringManipulator::toString<double>(endValue) +
                          ERR_TIMEPOINT_END_MIDDLE +
                          StringManipulator::toString<double>(startValue),
                          ERR_TIMEPOINT_END_END);
    }
}

void SpatialTemporalTrace::validateIndex(unsigned int index) const {
    if (index >= timePoints.size()) {
        MS_throw_detailed(SpatialTemporalException, ERR_TIMEPOINT_INDEX_OUT_OF_BOUNDS_START,
                          StringManipulator::toString<unsigned int>(index), ERR_TIMEPOINT_INDEX_OUT_OF_BOUNDS_END);
    }
}

void SpatialTemporalTrace::validateValue(unsigned long value) const {
    if (value > timePoints.back().getValue()) {
        MS_throw_detailed(SpatialTemporalException, ERR_TIMEPOINT_VALUE_OUT_OF_BOUNDS_START,
                          StringManipulator::toString<double>(value), ERR_TIMEPOINT_VALUE_OUT_OF_BOUNDS_END);
    }
}


// Constants
const std::string SpatialTemporalTrace::ERR_TIMEPOINT_INDEX_OUT_OF_BOUNDS_START = "The provided timepoint index (";
const std::string SpatialTemporalTrace::ERR_TIMEPOINT_INDEX_OUT_OF_BOUNDS_END   = ") is out of bounds for the given spatial temporal trace.";

const std::string SpatialTemporalTrace::ERR_TIMEPOINT_VALUE_OUT_OF_BOUNDS_START = "The provided timepoint value (";
const std::string SpatialTemporalTrace::ERR_TIMEPOINT_VALUE_OUT_OF_BOUNDS_END   = ") is out of bounds for the given spatial temporal trace.";

const std::string SpatialTemporalTrace::ERR_TIMEPOINT_END_START     = "The provided end timepoint (";
const std::string SpatialTemporalTrace::ERR_TIMEPOINT_END_MIDDLE    = ") should be greater or equal to the start timepoint  (";
const std::string SpatialTemporalTrace::ERR_TIMEPOINT_END_END       = ").";

const std::string SpatialTemporalTrace::ERR_TIMEPOINT_VALUE_INVALID_START   = "The current timepoint value (";
const std::string SpatialTemporalTrace::ERR_TIMEPOINT_VALUE_INVALID_MIDDLE  = ") should be greater than the previously added timepoint value (";
const std::string SpatialTemporalTrace::ERR_TIMEPOINT_VALUE_INVALID_END     = ").";

const std::string SpatialTemporalTrace::ERR_ITERATOR_NEXT   = "There is no next timepoint which the iterator can"
                                                              " return. Please use the hasNext() method before"
                                                              " to ensure there are further timepoints available"
                                                              " before calling the next() method.";

const int SpatialTemporalTrace::TIMEPOINT_INDEX_NOT_FOUND = -1;
