#ifndef CIRCLEINTERSECTION_H
#define CIRCLEINTERSECTION_H

class CircleIntersection {
public:
    CircleIntersection(double x1, double y1, double r1, double x2, double y2, double r2);

    void CalculateIntersection();

    bool HasIntersection() const;

    double GetX1() const;
    double GetY1() const;
    double GetX2() const;
    double GetY2() const;

private:
    double DistanceBetweenCenters() const;

    double x1_, y1_, r1_, x2_, y2_, r2_;
    double x3_, y3_, x4_, y4_;
    bool intersection_;
};

#endif
