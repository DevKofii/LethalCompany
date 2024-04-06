#include "TestUnitControls.hpp"

using namespace components;

TestUnitControls::TestUnitControls(std::string strName) : Component  (strName, ComponentType::SCRIPT) {
    this->fSpeed = 200.0f;
}

void TestUnitControls::perform() {

    TestUnit* pUnitOwner = (TestUnit*)this->pOwner;
    TestUnitInput* pUnitInput = (TestUnitInput*)this->getOwner()->findComponentByName(pUnitOwner->getName() + " Input");

    Light* pLight = (Light*)GameObjectManager::getInstance()->findObjectByName("Light");
    pLight->setPosition(pUnitOwner->getPosition());
    
    Shadow* pShadow = (Shadow*)GameObjectManager::getInstance()->findObjectByName("Shadow");
    //GameObject* pClone = pShadow->clone();

    pShadow->setPosition({pUnitOwner->getPosition().x,pUnitOwner->getPosition().y});
    pShadow->getSprite()->setColor(sf::Color::Transparent);

    if(pUnitInput == NULL && pUnitOwner == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        //Player
        if(pUnitOwner->getName() == "TestUnit") {

            float fOffset  = this->fSpeed * this->tDeltaTime.asSeconds();

            //Movement
            if(pUnitInput->getUp()) pUnitOwner->getSprite()->move(0.f,-fOffset);
            if(pUnitInput->getDown()) pUnitOwner->getSprite()->move(0.f,fOffset);

            if(pUnitInput->getLeft()) {
                pUnitOwner->getSprite()->setScale(-2.0f,2.0f);
                pUnitOwner->getSprite()->move(-fOffset,0.f);
                pUnitOwner->setOrientationLeft(pUnitInput->getLeft());
                pUnitOwner->setOrientationRight(false);

                pShadow->getSprite()->setScale(-1.5f,1.5f);
                pLight->getSprite()->setScale(-1.0f,1.0f);
                
            }
            if(pUnitInput->getRight()) {
                pUnitOwner->getSprite()->setScale(2.0f,2.0f);
                pUnitOwner->getSprite()->move(fOffset,0.f);
                pUnitOwner->setOrientationRight(pUnitInput->getRight());
                pUnitOwner->setOrientationLeft(false);
                
                pShadow->getSprite()->setScale(1.5f,1.5f);
                pLight->getSprite()->setScale(1.0f,1.0f);
            }

            //Actions
            // if(pUnitInput->getShoot()) { 
            //     pUnitInput->resetShoot();
            //     if(pUnitOwner->getOrientationRight()) {
            //         ObjectPoolManager::getInstance()->getPool(PoolTag::TEST_BULLET_R)->requestPoolable();
            //     }
            //     else if(pUnitOwner->getOrientationLeft()) {
            //         ObjectPoolManager::getInstance()->getPool(PoolTag::TEST_BULLET_L)->requestPoolable();
            //     }

            // }
            
            int currentGrid = MapManager::getInstance()->getActiveGrid();

            //Orientation
            if(pUnitOwner->getOrientationRight() == true && pUnitOwner->getOrientationLeft() == false) pUnitOwner->getSprite()->setScale(2.0f,2.0f);
            if(pUnitOwner->getOrientationRight() == false && pUnitOwner->getOrientationLeft() == true) pUnitOwner->getSprite()->setScale(-2.0f,2.0f);
        }
    }
}
