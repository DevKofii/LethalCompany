#include "PlayerMovement.hpp"

using namespace components;

PlayerMovement::PlayerMovement(std::string strName) : Component  (strName, ComponentType::SCRIPT) {
    this->pPlayer = NULL;
    this->pInput = NULL;
    this->fSpeed = 300.0f;
}

void PlayerMovement::perform() {
    
    if(this->pPlayer == NULL) this->pPlayer = (Player*)this->pOwner;
    if(this->pInput == NULL) this->pInput = (PlayerInput*)this->getOwner()->findComponentByName(this->pPlayer->getName() + " Input");

    if(pInput == NULL && pPlayer == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        //Player
        if(this->pPlayer->getName() == "TestUnit") {

            float fOffset  = this->fSpeed * this->tDeltaTime.asSeconds();

            //Movement
            if(pInput->getUp()) pPlayer->getSprite()->move(0.f,-fOffset);
            if(pInput->getDown()) pPlayer->getSprite()->move(0.f,fOffset);

            if(pInput->getLeft()) {
                pPlayer->getSprite()->setScale(-2.0f,2.0f);
                pPlayer->getSprite()->move(-fOffset,0.f);
                pPlayer->setOrientationLeft(pInput->getLeft());
                pPlayer->setOrientationRight(false);
                
            }
            if(pInput->getRight()) {
                pPlayer->getSprite()->setScale(2.0f,2.0f);
                pPlayer->getSprite()->move(fOffset,0.f);
                pPlayer->setOrientationRight(pInput->getRight());
                pPlayer->setOrientationLeft(false);
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

            //Orientation
            if(pPlayer->getOrientationRight() == true && pPlayer->getOrientationLeft() == false) pPlayer->getSprite()->setScale(2.0f,2.0f);
            if(pPlayer->getOrientationRight() == false && pPlayer->getOrientationLeft() == true) pPlayer->getSprite()->setScale(-2.0f,2.0f);
        }
    }
}