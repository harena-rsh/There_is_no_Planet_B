#pragma once

#ifndef LANDSCAPE_H
#define LANDSCAPE_H

#include <iostream>
#include <string>

class Landscape {
  protected:
    std::string name;
    int nb_endangered_species;
  public:
    Landscape(){};
    Landscape(std::string str, int species):name(str),nb_endangered_species(species){};
    Landscape(Landscape const& l){name=l.name;nb_endangered_species=l.nb_endangered_species;};
    void set_endangered(int nb);
    int get_endangered(){ return nb_endangered_species;};
    //virtual void showLandscape(){ };
    friend std::ostream & operator<<(std::ostream &out, const Landscape &l);
};

/*std::ostream & operator<<(std::ostream &out, const Landscape &l){
  out <<  l.name << std::endl;
  out << "Number of endangered species: "<< l.nb_endangered_species << std::endl;
  return out;
}*/

#endif
