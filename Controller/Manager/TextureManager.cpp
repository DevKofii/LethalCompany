#include "TextureManager.hpp"
using namespace managers;
using namespace std;

void TextureManager::loadAll() {}

void TextureManager::loadMap() {
    this->nRooms = (rand() % (9 - 4 + 1)) + 4;
    std::cout << "Rooms: " << this->nRooms << std::endl;  

    if(this->nRooms == 9) this->loadNineRooms();
    else this->loadRooms();
}

void TextureManager::loadNineRooms() {
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

    // for(int i = 0; i < this->vecMap.size(); i++) std::cout << this->vecMap[i] << " ";
    // std::cout << std::endl;

    //Load connecting grids
    for(int i = 0; i < this->vecMap.size(); i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Debug/map/grid" + std::to_string(this->vecMap[i]) + ".png");
        this->mapTexture[AssetType::MAP_BACKGROUND].push_back(pTexture);
    }
}

void TextureManager::loadRooms() {
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
    // for(int i = 0; i < this->vecMap.size(); i++) std::cout << this->vecMap[i] << " ";
    // std::cout << std::endl;

    //Load connecting grids
    for(int i = 0; i < this->vecMap.size(); i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Debug/map/grid" + std::to_string(this->vecMap[i]) + ".png");
        this->mapTexture[AssetType::MAP_BACKGROUND].push_back(pTexture);
    }
}

void TextureManager::loadMainMenu() {
    // sf::Texture* pTexture = new sf::Texture();
    // pTexture->loadFromFile("View/Image/Space Impact/main_menu_background.png");
    // this->mapTexture[AssetType::MAIN_MENU_BACKGROUND].push_back(pTexture);
}

void TextureManager::loadGame() {
    // sf::Texture* pTexture = new sf::Texture();
    // pTexture->loadFromFile("View/Image/Space Impact/game_background.png");
    // this->mapTexture[AssetType::GAME_BACKGROUND].push_back(pTexture);

    // pTexture = new sf::Texture();
    // pTexture->loadFromFile("View/Image/Space Impact/Player/this_ship_be_otp.png");
    // this->mapTexture[AssetType::SHIP].push_back(pTexture);

    // pTexture = new sf::Texture();
    // pTexture->loadFromFile("View/Image/Space Impact/Player/bullet.png");
    // this->mapTexture[AssetType::PLAYER_BULLET].push_back(pTexture);
}

void TextureManager::unloadAll() {
    for(AssetType EType : this->vecAssetTypes) {
        std::vector<sf::Texture*> vecTextures = this->mapTexture[EType];
        for(int i = 0; i < vecTextures.size(); i++) {
            delete this->mapTexture[EType][i];
        }
    }

    this->vecAssetTypes.clear();
    this->mapTexture.clear();
}

std::vector<sf::Texture*> TextureManager::getTexture(AssetType EKey) {
    return this->mapTexture[EKey];
}

sf::Texture* TextureManager::getTextureAt(AssetType EKey, int nFrame) {
    return this->mapTexture[EKey][nFrame];
}

bool TextureManager::getLock(int nGrid) {
    switch(nGrid){
        case 1:
            return this->bOne;
            break;
        case 2:
            return this->bTwo;
            break;
        case 3:
            return this->bThree;
            break;
        case 4:
            return this->bFour;
            break;
        case 5:
            return this->bFive;
            break;
        case 6:
            return this->bSix;
            break;
        case 7:
            return this->bSeven;
            break;
        case 8:
            return this->bEight;
            break;
        case 9:
            return this->bNine;
            break;
    }
}
void TextureManager::setLock(int nGrid, bool bLock) {
    switch(nGrid){
        case 1:
            this->bOne = bLock;
            break;
        case 2:
            this->bTwo = bLock;
            break;
        case 3:
            this->bThree = bLock;
            break;
        case 4:
            this->bFour = bLock;
            break;
        case 5:
            this->bFive = bLock;
            break;
        case 6:
            this->bSix = bLock;
            break;
        case 7:
            this->bSeven = bLock;
            break;
        case 8:
            this->bEight = bLock;
            break;
        case 9:
            this->bNine = bLock;
            break;
    }
}


TextureManager* TextureManager::P_SHARED_INSTANCE = NULL;

TextureManager::TextureManager() {}

TextureManager::TextureManager(const TextureManager&) {}

TextureManager* TextureManager::getInstance() {
    // If instance does not exist, create a new instance of that object by
    // allocating new memory.
    if(P_SHARED_INSTANCE  == NULL) P_SHARED_INSTANCE = new TextureManager();

    //Return Shared Instance
    return P_SHARED_INSTANCE;
}
