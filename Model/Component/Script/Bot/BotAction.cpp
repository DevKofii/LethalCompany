#include "BotAction.hpp"

using namespace components;
using namespace std;

BotAction::BotAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->fFrameInterval = 0.01f;
    this->fTicks = 0.0f;
    this->fSpeed = 350.0f;
}

void BotAction::perform() {
    // PoolableObject* pPoolableOwner = (PoolableObject*)this->pOwner;
    // int currentGrid = MapManager::getInstance()->getActiveGrid();

    // if(pPoolableOwner == NULL && pOwner == NULL) {
    //     std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    // }
    // else { 
    //     //if(currentGrid == 0) pPoolableOwner->getSprite()->setPosition(SCREEN_WIDTH/2,SCREEN_HEIGHT/2);
    //     //std::cout << this->randomPos().x << std::endl;
    //     //std::cout << this->randomPos().y << std::endl;
    //     if(currentGrid == 0) pPoolableOwner->getSprite()->setPosition(this->randomPos());
    //     else pPoolableOwner->getSprite()->setPosition(-1000.0f,-1000.0f);
    // }
}

sf::Vector2f BotAction::randomPos() {
    GameObjectManager::getInstance()->findObjectByName("TestBackground");

    float 

    srand(static_cast<unsigned>(time(0)));

    float x = 0.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(50.0f-0.0f)));
    float y = 0.0f + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(50.0f-0.0f)));
    
    sf::Vector2f vect{x,y};

    return vect;
    //return (rand() % (9 - 4 + 1)) + 4;
}
