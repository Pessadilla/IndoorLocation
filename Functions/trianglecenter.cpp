#include "trianglecenter.h"

TriangleCenter::TriangleCenter(double x1, double y1, double x2, double y2, double x3, double y3)
    : x1_(x1), y1_(y1), x2_(x2), y2_(y2), x3_(x3), y3_(y3) {}

void TriangleCenter::CalculateCenter() {
    center_x_ = (x1_ + x2_ + x3_) / 3.0;
    center_y_ = (y1_ + y2_ + y3_) / 3.0;
}

double TriangleCenter::GetCenterX() const {
    return center_x_;
}

double TriangleCenter::GetCenterY() const {
    return center_y_;
}
