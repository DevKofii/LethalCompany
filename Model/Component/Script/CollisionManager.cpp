#include "CollisionManager.hpp"

using namespace components;

CollisionManager::CollisionManager(std::string strName) : Component  (strName, ComponentType::SCRIPT) {
    this->nFrame = 0;
    this->nLastFrame = 0;

    this->currentGrid = MapManager::getInstance()->getActiveGrid();
    this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);
    this->prevGrid = -1;

    this->debug = true;
}

void CollisionManager::perform() {
    TestUnit* pUnitOwner = (TestUnit*)this->pOwner;
    TestUnitInput* pUnitInput = (TestUnitInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0];

    if(pUnitInput == NULL && pUnitOwner == NULL) {
        std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    }
    else {
        this->windowBounds();
        this->mapBounds();
    }
}

void CollisionManager::windowBounds() {
    TestUnit* pUnitOwner = (TestUnit*)this->pOwner;
    TestUnitInput* pUnitInput = (TestUnitInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0];
    TestBoundary* pLeftBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("LeftBounds");
    TestBoundary* pTopBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("TopBounds");

    float fOffset  = pUnitOwner->getSpeed() * this->tDeltaTime.asSeconds();

    //Left Boundary
    if(pUnitOwner->getSprite()->getGlobalBounds().left <= 0.f) {
        pUnitOwner->getSprite()->move(fOffset,0.f);
    }

    //Right Boundary
    if(pUnitOwner->getSprite()->getGlobalBounds().left + pUnitOwner->getSprite()->getGlobalBounds().width >= SCREEN_WIDTH) {
        pUnitOwner->getSprite()->move(-fOffset,0.f);
    }

    //Top Boundary
    if(pUnitOwner->getSprite()->getGlobalBounds().top <= 0.f) {
        pUnitOwner->getSprite()->move(0.f,fOffset);
    }

    //Bottom Boundary
    if(pUnitOwner->getSprite()->getGlobalBounds().top + pUnitOwner->getSprite()->getGlobalBounds().height >= SCREEN_HEIGHT) {
        pUnitOwner->getSprite()->move(0.f,-fOffset);
    }
}

void CollisionManager::setDoorPosL(int num) {
    TestDoor* pDoorL = (TestDoor*)GameObjectManager::getInstance()->findObjectByName("DoorLeft");
    switch(num) {
        case 2:
            pDoorL->getSprite()->setPosition(GRID2_X,DOOR_GRID_Y);
            break;
        case 3:
            pDoorL->getSprite()->setPosition(GRID3_X,DOOR_GRID_Y);
            break;
        case 5:
            pDoorL->getSprite()->setPosition(GRID5_X,DOOR_GRID_Y);
            break;
        case 6:
            pDoorL->getSprite()->setPosition(GRID6_X,DOOR_GRID_Y);
            break;
        case 8:
            pDoorL->getSprite()->setPosition(GRID8_X,DOOR_GRID_Y);
            break;
        case 9:
            pDoorL->getSprite()->setPosition(GRID9_X,DOOR_GRID_Y);
            break;
        default:
            pDoorL->getSprite()->setPosition(-1000.f,-1000.f);
            break;
    }
}

void CollisionManager::setDoorPosR(int num) {
    TestDoor* pDoorR = (TestDoor*)GameObjectManager::getInstance()->findObjectByName("DoorRight");
    switch(num) {
        case 0:
            pDoorR->getSprite()->setPosition(GRID0_X + GRID0_WIDTH, DOOR_GRID_Y);
            break;
        case 1:
            pDoorR->getSprite()->setPosition(GRID1_X + GRID1_WIDTH, DOOR_GRID_Y);
            break;
        case 2:
            pDoorR->getSprite()->setPosition(GRID2_X + GRID2_WIDTH, DOOR_GRID_Y);
            break;
        case 4:
            pDoorR->getSprite()->setPosition(GRID4_X + GRID4_WIDTH, DOOR_GRID_Y);
            break;
        case 5:
            pDoorR->getSprite()->setPosition(GRID5_X + GRID5_WIDTH, DOOR_GRID_Y);
            break;
        case 7:
            pDoorR->getSprite()->setPosition(GRID7_X + GRID7_WIDTH, DOOR_GRID_Y);
            break;
        case 8:
            pDoorR->getSprite()->setPosition(GRID8_X + GRID8_WIDTH, DOOR_GRID_Y);
            break;
        default:
            pDoorR->getSprite()->setPosition(-1000.f,-1000.f);
            break;
    }
}

