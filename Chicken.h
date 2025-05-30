#include "Entity.h"
#include <random>
#ifndef CHICKEN_HPP
#define CHICKEN_HPP

class Chicken : public Entity
{
private:
    
    float m_speed=100.f;
    float m_xGlobalSize=0, m_yGlobalSize=0;
	float m_initial_yPosition; 

    inline static int m_direction = 1;
    const float M_WIDTH_GAP = 30.0f;
    const float M_HEIGHT_GAP = 5.0f;
 
    
    sf::Image* m_image = nullptr;
    sf::Texture* m_texture = nullptr;
    sf::Sprite* m_sprite = nullptr;

    //pentru generarea numerelor random
    float m_minInterval=3.5f;
    float m_remainedTime=5.f;
	inline static float m_maxInterval=15.f;
    std::random_device m_rd;
    std::mt19937 m_rng;
    std::uniform_real_distribution<float> m_dist;



    void updatePosition(float& deltaTime);

public:
    Chicken() = delete;
    Chicken(const sf::Vector2f& coords);
	Chicken(const Chicken&) = delete;
    ~Chicken();
    /*std::unique_ptr<Entity> clone() const override {
        return std::make_unique<Chicken>(sf::Vector2f{ getCoords().x, getCoords().y });
    }*/
    void draw(sf::RenderWindow* window) const override;
    void update(float& deltaTime) override;
    
    
    float getX_GlobalSize() const { return m_xGlobalSize; }
    float getY_GlobalSize() const { return m_yGlobalSize; }
    float get_heightGap()   const { return M_HEIGHT_GAP; }
    float get_widthGap()    const { return M_WIDTH_GAP; }
	float get_initialYPosition() const { return m_initial_yPosition; }
	static void set_maxInterval() { m_maxInterval *= m_maxInterval*0.9f; }
};

#endif