#include "PutBox.h"
#include <iostream>

PutBox::PutBox(int x0, int y0, int z0, int x1, int y1, int z1, float r, float g, float b, float a) {
  this->x0 = x0;
  this->y0 = y0;
  this->z0 = z0;
  this->x1 = x1;
  this->y1 = y1;
  this->z1 = z1;
  this->r = r;
  this->g = g;
  this->b = b;
  this->a = a;
}
void PutBox::draw (Sculptor &s) {
  std::cout << "desenhando um cubo em ( " << x0 << "," << y0 << "," << z0 << std::endl;
  s.SetColor(r, g, b, a);
  s.PutBox(x0, y0, z0, x1, y1, z1);
}
