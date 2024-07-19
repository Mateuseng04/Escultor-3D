#include "CutVoxel.h"
#include <iostream>

CutVoxel::CutVoxel(int x, int y, int z){
  this->x = x;
  this->y = y;
  this->z = z;
}

void CutVoxel::draw(Sculptor &s){
  std::cout << "cortando um voxel em" << x << "," << y << "," << z << std::endl;
  s.CutVoxel(x, y, z);
}
