#include "Enemy.hpp"

using namespace poolables;

Enemy::Enemy(std::string strName, AnimatedTexture* pTexture)
    : PoolableObject(PoolTag::ENEMY, strName, pTexture) {
    this->centerOrigin();

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);

 
}

void Enemy::initialize() {
    this->centerOrigin();

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

void Enemy::onActivate() {
    // Set the enemy's position and other properties here
}

void Enemy::onRelease() {}

PoolableObject* Enemy::clone() {
    AnimatedTexture* pCloneTexture = new AnimatedTexture(*this->pTexture);
    Enemy* pClone = new Enemy(this->strName, pCloneTexture);
    return pClone;
}