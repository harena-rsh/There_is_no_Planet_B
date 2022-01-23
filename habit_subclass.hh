#pragma once

#ifndef HABIT_SUBCLASS_H
#define HABIT_SUBCLASS_H

#include "planet.hh"
#include "air.hh"
#include "forest.hh"
#include "fresh_water.hh"
#include "salt_water.hh"
#include "island.hh"
#include "water.hh"
#include "surface.hh"

class Air_Saving:public Habit{
private:
    int pollution_reduction;
    float temperature_reduction;
    float humidity_reduction;
public:
    Air_Saving(){};
    Air_Saving(std::string name, int point, int hp, int pr, float tr, float hr): Habit(name,point,hp),
    pollution_reduction(pr), temperature_reduction(tr), humidity_reduction(hr){};
    void purifyAir(Planet p, Hero h, Air a);
    int getPollutionReduction(){return pollution_reduction;};
    float getTemperatureReduction(){return temperature_reduction;};
    float getHumidityReduction(){return humidity_reduction;};
    void setPollutionReduction (int val){pollution_reduction = val;};
    void setTemperatureReduction (float val){temperature_reduction = val;};
    void setHumidityReduction (float val){humidity_reduction = val;};
};

class Land_Saving:public Habit{
private:
    int tree_gain;
    int level_gain;
public:
    Land_Saving(){};
    Land_Saving(std::string name, int point, int hp, int tg, int lg): Habit(name,point,hp),tree_gain(tg),level_gain(lg){};
    void plantTree(Planet p, Hero h, Forest f);
    void riseUp(Planet p, Hero h, Island isl);
    int getTreeGain(){return tree_gain;};
    int getLevelGain(){return level_gain;};
    void setTreeGain (int val){tree_gain = val;};
    void setLevelGain (int val){level_gain = val;};
};

class Water_Saving:public Habit{
private:
    int fish_gain;
    int purity_gain;
    int fresh_water_gain;
    float oil_reduction;
    float chemicals_reduction;
public:
    Water_Saving(){};
    Water_Saving(std::string name, int point, int hp, int fg, int pg, int fwg, float oilr, float cr): Habit(name,point,hp),
    fish_gain(fg), purity_gain(pg),fresh_water_gain(fwg),oil_reduction(oilr),chemicals_reduction(cr){};
    void refreshWater(Planet p, Hero h, Fresh_Water fw);
    void cleanOilSpill(Planet p, Hero h, Salt_Water sw);
    int getFishGain(){return fish_gain;};
    int getPurityGain(){return purity_gain;};
    int getFreshWaterGain(){return fresh_water_gain;};
    float getOilReduction(){return oil_reduction;};
    float getChemicalsReduction(){return chemicals_reduction;};
    void setFishGain (int val){fish_gain= val;};
    void setPurityGain (int val){purity_gain = val;};
    void setFreshWaterGain (int val){fresh_water_gain= val;};
    void setOilReduction (float val){oil_reduction = val;};
    void setChemicalsReduction (float val){chemicals_reduction = val;}
};

#endif
