#pragma once

#ifndef HABIT_H
#define HABIT_H

#include <string>
#include <vector>

class Habit {
  protected:
    std::string _name;
    int nb_points;
    bool checked;
    int health_points;

  public:
    Habit(){};
    Habit(std::string name,int point,int hp):_name(name),nb_points(point),health_points(hp){};
    Habit(const Habit &h){_name=h._name; nb_points=h.nb_points; health_points=h.health_points;};
    std::string getName(){return _name;};
    int getPoint(){return nb_points;};
    void setChecked(){checked=true;};
    bool isChecked();
};

class Hero {
  private:
    std::string _name;
    std::vector <Habit> habit;
    int nb_points;
  public:
    Hero(){};
    Hero(std::string name):_name(name),nb_points(0){};
    void setName(std::string name);
    int getPoint(){return nb_points;};
    std::string getName(){return _name;};
    void addHabit(Habit hab);
    std::vector<Habit> getHabit(){ return habit;};
    void addPointHero(int point);
};

#endif
