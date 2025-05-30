#include "Chicken.h"
#include "Game.h"
#include "Factory_pattern.h"
#include <iostream>
#include <random>
#include <time.h>


Chicken::Chicken(const sf::Vector2f& coords) : Entity{ coords }, m_initial_yPosition{coords.y}
{
	/*m_rng.seed(m_rd());
    m_remainedTime = m_dist(m_rng);*/

	m_remainedTime = rand() % (int)m_maxInterval + 1 + m_minInterval;

    //Cream imaginea, verificam daca nu exista erori la incarcarea imaginii
    sf::Image *image= new sf::Image;
    this->m_image = image;
    if (!image->loadFromFile("duck2.png")) {
		delete image;
		image = nullptr;
        std::cerr << "Error loading image" << std::endl;
        return;
    }
    sf::Vector2u imageSize = image->getSize();
	//std::cout << "Image size: " << imageSize.x << "x" << imageSize.y << std::endl;
	//std::cout << imageSize.x * 0.1f << std::endl;
	

    //Setam sprite-ul si "decupam" imaginea astfel incat marginea imaginii sa fie
    //exact la borderul box-ului

    m_texture = new sf::Texture(*m_image);
    m_sprite = new sf::Sprite(*m_texture);
    sf::IntRect crop({ 42, 37 }, { 900, 1005 });
    m_sprite->setTextureRect(crop);
    m_sprite->setScale({ 0.09f, 0.09f });
    


    //seteaza m_xGlobalSize si m_yGlobalSize
    sf::FloatRect globalBounds = m_sprite->getGlobalBounds();
    m_xGlobalSize = globalBounds.size.x;
    m_yGlobalSize = globalBounds.size.y;


    

}

void Chicken::draw(sf::RenderWindow* window) const
{
	

    m_sprite->setPosition(this->m_coordonate);
    //setarea un box in jurul imaginii pentru a vizualiza mai bine entitatea

    sf::RectangleShape box;
    box.setSize(sf::Vector2f(m_sprite->getGlobalBounds().size));
    box.setPosition(m_sprite->getPosition());
    box.setFillColor(sf::Color::Transparent);
    box.setOutlineThickness(1.f);
    box.setOutlineColor(sf::Color::Black);


   // window->draw(box);
    window->draw(*m_sprite);

}

void Chicken::update(float& deltaTime)
{
	updatePosition(deltaTime);
	
    
	m_remainedTime = m_remainedTime - deltaTime;
	if (m_remainedTime < 0)
	{
        Egg* copyEgg = new Egg({ -20.f,-20.f });
		
        m_remainedTime = rand() % (int)m_maxInterval + 1 + m_minInterval;

		Game& game = Game::instance();



        float bigImage = getCoords().x + m_xGlobalSize / 2.f;
        float smallImage = copyEgg->getX_GlobalSize() / 2.f;
        game.createEnt<Egg>(
            { bigImage - smallImage,10.f + getY_GlobalSize() + getCoords().y });

        delete copyEgg;
	}


}

void Chicken::updatePosition(float& deltaTime)
{
	if (m_coordonate.x < 50.f)
	{
		m_direction = 1;
	}
	else if (m_coordonate.x > 1920.f - m_xGlobalSize-50.f)
	{
		m_direction = -1;
	}
	float amplitude = 15.f;
    m_coordonate.x += (m_speed * m_direction * deltaTime);
    m_coordonate.y =  m_initial_yPosition+amplitude * sin(m_coordonate.x * .1f);
}

Chicken::~Chicken()
{
	delete m_image;
    delete m_texture;
    delete m_sprite;
}

