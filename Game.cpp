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

Game::EntityType Game::getEntityType(const int& i)
{
	if (i == 0)
		return EntityType::PLAYER;
	else if (i == 1)
		return EntityType::CHICKEN;
	else if (i == 2)
		return EntityType::BULLET;
	else if (i == 3)
        return EntityType::EGG;
}



Game::Game()  
{  
   sf::ContextSettings settings;  
   settings.antiAliasingLevel = 8;  
       sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode({ 1920, 1080 }), "Duck attack!", sf::Style::Close, sf::State::Windowed);

       this->window = window;  

   //creaza player  

   createEntity(EntityType::PLAYER, { 1920.0f/2-100.f, float(1080.0f*8/10)});
   
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

    Chicken* copyChicken = new Chicken({ 1.f,1.f });
	
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 8; j++) {
            
			float availableWidth = 1920.0f - 2 * 250;
            float total_width = copyChicken->getX_GlobalSize() * 8.0f + copyChicken->get_widthGap()*7;
            float spacing = (availableWidth-total_width)/ 2.0f;
            
            //(1920.0f-400) / 8 - Chicken::getXSize() / 2.0f;
            createEntity(EntityType::CHICKEN, { 250.0f+spacing+
                j*(copyChicken->getX_GlobalSize()+copyChicken->get_widthGap()), 
                100.0f+copyChicken->get_initialYPosition() + i * (copyChicken->get_heightGap() + copyChicken->getY_GlobalSize())});
         
        }
    }

	delete copyChicken;
}

void Game::movementChickens(float& deltaTime) {


    bool chickenFound = false;
    for (const auto& entity : entities) {
        if (auto chicken = dynamic_cast<Chicken*>(entity.get())) {
            chickenFound = true;
			chicken->update(deltaTime);
        
        }
    }
    if (!chickenFound) 
    {
        
        (this->m_wave)++;
        if (this->m_wave == 10) 
        {
			std::cout << "You win!" << std::endl;
            
        }
        Chicken::set_maxInterval();
        m_chickensRemained = 40;
        generateSetChickens();
    }
}


void Game::run() {
	//createEntity(EntityType::EGG, { 40.f,40.f });

	float bulletInterval = 0.5f;
    Egg *egg = new Egg({40.f,40.f});
    generateSetChickens();
    sf::Clock clock;
    Player* player=nullptr;
    if(entities.size()!=0)
    {
		player = dynamic_cast<Player*>(entities[0].get());
    }

    while (window->isOpen())
    {   

		float deltaTime = clock.restart().asSeconds();

        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window->close();

        }
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
		{
			window->close();
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
		{
			player->set_UP(deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
		{
			player->set_DOWN(deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
		{
			player -> set_LEFT(deltaTime);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
		{
			player -> set_RIGHT(deltaTime);
		}
		
        bulletInterval -= deltaTime;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
        {
            if (bulletInterval < 0)
            {
                createEntity(EntityType::BULLET, { player->getCoords().x + player->getX_GlobalSize() / 2.f - 10.f,
                   player->getCoords().y - 30.f });
				bulletInterval = 0.5f;
            }
        }

        
        movementChickens(deltaTime);
        updateEgg(deltaTime);
		updateBullet(deltaTime);
        egg->update(deltaTime);

        collisionDetection();
		if (m_gameOver)
		{
			std::cout << "GAME OVER!!!" << std::endl;
			std::cout << "Scorul tau este: " << m_score << std::endl;
			window->close();
            return;
		}
        //partea de desenare
        window->clear(sf::Color::Cyan);
        drawEntities();
        //player->draw(window);
        window->display();
    }
    delete egg;
}

void Game::updateEgg(float& deltaTime)
{
    for (const auto& entity : entities) {
        if (auto egg = dynamic_cast<Egg*>(entity.get())) {
            
            egg->update(deltaTime);

        }
    }
    /*if (!chickenFound)
    {

        (this->m_wave)++;
        if (this->m_wave == 10)
        {
            std::cout << "You win!" << std::endl;

        }
        Chicken::set_maxInterval();
        m_chickensRemained = 40;
        generateSetChickens();
    }*/
}

void Game::updateBullet(float& deltaTime)
{
	for (const auto& entity : entities) {
		if (auto bullet = dynamic_cast<Bullet*>(entity.get())) {
			bullet->update(deltaTime);
		}
	}
}

void Game::collisionDetection()  
{  
    bool reset = false;
   for (auto it = entities.begin(); it != entities.end(); ++it)
   {
       if (auto bullet = dynamic_cast<Bullet*>(it->get())) {
           for (auto it2 = entities.begin(); it2 != entities.end(); ++it2)
           {
               if (auto chicken = dynamic_cast<Chicken*>(it2->get())) {
                   if (bullet->getCoords().x + bullet->getX_GlobalSize() > chicken->getCoords().x &&
                       bullet->getCoords().x < chicken->getCoords().x + chicken->getX_GlobalSize() &&
                       bullet->getCoords().y + bullet->getY_GlobalSize() > chicken->getCoords().y &&
                       bullet->getCoords().y < chicken->getCoords().y + chicken->getY_GlobalSize())
                   {
                       (*it)->set_entityIsAlive(false); 
                       reset = true;
					   m_score += 50;
                       entities.erase(it2);
                       break;
                   }
               }
               else if (auto egg = dynamic_cast<Egg*>(it2->get())) {
                   if (bullet->getCoords().x + bullet->getX_GlobalSize() > egg->getCoords().x &&
                       bullet->getCoords().x < egg->getCoords().x + egg->getX_GlobalSize() &&
                       bullet->getCoords().y + bullet->getY_GlobalSize() > egg->getCoords().y &&
                       bullet->getCoords().y < egg->getCoords().y + egg->getY_GlobalSize())
                   {
                       (*it)->set_entityIsAlive(false); 
                       entities.erase(it2);
                       m_score += 30;
                       reset = true;
                       break;
                   }
               }
           }
           if (reset) {
               break;
           }
       }
       else if (auto player = dynamic_cast<Player*>(it->get())) {
           for (auto it2 = entities.begin(); it2 != entities.end(); ++it2)
           {
               if (auto egg = dynamic_cast<Egg*>(it2->get())) {
                   if (player->getCoords().x + player->getX_GlobalSize() > egg->getCoords().x &&
                       player->getCoords().x < egg->getCoords().x + egg->getX_GlobalSize() &&
                       player->getCoords().y + player->getY_GlobalSize() > egg->getCoords().y &&
                       player->getCoords().y < egg->getCoords().y + egg->getY_GlobalSize())
                   {
                       m_gameOver = true;

                       return;
                   }
               }
           }
       }
   }
   for (auto it = entities.begin(); it != entities.end();)
   {
	   if (!(*it)->entityAlive()) {
		   it = entities.erase(it);
	   }
	   else {
		   ++it;
	   }
   }
}


void Game::drawEntities()
{
    for (const auto& entity : entities) {
        
            entity->draw(window);
            
    }
}


