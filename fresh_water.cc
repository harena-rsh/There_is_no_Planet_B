#include "fresh_water.hh"
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

int Fresh_Water::showLandscape(){
  sf::RenderWindow window(sf::VideoMode(800,600),"No Planet B");

  sf::Texture sale;
  sale.create(4,3);
  if (!sale.loadFromFile("eau_sale.jpg"))
      return EXIT_FAILURE;

  sf::Texture pure;
  pure.create(4,3);
  if (!pure.loadFromFile("pure_water.jpg"))
      return EXIT_FAILURE;

  std::cout << purity << std::endl;
  /*Pour remplir la fenêtre on fait une liste de sprite*/
  int x=0;
  int y=0;
  int cpt_pure=0;
  std::list<sf::Sprite> sl;
  for(int j=0;j<10;j++){//on remplit les colonnes
    for(int i=0;i<10;i++){ //on remplit une ligne
      if(cpt_pure<purity){
        sf::Sprite sprite(pure);
        sprite.setTextureRect(sf::IntRect(0,0,80,60));
        sprite.setPosition(x,y);
        sl.push_back(sprite);
        cpt_pure++;
      }
      else {
        sf::Sprite sprite(sale);
        sprite.setTextureRect(sf::IntRect(0,0,80,60));
        sprite.setPosition(x,y);
        sl.push_back(sprite);
      }
      x=x+80;
    }
    x=0;
    y=y+60;
  }

  //std::cout<<"Nombre de sprite ="<<sl.size()<<std::endl;
  // Start the game loop
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
      for(std::list<sf::Sprite>::iterator it = sl.begin(); it != sl.end(); it++){
		        window.draw(*it);
	     }
      // Update the window
      window.display();
  }
  return EXIT_SUCCESS;
}

void Fresh_Water::setPure(float val){
  purity=val;
}

void Fresh_Water::setVolume(float val){
  volume=val;
}
