#pragma once

#ifndef PLANET_H
#define PLANET_H

#include <vector>
#include "landscape.hh"
#include "habit.hh"
#include <string>


class Planet {
  private:
    std::string _name;
    Hero _hero;
    int nb_landscapes;
    std::vector <Landscape> _landscapes;
    int _health;
  public:
    Planet(){};
    Planet(std::string name,Hero hero,int landscapes):_name(name),_hero(hero),nb_landscapes(landscapes),_health(25){};
    Planet(Planet& p){_name=p._name; _hero=p._hero; nb_landscapes = p.nb_landscapes; _landscapes = p._landscapes; _health = p._health;};
    void addLandscape(Landscape land);
    void addHealthPlanet(int health);
    int getHealth(){return _health;};
    /* Solution 1 (douteuse): récupérer les attributs de la planète pas référence
    std::vector <Landscape>& getLandscapes(){return &_landscapes;};
    Hero& getHero(){return &_hero;};*/
    /*Solution 2 la planète se met à jour elle-même*/
    void purifyAir(int health, int points, int pollution_reduction, float temperature_reduction, float humidity_reduction);
    void plantTree(int health, int points, int nb_tree);
    void riseUp(int health, int points, int level);
    void refreshWater(int health, int points, int fish_gain, float chemicals_reduction, int purity_gain, int fresh_water_gain);
    void cleanOilSpill(int health, int points, int fish_gain, float chemicals_reduction, int oil_reduction);
    void init();
};

#endif
