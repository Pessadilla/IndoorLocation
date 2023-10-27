#ifndef POINTCOMPARER_H
#define POINTCOMPARER_H

class PointComparer {
public:
    PointComparer();

    double GetPointWithSmallerY(double y1, double y2);
    double GetPointWithGreaterY(double y1, double y2);
};

#endif // POINTCOMPARER_H
