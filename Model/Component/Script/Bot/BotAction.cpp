#include "BotAction.hpp"

using namespace components;
using namespace std;

BotAction::BotAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->ETag = BotTag::IDLE;
    this->fSpeed = 50.0f;
    this->delayTimer.restart();
    this->delayTimerMax = 1.3f;
    this->select = 0;
    this->bEnabled = false;
}

void BotAction::perform() {
    TestEnemy* pEnemy = (TestEnemy*)this->pOwner;
    if(pEnemy == NULL) std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    else {
        this->spawnEnemy();
        if(this->bEnabled == true) {
            this->performState();
            this->checkCollision();
        }
    }
}

void BotAction::spawnEnemy() {
    TestEnemy* pEnemy = (TestEnemy*)this->pOwner;
    int currentActive = MapManager::getInstance()->getActiveGrid();

    if(pEnemy->getGrid() == currentActive) {
        //pEnemy->setPosition({x,y});
        pEnemy->getSprite()->setColor(sf::Color(255,255,255,255));
        this->bEnabled = true;
    }
    else { 
        pEnemy->getSprite()->setColor(sf::Color(0,0,0,0));
        this->bEnabled = false;
        //pEnemy->resetPos();
    }
}

void BotAction::selectState(){
    TestEnemy* pEnemy = (TestEnemy*)this->pOwner;

    std::cout << pEnemy->getName() << std::endl;
    pEnemy->setRandom();

    switch(pEnemy->getRandom()) {
        case 1: // WALK_LEFT
            std::cout << "WALK_LEFT" << std::endl;
            pEnemy->setTag(BotTag::WALK_LEFT);
            break;

        case 2: // WALK_RIGHT
            std::cout << "WALK_RIGHT" << std::endl;
            pEnemy->setTag(BotTag::WALK_RIGHT);
            break;

        case 3: // WALK_UP
            std::cout << "WALK_UP" << std::endl;
            pEnemy->setTag(BotTag::WALK_UP);
            break;

        case 4: // WALK_DOWN
            std::cout << "WALK_DOWN" << std::endl;
            pEnemy->setTag(BotTag::WALK_DOWN);
            break;

        default: // CATCH ERROR?
            std::cout << "IDLE" << std::endl;
            pEnemy->setTag(BotTag::IDLE);
            break;
    }
    std::cout << std::endl;
}

void BotAction::performState() {
    TestEnemy* pEnemy = (TestEnemy*)this->pOwner;
    // Enemy Speed
    float fOffset = this->fSpeed * this->tDeltaTime.asSeconds();

    switch(pEnemy->getTag()) {
        case BotTag::IDLE:
            if(this->getDelayTimer()) {
                this->selectState();
            }
            else {
                pEnemy->getSprite()->move(0.f,0.f);
            }
            break;

        case BotTag::WALK_LEFT:
            if(this->getDelayTimer()) {
                this->selectState();
            }
            else {
                pEnemy->getSprite()->setScale(-2.0f,2.0f);
                pEnemy->getSprite()->move(-fOffset,0.f);
            }
            break;

        case BotTag::WALK_RIGHT:
            if(this->getDelayTimer()) {
                this->selectState();
            }
            else {
                pEnemy->getSprite()->setScale(2.0f,2.0f);
                pEnemy->getSprite()->move(fOffset,0.f);
            }
            break;
        
        case BotTag::WALK_UP:
            if(this->getDelayTimer()) {
                this->selectState();
            }
            else {
                pEnemy->getSprite()->move(0.f, -fOffset);
            }
            break;
        
        case BotTag::WALK_DOWN:
            if(this->getDelayTimer()) {
                this->selectState();
            }
            else {
                pEnemy->getSprite()->move(0.f, fOffset);
            }
            break;

        default:
            break;
        }
    }

void BotAction::checkCollision() {
    TestEnemy* pEnemy = (TestEnemy*)this->pOwner;
    TestBoundary* pLeftBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("LeftBounds");
    TestBoundary* pRightBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("RightBounds");
    TestBoundary* pTopBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("TopBounds");
    TestBoundary* pBottomBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("BottomBounds");
    float fOffset  = this->fSpeed * this->tDeltaTime.asSeconds();

    //Left Boundary
    if(pEnemy->getSprite()->getGlobalBounds().intersects(pLeftBounds->getSprite()->getGlobalBounds())) {
        //pEnemy->getSprite()->move(fOffset,0.f);
        if(this->getDelayTimer()) {
            this->selectState();
        }
        else {
            pEnemy->getSprite()->move(fOffset,0.f);
            this->setTag(BotTag::WALK_RIGHT);
        }
    }

    //Right Boundary
    if(pEnemy->getSprite()->getGlobalBounds().intersects(pRightBounds->getSprite()->getGlobalBounds())) {
        //pEnemy->getSprite()->move(-fOffset,0.f);
        if(this->getDelayTimer()) {
            this->selectState();
        }
        else {
            pEnemy->getSprite()->move(-fOffset,0.f);
            this->setTag(BotTag::WALK_LEFT);
        }
    }

    //Top Boundary
    if(pEnemy->getSprite()->getGlobalBounds().intersects(pTopBounds->getSprite()->getGlobalBounds())) {
        //pEnemy->getSprite()->move(0.f,fOffset);
        if(this->getDelayTimer()) {
            this->selectState();
        }
        else {
            pEnemy->getSprite()->move(0.f,fOffset);
            this->setTag(BotTag::WALK_DOWN);
        }
    }

    //Bottom Boundary
    if(pEnemy->getSprite()->getGlobalBounds().intersects(pBottomBounds->getSprite()->getGlobalBounds())) {
        //pEnemy->getSprite()->move(0.f,-fOffset);
        if(this->getDelayTimer()) {
            this->selectState();
        }
        else {
            pEnemy->getSprite()->move(0.f,-fOffset);
            this->setTag(BotTag::WALK_UP);
        }
    }
}

void BotAction::setTag(BotTag ETag) {
    this->ETag = ETag; 
}

const bool BotAction::getDelayTimer() {
    //std::cout << this->delayTimer.getElapsedTime().asSeconds() << std::endl;
    if(this->delayTimer.getElapsedTime().asSeconds() >= this->delayTimerMax)
    {
        this->delayTimer.restart();
        return true;
    }
    return false;
}