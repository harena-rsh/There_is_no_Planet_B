#include "island.hh"
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>


void Island::setLevel(float val){
  level_above_the_water=val;
}

int Island::showLandscape(){
  sf::RenderWindow window(sf::VideoMode(800,480),"No Planet B");

  sf::Texture island;
  island.create(4,3);
  if (!island.loadFromFile("island.png"))
      return EXIT_FAILURE;

  sf::Texture sea;
  sea.create(4,3);
  if (!sea.loadFromFile("ater.jpg"))
      return EXIT_FAILURE;

  sf::Sprite sprite1(sea);
  sprite1.setPosition(0,0);

  int x=0;
  int y=0;
  int cpt_island=0;
  std::list<sf::Sprite> sl;
  for(int j=0;j<5;j++){//on remplit les colonnes
    for(int i=0;i<5;i++){ //on remplit une ligne
        if(cpt_island<10){
          sf::Sprite sprite(island);
          sprite.setPosition(x,y);
          sl.push_back(sprite);
          cpt_island++;
        }
        x=x+138;
        }
      x=0;
      y=y+160;
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

          window.draw(sprite1);
          // Draw the sprite
          for(std::list<sf::Sprite>::iterator it = sl.begin(); it != sl.end(); it++){
                window.draw(*it);
           }
          // Update the window
          window.display();
    }
  return EXIT_SUCCESS;

}
