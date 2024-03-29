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

void CollisionManager::mapBounds() {
    TestUnit* pUnitOwner = (TestUnit*)this->pOwner;
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

    //LeftBounds
    if(pUnitOwner->getSprite()->getGlobalBounds().intersects(pLeftBounds->getSprite()->getGlobalBounds())) {
        pUnitOwner->getSprite()->move(fOffset,0.f);
        next = MapManager::getInstance()->isValidLeft(this->currentGrid, this->nextGrid);
        prev = MapManager::getInstance()->isValidLeft(this->currentGrid, this->prevGrid);

        if(next == true) {
            this->mapTraversal(1);
            MapManager::getInstance()->setActiveGrid(this->nextGrid);
            this->prevGrid = this->currentGrid;
            this->currentGrid = this->nextGrid;
            this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);

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
            this->prevGrid = temp;

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

        if(next == true) {
            this->mapTraversal(2);
            MapManager::getInstance()->setActiveGrid(this->nextGrid); 
            this->prevGrid = this->currentGrid;
            this->currentGrid = this->nextGrid;
            this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);

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
            this->prevGrid = temp;

            std::cout << "RIGHT | PREV FRAME" << std::endl;
            std::cout << "Current Grid: " << this->currentGrid << std::endl;
            std::cout << "Next Grid: " << this->nextGrid << std::endl;
            std::cout << "Last Grid: " << this->prevGrid << std::endl << std::endl;
        }
    }

    //TopBounds
    if(pUnitOwner->getSprite()->getGlobalBounds().intersects(pTopBounds->getSprite()->getGlobalBounds())) {
        pUnitOwner->getSprite()->move(0.f,fOffset);
        next = MapManager::getInstance()->isValidTop(this->currentGrid, this->nextGrid);
        prev = MapManager::getInstance()->isValidTop(this->currentGrid, this->prevGrid);

        if(next == true) {
            this->mapTraversal(3);
            MapManager::getInstance()->setActiveGrid(this->nextGrid); 
            this->prevGrid = this->currentGrid;
            this->currentGrid = this->nextGrid;
            this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);

            std::cout << "RIGHT | NEXT FRAME" << std::endl;
            std::cout << "Current Grid: " << this->currentGrid << std::endl;
            std::cout << "Next Grid: " << this->nextGrid << std::endl;
            std::cout << "Last Grid: " << this->prevGrid << std::endl << std::endl;
        }

        else if(prev == true) {
            this->mapTraversal(3);
            MapManager::getInstance()->setActiveGrid(this->prevGrid); 
            int temp = this->currentGrid; // Store current grid
            this->currentGrid = this->prevGrid;
            this->prevGrid = temp;

            std::cout << "RIGHT | PREV FRAME" << std::endl;
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
            this->prevGrid = this->currentGrid;
            this->currentGrid = this->nextGrid;
            this->nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(this->currentGrid) + 1);

            std::cout << "RIGHT | NEXT FRAME" << std::endl;
            std::cout << "Current Grid: " << this->currentGrid << std::endl;
            std::cout << "Next Grid: " << this->nextGrid << std::endl;
            std::cout << "Last Grid: " << this->prevGrid << std::endl << std::endl;
        }

        else if(prev == true) {
            this->mapTraversal(4);
            MapManager::getInstance()->setActiveGrid(this->prevGrid); 
            int temp = this->currentGrid; // Store current grid
            this->currentGrid = this->prevGrid;
            this->prevGrid = temp;

            std::cout << "RIGHT | PREV FRAME" << std::endl;
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

