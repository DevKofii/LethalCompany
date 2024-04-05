#include "MapManager.hpp"

using namespace managers;
using namespace std;

void MapManager::loadMap() {
    this->nRooms = (rand() % (9 - 4 + 1)) + 4;
    std::cout << "Rooms: " << this->nRooms << std::endl;  

    if(this->nRooms == 6) this->loadSixRooms();
    else if(this->nRooms == 7) this->loadSevenRooms();
    else if(this->nRooms == 8) this->loadEightRooms();
    else if(this->nRooms == 9) this->loadNineRooms();
    else this->loadRooms();
}

void MapManager::loadSixRooms() {
    sf::Texture* pTexture;
    this->vecMap.push_back(0); // Safe Zone
    this->setActiveGrid(0);
    this->nRandomNum = (rand() % (8 - 1 + 1)) + 1;
    switch(this->nRandomNum) {
        case 1:
            this->vecMap.push_back(1);
            this->vecMap.push_back(2);
            this->vecMap.push_back(3);
            this->vecMap.push_back(6);
            this->vecMap.push_back(5);
            this->vecMap.push_back(4);
            break;
        case 2:
            this->vecMap.push_back(9);
            this->vecMap.push_back(8);
            this->vecMap.push_back(7);
            this->vecMap.push_back(4);
            this->vecMap.push_back(5);
            this->vecMap.push_back(6);
            break;
        case 3:
            this->vecMap.push_back(3);
            this->vecMap.push_back(2);
            this->vecMap.push_back(1);
            this->vecMap.push_back(4);
            this->vecMap.push_back(5);
            this->vecMap.push_back(6);
            break;
        case 4:
            this->vecMap.push_back(7);
            this->vecMap.push_back(8);
            this->vecMap.push_back(9);
            this->vecMap.push_back(6);
            this->vecMap.push_back(5);
            this->vecMap.push_back(4);
            break;
        case 5:
            this->vecMap.push_back(1);
            this->vecMap.push_back(4);
            this->vecMap.push_back(7);
            this->vecMap.push_back(8);
            this->vecMap.push_back(5);
            this->vecMap.push_back(2);
            break;
        case 6:
            this->vecMap.push_back(9);
            this->vecMap.push_back(6);
            this->vecMap.push_back(3);
            this->vecMap.push_back(2);
            this->vecMap.push_back(5);
            this->vecMap.push_back(8);
            break;
        case 7:
            this->vecMap.push_back(7);
            this->vecMap.push_back(4);
            this->vecMap.push_back(1);
            this->vecMap.push_back(2);
            this->vecMap.push_back(5);
            this->vecMap.push_back(8);
            break;
        case 8:
            this->vecMap.push_back(3);
            this->vecMap.push_back(6);
            this->vecMap.push_back(9);
            this->vecMap.push_back(8);
            this->vecMap.push_back(5);
            this->vecMap.push_back(2);
            break;
    }
}

void MapManager::loadSevenRooms() {
    sf::Texture* pTexture;
    this->vecMap.push_back(0); // Safe Zone
    this->setActiveGrid(0);
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
            break;
        case 2:

            this->vecMap.push_back(9);
            this->vecMap.push_back(8);
            this->vecMap.push_back(7);
            this->vecMap.push_back(4);
            this->vecMap.push_back(5);
            this->vecMap.push_back(6);
            this->vecMap.push_back(3);
            break;
        case 3:

            this->vecMap.push_back(3);
            this->vecMap.push_back(2);
            this->vecMap.push_back(1);
            this->vecMap.push_back(4);
            this->vecMap.push_back(5);
            this->vecMap.push_back(6);
            this->vecMap.push_back(9);
            break;
        case 4:

            this->vecMap.push_back(7);
            this->vecMap.push_back(8);
            this->vecMap.push_back(9);
            this->vecMap.push_back(6);
            this->vecMap.push_back(5);
            this->vecMap.push_back(4);
            this->vecMap.push_back(1);
            break;
        case 5:

            this->vecMap.push_back(1);
            this->vecMap.push_back(4);
            this->vecMap.push_back(7);
            this->vecMap.push_back(8);
            this->vecMap.push_back(5);
            this->vecMap.push_back(2);
            this->vecMap.push_back(3);
            break;
        case 6:

            this->vecMap.push_back(9);
            this->vecMap.push_back(6);
            this->vecMap.push_back(3);
            this->vecMap.push_back(2);
            this->vecMap.push_back(5);
            this->vecMap.push_back(8);
            this->vecMap.push_back(7);
            break;
        case 7:

            this->vecMap.push_back(7);
            this->vecMap.push_back(4);
            this->vecMap.push_back(1);
            this->vecMap.push_back(2);
            this->vecMap.push_back(5);
            this->vecMap.push_back(8);
            this->vecMap.push_back(9);
            break;
        case 8:

            this->vecMap.push_back(3);
            this->vecMap.push_back(6);
            this->vecMap.push_back(9);
            this->vecMap.push_back(8);
            this->vecMap.push_back(5);
            this->vecMap.push_back(2);
            this->vecMap.push_back(1);
            break;
    }
}