void CollisionManager::setDoorPosT(int num) {
    TestDoor* pDoorT = (TestDoor*)GameObjectManager::getInstance()->findObjectByName("DoorTop");
    switch(num) {
        case 4:
            //pDoorT->getSprite()->setPosition(GRID2_X,DOOR_GRID_Y);
            pDoorT->getSprite()->setPosition(DOOR_GRID_X,GRID4_Y);
            break;
        case 5:
            pDoorT->getSprite()->setPosition(DOOR_GRID_X,GRID5_Y);
            break;
        case 6:
            pDoorT->getSprite()->setPosition(DOOR_GRID_X,GRID6_Y);
            break;
        case 7:
            pDoorT->getSprite()->setPosition(DOOR_GRID_X,GRID7_Y);
            break;
        case 8:
            pDoorT->getSprite()->setPosition(DOOR_GRID_X,GRID8_Y);
            break;
        case 9:
            pDoorT->getSprite()->setPosition(DOOR_GRID_X,GRID9_Y);
            break;
        default:
            pDoorT->getSprite()->setPosition(-1000.f,-1000.f);
            break;
    }
}

void CollisionManager::setDoorPosB(int num) {
    TestDoor* pDoorB = (TestDoor*)GameObjectManager::getInstance()->findObjectByName("DoorBottom");
    switch(num) {
        case 1:
            pDoorB->getSprite()->setPosition(DOOR_GRID_X,GRID1_Y + GRID1_HEIGHT);
            break;
        case 2:
            pDoorB->getSprite()->setPosition(DOOR_GRID_X,GRID2_Y + GRID2_HEIGHT);
            break;
        case 3:
            pDoorB->getSprite()->setPosition(DOOR_GRID_X,GRID3_Y + GRID3_HEIGHT);
            break;
        case 4:
            pDoorB->getSprite()->setPosition(DOOR_GRID_X,GRID4_Y + GRID4_HEIGHT);
            break;
        case 5:
            pDoorB->getSprite()->setPosition(DOOR_GRID_X,GRID5_Y + GRID5_HEIGHT);
            break;
        case 6:
            pDoorB->getSprite()->setPosition(DOOR_GRID_X,GRID6_Y + GRID6_HEIGHT);
            break;
        default:
            pDoorB->getSprite()->setPosition(-1000.f,-1000.f);
            break;
    }
}

