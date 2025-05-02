#include "Chicken.h"
#include <iostream>
Chicken::Chicken(const sf::Vector2f& coords) : Entity{ coords }
{

}

void Chicken::draw(sf::RenderWindow* window) const
{
    sf::Image image;
    if (!image.loadFromFile("duck2.png")) {
        std::cerr << "Error loading image" << std::endl;
        return;
    }
    sf::Texture texture(image);


    sf::Sprite sprite(texture);

    sprite.setPosition(this->m_coordonate);
    sprite.setScale({ 0.1f, 0.1f });
	sf::FloatRect globalBounds = sprite.getGlobalBounds();
    std::cout << globalBounds.size.x<< std::endl;
    window->draw(sprite);

}

void Chicken::update()
{
}
