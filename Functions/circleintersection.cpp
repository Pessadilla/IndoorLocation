#include "circleintersection.h"
#include <cmath>

CircleIntersection::CircleIntersection(double x1, double y1, double r1, double x2, double y2, double r2)
    : x1_(x1), y1_(y1), r1_(r1), x2_(x2), y2_(y2), r2_(r2) {}

void CircleIntersection::CalculateIntersection() {
    double d = DistanceBetweenCenters();

    if (d > r1_ + r2_ || d <= std::abs(r1_ - r2_)) {
        intersection_ = false;
        return;
    }

    double a = (r1_ * r1_ - r2_ * r2_ + d * d) / (2 * d);
    double h = sqrt(r1_ * r1_ - a * a);

    double x = x1_ + (a * (x2_ - x1_)) / d;
    double y = y1_ + (a * (y2_ - y1_)) / d;

    x3_ = x + (h * (y2_ - y1_)) / d;
    y3_ = y - (h * (x2_ - x1_)) / d;
    x4_ = x - (h * (y2_ - y1_)) / d;
    y4_ = y + (h * (x2_ - x1_)) / d;
    intersection_ = true;
}

bool CircleIntersection::HasIntersection() const {
    return intersection_;
}

double CircleIntersection::GetX1() const {
    return y3_;
}

double CircleIntersection::GetY1() const {
    return x3_;
}

double CircleIntersection::GetX2() const {
    return y4_;
}

double CircleIntersection::GetY2() const {
    return x4_;
}

double CircleIntersection::DistanceBetweenCenters() const {
    return sqrt((x2_ - x1_) * (x2_ - x1_) + (y2_ - y1_) * (y2_ - y1_));
}
