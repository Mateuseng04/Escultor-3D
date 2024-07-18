#ifndef CUTDISC_H
#define CUTDISC_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class CutDisc::FiguraGeometrica{
  private:
    int xcenter, ycenter, zcenter, radius, height, axis;

  public:
    CutDisc(int xcenter, int ycenter, int zcenter, int radius, int height, int axis);
    ~CutDisc(){}

  void draw(Sculptor &t);
};

#endif CUTDISC_H