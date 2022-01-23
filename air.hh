#pragma once
#include "landscape.hh"
#include <iostream>
#include <string>

class Air:public Landscape {
  private:
    int pollution;
    float temperature;
    float humidity;
  public:
    Air(){};
    Air(int pollution,float temperature,float humidity):Landscape("Air",100),pollution(pollution),temperature(temperature),humidity(humidity){};
    int showLandscape(); //redéfinition
    float getPollution(){ return pollution;};
    float getTemperature(){ return temperature;};
    float getHumidity(){ return humidity;};
    void setPollution(float val);
    void setTemperature(float val);
    void setHumidity(float val);
    friend std::ostream & operator<<(std::ostream &out, const Air &air);
};

/*std::ostream & operator<<(std::ostream &out, const Air &air){
  out << (Landscape)air;
  out << "Temperature: " << air.temperature << "°C" << std::endl;
  out << "Humidity: " << air.humidity << "%"<< std::endl;
  return out;
}*/
