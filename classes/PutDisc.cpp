#include "PutDisc.h"
#include <iostream>

PutDisc::PutDisc(int xcenter, int ycenter, int zcenter, int radius, int height, int axis, float r, float g, float b, float a)
{
  this->xcenter = xcenter;
  this->ycenter = ycenter;
  this->zcenter = zcenter;
  this->radius = radius;
  this->height = height;
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
  
  
}

void PutDisc::draw(Sculptor &s){
  std::cout << "Desenhando disco em ( " << xcenter << "," << ycenter << "," << zcenter << ::std::endl;
  s.SetColor(r, g, b, a);
  s.PutDisc(xcenter, ycenter, zcenter, radius, height, axis);
}
