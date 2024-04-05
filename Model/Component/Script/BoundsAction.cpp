#include "BoundsAction.hpp"

using namespace components;

BoundsAction::BoundsAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->vecMap = {};
    this->nCurrentGrid = 0;
}

void BoundsAction::perform() {
    TestBoundary* pLeftBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("LeftBounds");
    TestBoundary* pRightBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("RightBounds");
    TestBoundary* pTopBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("TopBounds");
    TestBoundary* pBottomBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("BottomBounds");
    int num = MapManager::getInstance()->getActiveGrid();
    
    int debug;

    if(pLeftBounds == NULL && pRightBounds == NULL && pTopBounds == NULL && pBottomBounds == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        switch(num) {
            case 0:
                pLeftBounds->getSprite()->setPosition(0.f, GRID0_Y);
                pTopBounds->getSprite()->setPosition(GRID0_X, 0.f);
                pRightBounds->getSprite()->setPosition(GRID0_X + GRID0_WIDTH, GRID0_Y);
                pBottomBounds->getSprite()->setPosition(GRID0_X, GRID0_Y + GRID0_HEIGHT);
                break;

            case 1:
                pLeftBounds->getSprite()->setPosition(0.f, GRID1_Y);
                pTopBounds->getSprite()->setPosition(GRID1_X, 0.f);
                pRightBounds->getSprite()->setPosition(GRID1_X + GRID1_WIDTH, GRID1_Y);
                pBottomBounds->getSprite()->setPosition(GRID1_X, GRID1_Y + GRID1_HEIGHT);
                break;
            case 2:
                pLeftBounds->getSprite()->setPosition(0.f,GRID2_Y);
                pTopBounds->getSprite()->setPosition(GRID2_X, 0.f);
                pRightBounds->getSprite()->setPosition(GRID2_X + GRID2_WIDTH, GRID2_Y);
                pBottomBounds->getSprite()->setPosition(GRID2_X, GRID2_Y + GRID2_HEIGHT);
                break;
            case 3:
                pLeftBounds->getSprite()->setPosition(0.f,GRID3_Y);
                pTopBounds->getSprite()->setPosition(GRID3_X, 0.f);
                pRightBounds->getSprite()->setPosition(GRID3_X + GRID3_WIDTH, GRID3_Y);
                pBottomBounds->getSprite()->setPosition(GRID3_X, GRID3_Y + GRID3_HEIGHT);
                break;
            case 4:
                pLeftBounds->getSprite()->setPosition(0.f,GRID4_Y);
                pTopBounds->getSprite()->setPosition(GRID4_X, 0.f);
                pRightBounds->getSprite()->setPosition(GRID4_X + GRID4_WIDTH, GRID4_Y);
                pBottomBounds->getSprite()->setPosition(GRID4_X, GRID4_Y + GRID4_HEIGHT);
                break;
            case 5:
                pLeftBounds->getSprite()->setPosition(0.f,GRID5_Y);
                pTopBounds->getSprite()->setPosition(GRID5_X, 0.f);
                pRightBounds->getSprite()->setPosition(GRID5_X + GRID5_WIDTH, GRID5_Y);
                pBottomBounds->getSprite()->setPosition(GRID5_X, GRID5_Y + GRID5_HEIGHT);
                break;
            case 6:
                pLeftBounds->getSprite()->setPosition(0.f,GRID6_Y);
                pTopBounds->getSprite()->setPosition(GRID6_X, 0.f);    
                pRightBounds->getSprite()->setPosition(GRID6_X + GRID6_WIDTH, GRID6_Y);
                pBottomBounds->getSprite()->setPosition(GRID6_X, GRID6_Y + GRID6_HEIGHT);
                break;
            case 7:
                pLeftBounds->getSprite()->setPosition(0.f,GRID7_Y);
                pTopBounds->getSprite()->setPosition(GRID7_X, 0.f);
                pRightBounds->getSprite()->setPosition(GRID7_X + GRID7_WIDTH, GRID7_Y);
                pBottomBounds->getSprite()->setPosition(GRID7_X, GRID7_Y + GRID7_HEIGHT);
                break;
            case 8:
                pLeftBounds->getSprite()->setPosition(0.f,GRID8_Y);
                pTopBounds->getSprite()->setPosition(GRID8_X, 0.f);
                pRightBounds->getSprite()->setPosition(GRID8_X + GRID8_WIDTH, GRID8_Y);
                pBottomBounds->getSprite()->setPosition(GRID8_X, GRID8_Y + GRID8_HEIGHT);
                break;
            case 9:
                pLeftBounds->getSprite()->setPosition(0.f,GRID9_Y);
                pTopBounds->getSprite()->setPosition(GRID9_X, 0.f);
                pRightBounds->getSprite()->setPosition(GRID9_X + GRID9_WIDTH, GRID9_Y);
                pBottomBounds->getSprite()->setPosition(GRID9_X, GRID9_Y + GRID9_HEIGHT);
                break;
            default:
                break;
        }
    }
}
