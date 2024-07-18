#include "PutDisc.h"
#include <iostream.h>

PutDisc::PutDisc(int xcenter, int ycenter, int zcenter, int radius, int height, int axis, float g, float b, float alpha){

  this xcenter = xcenter;
  this ycenter = ycenter;
  this zcenter = zcenter;
  this radius = radius;
  this height = height;
  this r = r;
  this g = g;
  this b = b;
  this alpha = alpha;
  
}

void PutDisc::draw(Sculptor &s){
  std::cout << "Desenhando disco em ( " << xcenter << "," << ycenter << "," << zcenter ")\n"::std::endl;
  s.setcolor(r, g, b, a);
  s.PutDisc(xcenter, ycenter, zcenter, radius, height, axis);
}