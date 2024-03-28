#include "MapManager.hpp"

using namespace managers;
using namespace std;

void MapManager::loadMap() {
    this->nRooms = (rand() % (9 - 4 + 1)) + 4;
    std::cout << "Rooms: " << this->nRooms << std::endl;  

    if(this->nRooms == 9) this->loadNineRooms();
    else this->loadRooms();
}

void MapManager::loadNineRooms() {
    sf::Texture* pTexture;
    this->nRandomNum = (rand() % (8 - 1 + 1)) + 1;
    switch(this->nRandomNum) {
        case 1:
            this->vecMap.push_back(1);
            this->vecMap.push_back(2);
            this->vecMap.push_back(3);
            this->vecMap.push_back(6);
            this->vecMap.push_back(5);
            this->vecMap.push_back(4);
            this->vecMap.push_back(7);
            this->vecMap.push_back(8);
            this->vecMap.push_back(9);
            break;
        case 2:
            this->vecMap.push_back(9);
            this->vecMap.push_back(8);
            this->vecMap.push_back(7);
            this->vecMap.push_back(4);
            this->vecMap.push_back(5);
            this->vecMap.push_back(6);
            this->vecMap.push_back(3);
            this->vecMap.push_back(2);
            this->vecMap.push_back(1);
            break;
        case 3:
            this->vecMap.push_back(3);
            this->vecMap.push_back(2);
            this->vecMap.push_back(1);
            this->vecMap.push_back(4);
            this->vecMap.push_back(5);
            this->vecMap.push_back(6);
            this->vecMap.push_back(9);
            this->vecMap.push_back(8);
            this->vecMap.push_back(7);
            break;
        case 4:
            this->vecMap.push_back(7);
            this->vecMap.push_back(8);
            this->vecMap.push_back(9);
            this->vecMap.push_back(6);
            this->vecMap.push_back(5);
            this->vecMap.push_back(4);
            this->vecMap.push_back(1);
            this->vecMap.push_back(2);
            this->vecMap.push_back(3);
            break;
        case 5:
            this->vecMap.push_back(1);
            this->vecMap.push_back(4);
            this->vecMap.push_back(7);
            this->vecMap.push_back(8);
            this->vecMap.push_back(5);
            this->vecMap.push_back(2);
            this->vecMap.push_back(3);
            this->vecMap.push_back(6);
            this->vecMap.push_back(9);
            break;
        case 6:
            this->vecMap.push_back(9);
            this->vecMap.push_back(6);
            this->vecMap.push_back(3);
            this->vecMap.push_back(2);
            this->vecMap.push_back(5);
            this->vecMap.push_back(8);
            this->vecMap.push_back(7);
            this->vecMap.push_back(4);
            this->vecMap.push_back(1);
            break;
        case 7:
            this->vecMap.push_back(7);
            this->vecMap.push_back(4);
            this->vecMap.push_back(1);
            this->vecMap.push_back(2);
            this->vecMap.push_back(5);
            this->vecMap.push_back(8);
            this->vecMap.push_back(9);
            this->vecMap.push_back(6);
            this->vecMap.push_back(3);
            break;
        case 8:
            this->vecMap.push_back(3);
            this->vecMap.push_back(6);
            this->vecMap.push_back(9);
            this->vecMap.push_back(8);
            this->vecMap.push_back(5);
            this->vecMap.push_back(2);
            this->vecMap.push_back(1);
            this->vecMap.push_back(4);
            this->vecMap.push_back(7);
            break;
    }

    for(int i = 0; i < this->vecMap.size(); i++) std::cout << this->vecMap[i] << " ";
    std::cout << std::endl;
}

