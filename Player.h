#include "Entity.h"
#ifndef PLAYER_HPP
#define PLAYER_HPP


class Player : public Entity
{
private:
	float m_speed = 600.f;
	float m_xGlobalSize = 0, m_yGlobalSize = 0;
	//bool m_fillColor = false;
	sf::Image* m_image = nullptr;
	sf::Texture* m_texture = nullptr;
	sf::Sprite* m_sprite = nullptr;


	void updatePosition(float& deltaTime);

public:
	Player() = delete;
	Player(const sf::Vector2f& a);
	Player(const Player&) = delete;
	~Player();

	void draw(sf::RenderWindow* window) const override;
	void update(float& deltaTime) override;
	/*std::unique_ptr<Entity> clone() const override {
		return std::make_unique<Player>(sf::Vector2f{ getCoords().x, getCoords().y });
	}*/
	float getX_GlobalSize() const { return m_xGlobalSize; }
	float getY_GlobalSize() const { return m_yGlobalSize; }
	void set_UP(float& deltaTime) { m_coordonate.y -= m_speed*deltaTime; }
	void set_DOWN(float& deltaTime) { m_coordonate.y += m_speed * deltaTime; }
	void set_RIGHT(float& deltaTime) { m_coordonate.x += m_speed * deltaTime; }
	void set_LEFT(float& deltaTime) { m_coordonate.x -= m_speed * deltaTime; }
	//void set_SPACE(float& deltaTime) { m_coordonate.y -= m_speed * deltaTime; }

};

#endif