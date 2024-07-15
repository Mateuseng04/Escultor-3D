#include "PutEllipsoid.h"
#include <iostream.h>

Putellipsoid::Putellipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz, float r, float g, float b, float a){
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
void Putellipsoid::draw(Sculptor &s){
  std::cout << "Desenhando elipsoide" << std::endl;
  s.setcolor(r, g, b, a);
  s.Putelipsoid(xcenter, ycenter, zcenter, rx, ry, rz);
}