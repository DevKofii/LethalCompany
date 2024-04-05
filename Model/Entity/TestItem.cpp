#include "TestItem.hpp"

using namespace entities;

TestItem::TestItem(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 300.0f, pTexture) {
    this->grid = 0;
    this->posX = 0;
    this->posY = 0;
}

void TestItem::initialize() {
    this->centerOrigin();
    //this->pSprite->setOrigin(this->pSprite->getTexture()->getSize().x/2, 0.f);
    //this->pSprite->setPosition(-1000.f,-1000.f);
    this->pSprite->setScale(2.0f,2.0f);
    this->resetPos();

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}


int TestItem::getGrid() {
    return this->grid;
}

void TestItem::setGrid(int num) {
    this->grid = num;
}

void TestItem::resetPos() {
    this->pSprite->setPosition(-10000.f,-10000.f);
}

void TestItem::setPosX(int x) {
    this->posX = x;
}

void TestItem::setPosY(int y) {
    this->posY = y;
}

int TestItem::getPosX() {
    return this->posX;
}

int TestItem::getPosY() {
    return this->posY;
}