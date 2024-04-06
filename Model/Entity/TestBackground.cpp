#include "TestBackground.hpp"

using namespace entities;

TestBackground::TestBackground(std::string strName, AnimatedTexture* pTexture) : GameObject(strName,0.0f,pTexture) {}

void TestBackground::initialize() {
    //this->pSprite->setColor(sf::Color::Transparent);
    this->pSprite->setColor(sf::Color(255,255,255,50));

    BackgroundInput* backgroundInput = new BackgroundInput(this->strName + " Input");
    this->attachComponent(backgroundInput);

    BackgroundAction* backgroundAction = new BackgroundAction(this->strName + " Script"); 
    this->attachComponent(backgroundAction);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}