#include "Entity.h"
#ifndef CHICKEN_HPP
#define CHICKEN_HPP

class Chicken : public Entity
{
private:
    inline static float xSize=100.6f, ySize=100.6f;
    inline static int m_direction = 1;
    float m_widthGap = 0.0f;
    float m_heightGap = 0.0f;
public:
    Chicken() = delete;
    Chicken(const sf::Vector2f& coords);
    ~Chicken() = default;
    std::unique_ptr<Entity> clone() const override {
        return std::make_unique<Chicken>(*this);
    }
    void draw(sf::RenderWindow* window) const override;
    void update() override;
    static float getXSize() { return xSize; }
    static float getYSize() { return ySize; }
};

#endif