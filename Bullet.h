#ifndef BULLET_HPP  
#define BULLET_HPP  
#include "Entity.h"  

class Bullet : public Entity  
{  
private:  
    const float m_speed = 800.f;
    float m_xGlobalSize = 0, m_yGlobalSize = 0;
    
    
    sf::RectangleShape* m_rectangle = nullptr;
    sf::Image* m_image = nullptr;
	sf::Texture* m_texture = nullptr;
	sf::Sprite* m_sprite = nullptr;


public:  
   Bullet() = delete;  
   Bullet(const sf::Vector2f& coords);  
   ~Bullet();  
   std::unique_ptr<Entity> clone() const override  
   {  
        return std::make_unique<Bullet>(sf::Vector2f{ getCoords().x, getCoords().y });
   }  
   void draw(sf::RenderWindow* window) const override;  
   void update(float& deltaTime) override;  

   // Getters for xSize and ySize  
   float getX_GlobalSize() const { return m_xGlobalSize; }
   float getY_GlobalSize() const { return m_yGlobalSize; }
};  

#endif
