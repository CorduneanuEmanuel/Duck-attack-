#ifndef BULLET_HPP  
#define BULLET_HPP  
#include "Entity.h"  
#include "Game.h"
#include "SFML/Graphics.hpp"
#include "Exceptions.h"
#include <iostream>





template <typename T>
class Bullet : public Entity  
{  
private:  

	T m_bulletType;
    bool m_superPower = false;


    const float m_speed = 800.f;
    float m_xGlobalSize = 0, m_yGlobalSize = 0;
    
    
    sf::RectangleShape* m_rectangle = nullptr;
    sf::Image* m_image = nullptr;
	sf::Texture* m_texture = nullptr;
	sf::Sprite* m_sprite = nullptr;


public:  
   Bullet() = delete;  
   Bullet(const sf::Vector2f& coords);  
   ~Bullet();  
   /*std::unique_ptr<Entity> clone() const override  
   {  
        return std::make_unique<Bullet>(sf::Vector2f{ getCoords().x, getCoords().y });
   } */ 
   void draw(sf::RenderWindow* window) const override;  
   void update(float& deltaTime) override;  

   // Getters for xSize and ySize  
   float getX_GlobalSize() const { return m_xGlobalSize; }
   float getY_GlobalSize() const { return m_yGlobalSize; }

   sf::RectangleShape* get_rectangle() const { return m_rectangle; }
   sf::Image* get_image() const { return m_image; }
   sf::Texture* get_texture() const { return m_texture; }
   sf::Sprite* get_sprite() const { return m_sprite; }
   


};  


template <typename T>
Bullet<T>::Bullet(const sf::Vector2f& coords) : Entity(coords)
{
    try
    {
        sf::Image* image = new sf::Image;
        this->m_image = image;
        if (!image->loadFromFile("bullet.png")) {
            delete image;
            image = nullptr;
            throw FileException("Eroare incarcare imagine");
        }
        sf::Vector2u imageSize = image->getSize();

        m_texture = new sf::Texture(*m_image);
        m_sprite = new sf::Sprite(*m_texture);
        sf::IntRect crop(m_sprite->getGlobalBounds());
        m_sprite->setTextureRect(crop);
        float scaleX = 10.0f / m_sprite->getGlobalBounds().size.x;
        float scaleY = 50.0f / m_sprite->getGlobalBounds().size.y;
        m_sprite->setScale({ scaleX, scaleY });
    }
    catch (const FileException& e)
    {
        m_image = nullptr;
        m_sprite = nullptr;
        m_texture = nullptr;
        std::cerr << e.what() << std::endl;
        m_rectangle = new sf::RectangleShape(sf::Vector2f{ 10.f, 50.f });
        sf::FloatRect globalBounds = m_rectangle->getGlobalBounds();
        m_xGlobalSize = globalBounds.size.x;
        m_yGlobalSize = globalBounds.size.y;

    }
    catch (const std::bad_alloc& e)
    {
        std::cerr << "Nu exista destula memorie" << std::endl;
    }




    m_rectangle = new sf::RectangleShape(sf::Vector2f{ 10.f, 50.f });
    sf::FloatRect globalBounds = m_rectangle->getGlobalBounds();
    m_xGlobalSize = globalBounds.size.x;
    m_yGlobalSize = globalBounds.size.y;

}

template <typename T>
void Bullet<T>::draw(sf::RenderWindow* window) const
{

    if (m_sprite != nullptr)
    {
        m_sprite->setPosition(this->m_coordonate);
        sf::RectangleShape box;
        box.setSize(sf::Vector2f(m_sprite->getGlobalBounds().size));
        box.setPosition(m_sprite->getPosition());
        box.setFillColor(sf::Color::Transparent);
        box.setOutlineThickness(1.f);
        box.setOutlineColor(sf::Color::Black);
        window->draw(*m_sprite);
    }
    else if (m_rectangle != nullptr)
    {
        /*m_rectangle->setPosition(this->m_coordonate);
        m_rectangle->setFillColor(sf::Color::Red);
        m_rectangle->setOutlineThickness(1.f);
        m_rectangle->setOutlineColor(sf::Color::Black);*/
        
		m_bulletType.shape(window, this);
    }
}

template <typename T>
void Bullet<T>::update(float& deltaTime)
{
    m_coordonate.y -= m_speed * deltaTime;

}

template <typename T>
Bullet<T>::~Bullet()
{
    delete m_rectangle;
    delete m_image;
    delete m_texture;
    delete m_sprite;
}



class Rectangle
{
public:
	void shape(sf::RenderWindow* window, const Bullet<Rectangle>* bullet) const
	{
        
		sf::RectangleShape rectangle;
        rectangle.setSize(sf::Vector2f(10.f, 50.f));
		rectangle.setPosition(bullet->getCoords());
		rectangle.setFillColor(sf::Color::Red);
		window->draw(rectangle);
	}
};

class Star
{
public:
    void shape(sf::RenderWindow* window, const Bullet<Star>* bullet) const
    {
        sf::ConvexShape star;
        star.setPointCount(5);

        sf::Vector2f center = bullet->getCoords();

        float radius = 15.0f;
        for (int i = 0; i < 5; ++i) {
            float angle = (float)(i * 2 * 3.14 / 5);
            float x = radius * cos(angle);
            float y = radius * sin(angle);
            star.setPoint(i, sf::Vector2f(x, y));
        }

        for (int i = 0; i < 5; ++i) {
            star.setPoint(i, star.getPoint(i) + center);
        }
        
        star.setOutlineThickness(1.f);
        star.setOutlineColor(sf::Color::Black);
        star.setFillColor(sf::Color::Red);
        window->draw(star);
    }
};


#endif
