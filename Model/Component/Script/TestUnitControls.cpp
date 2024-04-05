#include "TestUnitControls.hpp"

using namespace components;

TestUnitControls::TestUnitControls(std::string strName) : Component  (strName, ComponentType::SCRIPT) {
    this->pUnitInput = NULL;
    this->pUnitOwner = NULL;
    this->fSpeed = 300.0f;
}

void TestUnitControls::perform() {

    if(this->pUnitOwner == NULL) this->pUnitOwner = (TestUnit*)this->pOwner;
    if(this->pUnitInput == NULL) this->pUnitInput = (TestUnitInput*)this->getOwner()->findComponentByName(this->pUnitOwner->getName() + " Input");

    // Light* pLight = (Light*)ObjectPoolManager::getInstance()->getPool(PoolTag::LIGHT)->getPoolable();
    // pLight->setPosition(this->pUnitOwner->getPosition());

    Light* pLight = (Light*)GameObjectManager::getInstance()->findObjectByName("Light");
    pLight->setPosition(this->pUnitOwner->getPosition());

    if(pUnitInput == NULL && pUnitOwner == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        //Player
        if(this->pUnitOwner->getName() == "TestUnit") {

            float fOffset  = this->fSpeed * this->tDeltaTime.asSeconds();

            //Movement
            if(pUnitInput->getUp()) pUnitOwner->getSprite()->move(0.f,-fOffset);
            if(pUnitInput->getDown()) pUnitOwner->getSprite()->move(0.f,fOffset);

            if(pUnitInput->getLeft()) {
                pUnitOwner->getSprite()->setScale(-2.0f,2.0f);
                pUnitOwner->getSprite()->move(-fOffset,0.f);
                pUnitOwner->setOrientationLeft(pUnitInput->getLeft());
                pUnitOwner->setOrientationRight(false);

                pLight->getSprite()->setScale(-1.0f,1.0f);
                
            }
            if(pUnitInput->getRight()) {
                pUnitOwner->getSprite()->setScale(2.0f,2.0f);
                pUnitOwner->getSprite()->move(fOffset,0.f);
                pUnitOwner->setOrientationRight(pUnitInput->getRight());
                pUnitOwner->setOrientationLeft(false);
                
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
            PoolableObject* pPoolableOwner = (PoolableObject*)this->pOwner;
            int currentGrid = MapManager::getInstance()->getActiveGrid();

            if(pUnitInput->getInteract()) {
                pUnitInput->resetInteract();
                if(currentGrid == 0) pPoolableOwner->getSprite()->setPosition(this->randomPos());
                else pPoolableOwner->getSprite()->setPosition(-1000.0f,-1000.0f);
                ObjectPoolManager::getInstance()->getPool(PoolTag::ENEMY)->requestPoolable();
            }

            //Orientation
            if(pUnitOwner->getOrientationRight() == true && pUnitOwner->getOrientationLeft() == false) pUnitOwner->getSprite()->setScale(2.0f,2.0f);
            if(pUnitOwner->getOrientationRight() == false && pUnitOwner->getOrientationLeft() == true) pUnitOwner->getSprite()->setScale(-2.0f,2.0f);
        }

        //BotTest
        if(this->pUnitOwner->getName() == "TestBot") {
            // float fOffset  = this->fSpeed * this->tDeltaTime.asSeconds();
            // pUnitOwner->getSprite()->move(-fOffset,0.f);
        }
    }
}

sf::Vector2f TestUnitControls::randomPos() {
    srand(time(NULL));

    int x = (rand() % (740 - 540 + 1)) + 540;
    int y = (rand() % (410 - 310 + 1)) + 310;
    
    sf::Vector2f vect{x,y};

    return vect;
}
