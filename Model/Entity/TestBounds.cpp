#include "TestBounds.hpp"

using namespace entities;

TestBounds::TestBounds(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 0.0f, pTexture) {}

void TestBounds::initialize() {
    //this->pSprite->setColor(sf::Color);
    //this->centerOrigin();
    this->pSprite->setOrigin(sf::Vector2f(0.f,0.f));

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}