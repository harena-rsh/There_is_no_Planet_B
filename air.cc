#include "air.hh"
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

void Air::setTemperature(float val){
  temperature=val;
}

void Air::setHumidity(float val){
  humidity=val;
}

void Air::setPollution(float val){
  pollution=val;
}

int Air::showLandscape(){
  sf::RenderWindow window(sf::VideoMode(800,480),"No Planet B");

  sf::Texture sun;
  sun.create(4,3);
  if (!sun.loadFromFile("sun1.jpg"))
      return EXIT_FAILURE;
  sf::Texture cloud;
  cloud.create(4,3);
  if (!cloud.loadFromFile("cloud2.png"))
      return EXIT_FAILURE;

  int x=0;
  int y=0;
  std::list<sf::Sprite> sl;
    for(int j=0;j<10;j++){//on remplit les colonnes
      for(int i=0;i<10;i++){ //on remplit une ligne
        sf::Sprite sprite(cloud);
        sprite.setTextureRect(sf::IntRect(0,0,80,60));
        sprite.setPosition(x,y);
        sl.push_back(sprite);
        x=x+80;
      }
      x=0;
      y=y+48;
    }

  /*on enlève en fonction de la valeur de l'attribut pollution*/
  for(int i=0;i<(100-pollution);i++){
      sl.pop_back();
  }

  sf::Sprite sprite(sun);
  sprite.setPosition(0,0);

  while (window.isOpen())
  {
      // Process events
      sf::Event event;
      while (window.pollEvent(event))
      {
          // Close window: exit
          if (event.type == sf::Event::Closed)
              window.close();
      }
      // Clear screen
      window.clear(sf::Color(249,221,109));
      window.draw(sprite);
      // Draw the sprite
      for(std::list<sf::Sprite>::iterator it = sl.begin(); it != sl.end(); it++){
          window.draw(*it);
       }
      window.display();
  }
  return EXIT_SUCCESS;
}
