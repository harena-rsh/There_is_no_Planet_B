#pragma once

#ifndef FOREST_H
#define FOREST_H

#include "surface.hh"
#include <iostream>
#include <string>

class Forest : public Surface{
  private:
    int nb_trees;
  public:
    Forest(){};
    Forest(std::string name,int nb_trees):Surface(name,9999),nb_trees(nb_trees){};
    int showLandscape();
    int getNbTree(){return nb_trees;};
    void setNbTree(int val);
    friend std::ostream & operator<<(std::ostream &out, const Forest &f);
};

/*std::ostream & operator<<(std::ostream &out, const Forest &f){
  out << (Surface)f;
  out << "Number of trees: "<< f.nb_trees << " meters"<< std::endl;
  return out;
}*/

#endif
