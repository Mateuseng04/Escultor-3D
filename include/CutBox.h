#ifndef CUTBOX_H
#define CUTBOX_H
#include "FiguraGeometrica.h"


class CutBox::FiguraGeometrica {
private:
  int x0, x1, y0, y1, z0, z1;

public:

  CutBox(int x0, int x1, int y0, int y1);
  
  ~CutBox(){}

  void draw(Sculptor &t);
};

#endif CUTBOX_H