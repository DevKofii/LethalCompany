#include "TestItem.hpp"

using namespace entities;

TestItem::TestItem(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 300.0f, pTexture) {}

void TestItem::initialize() {
    this->centerOrigin();
    this->pSprite->setScale(2.0f,2.0f);
    this->resetPos();

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}
