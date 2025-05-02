#include "Entity.h"
#ifndef PLAYER_HPP
#define PLAYER_HPP


class Player : public Entity
	{
	private:
		inline static float xSize, ySize;
	    float m_widthGap= 0.0f;
	    float m_heightGap = 0.0f;
	
	public:
		Player() = delete;
	    Player(const sf::Vector2f& a);
	    Player(const Player&);
	    ~Player() = default;
	    
	    void draw(sf::RenderWindow* window) const override;
	    void update() override;
	    std::unique_ptr<Entity> clone() const override{
	        return std::make_unique<Player>(*this);
	    }	
		static float getXSize() { return xSize; }
		static float getYSize() { return ySize; }
	};

#endif