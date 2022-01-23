#include "planet.hh"
#include "air.hh"

void Planet::addLandscape(Landscape land){
  _landscapes.push_back(land);
}

void Planet::addHealthPlanet(int health){
  _health=_health+health;
}

/*void Planet::purifyAir(int health, int points, int pollution_reduction, float temperature_reduction, float humidity_reduction){
	_health += health;
	_hero.setPoint(_hero.getPoint() + points);
	for (auto it=_landscapes.begin(); it!=_landscapes.end(); ++it){
		if(is_base_of<Air,(*it)>){
			(*it).setPollution((*it).getPollution() - pollution_reduction);
			(*it).setTemperature((*it).getTemperature() - temperature_reduction);
			(*it).setHumidity((*it).getHumidity() - humidity_reduction);
		}
	}
	checked = 0;
}

void Land_Saving::plantTree(Planet p){
	_health += health;
	_hero.setPoint(_hero.getPoint() + points);
	for (auto it=_landscapes.begin(); it!=_landscapes.end(); ++it){
		if(is_base_of<Forest,(*it)>){
			(*it).setNbTree((*it).getNbTree() + tree_gain);
		}
	}
	checked = 0;
}

void Land_Saving::riseUp(Planet p){
	_health += health;
	_hero.setPoint(_hero.getPoint() + points);
	for (auto it=_landscapes.begin(); it!=_landscapes.end(); ++it){
		if(is_base_of<Island,(*it)>){
			(*it).setLevel((*it).getLevel() + level_gain);
		}
	}
	checked = 0;
}

void Water_Saving::refreshWater(Planet p){
	_health += health;
	_hero.setPoint(_hero.getPoint() + points);
	for (auto it=_landscapes.begin(); it!=_landscapes.end(); ++it){
		if(is_base_of<Fresh_Water,(*it)>){
			(*it).setFish((*it).getFish() + fish_gain);
			(*it).setChemicals((*it).getChemicals() - chemicals_reduction);
			(*it).setPure((*it).getPure() + purity_gain);
			(*it).setVolume((*it).getVolume() + fresh_water_gain);
		}
	}
	checked = 0;
}

void Water_Saving::cleanOilSpill(Planet p){
	_health += health;
	_hero.setPoint(_hero.getPoint() + points);
	for (auto it=_landscapes.begin(); it!=_landscapes.end(); ++it){
		if(is_base_of<Salt_Water,(*it)>){
			(*it).setFish((*it).getFish() + fish_gain);
			(*it).setChemicals((*it).getChemicals() - chemicals_reduction);
			(*it).setOil((*it).getOil() - oil_reduction);
		}
	}
	checked = 0;
}*/
