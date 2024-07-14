#ifndef  CUTVOXEL_H
#define  CUTVOXEL_H
#include "FiguraGeometrica.h"

class CutVoxel::FiguraGeometrica {
private:
  int nx, ny, nz;

public:
  CutVoxel(int x, int y, int z);
  ~CutVoxel(){}

  void draw(Sculptor &t);
};

#endif  // PUTVOXEL_H