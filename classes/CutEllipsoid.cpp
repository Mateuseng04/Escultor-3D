#include "CutEllipsoid.h"
#include <iostream>


CutEllipsoid::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz)
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
  void CutEllipsoid::draw(Sculptor &s) {
  std::cout << "Removendo elipsoide" << std::endl;
  s.CutEllipsoid(xcenter, ycenter, zcenter, rx, ry, rz);
}
