#include "FiguraGeometrica.h"
#include "PutVoxel.h"
#include "CutVoxel.h"
#include "PutBox.h"
#include "CutBox.h"
#include "PutSphere.h"
#include "CutSphere.h"
#include "PutEllipsoid.h"
#include "CutEllipsoid.h"
#include "Interpretador.h"
#include "PutDisc.h"
#include "CutDisc.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>


Interpretador::Interpretador(){}


std::vector<FiguraGeometrica*> Interpretador::compile(std::string filename){
    std::ifstream f;
    std::vector<FiguraGeometrica*> figs;
    std::string Keyword;
    std::string s;
    std::stringstream ss;
    int x0, y0, z0, height, radius, xradius, yradius, zradius, axis, x1, y1, z1;
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
        ss.clear();
        ss.str(s);
        ss >> Keyword;
      if (ss.good()) 
      {
        if (Keyword.compare("Dim") == 0)
        {
          ss >> Dimx >> Dimy >> Dimz;

        }
        else if (Keyword.compare("PutVoxel") == 0) 
        {
          ss >> x0 >> y0 >> z0 >> r >> g >> b >> a;
          figs.push_back(new PutVoxel(x0, y0, z0, r, g, b, a));
        }
        else if (Keyword.compare("Cutvoxel") == 0) 
        {
          ss >> x0 >> y0 >> z0;
          figs.push_back(new CutVoxel(x0, y0, z0));
        }
        else if (Keyword.compare("PutBox") == 0) 
        {
          ss >> x0 >> y0 >> z0 >> x1 >> y1 >> z1 >> r >> g >> a;
          figs.push_back(new PutBox(x0, y0, z0, x1, y1, z1, r, g, b, a));
        }
        else if (Keyword.compare("CutBox") == 0) 
        {
          ss >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
          figs.push_back(new CutBox(x0, y0, z0, x1, y1, z1));
        }
        else if (Keyword.compare("PutSphere") == 0) 
        {
          ss >> x0 >> y0 >> z0 >> radius >> r >> g >> b >> a;
          figs.push_back(new PutSphere(x0, y0, z0, radius, r, g, b, a));
        }
        else if (Keyword.compare("CutSphere") == 0) 
        {
          ss >> x0 >> y0 >> z0 >> radius;
          figs.push_back(new CutSphere(x0, y0, z0, radius));
        }
        else if (Keyword.compare("PutEllipsoid") == 0) 
        {
          ss >> x0 >> y0 >> z0 >> xradius >> yradius >> zradius >> r >> g >> b >> a;
          figs.push_back(new PutEllipsoid(x0, y0, z0, xradius, yradius, zradius, r, g, b, a));
        }
        else if (Keyword.compare("CutEllipsoid") == 0) 
        {
          ss >> x0 >> y0 >> z0 >> xradius >> yradius >> zradius;
          figs.push_back(new CutEllipsoid(x0, y0, z0, xradius, yradius, zradius));
        }
        else if (Keyword.compare("PutDisc") == 0)
        {
          ss >> x0 >> y0 >> z0 >> radius >> height >> axis >> r >> g >> b >> a;
          figs.push_back(new PutDisc(x0, y0, z0, radius, height, axis, r, g, b, a));
        }
        else if (Keyword.compare("CutDisc") == 0) 
        {
          ss >> x0 >> y0 >> z0 >> radius >> height >> axis;
          figs.push_back(new CutDisc(x0, y0, z0, radius, height, axis));
        }
      }
    }
  }
  f.close();
  return figs;
}
int Interpretador::getDimx()
{
  return Dimx;
}
int Interpretador::getDimy() {
  return Dimy;
}
int Interpretador::getDimz() {
  return Dimz;
}
