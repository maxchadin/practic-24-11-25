#ifndef VECTOR_H
#define VECTOR_H

#include "planar.h"
#include "point.h"

struct Vector : Planar
{
  Vector(const Point& start, const Point& end);
  int x() const override;
  int y() const override;
  int abs_sqr() const override;
private:
  Point a;
  Point b;
};

#endif
