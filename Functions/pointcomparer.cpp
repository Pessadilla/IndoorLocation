#include "PointComparer.h"

PointComparer::PointComparer() {}

double PointComparer::GetPointWithSmallerY(double y1, double y2) {
    return (y1 < y2) ? y1 : y2;
}

double PointComparer::GetPointWithGreaterY(double y1, double y2) {
    return (y1 > y2) ? y1 : y2;
}
