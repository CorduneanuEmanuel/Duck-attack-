#include "Factory_pattern.h"
#include "Game.h"
#include "Includes.h"
//void Factory_pattern::createEntity(int EntityType, const sf::Vector2f& coords)
//{
//    try {
//        switch (EntityType)
//        {
//        case 0:
//            entities->push_back(std::make_unique<Player>(coords));
//            break;
//        case 1:
//            entities->push_back(std::make_unique<Chicken>(coords));
//            break;
//
//        case 2:
//            entities->push_back(std::make_unique<Bullet<Rectangle>>(coords));
//            break;
//
//        case 3:
//            entities->push_back(std::make_unique<Egg>(coords));
//            break;
//
//        case 4:
//            entities->push_back(std::make_unique<Bullet<Star>>(coords));
//            break;
//
//        default:
//            throw - 1;
//            std::cerr << "Tip de date necunoscut";
//            break;
//        }
//    }
//    catch (const Memory& e)
//    {
//        std::cerr << e.what() << std::endl;
//        std::exit(1);
//    }
//    catch (const std::bad_alloc& e)
//    {
//        std::cerr << "Nu exista destula memorie" << std::endl;
//        std::exit(1);
//    }
//}
//
//void Factory_pattern::generateSetChickens()
//{
//    Chicken* copyChicken = new Chicken({ 1.f,1.f });
//
//    for (int i = 0; i < 5; i++) {
//        for (int j = 0; j < 8; j++) {
//
//            float availableWidth = 1920.0f - 2 * 250;
//            float total_width = copyChicken->getX_GlobalSize() * 8.0f + copyChicken->get_widthGap() * 7;
//            float spacing = (availableWidth - total_width) / 2.0f;
//
//            //(1920.0f-400) / 8 - Chicken::getXSize() / 2.0f;
//            createEntity(1, {250.0f + spacing +
//                j * (copyChicken->getX_GlobalSize() + copyChicken->get_widthGap()),
//                100.0f + copyChicken->get_initialYPosition() + i * (copyChicken->get_heightGap() + copyChicken->getY_GlobalSize()) });
//
//        }
//    }
//
//    delete copyChicken;
//}
//
//void Factory_pattern::createPlayer()
//{
//    createEntity(0, { 1920.0f / 2 - 100.f, float(1080.0f * 8 / 10) });
//}
