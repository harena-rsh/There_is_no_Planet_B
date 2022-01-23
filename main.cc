#include <TGUI/TGUI.hpp>

#include "air.hh"
#include "forest.hh"
#include "fresh_water.hh"
#include "salt_water.hh"
#include "island.hh"
#include "water.hh"
#include "surface.hh"
#include "landscape.hh"

#include "habit.hh"
#include "habit_subclass.hh"
#include "planet.hh"
#include <vector>
#include <list>

/*Fonction qui met à jour les points*/
void function(){
  std::cout<<"You did a great action for the Planet!"<<std::endl;
}
/*Fonction Callbacks*/
void f_Island(){
  Island corse("Corse",30);
  corse.showLandscape();
}

void f_Forest(){
  Forest vincennes("Vincennes",50);
  vincennes.showLandscape();
}

void f_Sea(){
  Salt_Water manche("Manche",1234567,0.09,10);
  manche.showLandscape();
}

void f_Air(){
  Air b(50,25.3,50.4);
  b.showLandscape();
}

/*Fonction qui permet de créer un CheckBox à partir d'une habitude et d'une position
et l'affiche dans une fenêtre tgui::Gui*/
void create_checkbox(Habit h,int x, int y, tgui::Gui* gui){
  auto checkbox = tgui::CheckBox::create();
  checkbox->setPosition(x, y);
  checkbox->setText(h.getName());
  checkbox->setSize(25, 25);
  checkbox->connect("checked",function);
  gui->add(checkbox);
}


