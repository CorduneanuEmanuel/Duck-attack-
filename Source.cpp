#include "SFML/Graphics.hpp"
#include "Game.h"
#include <iostream>
#include <vector>
#include <memory>
#include <string>


int main()
{
    Game& game = Game::instance();
    game.run();

    //sf::ContextSettings settings;
    //settings.antiAliasingLevel = 8;
    //std::cout << typeid({ 800, 600 });
    //sf::RenderWindow window(sf::VideoMode({1920, 1080}), "Cerc Mov cu SFML", sf::Style::Close, sf::State::Windowed);

   
    //sf::Texture texture;
    //sf::Image image;


    //image.loadFromFile("duck.png");
    //texture.loadFromImage(image);
    //sf::Sprite sprite(texture);
    //sprite.setScale({ 0.05f, 0.05f });
    //float xPosition = 0.0f;
    //
    //
    //// Loop-ul principal
    //while (window.isOpen()) {
    //   
    //    // Șterge ecranul și desenează cercul
    //    while (const std::optional event = window.pollEvent())
    //    {


    //        if(event->is<sf::Event::Closed>()){
    //            window.close();
    //        }
    //        else if (event->is<sf::Event::KeyPressed>() )
    //        {
    //            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))std::cout << "shift";
    //            std::cout << "mancare";
    //        }
    //    }


    //    window.clear(sf::Color::White); // Fundal alb
    //    
    //    

    //    sprite.setPosition({ xPosition, 0.0f });
    //    xPosition += 0.5f;
    //    if (xPosition > 1000)xPosition = 0;

    //    
    //    window.draw(sprite);
    //    window.display();
    //    //
    //    



        //sf::sleep(sf::seconds(3.0f));
}