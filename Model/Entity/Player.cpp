#include "Player.hpp"

using namespace entities;

Player::Player(std::string strName) : GameObject(strName, 300.0f) {}
Player::Player(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 300.0f, pTexture) {}

void Player::initialize() {
    this->pSprite->setOrigin(64.f,64.f);
    this->pSprite->setPosition(640.f,320.f);
    this->pSprite->setScale(0.5f,0.5f);

    PlayerInput* playerInput = new PlayerInput(this->strName + " Input");
    this->attachComponent(playerInput);

    PlayerMovement* playerMovement = new PlayerMovement(this->strName + " Movement");
    this->attachComponent(playerMovement);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}
