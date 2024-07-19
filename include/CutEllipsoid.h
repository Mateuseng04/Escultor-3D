#ifndef _CUTELLIPSOID_H_
#define _CUTELLIPSOID_H_
#include "FiguraGeometrica.h"
#include "Sculptor.h"


class CutEllipsoid : public FiguraGeometrica{

private:
  int xcenter, ycenter, zcenter, rx, ry, rz;

public:
  CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  ~CutEllipsoid(){}


  void draw(Sculptor &t);

};

#endif 
