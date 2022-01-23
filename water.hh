#pragma once

#ifndef WATER_H
#define WATER_H

#include "surface.hh"
#include <iostream>
#include <string>


class Water:public Surface  {
  private:
    int nb_fish;
    float chemicals;
  public:
    Water(){};
    Water(std::string name,int nb_fish,float chemicals):Surface(name,9999),nb_fish(nb_fish),chemicals(chemicals){};
    //void showLandscape(){std::cout<<"Not yet implemented"<<std:endl};
    int getFish(){return nb_fish;};
    float getChemicals(){return chemicals;};
    void setFish(int val);
    void setChemicals(float val);
    friend std::ostream & operator<<(std::ostream &out, const Water &w);
};

/*std::ostream & operator<<(std::ostream &out, const Water &w){
  out << (Surface)w;
  out << "Number of fish: " << w.nb_fish<< std::endl;
  out << "Chemicals concentration: "<< w.chemicals << "%"<< std::endl;
  return out;
}*/

#endif
