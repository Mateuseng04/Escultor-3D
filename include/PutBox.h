#ifndef PUTBOX_H
#define PUTBOX_H
#include "FiguraGeometrica.h"

class PutBox::FiguraGeometrica {
private:
  int x0, x1, y0, y1, z0, z1;
  float r, g, b, a;
public:

  PutBox(int x0, int x1, int y0, int y1, int z0, int z1);
 
  ~PutBox(){}

  void draw(Sculptor &t);
};

#endif PUTBOX_H