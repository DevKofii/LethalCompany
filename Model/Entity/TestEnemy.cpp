#include "TestEnemy.hpp"

using namespace entities;

TestEnemy::TestEnemy(std::string strName, AnimatedTexture* pTexture, int ID) : GameObject(strName, 300.0f, pTexture) {}

void TestEnemy::initialize() {
    this->centerOrigin();

    this->pSprite->setScale(2.0f,2.0f);
    //this->resetPos();

    this->setPosition({SCREEN_WIDTH/2,SCREEN_HEIGHT/2});

    BotAction* pAction = new BotAction(this->strName + " Action");
    this->attachComponent(pAction);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}