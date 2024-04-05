#include "TestEnemy.hpp"

using namespace entities;

TestEnemy::TestEnemy(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 300.0f, pTexture) {}

void TestEnemy::initialize() {
    this->centerOrigin();

    this->pSprite->setScale(2.0f,2.0f);
    this->resetPos();

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}