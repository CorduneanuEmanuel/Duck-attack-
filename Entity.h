#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "SFML/Graphics.hpp"
#include <memory>

class Entity
	{

	protected:
	    sf::Vector2f m_coordonate;
		bool entityIsAlive = true;
		bool m_active = true;
	public:
		Entity() ;
	    Entity(const sf::Vector2f& coords) : m_coordonate{ coords } {}
	    virtual ~Entity() = default;
	    virtual void draw(sf::RenderWindow* window) const = 0;
	    virtual void update(float& deltaTime) = 0;
	    //virtual std::unique_ptr<Entity> clone() const = 0;
	    sf::Vector2f getCoords() const { return m_coordonate; }
		void set_entityIsAlive(bool alive) { entityIsAlive = alive; }
		bool entityAlive() const { return entityIsAlive; }

		void setActive(bool active) { m_active = active; }
		bool isActive() const { return m_active; }


};

#endif