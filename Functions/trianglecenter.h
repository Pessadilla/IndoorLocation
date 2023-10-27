#ifndef TRIANGLECENTER_H
#define TRIANGLECENTER_H

class TriangleCenter {
public:
    TriangleCenter(double x1, double y1, double x2, double y2, double x3, double y3);

    void CalculateCenter();

    double GetCenterX() const;
    double GetCenterY() const;

private:
    double x1_, y1_, x2_, y2_, x3_, y3_;
    double center_x_, center_y_;
};

#endif
