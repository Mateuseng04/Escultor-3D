#ifndef PUTDISC_H
#define PUTDISC_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class PutDisc : public FiguraGeometrica{
  private:
    int xcenter, ycenter, zcenter, radius, height, axis;

  public:
    PutDisc(int xcenter, int ycenter, int zcenter, int radius, int height, int axis, float r, float g, float b, float a);
    ~PutDisc(){}

  void draw(Sculptor &t);
};

#endif 
