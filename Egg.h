#include "Entity.h"
#ifndef EGG_HPP
#define EGG_HPP

class Egg : public Entity
{
private:
    inline static float xSize, ySize;
    float m_widthGap = 0.0f;
    float m_heightGap = 0.0f;
public:
    Egg() = delete;
    Egg(const sf::Vector2f& coords);
    ~Egg() = default;
    std::unique_ptr<Entity> clone() const override { return std::make_unique<Egg>(*this); }
    void draw(sf::RenderWindow* window) const;
    void update();
  
    static float getXSize() { return xSize; }
    static float getYSize() { return ySize; }
};


#endif