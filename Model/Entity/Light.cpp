#include "Light.hpp"

using namespace entities;

Light::Light(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 300.0f, pTexture) {}

void Light::initialize() {
    //this->centerOrigin();
    this->pSprite->setColor(sf::Color(255,255,255,100));
    this->pSprite->setOrigin(0.f,this->pSprite->getTexture()->getSize().y/2);
    this->pSprite->setScale(1.0f,1.0f);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}
