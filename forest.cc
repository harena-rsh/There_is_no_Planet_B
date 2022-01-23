#include "forest.hh"
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

void Forest::setNbTree(int val){
  nb_trees=val;
}

int Forest::showLandscape(){
  sf::RenderWindow window(sf::VideoMode(600,600),"No Planet B");

  sf::Texture tree;
  tree.create(4,3);
  if (!tree.loadFromFile("tree2.png"))
      return EXIT_FAILURE;

  int x=0;
  int y=0;
  int cpt_tree=0;
  std::list<sf::Sprite> sl;

  for(int j=0;j<10;j++){//on remplit les colonnes
    for(int i=0;i<10;i++){ //on remplit une ligne
      if(cpt_tree<nb_trees){
        sf::Sprite sprite(tree);
        sprite.setPosition(x,y);
        sl.push_back(sprite);
        cpt_tree++;
      }
      x=x+60;
    }
    x=0;
    y=y+60;
  }
  //std::cout<<"Position x = "<<x<<std::endl;
  //std::cout<<"Position y = "<<y<<std::endl;

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
      // Draw the sprite
      for(std::list<sf::Sprite>::iterator it = sl.begin(); it != sl.end(); it++){
            window.draw(*it);
       }
      // Update the window
      window.display();
  }
  return EXIT_SUCCESS;
}
