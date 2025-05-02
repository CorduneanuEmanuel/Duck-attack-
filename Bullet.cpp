#include "Game.h"
#include "Bullet.h"
#include "SFML/Graphics.hpp"

Bullet::Bullet(const sf::Vector2f& coords) : Entity(coords)
{
	coords_Player();
}

sf::Vector2f Bullet::coords_Player() const
{
	Game& game = Game::instance();
	
	return { 5.0f, 1.0f };
}

void Bullet::draw(sf::RenderWindow* window) const
{
	std::cout << "mere";
}
void Bullet::update()
{
	std::cout << "pere";
}
