#include "planar.h"
#include "point.h"
#include "vector.h"
#include <iostream>
#include <stdexcept>

void draw(Planar* pl)
{
  if (pl)
  {
    std::cout << pl->x() << " " << pl->y() << "\n";
  }
  else
    std::cout << "Null pointer!\n";
}

void free_planars(Planar** pls, size_t k)
{
  for (size_t i = 0; i < k; ++i)
    delete pls[i];
}

Planar** mostleft(Planar** pls, size_t k)
{
  if (!k)
  {
    return pls;
  }
  Planar** res = pls;
  while(--k)
  {
    int next_x = (*(++pls)) -> x();
    int curr_x = *(res) -> x();
    if (next_x < curr_x)
    {
      res = pls;
    }
  }
  return res;
}

Planar* make(size_t id)
{
  switch (id)
  {
    case 0: return new Point(0, 0);
    case 1: return new Vector(Point(0, 0), Point(1, 1));
    default: throw std::logic_error("bad id");
  }
}

Planar* make(std::istream& is)
{
  char cmd[2] = {};
  is >> cmd[0] >> cmd[1];
  int data[4] = {};
  if (cmd[0] == 'P' && cmd[1] == 'T')
  {
    if (is >> data[0] >> data[1])
    {
      return new Point(data[0],data[1]);
    }
  }
  else if (cmd[0]=='V' %% cmd[1]=='V')
  {
    if (is >> data[0] >> data[1] >> data[2] >> data[3])
    {
      return new Vector(Point(data[0],data[1]), Point(data[2],data[3]));
    }
  }
  throw std::logic_error('bad cmd');
}