void CollisionManager::mapBounds() {
    TestUnit* pUnitOwner = (TestUnit*)this->pOwner;
    TestUnitInput* pUnitInput = (TestUnitInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0];
    TestBoundary* pLeftBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("LeftBounds");
    TestBoundary* pRightBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("RightBounds");
    TestBoundary* pTopBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("TopBounds");
    TestBoundary* pBottomBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("BottomBounds");

    float fOffset  = pUnitOwner->getSpeed() * this->tDeltaTime.asSeconds();

    //Set Max Frame
    this->nLastFrame = MapManager::getInstance()->getRoomSize();

    //Set Vars
    bool next = false;
    bool prev = false;

    //Return Hub
    int safeGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(0));
    int p = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) - 1);
    if(safeGrid == p) {
        //std::cout << "Press E To Return" << std::endl;
        if(pUnitInput->getInteract()) {
            pUnitOwner->getSprite()->setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

            MapManager::getInstance()->setActiveGrid(MapManager::getInstance()->getMapGrid(0));
            this->currentGrid = MapManager::getInstance()->getActiveGrid();
            this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);
            this->prevGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) - 1);

            std::cout << "Current Grid: " << this->currentGrid << std::endl;
            std::cout << "Next Grid: " << this->nextGrid << std::endl;
            std::cout << "Last Grid: " << this->prevGrid << std::endl << std::endl;
        }
    }

    //Door Checks | LEFT
    bool nextDoor_L = MapManager::getInstance()->isValidLeft(this->currentGrid, this->nextGrid);
    bool prevDoor_L = MapManager::getInstance()->isValidLeft(this->currentGrid, this->prevGrid);
    if(nextDoor_L == true || prevDoor_L == true) this->setDoorPosL(this->currentGrid);
    else this->setDoorPosL(-1);
    
    //Door Checks | Right
    bool nextDoor_R = MapManager::getInstance()->isValidRight(this->currentGrid, this->nextGrid);
    bool prevDoor_R = MapManager::getInstance()->isValidRight(this->currentGrid, this->prevGrid);
    if(nextDoor_R == true || prevDoor_R == true && this->prevGrid != 0) this->setDoorPosR(this->currentGrid);
    else if(prevDoor_R == true && this->prevGrid == 0) this->setDoorPosR(-1);
    else this->setDoorPosR(-1);

    //Door Checks | Top
    bool nextDoor_T = MapManager::getInstance()->isValidTop(this->currentGrid, this->nextGrid);
    bool prevDoor_T = MapManager::getInstance()->isValidTop(this->currentGrid, this->prevGrid);
    if(nextDoor_T == true || prevDoor_T == true) this->setDoorPosT(this->currentGrid);
    else this->setDoorPosT(-1);

    //Door Checks | Bottom
    bool nextDoor_B = MapManager::getInstance()->isValidBottom(this->currentGrid, this->nextGrid);
    bool prevDoor_B = MapManager::getInstance()->isValidBottom(this->currentGrid, this->prevGrid);
    if(nextDoor_B == true || prevDoor_B == true) this->setDoorPosB(this->currentGrid);
    else this->setDoorPosB(-1);

    //LeftBounds
    if(pUnitOwner->getSprite()->getGlobalBounds().intersects(pLeftBounds->getSprite()->getGlobalBounds())) {
        pUnitOwner->getSprite()->move(fOffset,0.f);
        next = MapManager::getInstance()->isValidLeft(this->currentGrid, this->nextGrid);
        prev = MapManager::getInstance()->isValidLeft(this->currentGrid, this->prevGrid);

        if(next == true) {
            //pUnitOwner->getSprite()->setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
            this->mapTraversal(1);
            MapManager::getInstance()->setActiveGrid(this->nextGrid);
            //this->prevGrid = this->currentGrid;
            this->currentGrid = this->nextGrid;
            this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);
            this->prevGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) - 1);

            //this->setDoorPosL(this->currentGrid);

            std::cout << "LEFT | NEXT FRAME" << std::endl;
            std::cout << "Current Grid: " << this->currentGrid << std::endl;
            std::cout << "Next Grid: " << this->nextGrid << std::endl;
            std::cout << "Last Grid: " << this->prevGrid << std::endl << std::endl;
        }

        else if(prev == true) {
            this->mapTraversal(1);
            MapManager::getInstance()->setActiveGrid(this->prevGrid);
            int temp = this->currentGrid; // Store current grid
            this->currentGrid = this->prevGrid;
            this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);
            this->prevGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) - 1);
            //this->prevGrid = temp;

            //this->setDoorPosL(this->currentGrid);

            std::cout << "LEFT | PREV FRAME" << std::endl;
            std::cout << "Current Grid: " << this->currentGrid << std::endl;
            std::cout << "Next Grid: " << this->nextGrid << std::endl;
            std::cout << "Last Grid: " << this->prevGrid << std::endl << std::endl;
        }
    }

    //RightBounds
    if(pUnitOwner->getSprite()->getGlobalBounds().intersects(pRightBounds->getSprite()->getGlobalBounds())) {
        pUnitOwner->getSprite()->move(-fOffset,0.f);

        next = MapManager::getInstance()->isValidRight(this->currentGrid, this->nextGrid);
        prev = MapManager::getInstance()->isValidRight(this->currentGrid, this->prevGrid);

        if(next == true && this->currentGrid == 0) {
            pUnitOwner->getSprite()->setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
            MapManager::getInstance()->setActiveGrid(this->nextGrid); 
            //this->prevGrid = this->currentGrid;
            this->currentGrid = this->nextGrid;
            this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);
            this->prevGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) - 1);

            //this->setDoorPosR(this->currentGrid);

            std::cout << "RIGHT | NEXT FRAME" << std::endl;
            std::cout << "Current Grid: " << this->currentGrid << std::endl;
            std::cout << "Next Grid: " << this->nextGrid << std::endl;
            std::cout << "Last Grid: " << this->prevGrid << std::endl << std::endl;
        }

        else if(next == true && this->currentGrid != 0) {
            // pUnitOwner->getSprite()->setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

            this->mapTraversal(2);
            MapManager::getInstance()->setActiveGrid(this->nextGrid); 
            //this->prevGrid = this->currentGrid;
            this->currentGrid = this->nextGrid;
            this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);
            this->prevGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) - 1);

            //this->setDoorPosR(this->currentGrid);

            std::cout << "RIGHT | NEXT FRAME" << std::endl;
            std::cout << "Current Grid: " << this->currentGrid << std::endl;
            std::cout << "Next Grid: " << this->nextGrid << std::endl;
            std::cout << "Last Grid: " << this->prevGrid << std::endl << std::endl;
        }

        else if(prev == true) {
            this->mapTraversal(2);
            MapManager::getInstance()->setActiveGrid(this->prevGrid); 
            int temp = this->currentGrid; // Store current grid
            this->currentGrid = this->prevGrid;
            this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);
            this->prevGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) - 1);
            //this->prevGrid = temp;

            //this->setDoorPosR(this->currentGrid);

            std::cout << "RIGHT | PREV FRAME" << std::endl;
            std::cout << "Current Grid: " << this->currentGrid << std::endl;
            std::cout << "Next Grid: " << this->nextGrid << std::endl;
            std::cout << "Last Grid: " << this->prevGrid << std::endl << std::endl;
            
        }

        else this->setDoorPosR(-1);
    }

    //TopBounds
    if(pUnitOwner->getSprite()->getGlobalBounds().intersects(pTopBounds->getSprite()->getGlobalBounds())) {
        pUnitOwner->getSprite()->move(0.f,fOffset);
        next = MapManager::getInstance()->isValidTop(this->currentGrid, this->nextGrid);
        prev = MapManager::getInstance()->isValidTop(this->currentGrid, this->prevGrid);

        if(next == true) {
            this->mapTraversal(3);
            MapManager::getInstance()->setActiveGrid(this->nextGrid); 
            //this->prevGrid = this->currentGrid;
            this->currentGrid = this->nextGrid;
            this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);
            this->prevGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) - 1);

            //this->setDoorPosT(this->currentGrid);

            std::cout << "TOP | NEXT FRAME" << std::endl;
            std::cout << "Current Grid: " << this->currentGrid << std::endl;
            std::cout << "Next Grid: " << this->nextGrid << std::endl;
            std::cout << "Last Grid: " << this->prevGrid << std::endl << std::endl;
        }

        else if(prev == true) {
            this->mapTraversal(3);
            MapManager::getInstance()->setActiveGrid(this->prevGrid); 
            int temp = this->currentGrid; // Store current grid
            this->currentGrid = this->prevGrid;
            this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);
            this->prevGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) - 1);
            //this->prevGrid = temp;

            //this->setDoorPosT(this->currentGrid);

            std::cout << "TOP | PREV FRAME" << std::endl;
            std::cout << "Current Grid: " << this->currentGrid << std::endl;
            std::cout << "Next Grid: " << this->nextGrid << std::endl;
            std::cout << "Last Grid: " << this->prevGrid << std::endl << std::endl;
        }
    }

    //BottomBounds
    if(pUnitOwner->getSprite()->getGlobalBounds().intersects(pBottomBounds->getSprite()->getGlobalBounds())) {
        pUnitOwner->getSprite()->move(0.f,-fOffset);
        next = MapManager::getInstance()->isValidBottom(this->currentGrid, this->nextGrid);
        prev = MapManager::getInstance()->isValidBottom(this->currentGrid, this->prevGrid);

        if(next == true) {
            this->mapTraversal(4);
            MapManager::getInstance()->setActiveGrid(this->nextGrid); 
            //this->prevGrid = this->currentGrid;
            this->currentGrid = this->nextGrid;
            this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);
            this->prevGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) - 1);

            //this->setDoorPosB(this->currentGrid);

            std::cout << "BOTTOM | NEXT FRAME" << std::endl;
            std::cout << "Current Grid: " << this->currentGrid << std::endl;
            std::cout << "Next Grid: " << this->nextGrid << std::endl;
            std::cout << "Last Grid: " << this->prevGrid << std::endl << std::endl;
        }

        else if(prev == true) {
            this->mapTraversal(4);
            MapManager::getInstance()->setActiveGrid(this->prevGrid); 
            int temp = this->currentGrid; // Store current grid
            this->currentGrid = this->prevGrid;
            this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);
            this->prevGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) - 1);
            //this->prevGrid = temp;

            //this->setDoorPosB(this->currentGrid);

            std::cout << "BOTTOM | PREV FRAME" << std::endl;
            std::cout << "Current Grid: " << this->currentGrid << std::endl;
            std::cout << "Next Grid: " << this->nextGrid << std::endl;
            std::cout << "Last Grid: " << this->prevGrid << std::endl << std::endl;            
        }
    }
}

