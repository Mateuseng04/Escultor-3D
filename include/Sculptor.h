#ifndef _SCULPTOR_H_
#define _SCULPTOR_H_
#include "Voxel.h"
#include <string>
class Sculptor {
protected:
  float r, g, b, a; // cores e transparência
  int nx, ny, nz; // dimensões
  Voxel ***v; // ponteiro para alocação dinâmica dos voxels
  float lado; // lado do cubo
public:
  Sculptor(int _nx = 1, int _ny = 1, int _nz = 1);
  ~Sculptor();
  void alocarmemoria();
  void limparmemoria();
  void SetColor(float r, float g, float b, float a);
  void PutVoxel(int x, int y, int z);
  void CutVoxel(int x, int y, int z);
  void PutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void CutBox(int x0, int x1, int y0, int y1, int z0, int z1);
  void PutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void CutSphere(int xcenter, int ycenter, int zcenter, int radius);
  void PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz);
  void PutDisc(int xcenter, int ycenter, int zcenter, int radius, int height, int axis);
  void CutDisc(int xcenter, int ycenter, int zcenter, int radius, int height, int axis);
  void writeOFF(std::string filename);
};
#endif
