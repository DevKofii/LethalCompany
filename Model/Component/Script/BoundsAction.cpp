#include "BoundsAction.hpp"

using namespace components;

BoundsAction::BoundsAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->vecMap = {};
    this->nCurrentGrid = 0;
}

void BoundsAction::perform() {
    TestBoundary* pLeftBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("LeftBounds");
    TestBoundary* pTopBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("TopBounds");
    int num = MapManager::getInstance()->getActiveGrid();


    if(pLeftBounds == NULL && pTopBounds == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        switch(num) {
            case 1:
                pLeftBounds->getSprite()->setPosition(0.f,GRID1_Y);
                pTopBounds->getSprite()->setPosition(GRID1_X, 0.f);
                break;
            case 2:
                pLeftBounds->getSprite()->setPosition(0.f,GRID2_Y);
                pTopBounds->getSprite()->setPosition(GRID2_X, 0.f);
                break;
            case 3:
                pLeftBounds->getSprite()->setPosition(0.f,GRID3_Y);
                pTopBounds->getSprite()->setPosition(GRID3_X, 0.f);
                break;
            case 4:
                pLeftBounds->getSprite()->setPosition(0.f,GRID4_Y);
                pTopBounds->getSprite()->setPosition(GRID4_X, 0.f);
                break;
            case 5:
                pLeftBounds->getSprite()->setPosition(0.f,GRID5_Y);
                pTopBounds->getSprite()->setPosition(GRID5_X, 0.f);
                break;
            case 6:
                pLeftBounds->getSprite()->setPosition(0.f,GRID6_Y);
                pTopBounds->getSprite()->setPosition(GRID6_X, 0.f);    
                break;
            case 7:
                pLeftBounds->getSprite()->setPosition(0.f,GRID7_Y);
                pTopBounds->getSprite()->setPosition(GRID7_X, 0.f);
                break;
            case 8:
                pLeftBounds->getSprite()->setPosition(0.f,GRID8_Y);
                pTopBounds->getSprite()->setPosition(GRID8_X, 0.f);
                break;
            case 9:
                pLeftBounds->getSprite()->setPosition(0.f,GRID8_Y);
                pTopBounds->getSprite()->setPosition(GRID8_X, 0.f);
                break;
            default:
                break;
        }
    }
}
