#ifndef POINT_H
#define POINT_H

#include "planar.h"

struct Point : Planar
{
  int x() const override;
  int y() const override;
  int abs_sqr() const override;
  Point(int xx, int yy);
private:
  int data[2];
};

#endif