int main(){

  Hero her("Cecile");
  Planet earth("Not B", her, 10);
  Air_Saving habit1("Take the bike", 2, 3, 1, 0.1, 0.05);
  Land_Saving habit2("Use virtual ticket", 1, 1, 1, 0);
  Water_Saving habit3("Close the tap when brushing teeth", 2, 2, 0, 0, 1, 0, 0);

  Air a(100,30.5,70.9);
  Fresh_Water seine("Seine",12345,0.21,80,1000);


  /*Ajouter des habitudes dans le vecteur d'habitude*/
  her.addHabit(habit1);
  her.addHabit(habit2);
  her.addHabit(habit3);

  //int y=200;
  sf::RenderWindow window(sf::VideoMode(800, 600), "TGUI window");
  /*Création d'une fenêtre TGUI*/
  tgui::Gui gui(window);

  int pos_x=25;
  int pos_y=100;
  /*Boucle pour l'affichage des habitudes dans la fenêtre*/
  /*on parcourt le vecteur des habitudes du Héro et on affiche*/
  std::vector <Habit> hb=her.getHabit();
  for(std::vector<Habit>::iterator it = hb.begin(); it != hb.end(); it++){
    create_checkbox(*it,pos_x,pos_y,&gui); //création de la fenêtre
    pos_y=pos_y+50;
  }

  sf::Font font;
  if (!font.loadFromFile("OpenSans-Regular.ttf")){
    std::cout<<"ERREUR!"<<std::endl;
  }

  sf::Text text;
  text.setFont(font);
  text.setString("What did you do for the planet today ?");
  text.setColor(sf::Color::Green);
  text.setStyle(sf::Text::Bold);
  text.setPosition(25,50);

  sf::Text text1;
  text1.setFont(font);
  text1.setString("There is no planet B !");
  text1.setColor(sf::Color::Red);
  text1.setStyle(sf::Text::Bold);
  text1.setPosition(250,10);

  sf::Texture texture;
  if (!texture.loadFromFile("island.png"))
      return EXIT_FAILURE;

  sf::Sprite sprite1(texture);
  sprite1.setPosition(65,300);

  sf::Texture texture1;
  if (!texture1.loadFromFile("tree2.png"))
      return EXIT_FAILURE;

  sf::Sprite sprite2(texture1);
  sprite2.setPosition(250,300);

  sf::Texture texture2;
  if (!texture2.loadFromFile("water.jpg"))
      return EXIT_FAILURE;

  sf::Sprite sprite3(texture2);
  sprite3.setPosition(435,300);

  sf::Texture texture3;
  if (!texture3.loadFromFile("weather.png"))
      return EXIT_FAILURE;

  sf::Sprite sprite4(texture3);
  sprite4.setPosition(620,300);

  auto button = tgui::Button::create();
  button = tgui::Button::create();
  button->setPosition(75,450);
  button->setText("Show Island");
  button->setSize(100, 40);
  button->connect("pressed",f_Island);
  gui.add(button);

  auto button1 = tgui::Button::create();
  button1 = tgui::Button::create();
  button1->setPosition(260,450);
  button1->setText("Show Forest");
  button1->setSize(100, 40);
  button1->connect("pressed",f_Forest);
  gui.add(button1);

  auto button2 = tgui::Button::create();
  button2 = tgui::Button::create();
  button2->setPosition(445,450);
  button2->setText("Show Sea");
  button2->setSize(100, 40);
  button2->connect("pressed",f_Sea);
  gui.add(button2);

  auto button3 = tgui::Button::create();
  button3 = tgui::Button::create();
  button3->setPosition(630,450);
  button3->setText("Show Air");
  button3->setSize(100, 40);
  button3->connect("pressed",f_Air);
  gui.add(button3);

  while (window.isOpen())
  {
      sf::Event event;
      while (window.pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              window.close();

          gui.handleEvent(event);
      }

    window.clear(sf::Color(255,255,255));
    gui.draw();
    window.draw(text);
    window.draw(text1);
    window.draw(sprite1);
    window.draw(sprite2);
    window.draw(sprite3);
    window.draw(sprite4);
    window.display();
  }

  /*Test pour l'affichage de chaque fenêtre*/
  /*Air a(100,30.5,70.9);
  Air b(50,25.3,50.4);
  Fresh_Water seine("Seine",12345,0.21,80,1000);
  Salt_Water manche("Manche",1234567,0.09,10);
  Island corse("Corse",30);
  Forest vincennes("Vincennes",50);
  Landscape c("Borneo",200);
  a.showLandscape();
  corse.showLandscape();
  vincennes.showLandscape();*/
  /*std::cout << a << std::endl;
  std::cout << b << std::endl;
  std::cout << seine << std::endl;
  std::cout << manche << std::endl;
  std::cout << corse << std::endl;
  std::cout << vincennes << std::endl;
  std::cout << c << std::endl;*/
  /*Forest f1(5);
  Air a1(25.0,36);
  Fresh_Water water1(100);
  Salt_Water mer(100);
  Island mada(50);
  mada.showLandscape();
  mer.setOil(50);
  mer.showLandscape();
  water1.setPure(50);
  water1.showLandscape();
  f1.showLandscape();
  f1.setNbTree(75);
  f1.showLandscape();
  a1.showLandscape();
  a1.setPollution(50);
  a1.showLandscape();*/

/*sf::RenderWindow window(sf::VideoMode(800,600),"No Planet B");
// tant qu'il y a des évènements à traiter...
sf::Texture unchecked;
unchecked.create(4,3);
if (!unchecked.loadFromFile("unchecked.png"))
    return EXIT_FAILURE;

sf::Texture checked;
checked.create(4,3);
if (!unchecked.loadFromFile("cheked.png"))
    return EXIT_FAILURE;


sf::Sprite sprite(unchecked);
sprite.setPosition(50,10);

sf::Sprite sprite1(checked);*/
/*Grosse boucle fenêtre ouverte*/
/*while (window.isOpen())
{
    // Process events
    sf::Event event;
    while (window.pollEvent(event))
    {
        // Close window: exit
        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::MouseButtonPressed)
          {
            if (event.mouseButton.button == sf::Mouse::Left)
            {
              std::cout << "the left button was pressed" << std::endl;
              std::cout << "mouse x: " << event.mouseButton.x << std::endl;
              std::cout << "mouse y: " << event.mouseButton.y << std::endl;
            }
          }
    }
    // Clear screen
    window.clear(sf::Color(200,200,200));
    // Draw the sprite
    window.draw(sprite);
    // Update the window
    window.display();
}*/

  return EXIT_SUCCESS;
}
