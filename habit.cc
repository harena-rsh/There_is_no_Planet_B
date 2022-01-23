#include "habit_subclass.hh"

bool Habit::isChecked(){
  if(checked==1){
    return true;
  }
  else {
    return false;
  }
}

void Air_Saving::purifyAir(Planet p, Hero h, Air a){
	p.addHealthPlanet(health_points);
	h.addPointHero(nb_points);
	a.setPollution(a.getPollution() - pollution_reduction);
	a.setTemperature(a.getTemperature() - temperature_reduction);
	a.setHumidity(a.getHumidity() - humidity_reduction);
	checked = 0;
}

void Land_Saving::plantTree(Planet p, Hero h, Forest f){
	p.addHealthPlanet(health_points);
	h.addPointHero(nb_points);
	f.setNbTree(f.getNbTree() + tree_gain);
	checked = 0;
}

void Land_Saving::riseUp(Planet p, Hero h, Island isl){
	p.addHealthPlanet(health_points);
	h.addPointHero(nb_points);
	isl.setLevel(isl.getLevel() + level_gain);
	checked = 0;
}

void Water_Saving::refreshWater(Planet p, Hero h, Fresh_Water fw){
	p.addHealthPlanet(health_points);
	h.addPointHero(nb_points);
	fw.setFish(fw.getFish() + fish_gain);
	fw.setChemicals(fw.getChemicals() - chemicals_reduction);
	fw.setPure(fw.getPure() + purity_gain);
	fw.setVolume(fw.getVolume() + fresh_water_gain);
	checked = 0;
}

void Water_Saving::cleanOilSpill(Planet p, Hero h, Salt_Water sw){
	p.addHealthPlanet(health_points);
	h.addPointHero(nb_points);
	sw.setFish(sw.getFish() + fish_gain);
	sw.setChemicals(sw.getChemicals() - chemicals_reduction);
	sw.setOil(sw.getOil() - oil_reduction);
	checked = 0;
}
