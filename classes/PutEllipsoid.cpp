#include "PutEllipsoid.h"
#include <iostream>

PutEllipsoid::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a)
{
  this->xcenter = xcenter;
  this->ycenter = ycenter;
  this->zcenter = zcenter;
  this->rx = rx;
  this->ry = ry;
  this->rz = rz;
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}
void PutEllipsoid::draw(Sculptor &s){
  std::cout << "Desenhando elipsoide" << std::endl;
  s.SetColor(r, g, b, a);
  s.PutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz);
}
