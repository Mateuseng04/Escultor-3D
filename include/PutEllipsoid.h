#ifndef PUTELLIPSOID_H
#define PUTELLIPSOID_H
#include "FiguraGeometrica.h"
#include "Sculptor.h"


class PutEllipsoid::FiguraGeometrica{

private:
  int xcenter, ycenter, zcenter, rx, ry, rz;
  
public:
  PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int r);
  ~PutEllipsoid(){}

  void draw(Sculptor &t);

};

#endif PUTELLIPSOID_H