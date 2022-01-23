#pragma once

#ifndef SALT_WATER_H
#define SALT_WATER_H

#include "water.hh"
#include <iostream>
#include <string>

class Salt_Water:public Water {
  private:
    float oil_leakage;
  public:
    Salt_Water(){};
    Salt_Water(std::string name,int nb_fish, float chemicals,float oil_leakage):Water(name,nb_fish,chemicals),oil_leakage(oil_leakage){};
    int showLandscape();
    float getOil(){return oil_leakage;};
    void setOil(float val);
    friend std::ostream & operator<<(std::ostream &out, const Salt_Water &sw);
};

/*std::ostream & operator<<(std::ostream &out, const Salt_Water &sw){
  out << (Water)sw;
  out << "Oil leakage: "<< sw.oil_leakage << " cubic_meter"<< std::endl;
  return out;
}*/

#endif
