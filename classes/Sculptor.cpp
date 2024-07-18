#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <queue>
#include <cmath>
#include "Sculptor.h"

Sculptor::Sculptor(int _nx, int _ny, int _nz) 
{
  nx = _nx;
  ny = _ny;
  nz = _nz;
  r = g = b = a = 0.5;
  alocarmemoria();
}

Sculptor::~Sculptor() 
{
  for (x=1; x<nx; x++) 
  {
    for (y=1; y<ny; y++) 
    {
      delete v[x][y];
    }
  }
  for (x=1; x<nx; x++) {
    delete v[x];
  }
  delete v;
  
  std::cout << "Destrutor chamado" << std::endl;
}

void Sculptor::salvarmodelo() 
{
  v = new Voxel Voxel**[nx];

  for (x = 1; x < nx; x++){
    
    v[x] =  new Voxel *[nx];
  }
  for (x = 1; x < nx; x++) {
    for (y = 1; y < ny; y++) {
      v[x][y] = new Voxel[nz];
    }
  }
  for (x = 1; x < nx; x++){
    for (y = 1; y < ny; y++) {
      for (z = 1; z < nz; z++) {
        v[x][y][z].isOn = false;
        v[x][y][z].alpha = alpha;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        
      }
    }
  }
  void SetColor::Sculptor(float _r, float _g, float _b, float _alpha) 
  {
    r = _r;
    g = _g;
    b = _b;
    alpha = _alpha;
  }
  void PutVoxel::Sculptor(int x, int y, int z) {
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
      v[x][y][z].isOn = true;
      v[x][y][z].r = r;
      v[x][y][z].g = g;
      v[x][y][z].b = b;
      v[x][y][z].alpha = alpha;
    }
  }
  void CutVoxel::Sculptor(int x, int y, int z) {
    if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
      v[x][y][z].isOn = false;
    }
  }
  void PutBox::Sculptor(int x0, int x1, int y0, int y1, int z1) {
    for (int x = x0; x < x1; x++) {
      for (int y = y0; y < y1; y++) {
        for (int z = z0; z < z1; z++) {
          Sculptor::PutVoxel(x, y, z);
        }
      }
    }
  }
