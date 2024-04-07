#include "TestItem.hpp"

using namespace entities;

TestItem::TestItem(std::string strName, AnimatedTexture* pTexture, int ID) : GameObject(strName, 300.0f, pTexture) {
    this->ID = ID;
    this->bEnabled = true; //pickup-able
}

void TestItem::initialize() {
    //this->centerOrigin();
    this->pSprite->setScale(2.0f,2.0f);
    this->resetPos();

    ItemAction* pAction = new ItemAction(this->strName + " Action");
    this->attachComponent(pAction);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

int TestItem::getID() {
    return this->ID;
}

bool TestItem::getEnabled() {
    return this->bEnabled;
}

void TestItem::setEnabled(bool bEnabled) {
    this->bEnabled = bEnabled;
}
