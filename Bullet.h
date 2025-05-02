#ifndef BULLET_HPP  
#define BULLET_HPP  
#include "Entity.h"  

class Bullet : public Entity  
{  
private:  
   inline static float xSize, ySize;  
   sf::Vector2f coords_Player() const;  
   float m_widthGap = 0.0f;  
   float m_heightGap = 0.0f;  
public:  
   Bullet() = delete;  
   Bullet(const sf::Vector2f& coords);  
   ~Bullet() = default;  
   std::unique_ptr<Entity> clone() const override  
   {  
        return std::make_unique<Bullet>(*this);  
   }  
   void draw(sf::RenderWindow* window) const override;  
   void update() override;  

   // Getters for xSize and ySize  
   static float getXSize()  { return xSize; }  
   static float getYSize()  { return ySize; }  
};  

#endif
