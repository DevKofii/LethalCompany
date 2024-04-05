#include "BackgroundAction.hpp"

using namespace components;

BackgroundAction::BackgroundAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->nFrame = 0;
    this->nLastFrame = 0;
    this->bDebug = false;
}

void BackgroundAction::perform() {
    TestBackground* pTestBackground = (TestBackground*)this->pOwner;
    TestBoundary* pLeftBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("LeftBounds");
    TestBoundary* pRightBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("RightBounds");
    TestBoundary* pTopBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("TopBounds");
    TestBoundary* pBottomBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("BottomBounds");
    TestBounds* pTestBounds = (TestBounds*)GameObjectManager::getInstance()->findObjectByName("Bounds");

    TestUnit* pTestUnit = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");
    BackgroundInput* pBackgroundInput = (BackgroundInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0]; 

    this->nLastFrame = MapManager::getInstance()->getRoomSize();

    if(pTestBackground == NULL && pLeftBounds == NULL && pRightBounds == NULL && 
    pTopBounds == NULL && pBottomBounds == NULL && pBackgroundInput == NULL) std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;

    else {
        pTestBackground->setFrame(MapManager::getInstance()->findGridByNum(MapManager::getInstance()->getActiveGrid()));
        pLeftBounds->setFrame(MapManager::getInstance()->findGridByNum(MapManager::getInstance()->getActiveGrid()));
        pRightBounds->setFrame(MapManager::getInstance()->findGridByNum(MapManager::getInstance()->getActiveGrid()));
        pTopBounds->setFrame(MapManager::getInstance()->findGridByNum(MapManager::getInstance()->getActiveGrid()));
        pBottomBounds->setFrame(MapManager::getInstance()->findGridByNum(MapManager::getInstance()->getActiveGrid()));
        pTestBounds->setFrame(MapManager::getInstance()->findGridByNum(MapManager::getInstance()->getActiveGrid()));

        this->objSpawn();
    }
}

void BackgroundAction::objSpawn() {
    //(rand() % (9 - 4 + 1)) + 4;
    //Random grid
    //Random how many spawns;

    TestItem* pItem; 
    for(int i = 0; i < 10; i++) { 
        pItem = (TestItem*)GameObjectManager::getInstance()->findObjectByName("Barrel" + std::to_string(i)); 
        if(pItem != NULL) {
            this->spawn(pItem);
        }
    }
}


void BackgroundAction::spawn(TestItem* pItem) {
    int currentActive = MapManager::getInstance()->getActiveGrid();

    int x = pItem->getPosX();
    int y = pItem->getPosY();

    if(pItem->getGrid() == currentActive) {
        pItem->setPosition({x,y});
    }
    else pItem->resetPos();
}
