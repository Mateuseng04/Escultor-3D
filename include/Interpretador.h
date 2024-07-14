#ifndef INTERPRETADOR_H
#define INTERPRETADOR_H
#include "FiguraGeometrica.h"
#include <vector>
#include <string>


class Interpretador {
private:
  float r, g, b, a;
  int dimx = 50; dimy = 50; dimz = 50;

public:
  Interpretador();
  ~Interpretador();	

  std::vector<FiguraGeometrica*> parse(std::string filename);

  getDimx();

  getDimy();

  gteDimz();

};
#endif INTERPRETADOR_H