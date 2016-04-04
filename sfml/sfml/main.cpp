#include <SFML/Graphics.hpp>
#include <iostream>
int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");
  //sf::CircleShape shape(100.f);
  //shape.setFillColor(sf::Color::Green);
  sf::Clock clock;
  sf::Time time;// = sf::seconds(2);

  std::string message = "Hello";
  std::string display = "";

  while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
        std::cout << event.type << std::endl;
        std::cout << event.key.code << std::endl;
        std::cout << "///" << std::endl;

        if (event.type == sf::Event::Closed)
            window.close();

        if (event.type == sf::Event::KeyPressed){
            if (event.key.code == sf::Keyboard::Return)
            {
                display += message;
                //system("cls");
                std::cout << display;

                //if (window.waitEvent(event)){
                //}
            }
        }
      }

      time = clock.getElapsedTime();
      //std::cout << time.asSeconds() << std::endl;

      //window.clear();
      //window.draw(shape);
      //window.setPosition(sf::Vector2i(700,500));
      //window.setSize(sf::Vector2u(500,500));
      window.display();
    }

  return 0;
}
