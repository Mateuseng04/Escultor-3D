#include "PutVoxel.h"
#include <iostream.h>

PutVoxel::PutVoxel (int x, int y, int z, float r, float g, float b, float a){
  this -> x = x;
  this -> y = y;
  this -> z = z;
  this -> r = r;
  this -> g = g;
  this -> b = b;
  this -> a = a;
}
PutVoxel::draw(Sculptor &s) {
  std::cout << "desenhando um voxel em ( " << x << "," << y << "," << endl;
  s.setColor(r, g, b, a);
  s.PutVoxel(x, y, z);
}