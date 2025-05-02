#include "Game.h"

void Game::createEntity(const EntityType& a, const sf::Vector2f& coords)
{
    switch (a)
    {
    case EntityType::PLAYER:
        entities.push_back(std::make_unique<Player>(coords));
        break;
    case EntityType::CHICKEN:
        entities.push_back(std::make_unique<Chicken>(coords));
        break;

    case EntityType::BULLET:
        entities.push_back(std::make_unique<Bullet>(coords));
        break;

    case EntityType::EGG:
        entities.push_back(std::make_unique<Egg>(coords));
        break;

    default:
        throw 100;
        std::cerr << "Tip de date necunoscut";
        break;
    }
}


Game::Game()  
{  
   sf::ContextSettings settings;  
   settings.antiAliasingLevel = 8;  \
       sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ 1920, 1080 }), "Duck attack!", sf::Style::Close, sf::State::Windowed);

       this->window = window;  

   //creaza player  

   createEntity(EntityType::PLAYER, { 1920.0f/2-Player::getXSize()/2.0f, float(1080.0f*9/10)});
   
   Player* playerEntity = dynamic_cast<Player*>(entities.back().get());  
 

   if (playerEntity) {  
       std::cout << "Player adaugat cu succes!" << std::endl;  
   }
   else {
       throw 100;
       std::cerr << "Eroare la adaugarea Player-ului!" << std::endl;  
   }  
}
Game::~Game()
{
    delete window;
}

void Game::generateSetChickens()
{
    float xGap = 5.0f;
    float yGap = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
			float spacingX = ((1920 - 2 * 200) - 12 * Chicken::getXSize()) / 7.0f;
            //(1920.0f-400) / 8 - Chicken::getXSize() / 2.0f;
            createEntity(EntityType::CHICKEN, { j * (yGap + Chicken::getYSize()) + 200.0f, i * (spacingX + Chicken::getXSize()) + 200.0f});
        }
    }
}

void Game::movementChickens() {
    for (const auto& entity : entities) {
        if (auto chicken = dynamic_cast<Chicken*>(entity.get())) {
            //chicken->
        }
        else {
            (this->wave)++;
            generateSetChickens();
        }
    }
}


void Game::run() {
    generateSetChickens();
    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();
        }
		//else if (event->is<sf::Event::KeyPressed>())
        window->clear(sf::Color::White);
		//Chicken* chicken = dynamic_cast<Chicken*>(entities.back().get());
		//chicken->draw(window);
        drawChickensSet();
        window->display();
    }
}


void Game::drawChickensSet()
{
    for (const auto& entity : entities) {
        if (auto chicken = dynamic_cast<Chicken*>(entity.get())) {
            chicken->draw(window);
        }
    }
}

//void Game::draw() 
//{
//	
//}