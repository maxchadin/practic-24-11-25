#include <iostream>

struct Planar
{
  virtual int x() const=0;
  virtual int y() const=0;
  virtual int abs_sqr() const=0;
  virtual ~Planar()=default;
};

struct Point: Planar
{
  virtual int x() const;
  virtual int y() const;
  virtual int abs_sqr() const;
  Point(int xx, int yy);
  virtual ~Point()= default;
  private:
    int data[2];
};

struct Vector: Planar
{
  Vector(const Point& start, const Point& end);
  virtual int x() const override;
  virtual int y() const override;
  virtual int abs_sqr() const override;
  virtual ~Vector() = default;
private:
  Point a;
  Point b;
};


Planar* make(std::istream& is);
Planar* make(size_t pl);
void draw(Planar* pl);
void free_planars(Planar** pls, size_t k);
Planar* mostleft(Planar** pls, size_t k);

int main()
{
  Planar *pls[10]={};
  size_t k=0;
  for(size_t i=0; i<10; ++i)
  {
    try
    {
      pls[k]=make(i%2);
    }
    catch(...)
    {
      free_planars(pls,k);
      return 2;
    }
    k++;
  }
  draw(mostleft(pls,k));
  free_planars(pls,k);
  //pls[k++] = make(std::cin);
  Planar* lest = mostleft(pls,k);
  //draw(left);
  //free_planars(pls,k);
}

Planar* make(size_t pl)
{
  switch(pl)
  {
    default:
      throw std::logic_error("bad id");
  }
  return nullptr;
}

void free_planars(Planar** pls, size_t k)
{
  for(size_t i=0; i<k; ++i)
  {
    delete pls[i];
  }
}

void draw(Planar* pl)
{
  std::cout << pl -> x();
  std::cout << " ";
  std::cout << pl -> y() << "\n";
}

Planar* mostleft(Planar** pls, size_t k)
{
  return nullptr;
}

Planar* make(size_t id)
{
  switch(id)
  {
    case 0:
      return new Point(0,0);
    case 1:
      return new Vector(Point(0,0), Point(1,1));
    default:
      throw std::logic_error("bad id");
  }
}

Point::Point(int xx, int yy):
  Planar(),
  data{xx,yy}
{}

int Point::x() const
{
  return data[0];
}

int Point::y() const
{
  return data[1];
}

int Point::abs_sqr() const
{
  return x()*x() + y()*y();
}

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
