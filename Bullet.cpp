#include "Game.h"
#include "Bullet.h"
#include "SFML/Graphics.hpp"

Bullet::Bullet(const sf::Vector2f& coords) : Entity(coords)
{
	m_rectangle = new sf::RectangleShape(sf::Vector2f{10.f, 50.f});
    sf::FloatRect globalBounds = m_rectangle->getGlobalBounds();
    m_xGlobalSize = globalBounds.size.x;
    m_yGlobalSize = globalBounds.size.y;

}


void Bullet::draw(sf::RenderWindow* window) const
{
	m_rectangle->setPosition(this->m_coordonate);
    //setarea un box in jurul imaginii pentru a vizualiza mai bine entitatea

    m_rectangle->setFillColor(sf::Color::Red);
    m_rectangle->setOutlineThickness(1.f);
    m_rectangle->setOutlineColor(sf::Color::Black);
	window->draw(*m_rectangle);
}
void Bullet::update(float& deltaTime)
{
	m_coordonate.y -= m_speed * deltaTime;

}
Bullet::~Bullet()
{
   
}