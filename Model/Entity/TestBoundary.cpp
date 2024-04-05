#include "TestBoundary.hpp"

using namespace entities;

TestBoundary::TestBoundary(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 0.0f, pTexture) {}

void TestBoundary::initialize() {
    this->pSprite->setColor(sf::Color::Transparent);
    //this->centerOrigin();
    this->pSprite->setOrigin(sf::Vector2f(0.f,0.f));

    BoundsAction* boundsAction = new BoundsAction(this->strName + " Script");
    this->attachComponent(boundsAction);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}