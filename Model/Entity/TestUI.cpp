#include "TestUI.hpp"

using namespace entities;

TestUI::TestUI(std::string strName, AnimatedTexture* pTexture) : GameObject(strName,0.0f,pTexture) {}

void TestUI::initialize() {
    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}