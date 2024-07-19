#ifndef _INTERPRETADOR_H_
#define _INTERPRETADOR_H_
#include "FiguraGeometrica.h"
#include <vector>
#include <string>


class Interpretador {
private:
  float r, g, b, a;
  int Dimx = 50, Dimy = 50, Dimz = 50;

public:
  Interpretador();
  ~Interpretador();	

  std::vector<FiguraGeometrica*>compile(std::string filename);

  int getDimx();

  int getDimy();

  int getDimz();

};
#endif 
