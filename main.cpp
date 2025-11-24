#include <iostream>

struct Planar
{
  virtual int x() const=0;
  virtual int y() const=0;
  virtual int abs_sqr() const=0;
  virtual ~Planar()=default;
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
  for(size_t i=0, i<10, ++i)
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
