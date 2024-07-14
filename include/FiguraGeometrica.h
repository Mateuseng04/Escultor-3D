#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include "Sculptor.h"

class FiguraGeometrica {
protected:
  float r, g, b; 
  float a;

public:
  virtual FiguraGeometrica(){};
  virtual ~FiguraGeometrica(){};


  virtual draw(Sculptor &t) = 0;

};

#endif FIGURAGEOMETRICA_H