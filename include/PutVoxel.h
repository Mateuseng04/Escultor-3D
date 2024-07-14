#ifndef  PUTVOXEL_H
#define  PUTVOXEL_H

class PutVoxel::FiguraGeometrica {
private:
  int nx, ny, nz;

public:
  PutVoxel(int x, int y, int z, float r, float g, float b, float a);
  ~PutVoxel(){}


  void draw(Sculptor &t);
};

#endif  // PUTVOXEL_H