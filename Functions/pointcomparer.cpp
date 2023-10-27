#include "PointComparer.h"

PointComparer::PointComparer() {}

double  PointComparer::GetPointWithSmallerY(double y1, double y2) {
    if (y1<y2)
        return 1;
    else
        return 0;
}

double PointComparer::GetPointWithGreaterY(double y1, double y2) {
    return (y1 > y2) ? 1 : 0;
}
