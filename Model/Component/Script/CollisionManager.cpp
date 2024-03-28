#include "CollisionManager.hpp"

using namespace components;

CollisionManager::CollisionManager(std::string strName) : Component  (strName, ComponentType::SCRIPT) {}

void CollisionManager::perform() {
    TestUnit* pUnitOwner = (TestUnit*)this->pOwner;
    TestUnitInput* pUnitInput = (TestUnitInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0];
    TestBoundary* pLeftBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("LeftBounds");
    TestBoundary* pTopBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("TopBounds");

    if(pUnitInput == NULL && pUnitOwner == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        this->windowBounds();
        this->mapBounds();
    }
}

void CollisionManager::windowBounds() {
    TestUnit* pUnitOwner = (TestUnit*)this->pOwner;
    TestUnitInput* pUnitInput = (TestUnitInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0];
    TestBoundary* pLeftBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("LeftBounds");
    TestBoundary* pTopBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("TopBounds");

    float fOffset  = pUnitOwner->getSpeed() * this->tDeltaTime.asSeconds();

    //Left Boundary
    if(pUnitOwner->getSprite()->getGlobalBounds().left <= 0.f) {
        pUnitOwner->getSprite()->move(fOffset,0.f);
    }

    //Right Boundary
    if(pUnitOwner->getSprite()->getGlobalBounds().left + pUnitOwner->getSprite()->getGlobalBounds().width >= SCREEN_WIDTH) {
        pUnitOwner->getSprite()->move(-fOffset,0.f);
    }

    //Top Boundary
    if(pUnitOwner->getSprite()->getGlobalBounds().top <= 0.f) {
        pUnitOwner->getSprite()->move(0.f,fOffset);
    }

    //Bottom Boundary
    if(pUnitOwner->getSprite()->getGlobalBounds().top + pUnitOwner->getSprite()->getGlobalBounds().height >= SCREEN_HEIGHT) {
        pUnitOwner->getSprite()->move(0.f,-fOffset);
    }
}

void CollisionManager::mapBounds() {
    TestUnit* pUnitOwner = (TestUnit*)this->pOwner;
    TestUnitInput* pUnitInput = (TestUnitInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0];
    TestBoundary* pLeftBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("LeftBounds");
    TestBoundary* pTopBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("TopBounds");

    float fOffset  = pUnitOwner->getSpeed() * this->tDeltaTime.asSeconds();

    //LeftGridBounds
    if(pUnitOwner->getSprite()->getGlobalBounds().intersects(pLeftBounds->getSprite()->getGlobalBounds()) &&
    pUnitOwner->getSprite()->getGlobalBounds().width <= pLeftBounds->getSprite()->getGlobalBounds().width + pUnitOwner->getSprite()->getGlobalBounds().width) {
        //std::cout << "Collision Detected" << std::endl;
        pUnitOwner->getSprite()->move(fOffset,0.f);
    }

    //TopGridBounds
    if(pUnitOwner->getSprite()->getGlobalBounds().intersects(pTopBounds->getSprite()->getGlobalBounds()) &&
    pUnitOwner->getSprite()->getGlobalBounds().top <= pTopBounds->getSprite()->getGlobalBounds().top + pUnitOwner->getSprite()->getGlobalBounds().top) {
        //std::cout << "Collision Detected" << std::endl;
        pUnitOwner->getSprite()->move(0.f,fOffset);
    }
}