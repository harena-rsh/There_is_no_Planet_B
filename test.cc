// Let Catch provide main():
/*#define CATCH_CONFIG_MAIN
  #include "catch.hpp"

//your includes here
#include "hero.hh"
#include "planet.hh"
#include "habit.hh"

#include <iostream>

TEST_CASE("1:Habit")
{
  Habit h1("Use reusable bag",10,5);
  REQUIRE(h1.getName()=="Use reusable bag");
  REQUIRE(h1.getPoint()==10);
  REQUIRE(h1.isChecked()==false);
  h1.setChecked();
  REQUIRE(h1.isChecked()==true);

}

TEST_CASE("2:Hero")
{
  Habit h2("Take public transportation",20,5);
  Hero hero1("Me");
  REQUIRE(hero1.getName()=="Me");
  hero1.addPointHero(10);
  REQUIRE(hero1.getPoint()==10);
  hero1.addHabit(h2);

}

TEST_CASE("3: Ecosys")
{
  Landscape l1(50);
  Air a1(14.5,45,25.5,15,48);
  REQUIRE(a1.getFineDust()==45);
  Surface s1(90.5);
  REQUIRE(s1.getWasteMass()==90.5);
  Island i1(85);
  REQUIRE(i1.getLevel()==85);
  Forest f1(5);
  REQUIRE(f1.getNbTree()==5);

}*/
