#include "TestEnemy.hpp"

using namespace entities;

TestEnemy::TestEnemy(std::string strName, AnimatedTexture* pTexture, int ID) : GameObject(strName, 300.0f, pTexture) {
    this->ETag = BotTag::IDLE;
    this->random = 0;
    this->ID = ID;
}

void TestEnemy::initialize() {
    this->centerOrigin();

    this->pSprite->setScale(2.0f,2.0f);
    //this->resetPos();

    //this->setPosition({SCREEN_WIDTH/2,SCREEN_HEIGHT/2});

    BotAction* pAction = new BotAction(this->strName + " Action");
    this->attachComponent(pAction);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

int TestEnemy::getRandom() {
    return this->random;
}

void TestEnemy::setRandom() {
    srand(time(NULL));
    int temp_select = (rand() % (7 - 1 + 1)) + 1;
    if(this->random == temp_select) temp_select = (rand() % (7 - 1 + 1)) + 1;

    this->random = temp_select;
}


BotTag TestEnemy::getTag() {
    return this->ETag;
}

void TestEnemy::setTag(BotTag ETag) {
    this->ETag = ETag;
}

int TestEnemy::getID() {
    return this->ID;
}