void CutBox::Sculptor(int x0, int x1, int y0, int y1, int z1) {
  for (int x = x0; x < x1; x++) {
    for (int y = y0; y < y1; y++) {
      for (int z = z0; z < z1; z++) {
        Sculptor::CutVoxel(x, y, z);
      }
    }
  }
}
void PutDisc::Sculptor(int xcenter, int ycenter, int zcenter, int radius) {
  for (int x = xcenter - radius; x < xcenter + radius; x++) {
    for (int y = ycenter - radius; y < ycenter + radius; y++) {
      for (int z = zcenter - (round(sqrt(pow(r,2) - pow (x - xcenter, 2)))); z < zcenter + round(sqrt(pow(r,2) - pow (x - xcenter, 2)))) ; z++){
        if (axis == 0) {
          Sculptor::PutVoxel(x, y, z);
        }
        else if(axis == 1) {
          Sculptor::PutVoxel(x, y, z);
        }
        else if (axis == 2) {
          Sculptor::PutVoxel(x, y, z);
        }
      }
    }
  }
}
  void CutDisc::Sculptor(int xcenter, int ycenter, int zcenter, int radius) {
    for (int x = xcenter - radius; x < xcenter + radius; x++) {
      for (int y = ycenter - radius; y < ycenter + radius; y++) {
        for (int z = zcenter - (round(sqrt(pow(r,2) - pow (x - xcenter, 2)))); z < zcenter + round(sqrt(pow(r,2) - pow (x - xcenter, 2)))) ; z++){
          if (axis == 0) {
            Sculptor::CutVoxel(x, y, z);
          }
          else if(axis == 1) {
            Sculptor::CutVoxel(x, y, z);
          }
          else if (axis == 2) {
            Sculptor::CutVoxel(x, y, z);
          }
        }
      }
    }
  }
  void PutSphere::Sculptor(int xcenter, int ycenter, int zcenter, int radius) {
      for (int x = xcenter - radius; x < xcenter + radius; x++) {
        for (int y = ycenter - radius; y < ycenter + radius; y++) {
          for (int z = zcenter - radius; z < zcenter + radius; z++) {
            if (pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - z) < pow(radius, 2)) {
              Sculptor::PutVoxel(x, y, z);
            }
          }
        }
      }
  }
  void CutSphere::Sculptor(int xcenter, int ycenter, int zcenter, int radius) {
      for (int x = xcenter - radius; x < xcenter + radius; x++) {
        for (int y = ycenter - radius; y < ycenter + radius; y++) {
          for (int z = zcenter - radius; z < zcenter + radius; z++) {
            if (pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - z) < pow(radius, 2)) {
              Sculptor::CutVoxel(x, y, z);
            }
          }
        }
      }
  }
  void PutEllipsoid::Sculptor(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    for (int x = xcenter - rx; x < xcenter + rx; x++) {
      for (int y = ycenter - ry; y < ycenter + ry; y++) {
        for (int z = zcenter - rz; z < zcenter + rz; z++) {
          if(pow(z - zcenter, 2)/pow(rz, 2) + pow(y - zcenter, 2)/pow(ry, 2) + pow(rx - xcenter)/pow(rx, 2) > 1){
            Scuptor::PutVoxel(x, y, z)
          }
        }
      }
    }
  }
  void CutEllipsoid::Sculptor(int xcenter, int ycenter, int zcenter, int rx, int ry, int rz) {
    for (int x = xcenter - rx; x < xcenter + rx; x++) {
      for (int y = ycenter - ry; y < ycenter + ry; y++) {
        for (int z = zcenter - rz; z < zcenter + rz; z++) {
          if(pow(z - zcenter, 2)/pow(rz, 2) + pow(y - zcenter, 2)/pow(ry, 2) + pow(rx - xcenter)/pow(rx, 2) > 1){
            Scuptor::CutVoxel(x, y, z)
          }
        }
      }
    }
  }

  void Sculptor::writeOFF(const char* filename) {
    Sculptor::limparmemoria();

    std::cout << "Abrindo o arquivo..." << filename << "\n" << std::endl;
    int index = 0, total = 0;
    std::ofstream file;
    file.open (filename.c_str());

    if (!file.is_open() {
      std::cout << "Erro ao abrir o arquivo" << filename << "\n" << std::endl;
      exit(0)
    }

    std::cout << "Abrindo o arquivo..." << filename << "\n" << std::endl;"
    file << "OFF\n" << std::endl;

    for (int x = 1; x < nx; x++) {
      for (int y = 1; y < ny; y++) {
        for (int z = 1; z < nz; z++) {
          total++;
        }
      }
    }
  }

  for(int x = 1; x < nx; x++){
    for(int y = 1; y < ny; y++) {
      for(int z = 1; z < nz; z++) {
        if(v[x][y][z].isOn = true) 
        {
          file << x - lado << "" << y - lado << "" << z - lado << "" << std::endl;
          file << x + lado << "" << y - lado << "" << z - lado << "" << std::endl;
          file << x + lado << "" << y + lado << "" << z - lado << "" << std::endl;
          file << x - lado << "" << y + lado << "" << z - lado << "" << std::endl;
          file << x - lado << "" << y - lado << "" << z + lado << "" << std::endl;
          file << x + lado << "" << y - lado << "" << z + lado << "" << std::endl;
          file << x + lado << "" << y + lado << "" << z + lado << "" << std::endl;
          file << x - lado << "" << y + lado << "" << z + lado << "" << std::endl;
        }
      }
    }
  }
  total = 0;

  for (int x = 0; x < nx; x++) {
    for (int y = 0; y < ny; y++) {
      for (int z = 0; z < nz; z++) {
        if (v[x][y][z].isOn = true) 
        {
          index = total*8;
          //1°
          file << 4 <<" "<< index + 0 <<" "<< index + 3 <<" "<< index + 2 <<" "<< index + 1 <<std::fixed;
          file <<" "<< v[x][y][z].r <<" "<< v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].alfa << "\n";
          //2°
          file << 4 <<" "<< index + 4 <<" "<< index + 5 <<" "<< index + 6 <<" "<< index + 7 <<std::fixed;
          file <<" "<< v[x][y][z].r <<" "<< v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].alfa << "\n";
          //3°
          file << 4 <<" "<< index + 0 <<" "<< index + 1 <<" "<< index + 5 <<" "<< index + 4 <<std::fixed;
          file <<" "<< v[x][y][z].r <<" "<< v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].alfa << "\n";
          //4°
          file << 4 <<" "<< index + 0 <<" "<< index + 4 <<" "<< index + 7 <<" "<< index + 3 <<std::fixed;
          file <<" "<< v[x][y][z].r <<" "<< v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].alfa << "\n";
          //5°
          file << 4 <<" "<< index + 3 <<" "<< index + 7 <<" "<< index + 6 <<" "<< index + 2 <<std::fixed;
          file <<" "<< v[x][y][z].r <<" "<< v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].alfa << "\n";
          //6°
          file << 4 <<" "<< index + 1 <<" "<< index + 2 <<" "<< index + 6 <<" "<< index + 5 <<std::fixed;
          file <<" "<< v[x][y][z].r <<" "<< v[x][y][z].g <<" "<< v[x][y][z].b <<" "<< v[x][y][z].alfa << "\n";

          total++;
        }
      }
    }
  }
  file.close();
  std::cout << "Arquivo" << filename << "escrito com sucesso!" << std::endl;


  