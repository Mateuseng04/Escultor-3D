#ifndef CUTELLIPSOID_H
#define CUTELLIPSOID_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"


class CutEllipsoid::FiguraGeometrica{

private:
  int xcenter, ycenter, zcenter, rx, ry, rz;

public:
  CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int r);
  ~CutEllipsoid(){}


  void draw(Sculptor &t);

};

#endif CUTELLIPSOID_H