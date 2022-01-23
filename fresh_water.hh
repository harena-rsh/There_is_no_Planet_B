#pragma once

#ifndef FRESH_WATER_H
#define FRESH_WATER_H

#include "water.hh"
#include <iostream>
#include <string>

class Fresh_Water: public Water {
  private:
    float purity;
    float volume;
  public:
    Fresh_Water(std::string name,int nb_fish, float chemicals,float purity,float volume):Water(name,nb_fish,chemicals),purity(0),volume(volume){};
        int showLandscape();
    float getPure(){return purity;};
    void setPure(float val);
    float getVolume(){return volume;};
    void setVolume(float val);
    friend std::ostream & operator<<(std::ostream &out, const Fresh_Water &fw);
};

/*std::ostream & operator<<(std::ostream &out, const Fresh_Water &fw){
  out << (Water)fw;
  out << "Fresh water volume: " << fw.volume << " cubic_meter"<< std::endl;
  return out;
};*/

#endif
