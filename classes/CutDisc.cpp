#include "CutDisc.h"
#include <iostream>

CutDisc::CutDisc(int xcenter, int ycenter, int zcenter, int radius, int height, int axis)
{
    this->xcenter = xcenter;
    this->ycenter = ycenter;
    this->zcenter = zcenter;
    this->radius = radius;
    this->height = height;
    this->axis = axis;
}

void CutDisc::draw(Sculptor &s){
    std::cout<< "  > cortando disco em (" <<xcenter<<", "<<ycenter<<", "<<zcenter<<")\n";
    s.CutDisc(xcenter, ycenter, zcenter, radius, height, axis);
  
}
