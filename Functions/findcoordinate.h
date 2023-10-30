#ifndef FINDCOORDINATE_H
#define FINDCOORDINATE_H
#include <Functions/circleintersection.h>
#include <Functions/pointcomparer.h>
#include <Functions/trianglecenter.h>
#include <iostream>

class FindCoordinate
{
public:
    FindCoordinate(double x1, double y1, double r1, double x2, double y2, double r2, double x3, double y3, double r3);
};

#endif // FINDCOORDINATE_H
