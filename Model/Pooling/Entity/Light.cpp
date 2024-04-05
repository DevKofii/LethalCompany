#include "Light.hpp"

using namespace poolables;

Light::Light(std::string strName, AnimatedTexture* pTexture, TestUnit* pPlayer) : PoolableObject(PoolTag::LIGHT,strName,pTexture) {
    this->pPlayer = pPlayer;
}

void Light::initialize() {
    //this->centerOrigin();
    this->pSprite->setOrigin(0.f,this->pSprite->getTexture()->getSize().y/2);
    this->pSprite->setScale(1.0f,1.0f);

    this->pSprite->setPosition(this->pPlayer->getSprite()->getPosition());

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

void Light::onActivate() {}
void Light::onRelease() {}
PoolableObject* Light::clone() {
    PoolableObject* pClone = new Light(this->strName, new AnimatedTexture(*this->pTexture), this->pPlayer);
    return pClone;
}
