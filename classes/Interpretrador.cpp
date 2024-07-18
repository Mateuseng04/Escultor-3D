#include "Intrepretrador.h"
#include "FiguraGeometrica.h"
#include "PutVoxel.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "CutBox.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include "PutEllipsoid.h"
#include "CutEllipsoid.h"
#include "PutDisc.h"
#include "CutDisc.h"
#include <iostream>
#include <fstream>
#include <sstream>


Interpretador::Interpretador(){
}

  std::vector<FiguraGeometrica*> Interpretador::compile(std::string filename) {
    std::ifstream f;
    std::vector<FiguraGeometrica*> figs;
    std::string Keyword;
    std::string s;
    std::stringstream ss;

    int x0, y0, z0, height, radius, xradius, yradius, zradius,        radius, axis, x1, y1, z1;

    float r, g, b, a;

    f.open(filename.c_str());

    std::cout << "Lendo arquivo: " << filename << std::endl;
    if (!f.is_open()) {
        std::cout << "Arquivo nao encontrado\n" << std::endl;
        exit(0);
    }
    else {
          std::cout << "Arquivo encontrado\n" << std::endl;
    }
    while(f.good()) {

      std::getline(f, s);
      if (f.good()) 
      {
        ss.Clear();
        ss.str(s);
        ss >> Keyword;
      if (ss.good) 
      {
        if (Keyword.compare(dim == ) 
        {
          ss >> dimx >> dimy >> dimz;
          
        }
        else if (Keyword.compare(putvoxel) == 0) 
        {
          ss >> x0 >> y0 >> z0 >> r >> g >> b >> alpha;
          figs.push_back(new PutVoxel(x0, y0, z0, r, g, alpha)
        }
        else if (Keyword.compare(cutvoxel) == 0) 
        {
          ss >> x0 >> y0 >> z0;
          figs.push_back(new CutVoxel(x0, y0, z0));
        }
        else if (Keyword.compare(putbox) == 0) 
        {
          ss >> x0 >> y0 >> z0 >> x1 >> y1 >> z1 >> r >> g >> alpha;
          figs.push_back(new PutBox(x0, y0, z0, x1, y1, z1, r, g, alpha));
        }
        else if (Keyword.compare(cutbox) == 0) 
        {
          ss >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
          figs.push_back(new CutBox(x0, y0, z0, x1, y1, z1));
        }
        else if (Keyword.compare(putsphere) == 0) 
        {
          ss >> x0 >> y0 >> z0 >> radius >> r >> g >> b >> alpha;
          figs.push_back(new PutSphere(x0, y0, z0, radius, r, g, b, alpha);
        }
        else if (Keyword.compare(cutsphere) == 0) 
        {
          ss >> x0 >> y0 >> z0 >> radius;
          figs.push_back(new CutSphere(x0, y0, z0, radius));
        }
        else if (Keyword.compare(PutEllipsoid) == 0) 
        {
          ss >> x0 >> y0 >> z0 >> xradius >> yradius >> zradius >> r >> g >> b >> alpha;
          figs.push_back(new PutEllipsoid(x0, y0, z0, xradius, yradius, zradius, r, g, b, alpha);
        }
        else if (Keyword.compare(CutEllipsoid) == 0) 
        {
          ss >> x0 >> y0 >> z0 >> xradius >> yradius >> zradius;
          figs.push_back(new CutEllipsoid(x0, y0, z0, xradius, yradius, zradius));
        }
      }
    }
  }
  f.close();
  return figs;
}

int Interpretador::getDimx() {
  return dimx;
}
int Interpretador::getDimy() {
  return dimy;
}
int Interpretador::getDimz() {
  return dimz;
}