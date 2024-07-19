#ifndef  _PUTVOXEL_H_
#define  _PUTVOXEL_H_
#include "FiguraGeometrica.h"

class PutVoxel : public FiguraGeometrica {
// private:
 // int nx, ny, nz;
int x, y, z;

public:
  PutVoxel(int x, int y, int z, float r, float g, float b, float a);
  ~PutVoxel(){}


void draw(Sculptor &t);
};

#endif  // PUTVOXEL_H
