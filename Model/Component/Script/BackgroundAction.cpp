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
        this->debug();
        if(pBackgroundInput->getInteract()) {
            // pBackgroundInput->setInteract(false); //One Press at a time
            // this->bDebug = true; //Debug

            // std::cout << "Previous Grid: " << MapManager::getInstance()->getActiveGrid() << std::endl;
            // std::cout << "[ALT] Previous Grid: " << MapManager::getInstance()->getMapGrid(this->nFrame) << std::endl;
            // std::cout << "Previous Frame: " << this->nFrame << std::endl << std::endl;

            // this->nFrame += 1;
            // if(this->nFrame == this->nLastFrame) this->nFrame = 0;
            // int Grid = MapManager::getInstance()->getMapGrid(this->nFrame);
            // MapManager::getInstance()->setActiveGrid(Grid); 

            // // Debug Displays
            // std::cout << "Current Grid: " << MapManager::getInstance()->getActiveGrid() << std::endl;
            // std::cout << "[ALT] Current Grid: " << MapManager::getInstance()->getMapGrid(this->nFrame) << std::endl;
            // std::cout << "Current Frame: " << this->nFrame << std::endl;
            // std::cout << "Last Frame: " << this->nLastFrame << std::endl << std::endl;

            // pTestUnit->centerPosition();
        }
        else this->bDebug = false; //Prevent spam

        pTestBackground->setFrame(MapManager::getInstance()->findGridByNum(MapManager::getInstance()->getActiveGrid()));
        pLeftBounds->setFrame(MapManager::getInstance()->findGridByNum(MapManager::getInstance()->getActiveGrid()));
        pRightBounds->setFrame(MapManager::getInstance()->findGridByNum(MapManager::getInstance()->getActiveGrid()));
        pTopBounds->setFrame(MapManager::getInstance()->findGridByNum(MapManager::getInstance()->getActiveGrid()));
        pBottomBounds->setFrame(MapManager::getInstance()->findGridByNum(MapManager::getInstance()->getActiveGrid()));
        pTestBounds->setFrame(MapManager::getInstance()->findGridByNum(MapManager::getInstance()->getActiveGrid()));
    }
}

void BackgroundAction::debug() {
    //if(this->bDebug) std::cout << "Debug Press" << std::endl; //Debug Dis
}