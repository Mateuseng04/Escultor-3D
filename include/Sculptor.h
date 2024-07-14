#ifndef SCULPTOR_H
#define SCULPTOR_H
#include "Voxel.h"
#include <string>

class Sculptor {
protected:
  float r, g, b, a; // cores e transparência
  int nx, ny, nz; // dimensões
  Voxel ***v; // ponteiro para alocação dinâmica dos voxels
public:

  Sculptor();
  ~Sculptor();

void setColor(float r, float g, float b, float a);
void putVoxel(int x, int y, int z);
void cutVoxel(int x, int y, int z);
void putBox(int x0, int x1, int y0, int y1, int z0, int z1);
void cutBox(int x0, int x1, int y0, int y1, int z0, int z1);
void putSphere(int xcenter, int ycenter, int zcenter, int radius);
void cutSphere(int xcenter, int ycenter, int zcenter, int radius);
void putEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
void cutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
void writeOFF(std::string filename);

};

#endif SCULPTOR_H