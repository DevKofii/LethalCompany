#include "TestBoundary.hpp"

using namespace entities;

TestBoundary::TestBoundary(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 0.0f, pTexture) {}

void TestBoundary::initialize() {
    this->pSprite->setColor(sf::Color::Transparent);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}