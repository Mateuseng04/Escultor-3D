#ifndef _CUTSPHERE_H_
#define _CUTSPHERE_H_
#include "FiguraGeometrica.h"
#include "Sculptor.h"

class CutSphere : public FiguraGeometrica {

private:
  int xcenter, ycenter, zcenter, radius;

public:
  CutSphere(int xcenter, int ycenter, int zcenter, int radius);
  ~CutSphere(){}
  void draw(Sculptor &t);
};

#endif 
