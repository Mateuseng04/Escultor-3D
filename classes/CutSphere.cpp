#include "CutSphere.h"
#include <iostream.h>

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a);
  this -> xcenter = xcenter;
  this -> ycenter = ycenter;
  this -> zcenter = zcenter;
  this -> radius = radius;
  this -> r = r;
  this -> g = g;
  this -> b = b;
  this -> a = a;

CutSphere::draw(Sculptor &s) {
  std::cout << "removendo um esfera em ( " << xcenter << "," << ycenter << "," << zcenter << std::endl;
  s.setColor(r, g, b, a);
  s.PutSphere(xcenter, ycenter, zcenter, radius);
}