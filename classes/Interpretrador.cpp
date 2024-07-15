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
#include <iostream>
#include <fstream>
#include <sstream>


Interpretador::Interpretador(){
}

  std::vector<FiguraGeometrica*> Interpretador::compile(std::string filename) {
    
  }