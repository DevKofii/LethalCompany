#include "Enemy.hpp"

using namespace poolables;

Enemy::Enemy(std::string strName, AnimatedTexture* pTexture) : PoolableObject(PoolTag::ENEMY, strName, pTexture) {}

void Enemy::initialize() {
    this->centerOrigin();
    this->pSprite->setPosition(-1000.0f,-1000.0f);

    BotAction* pBotAction = new BotAction(this->strName + " Script");
    this->attachComponent(pBotAction);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

void Enemy::onActivate() {
    // Set the enemy's position and other properties here
}

void Enemy::onRelease() {}

PoolableObject* Enemy::clone() {
    PoolableObject* pClone = new Enemy(this->strName, new AnimatedTexture(*this->pTexture));
    return pClone;
}