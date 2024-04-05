#include "TestDoor.hpp"

using namespace entities;

TestDoor::TestDoor(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 300.0f, pTexture) {}

void TestDoor::initialize() {
    //this->centerOrigin();
    this->pSprite->setOrigin(this->pSprite->getTexture()->getSize().x/2, 0.f);
    this->pSprite->setPosition(-1000.f,-1000.f);
    this->pSprite->setScale(0.7f,0.7f);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}