void CollisionManager::mapTraversal(int debug) {
    TestUnit* pUnitOwner = (TestUnit*)this->pOwner;
    TestUnitInput* pUnitInput = (TestUnitInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0];
    TestBoundary* pLeftBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("LeftBounds");
    TestBoundary* pRightBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("RightBounds");
    TestBoundary* pTopBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("TopBounds");
    TestBoundary* pBottomBounds = (TestBoundary*)GameObjectManager::getInstance()->findObjectByName("BottomBounds");

    float fOffsetX = pUnitOwner->getSprite()->getPosition().x;
    float fOffsetY = pUnitOwner->getSprite()->getPosition().y;

    float fOffsetW = pUnitOwner->getSprite()->getGlobalBounds().width;
    float fOffsetH = pUnitOwner->getSprite()->getGlobalBounds().height;

    switch(debug) {
        case 1: //For Left Bounds | TP to Right bounds
            pUnitOwner->setPosition(sf::Vector2f(pRightBounds->getSprite()->getPosition().x - fOffsetW, fOffsetY));
            break;

        case 2: //For Right Bounds | TP to Left Bounds
            pUnitOwner->setPosition(sf::Vector2f(pLeftBounds->getSprite()->getGlobalBounds().width + fOffsetW, fOffsetY));
            break;

        case 3: //For Top Bounds | TP to Bottom Bounds
            pUnitOwner->setPosition(sf::Vector2f(fOffsetX, pBottomBounds->getSprite()->getPosition().y - fOffsetH));
            break;

        case 4: //For Bottom Bounds | TP to Top Bounds
            pUnitOwner->setPosition(sf::Vector2f(fOffsetX, pTopBounds->getSprite()->getGlobalBounds().height + fOffsetH));
            break;

        default:
            break;
    }
}

