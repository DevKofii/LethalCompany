#include "TestEnemy.hpp"

using namespace entities;

TestEnemy::TestEnemy(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 300.0f, pTexture) {}

void TestEnemy::initialize() {
    this->centerOrigin();;

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

int TestEnemy::getFrameStart() {
    return this->nFrameStart;
}

int TestEnemy::getFrameEnd() {
    return this->nFrameEnd;
}
