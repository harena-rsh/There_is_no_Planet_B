#include "habit.hh"

void Hero::setName(std::string name){
  _name=name;
}

/*Insérer une nouvelle habitude dans la map*/
void Hero::addHabit(Habit hab){
  habit.push_back(hab);
}

void Hero::addPointHero(int point){
  nb_points=nb_points+point;
}
