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

    int wave = 1;
    std::vector<std::unique_ptr<Entity>> entities;
    sf::RenderWindow *window;
    Game();
    ~Game();

    void createEntity(const EntityType& a, const sf::Vector2f& coords);
public:
    Game(const Game&) = delete;
    Game& operator=(const Game&) = delete;

    static Game& instance()
    {
        static Game singleton;
        return singleton;
    }

    void generateSetChickens();
	void movementChickens();
    void run();
    void drawChickensSet();
};



#endif