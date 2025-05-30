#include "Factory_pattern.h"
#ifndef GAME_HPP
#define GAME_HPP
#include "Includes.h"
#include "Exceptions.h"
#include <vector>
#include <memory>
#include <iostream>
#include <exception>

class Factory_pattern
{
    std::vector<std::unique_ptr<Entity>>* entities = nullptr;
public:
    Factory_pattern(std::vector<std::unique_ptr<Entity>>* entities) : entities{ entities } {  }
    //Factory_pattern() : entities{ nullptr } {}
	template <typename T>
    void createEntity(const sf::Vector2f& coords)
    {
		if (entities == nullptr)
			throw std::runtime_error("Entities vector is not initialized.");

        else
        {
            
			entities->emplace_back(std::make_unique<T>(coords));
        }
    }
    void generateSetChickens();
    void createPlayer();
    void setEntities(std::vector<std::unique_ptr<Entity>>& entities) { }
};

class Object_pool
{
	std::vector<std::unique_ptr<Entity>>* pool = nullptr;
public:
	Object_pool() = default;
	~Object_pool() = default;
    void lookOut();
	void resetEntity(int EntityType, const sf::Vector2f& coords);
};


class Game {
private:
    /*enum class EntityType : int
    {
        PLAYER,
        CHICKEN,
        BULLET,
        EGG,
        SPECIAL_BULLET
    };*/

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
    Factory_pattern m_factory;

    //void 
    // Egg();
public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    static Game& instance()
    {
        static Game singleton;
        return singleton;
    }

    //void generateSetChickens();
	void movementChickens(float& deltaTime);
    void drawEntities();
    //void createEntity(const EntityType& a, const sf::Vector2f& coords);
    //enum EntityType getEntityType(const int&);
   

    void run();
    void updateEgg(float& deltaTime);
	void updateBullet(float& deltaTime);
	void collisionDetection();
	template <typename T>
    void createEnt(sf::Vector2f b)
    {
        m_factory.createEntity<T>(b);
    }
};






#endif