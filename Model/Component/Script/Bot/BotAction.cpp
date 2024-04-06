#include "BotAction.hpp"

using namespace components;
using namespace std;

BotAction::BotAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->ETag = BotTag::IDLE;
    this->fSpeed = 50.0f;
    this->delayTimer.restart();
    this->delayTimerMax = 1.3f;

    this->select = 0;
    this->debug = false;

    this->randomDest = 0;
    this->destX_L = 0;
    this->destX_R = 0;
    this->destY_T = 0;
    this->destY_B = 0;
}

void BotAction::perform() {
    TestEnemy* pEnemy = (TestEnemy*)this->pOwner;
    if(pEnemy == NULL) std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    else {
        //this->spawnEnemy();
        this->performState();
        this->checkCollision();
    }
}

void BotAction::spawnEnemy() {
    TestEnemy* pEnemy = (TestEnemy*)this->pOwner;
    int currentActive = MapManager::getInstance()->getActiveGrid();

    int x = pEnemy->getPosX();
    int y = pEnemy->getPosY();

    if(pEnemy->getGrid() == currentActive) {
        pEnemy->setPosition({x,y});
    }
    else pEnemy->resetPos();
}

void BotAction::selectState(){
    TestEnemy* pEnemy = (TestEnemy*)this->pOwner;

    std::cout << "SELECTING STATE" << std::endl;

    srand(time(NULL));
    int temp_select = (rand() % (7 - 1 + 1)) + 1;
    if(this->select == temp_select) temp_select = (rand() % (5 - 1 + 1)) + 1;
    this->select = temp_select;

    switch(this->select) {
        case 1: // IDLE
            std::cout << "IDLE" << std::endl;
            this->setTag(BotTag::IDLE);
            break;
        case 2: // WALK_LEFT
            std::cout << "WALK_LEFT" << std::endl;
            this->setTag(BotTag::WALK_LEFT);
            break;

        case 3: // WALK_RIGHT
            std::cout << "WALK_RIGHT" << std::endl;
            this->setTag(BotTag::WALK_RIGHT);
            break;

        case 4: // WALK_UP
            std::cout << "WALK_UP" << std::endl;
            this->setTag(BotTag::WALK_UP);
            break;

        case 5: // WALK_DOWN
            std::cout << "WALK_DOWN" << std::endl;
            this->setTag(BotTag::WALK_DOWN);
            break;

        default: // CATCH ERROR?
            std::cout << "IDLE" << std::endl;
            this->setTag(BotTag::IDLE);
            break;
    }
    std::cout << std::endl;
}

int BotAction::random() {
    int random;
    return random = (rand() % (100 - 50 + 1)) + 50;
}

void BotAction::performState() {
    TestEnemy* pEnemy = (TestEnemy*)this->pOwner;
    // Enemy Speed
    float fOffset = this->fSpeed * this->tDeltaTime.asSeconds();

    switch(ETag) {
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