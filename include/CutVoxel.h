#ifndef  _CUTVOXEL_H_
#define  _CUTVOXEL_H_
#include "FiguraGeometrica.h"

class CutVoxel : public FiguraGeometrica {
private:
  int x, y, z;

public:
  CutVoxel(int x, int y, int z);
  ~CutVoxel(){}

  void draw(Sculptor &t);
};

#endif  // PUTVOXEL_H
