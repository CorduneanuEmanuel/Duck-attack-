#ifndef GAME_HPP
#define GAME_HPP
#include "Includes.h"
#include <vector>
#include <memory>
#include <iostream>

class Game {
private:

    enum class EntityType : int
    {
        PLAYER,
        CHICKEN,
        BULLET,
        EGG
    };

	bool m_gameOver = false;
	float m_score = 0;


    int m_chickensRemained=40;
    int m_wave = 1;
    float m_speed = 20.0f;
    

    float m_minInterval = 2.f;
    float m_maxInterval = 15.f;
    std::mt19937 m_random;
    std::uniform_real_distribution<float> m_dist;



    std::vector<std::unique_ptr<Entity>> entities;
    sf::RenderWindow *window;
    Game();
    ~Game();

    //void createEgg();
public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    static Game& instance()
    {
        static Game singleton;
        return singleton;
    }

    void generateSetChickens();
	void movementChickens(float& deltaTime);
    void drawEntities();
    void createEntity(const EntityType& a, const sf::Vector2f& coords);
    EntityType getEntityType(const int&);
   

    void run();
    void updateEgg(float& deltaTime);
	void updateBullet(float& deltaTime);
	void collisionDetection();

};



#endif