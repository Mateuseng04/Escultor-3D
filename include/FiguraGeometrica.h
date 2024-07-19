#ifndef _FIGURAGEOMETRICA_H_
#define _FIGURAGEOMETRICA_H_
#include "Sculptor.h"

class FiguraGeometrica {
protected:
  float r, g, b; 
  float a; // transparência;

public:
  FiguraGeometrica(){};
  virtual ~FiguraGeometrica(){};


  virtual void draw(Sculptor &t) = 0;

};

#endif 
