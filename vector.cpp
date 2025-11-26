#include "vector.h"

Vector::Vector(const Point& start, const Point& end)
  : a(start), b(end)
{}

int Vector::x() const
{
  return b.x() - a.x();
}

int Vector::y() const
{
  return b.y() - a.y();
}

int Vector::abs_sqr() const
{
  int dx = x();
  int dy = y();
  return dx * dx + dy * dy;
}