void MapManager::loadRooms() {
    sf::Texture* pTexture;
    for(int i = 0; i < 1; i++) {
            this->nGrid = (rand() % (9 - 1 + 1)) + 1;
            while(this->nGrid == 5) {
                this->nGrid = (rand() % (9 - 1 + 1)) + 1;
            }
            this->nCurrent = this->nGrid;
            this->vecMap.push_back(this->nCurrent);
            this->setLock(this->nCurrent,true);
        }

    for(int i = 0; i < this->nRooms - 1; i++) {
        switch(this->nCurrent) {
            case 1:
                this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                while(this->nGrid == 1 || this->nGrid == 3 || this->nGrid == 5 || this->nGrid == 6 || this->nGrid == 7 || this->nGrid == 8 || this->nGrid == 9 || this->getLock(this->nGrid) == true) {
                    this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                }
                break;

            case 2:
                this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                while(this->nGrid == 2 || this->nGrid == 5 || this->nGrid == 6 || this->nGrid == 7 || this->nGrid == 8 || this->nGrid == 9 || this->getLock(this->nGrid) == true) {
                    this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                }
                break;

            case 3:
                this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                while(this->nGrid == 1 || this->nGrid == 3 || this->nGrid == 4 || this->nGrid == 5 || this->nGrid == 7 || this->nGrid == 8 || this->nGrid == 9 || this->getLock(this->nGrid) == true) {
                    this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                }
                break;
            case 4:
                this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                while(this->nGrid == 2 || this->nGrid == 3 || this->nGrid == 4 || this->nGrid == 6 || this->nGrid == 8 || this->nGrid == 9 || this->getLock(this->nGrid) == true) {
                    this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                }
                break;

            case 5:
                this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                while(this->nGrid == 1 || this->nGrid == 3 || this->nGrid == 5 || this->nGrid == 7 || this->nGrid == 9 || this->getLock(this->nGrid) == true)  {
                    this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                }
                break;

            case 6:
                this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                while(this->nGrid == 1 || this->nGrid == 2 || this->nGrid == 4 || this->nGrid == 6 || this->nGrid == 7 || this->nGrid == 8 || this->getLock(this->nGrid) == true) {
                    this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                }
                break;

            case 7:
                this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                while(this->nGrid == 1 || this->nGrid == 2 || this->nGrid == 3 || this->nGrid == 5 || this->nGrid == 6 || this->nGrid == 7 || this->nGrid == 9 || this->getLock(this->nGrid) == true) {
                    this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                }
                break;

            case 8:
                this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                while(this->nGrid == 1 || this->nGrid == 2 || this->nGrid == 3 || this->nGrid == 4 || this->nGrid == 6 || this->nGrid == 8 || this->getLock(this->nGrid) == true) {
                    this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                }
                break;

            case 9:
                this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                while(this->nGrid == 1 || this->nGrid == 2 || this->nGrid == 3 || this->nGrid == 4 || this->nGrid == 5 || this->nGrid == 7 || this->nGrid == 9 || this->getLock(this->nGrid) == true) {
                    this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                }
                break;
            default:
                break;
        }
        this->nCurrent = this->nGrid;
        this->setLock(this->nGrid,true);
        this->vecMap.push_back(this->nCurrent);
    }
    for(int i = 0; i < this->vecMap.size(); i++) std::cout << this->vecMap[i] << " ";
    std::cout << std::endl;
}

void MapManager::loadBoundaries() { 
    switch(this->nActiveGrid)
    {
        case 1:
            //Pos
            this->VLeftPos = {0.f, GRID1_Y};
            this->VRightPos = {GRID1_X + GRID1_WIDTH, GRID1_Y};
            this->VTopPos = {GRID1_X, 0.f};
            this->VBottomPos = {GRID1_X, GRID1_Y + GRID1_HEIGHT};
            break;

        default:
            break;
    }
}

std::vector<int> MapManager::getMap() {
    return this->vecMap;
}

int MapManager::getMapGrid(int nGrid) {
    return this->vecMap[nGrid];
}
 
int MapManager::getRoomSize() {
    return this->nRooms;
}

bool MapManager::getLock(int nGrid) {
    switch(nGrid){
        case 1:
            return this->bOneLock;
            break;
        case 2:
            return this->bTwoLock;
            break;
        case 3:
            return this->bThreeLock;
            break;
        case 4:
            return this->bFourLock;
            break;
        case 5:
            return this->bFiveLock;
            break;
        case 6:
            return this->bSixLock;
            break;
        case 7:
            return this->bSevenLock;
            break;
        case 8:
            return this->bEightLock;
            break;
        case 9:
            return this->bNineLock;
            break;
    }
}

void MapManager::setLock(int nGrid, bool bLock) {
    switch(nGrid){
        case 1:
            this->bOneLock = bLock;
            break;
        case 2:
            this->bTwoLock = bLock;
            break;
        case 3:
            this->bThreeLock = bLock;
            break;
        case 4:
            this->bFourLock = bLock;
            break;
        case 5:
            this->bFiveLock = bLock;
            break;
        case 6:
            this->bSixLock = bLock;
            break;
        case 7:
            this->bSevenLock = bLock;
            break;
        case 8:
            this->bEightLock = bLock;
            break;
        case 9:
            this->bNineLock = bLock;
            break;
    }
}

bool MapManager::getActiveGrid() {
    return this->nActiveGrid;
}

void MapManager::setActiveGrid(int nActiveGrid) {
    this->nActiveGrid = nActiveGrid;
}

//Pos
sf::Vector2f MapManager::getLeftBounds_pos() {
    return this->VLeftPos;
}

sf::Vector2f MapManager::getRightBounds_pos() {
    return this->VRightPos;
}   

sf::Vector2f MapManager::getTopBounds_pos() {
    return this->VTopPos;
}

sf::Vector2f MapManager::getBottomBounds_pos() {
    return this->VBottomPos;
}

MapManager* MapManager::P_SHARED_INSTANCE = NULL;

MapManager::MapManager() {}

MapManager::MapManager(const MapManager&) {}

MapManager* MapManager::getInstance() {
    // If instance does not exist, create a new instance of that object by
    // allocating new memory.
    if(P_SHARED_INSTANCE  == NULL) P_SHARED_INSTANCE = new MapManager();

    //Return Shared Instance
    return P_SHARED_INSTANCE;
}
