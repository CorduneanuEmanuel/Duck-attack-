#include "Game.h"
#include "Bullet.h"
#include "SFML/Graphics.hpp"
#include "Exceptions.h"


//template <typename T>
//Bullet<T>::Bullet(const sf::Vector2f& coords) : Entity(coords)
//{
//    try 
//    {
//        sf::Image* image = new sf::Image;
//        this->m_image = image;
//        if (!image->loadFromFile("bullet.png")) {
//            delete image;
//            image = nullptr;
//			throw FileException("Eroare incarcare imagine");
//        }
//        sf::Vector2u imageSize = image->getSize();
//
//        m_texture = new sf::Texture(*m_image);
//        m_sprite = new sf::Sprite(*m_texture);
//        sf::IntRect crop(m_sprite->getGlobalBounds());
//        m_sprite->setTextureRect(crop);
//		float scaleX = 10.0f/m_sprite->getGlobalBounds().size.x;
//		float scaleY = 50.0f/ m_sprite->getGlobalBounds().size.y;
//        m_sprite->setScale({ scaleX, scaleY});
//    }
//	catch (const FileException& e)
//	{
//        m_image = nullptr;
//        m_sprite = nullptr;
//		m_texture = nullptr;
//		std::cerr << e.what() << std::endl;
//        m_rectangle = new sf::RectangleShape(sf::Vector2f{ 10.f, 50.f });
//        sf::FloatRect globalBounds = m_rectangle->getGlobalBounds();
//        m_xGlobalSize = globalBounds.size.x;
//        m_yGlobalSize = globalBounds.size.y;
//		
//	}
//	catch (const std::bad_alloc& e)
//	{
//		std::cerr << "Nu exista destula memorie" << std::endl;
//	}
//
//
//
//
//    m_rectangle = new sf::RectangleShape(sf::Vector2f{10.f, 50.f});
//    sf::FloatRect globalBounds = m_rectangle->getGlobalBounds();
//    m_xGlobalSize = globalBounds.size.x;
//    m_yGlobalSize = globalBounds.size.y;
//
//}
//
//template <typename T>
//void Bullet<T>::draw(sf::RenderWindow* window) const
//{
//    //setarea un box in jurul imaginii pentru a vizualiza mai bine entitatea
//
//    if (m_sprite != nullptr)
//    {
//		m_sprite->setPosition(this->m_coordonate);
//        sf::RectangleShape box;
//        box.setSize(sf::Vector2f(m_sprite->getGlobalBounds().size));
//        box.setPosition(m_sprite->getPosition());
//        box.setFillColor(sf::Color::Transparent);
//        box.setOutlineThickness(1.f);
//        box.setOutlineColor(sf::Color::Black);
//        window->draw(*m_sprite);
//    }
//    else if (m_rectangle != nullptr)
//    {
//        m_rectangle->setPosition(this->m_coordonate);
//        m_rectangle->setFillColor(sf::Color::Red);
//        m_rectangle->setOutlineThickness(1.f);
//        m_rectangle->setOutlineColor(sf::Color::Black);
//        window->draw(*m_rectangle);
//
//    }
//}
//void Bullet::update(float& deltaTime)
//{
//	m_coordonate.y -= m_speed * deltaTime;
//
//}
//Bullet::~Bullet()
//{
//    delete m_rectangle;
//	delete m_image;
//	delete m_texture;
//	delete m_sprite;
//}