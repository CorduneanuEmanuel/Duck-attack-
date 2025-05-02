#ifndef ENTITY_HPP
#define ENTITY_HPP
#include "SFML/Graphics.hpp"
#include <memory>

class Entity
	{

	protected:
	    sf::Vector2f m_coordonate;
	public:
		Entity() ;
	    Entity(const sf::Vector2f& coords) : m_coordonate{ coords } {}
	    virtual ~Entity() = default;
	    virtual void draw(sf::RenderWindow* window) const = 0;
	    virtual void update() = 0;
	    virtual std::unique_ptr<Entity> clone() const = 0;
	    sf::Vector2f getCoords() const { return m_coordonate; }
	
	};

#endif