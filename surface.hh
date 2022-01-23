#pragma once

#ifndef SURFACE_H
#define SURFACE_H

#include "landscape.hh"
#include <iostream>
#include <string>

class Surface:public Landscape {
  protected:
    float plasticWasteMass;

  public:
    Surface(){};
    Surface(std::string name,float plastic):Landscape(name,100),plasticWasteMass(plastic){};
    //void showLandscape(){std::cout<<"Not yet implemented"<<std:endl};
    void setWasteMass(float val);
    float getWasteMass(){return plasticWasteMass;};
    friend std::ostream & operator<<(std::ostream &out, const Surface &s);
};

/*std::ostream & operator<<(std::ostream &out, const Surface &s){
  out << (Landscape)s;
  out << "Plastic Waste Mass: " << s.plasticWasteMass << " tons"<< std::endl;
  return out;
}*/

#endif
