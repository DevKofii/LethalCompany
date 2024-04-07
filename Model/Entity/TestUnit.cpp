#include "TestUnit.hpp"

using namespace entities;

TestUnit::TestUnit(std::string strName, AnimatedTexture* pTexture) : GameObject(strName, 300.0f, pTexture) {
    this->pHealth = 100;
}

void TestUnit::initialize() {
    this->centerOrigin();;
    
    TestUnitInput* pTestUnitInput = new TestUnitInput(this->strName + " Input");
    this->attachComponent(pTestUnitInput);

    TestUnitControls* pTestUnitControls = new TestUnitControls(this->strName + " Movement");
    this->attachComponent(pTestUnitControls);
    
    CollisionManager* pCollisionManager = new CollisionManager(this->strName + " Collision");
    this->attachComponent(pCollisionManager);

    FrameAnimation* pFrameAnimation = new FrameAnimation(this->strName + " Animation");
    this->attachComponent(pFrameAnimation);

    Renderer* pRenderer = new Renderer(this->strName + " Renderer");
    pRenderer->assignDrawable(this->pSprite);
    this->attachComponent(pRenderer);
}

int TestUnit::getFrameStart() {
    return this->nFrameStart;
}

int TestUnit::getFrameEnd() {
    return this->nFrameEnd;
}

void TestUnit::getHit() {
    this->pHealth -= 10;
}