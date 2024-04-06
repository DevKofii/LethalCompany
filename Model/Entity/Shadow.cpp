#include "Shadow.hpp"

using namespace entities;

Shadow::Shadow(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 300.0f, pTexture) {}

void Shadow::initialize() {
    this->centerOrigin();
    this->pSprite->setColor(sf::Color(255,255,255,50));
    //this->pSprite->setOrigin(0.f,this->pSprite->getTexture()->getSize().y/2);
    this->pSprite->setScale(1.5f,1.5f);
    this->resetPos();

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

GameObject* Shadow::clone() {
    GameObject* pClone = new Shadow(this->strName, new AnimatedTexture(*this->pTexture));
    return pClone;
}
