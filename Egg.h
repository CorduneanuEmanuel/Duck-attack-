#include "Entity.h"
#ifndef EGG_HPP
#define EGG_HPP

class Egg : public Entity
{
private:
    float m_speed = 250.f;
    float m_xGlobalSize = 0, m_yGlobalSize = 0;
    

    sf::Image* m_image = nullptr;
    sf::Texture* m_texture = nullptr;
    sf::Sprite* m_sprite = nullptr;

    void updatePosition(float& deltaTime);

public:
    Egg() = delete;
    Egg(const sf::Vector2f& coords);
	Egg(const Egg&) = delete;
    ~Egg();
    //std::unique_ptr<Entity> clone() const override { return std::make_unique<Egg>(sf::Vector2f{getCoords().x, getCoords().y}); }
    void draw(sf::RenderWindow* window) const override;
    void update(float& deltaTime) override;
  
    


    float getX_GlobalSize() const { return m_xGlobalSize; }
    float getY_GlobalSize() const { return m_yGlobalSize; }



};


#endif