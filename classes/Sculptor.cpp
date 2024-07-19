#include "Sculptor.h"
#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

Sculptor::Sculptor(int _nx, int _ny, int _nz) {
  nx = _nx;
  ny = _ny;
  nz = _nz;
  r = g = b = a = 0.5;
  alocarmemoria();
}

Sculptor::~Sculptor() {
  for (int x = 0; x < nx; x++) {
    for (int y = 0; y < ny; y++) {
      delete[] v[x][y];
    }
    delete[] v[x];
  }
  delete[] v;

  std::cout << "Destrutor chamado" << std::endl;
}

void Sculptor::alocarmemoria() {
  v = new Voxel **[nx];
  for (int x = 0; x < nx; x++) {
    v[x] = new Voxel *[ny];
    for (int y = 0; y < ny; y++) {
      v[x][y] = new Voxel[nz];
      for (int z = 0; z < nz; z++) {
        v[x][y][z].isOn = false;
        v[x][y][z].r = r;
        v[x][y][z].g = g;
        v[x][y][z].b = b;
        v[x][y][z].a = a;
      }
    }
  }
}

void Sculptor::SetColor(float _r, float _g, float _b, float _alpha) {
  r = _r;
  g = _g;
  b = _b;
  a = _alpha;
}

void Sculptor::PutVoxel(int x, int y, int z) {
  if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
    v[x][y][z].isOn = true;
    v[x][y][z].r = r;
    v[x][y][z].g = g;
    v[x][y][z].b = b;
    v[x][y][z].a = a;
  }
}

void Sculptor::CutVoxel(int x, int y, int z) {
  if (x >= 0 && x < nx && y >= 0 && y < ny && z >= 0 && z < nz) {
    v[x][y][z].isOn = false;
  }
}

void Sculptor::PutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
  for (int x = x0; x < x1; x++) {
    for (int y = y0; y < y1; y++) {
      for (int z = z0; z < z1; z++) {
        PutVoxel(x, y, z);
      }
    }
  }
}

void Sculptor::CutBox(int x0, int x1, int y0, int y1, int z0, int z1) {
  for (int x = x0; x < x1; x++) {
    for (int y = y0; y < y1; y++) {
      for (int z = z0; z < z1; z++) {
        CutVoxel(x, y, z);
      }
    }
  }
}

void Sculptor::PutSphere(int xcenter, int ycenter, int zcenter, int radius) {
  for (int x = xcenter - radius; x < xcenter + radius; x++) {
    for (int y = ycenter - radius; y < ycenter + radius; y++) {
      for (int z = zcenter - radius; z < zcenter + radius; z++) {
        if (pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - zcenter, 2) <
            pow(radius, 2)) {
          PutVoxel(x, y, z);
        }
      }
    }
  }
}

void Sculptor::CutSphere(int xcenter, int ycenter, int zcenter, int radius) {
  for (int x = xcenter - radius; x < xcenter + radius; x++) {
    for (int y = ycenter - radius; y < ycenter + radius; y++) {
      for (int z = zcenter - radius; z < zcenter + radius; z++) {
        if (pow(x - xcenter, 2) + pow(y - ycenter, 2) + pow(z - zcenter, 2) <
            pow(radius, 2)) {
          CutVoxel(x, y, z);
        }
      }
    }
  }
}

void Sculptor::PutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,
                            int ry, int rz) {
  for (int x = xcenter - rx; x < xcenter + rx; x++) {
    for (int y = ycenter - ry; y < ycenter + ry; y++) {
      for (int z = zcenter - rz; z < zcenter + rz; z++) {
        if (pow(x - xcenter, 2) / pow(rx, 2) +
                pow(y - ycenter, 2) / pow(ry, 2) +
                pow(z - zcenter, 2) / pow(rz, 2) <
            1) {
          PutVoxel(x, y, z);
        }
      }
    }
  }
}

void Sculptor::CutEllipsoid(int xcenter, int ycenter, int zcenter, int rx,
                            int ry, int rz) {
  for (int x = xcenter - rx; x < xcenter + rx; x++) {
    for (int y = ycenter - ry; y < ycenter + ry; y++) {
      for (int z = zcenter - rz; z < zcenter + rz; z++) {
        if (pow(x - xcenter, 2) / pow(rx, 2) +
                pow(y - ycenter, 2) / pow(ry, 2) +
                pow(z - zcenter, 2) / pow(rz, 2) <
            1) {
          CutVoxel(x, y, z);
        }
      }
    }
  }
}

void Sculptor::writeOFF(std::string filename) {
  std::ofstream file;
  file.open(filename);
  if (!file.is_open()) {
    std::cerr << "Erro ao abrir o arquivo " << filename << "\n";
    exit(1);
  }

  file << "OFF\n";

  int total = 0;
  for (int x = 0; x < nx; x++) {
    for (int y = 0; y < ny; y++) {
      for (int z = 0; z < nz; z++) {
        if (v[x][y][z].isOn) {
          total++;
        }
      }
    }
  }

  file << total * 8 << " " << total * 6 << " 0\n";

  int index = 0;
  for (int x = 0; x < nx; x++) {
    for (int y = 0; y < ny; y++) {
      for (int z = 0; z < nz; z++) {
        if (v[x][y][z].isOn) {
          file << x - 0.5 << " " << y - 0.5 << " " << z - 0.5 << "\n";
          file << x + 0.5 << " " << y - 0.5 << " " << z - 0.5 << "\n";
          file << x + 0.5 << " " << y + 0.5 << " " << z - 0.5 << "\n";
          file << x - 0.5 << " " << y + 0.5 << " " << z - 0.5 << "\n";
          file << x - 0.5 << " " << y - 0.5 << " " << z + 0.5 << "\n";
          file << x + 0.5 << " " << y - 0.5 << " " << z + 0.5 << "\n";
          file << x + 0.5 << " " << y + 0.5 << " " << z + 0.5 << "\n";
          file << x - 0.5 << " " << y + 0.5 << " " << z + 0.5 << "\n";
        }
      }
    }
  }

  total = 0;
  for (int x = 0; x < nx; x++) {
    for (int y = 0; y < ny; y++) {
      for (int z = 0; z < nz; z++) {
        if (v[x][y][z].isOn) {
          index = total * 8;
          file << "4 " << index + 0 << " " << index + 3 << " " << index + 2
               << " " << index + 1 << " " << v[x][y][z].r << " " << v[x][y][z].g
               << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
          file << "4 " << index + 4 << " " << index + 5 << " " << index + 6
               << " " << index + 7 << " " << v[x][y][z].r << " " << v[x][y][z].g
               << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
          file << "4 " << index + 0 << " " << index + 1 << " " << index + 5
               << " " << index + 4 << " " << v[x][y][z].r << " " << v[x][y][z].g
               << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
          file << "4 " << index + 0 << " " << index + 4 << " " << index + 7
               << " " << index + 3 << " " << v[x][y][z].r << " " << v[x][y][z].g
               << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
          file << "4 " << index + 3 << " " << index + 7 << " " << index + 6
               << " " << index + 2 << " " << v[x][y][z].r << " " << v[x][y][z].g
               << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";
          file << "4 " << index + 1 << " " << index + 2 << " " << index + 6
               << " " << index + 5 << " " << v[x][y][z].r << " " << v[x][y][z].g
               << " " << v[x][y][z].b << " " << v[x][y][z].a << "\n";

          total++;
        }
      }
    }
  }

  file.close();
  std::cout << "Arquivo " << filename << " escrito com sucesso!" << std::endl;
}
