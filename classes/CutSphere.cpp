#include "CutSphere.h"
#include <iostream>

CutSphere::CutSphere(int xcenter, int ycenter, int zcenter, int radius) 
{
  this->xcenter = xcenter;
  this->ycenter = ycenter;
  this->zcenter = zcenter;
  this->radius = radius;

}
void CutSphere::draw(Sculptor &s) {
  std::cout << "removendo um esfera em ( " << xcenter << "," << ycenter << "," << zcenter << std::endl;
  s.SetColor(r, g, b, a);
  s.CutSphere(xcenter, ycenter, zcenter, radius);
}
