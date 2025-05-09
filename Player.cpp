#include "Player.h"
#include "Exceptions.h"
#include <iostream>
void Player::updatePosition(float& deltaTime)
{
}

Player::Player(const sf::Vector2f& a) : Entity{ a }
{
    sf::Image* image = new sf::Image;
    this->m_image = image;
    if (!image->loadFromFile("spaceship.png")) {
        delete image;
        image = nullptr;
        std::cerr << "Error loading image" << std::endl;
        return;
    }
    sf::Vector2u imageSize = image->getSize();

    m_texture = new sf::Texture(*m_image);
    m_sprite = new sf::Sprite(*m_texture);
    sf::IntRect crop(m_sprite->getGlobalBounds());
    m_sprite->setTextureRect(crop);
    m_sprite->setScale({ .1f, .1f });



    //seteaza m_xGlobalSize si m_yGlobalSize
    sf::FloatRect globalBounds = m_sprite->getGlobalBounds();
    m_xGlobalSize = globalBounds.size.x;
    m_yGlobalSize = globalBounds.size.y;


}



void Player::draw(sf::RenderWindow* window) const
{
    m_sprite->setPosition(this->m_coordonate);
    //setarea un box in jurul imaginii pentru a vizualiza mai bine entitatea

    sf::RectangleShape box;
    box.setSize(sf::Vector2f(m_sprite->getGlobalBounds().size));
    box.setPosition(m_sprite->getPosition());
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(1.f);
    box.setOutlineColor(sf::Color::Black);


    //window->draw(box);
    window->draw(*m_sprite);
}
void Player::update(float& deltaTime)
{

}
Player ::~Player()
{
	delete m_image;
	delete m_texture;
	delete m_sprite;
}
