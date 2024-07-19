#include "PutSphere.h"
#include <iostream>

PutSphere::PutSphere(int xcenter, int ycenter, int zcenter, int radius, float r, float g, float b, float a) {
  this -> xcenter = xcenter;
  this -> ycenter = ycenter;
  this -> zcenter = zcenter;
  this -> radius = radius;
  this -> r = r;
  this -> g = g;
  this -> b = b;
  this -> a = a;
}
void PutSphere::draw(Sculptor &s) {
  std::cout << "desenhando um esfera em ( " << xcenter << "," << ycenter << "," << zcenter << std::endl;
  s.SetColor(r, g, b, a);
  s.PutSphere(xcenter, ycenter, zcenter, radius);
}
