#pragma once

#ifndef ISLAND_H
#define ISLAND_H

#include "surface.hh"
#include <iostream>
#include <string>

class Island:public Surface {
  private:
    float level_above_the_water;
  public:
    Island(){};
    Island(std::string name,float level):Surface(name,999),level_above_the_water(level){};
    int showLandscape();
    float getLevel(){return level_above_the_water;};
    void setLevel(float val);
    friend std::ostream & operator<<(std::ostream &out, const Island &isl);
};

/*std::ostream & operator<<(std::ostream &out, const Island &isl){
  out << (Surface)isl;
  out << "Level above water: "<< isl.level_above_the_water << " meters"<< std::endl;
  return out;
}*/

#endif
