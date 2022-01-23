#include "salt_water.hh"
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

void Salt_Water::setOil(float val){
  oil_leakage=val;
}

int Salt_Water::showLandscape(){
  sf::RenderWindow window(sf::VideoMode(800,480),"No Planet B");

  sf::Texture water;
  water.create(4,3);
  if (!water.loadFromFile("ater.jpg"))
      return EXIT_FAILURE;
  sf::Sprite sprite1(water);
  sprite1.setPosition(0,0);

  sf::Texture oil;
  oil.create(4,3);
  if (!oil.loadFromFile("oil.jpg"))
      return EXIT_FAILURE;

  int x=0;
  int y=0;
  int cpt_oil=0;
  std::list<sf::Sprite> sl;
  for(int j=0;j<2;j++){//on remplit les colonnes
    for(int i=0;i<20;i++){
      if(cpt_oil<(oil_leakage*40)/100){
        sf::Sprite sprite(oil);
        sprite.setPosition(x,y);
        sl.push_back(sprite);
        cpt_oil++;
      }
      x=x+40;
    }
    x=0;
    y=y+40;
  }

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
      window.clear(sf::Color(255,255,255));
      // Draw the sprite
      window.draw(sprite1);
      for(std::list<sf::Sprite>::iterator it = sl.begin(); it != sl.end(); it++){
            window.draw(*it);
       }
      // Update the window
      window.display();
  }
  return EXIT_SUCCESS;
}