void MapManager::loadEightRooms() {
    sf::Texture* pTexture;
    this->vecMap.push_back(0); // Safe Zone
    this->setActiveGrid(0);
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
            break;
    }
}

void MapManager::loadNineRooms() {
    sf::Texture* pTexture;
    this->vecMap.push_back(0); // Safe Zone
    this->setActiveGrid(0);
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
}

void MapManager::loadRooms() {
    sf::Texture* pTexture;
    this->vecMap.push_back(0); // Safe Zone
    this->setActiveGrid(0);
    for(int i = 0; i < 1; i++) {
            this->nGrid = (rand() % (9 - 1 + 1)) + 1;
            while(this->nGrid == 5) {
                this->nGrid = (rand() % (9 - 1 + 1)) + 1;
            }
            this->nCurrent = this->nGrid;
            this->vecMap.push_back(this->nCurrent);
            this->setLock(this->nCurrent,true);
            //this->setActiveGrid(this->nGrid);
        }

    for(int i = 0; i < this->nRooms - 1; i++) {
        srand(time(NULL));
        switch(this->nCurrent) {
            case 1:
                this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                while(this->nGrid == 1 || this->nGrid == 3 || this->nGrid == 5 || this->nGrid == 6 || this->nGrid == 7 || this->nGrid == 8 || this->nGrid == 9 || this->getLock(this->nGrid) == true) {
                    this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                }
                break;

            case 2:
                this->nGrid = (rand() % (9 - 1 + 1)) + 1;
                while(this->nGrid == 2 || this->nGrid == 4 || this->nGrid == 6 || this->nGrid == 7 || this->nGrid == 8 || this->nGrid == 9 || this->getLock(this->nGrid) == true) {
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
                //while(this->getLock(this->nGrid) == true) this->nGrid = (rand() % (9 - 1 + 1)) + 1;
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
        this->vecMap.push_back(this->nCurrent);
        this->setLock(this->nCurrent,true);
    }
    // for(int i = 0; i < this->vecMap.size(); i++) std::cout << this->vecMap[i] << " ";
    // std::cout << std::endl;
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

int MapManager::findGridByNum(int nGrid) {
    for(auto i = 0; i < this->vecMap.size(); i++) {
        if(this->vecMap[i] == nGrid) {
            return i;
        }
    }
    return NULL;
}

int MapManager::getActiveGrid() {
    return this->nActiveGrid;
}

void MapManager::setActiveGrid(int nActiveGrid) {
    this->nActiveGrid = nActiveGrid;
}

bool MapManager::isValidLeft(int nGrid, int nFrame) {
    switch(nGrid) {
        case 2: // Going to Grid 1
            if(nFrame == 1) return true;
            else return false;
            break;
        case 3: 
            if(nFrame == 2) return true;
            else return false;
            break;
        case 5:
            if(nFrame == 4) return true;
            else return false;
            break;
        case 6: 
            if(nFrame == 5) return true;
            else return false;
            break;
        case 8:
            if(nFrame == 7) return true;
            else return false;
            break;
        case 9: 
            if(nFrame == 8) return true;
            else return false;
            break;
        default:
            return false;
            break;
    }
}

bool MapManager::isValidRight(int nGrid, int nFrame) {
    switch(nGrid) {
        case 0:
            return true;
            break;
        case 1: 
            if(nFrame == 2) return true;
            else return false;
            break;
        case 2:
            if(nFrame == 3) return true;
            else return false;
            break;
        case 4:
            if(nFrame == 5) return true;
            else return false;
            break;
        case 5:
            if(nFrame == 6) return true;
            else return false;
            break;
        case 7:
            if(nFrame == 8) return true;
            else return false;
            break;
        case 8:
            if(nFrame == 9) return true;
            else return false;
            break;
        default:
            return false;
            break;
    }
}

bool MapManager::isValidTop(int nGrid, int nFrame) {
    switch(nGrid) {
        case 4: 
            if(nFrame == 1) return true;
            else return false;
            break;
        case 5:
            if(nFrame == 2) return true;
            else return false;
            break;
        case 6:
            if(nFrame == 3) return true;
            else return false;
            break;
        case 7:
            if(nFrame == 4) return true;
            else return false;
            break;
        case 8:
            if(nFrame == 5) return true;
            else return false;
            break;
        case 9:
            if(nFrame == 6) return true;
            else return false;
            break;
        default:
            return false;
            break;
    }
}

bool MapManager::isValidBottom(int nGrid, int nFrame) {
    switch(nGrid) {
        case 1: 
            if(nFrame == 4) return true;
            else return false;
            break;
        case 2:
            if(nFrame == 5) return true;
            else return false;
            break;
        case 3:
            if(nFrame == 6) return true;
            else return false;
            break;
        case 4:
            if(nFrame == 7) return true;
            else return false;
            break;
        case 5:
            if(nFrame == 8) return true;
            else return false;
            break;
        case 6:
            if(nFrame == 9) return true;
            else return false;
            break;
        default:
            return false;
            break;
    }
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
