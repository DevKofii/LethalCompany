#include "TextureManager.hpp"
using namespace managers;

void TextureManager::loadAll() {}

void TextureManager::loadMainMenu() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/TitleScreen.png");
    this->mapTexture[AssetType::TITLE_SCREEN].push_back(pTexture);
}

void TextureManager::loadGame() {
    sf::Texture* pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Background.png");
    this->mapTexture[AssetType::GAME_BACKGROUND].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/Player/this_ship_be_otp.png");
    this->mapTexture[AssetType::SHIP].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/Player/bullet.png");
    this->mapTexture[AssetType::PLAYER_BULLET].push_back(pTexture);
}

void TextureManager::loadTest() {
    sf::Texture* pTexture;
    sf::RectangleShape* pShape;

    MapManager::getInstance()->loadMap();
    std::vector<int> vecMap = MapManager::getInstance()->getMap();

    // Load connecting grids
    for(int i = 0; i < vecMap.size(); i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Debug/map/grid" + std::to_string(vecMap[i]) + ".png");
        this->mapTexture[AssetType::TEST_BACKGROUND].push_back(pTexture);
    }

    // Load ENEMY_1 texture
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/Enemy/enemy1.png");
    this->mapTexture[AssetType::ENEMY_1].push_back(pTexture);

    // Load ENEMY_2 texture
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/Enemy/enemy2.png");
    this->mapTexture[AssetType::ENEMY_2].push_back(pTexture);

    // Load ENEMY_3 texture
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/Enemy/enemy3.png");
    this->mapTexture[AssetType::ENEMY_3].push_back(pTexture);

    // Load ENEMY_4 texture
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Space Impact/Enemy/enemy4.png");
    this->mapTexture[AssetType::ENEMY_4].push_back(pTexture);

    //Load map[debug]
    // pTexture = new sf::Texture();
    // pTexture->loadFromFile("View/Image/Debug/map/grid8.png");
    // this->mapTexture[AssetType::TEST_BACKGROUND].push_back(pTexture);


    //Load char
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/char/anims/idle/idle.png");
    this->mapTexture[AssetType::PLAYER].push_back(pTexture);

    for(int i = 1; i <= 8; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Debug/char/anims/move/frame" + std::to_string(i) + ".png");
        this->mapTexture[AssetType::PLAYER].push_back(pTexture);
    }

    // Load Boundaries [Left]
    for(int i = 0; i < vecMap.size(); i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Debug/map/bounds/g" + std::to_string(vecMap[i]) + "_left.png");
        this->mapTexture[AssetType::LEFT].push_back(pTexture);
    }

    for(int i = 0; i < vecMap.size(); i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Debug/map/bounds/g" + std::to_string(vecMap[i]) + "_left.png");
        this->mapTexture[AssetType::RIGHT].push_back(pTexture);
    }

    // Load Boundaries [Top]
    for(int i = 0; i < vecMap.size(); i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Debug/map/bounds/g" + std::to_string(vecMap[i]) + "_top.png");
        this->mapTexture[AssetType::TOP].push_back(pTexture);
    }

    for(int i = 0; i < vecMap.size(); i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Debug/map/bounds/g" + std::to_string(vecMap[i]) + "_top.png");
        this->mapTexture[AssetType::BOTTOM].push_back(pTexture);
    }

    // Load Door
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/map/door.png");
    this->mapTexture[AssetType::DOOR].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/map/door_alt.png");
    this->mapTexture[AssetType::DOOR_ALT].push_back(pTexture);

    //Load Boundaries [Debug]
    // pTexture = new sf::Texture();
    // pTexture->loadFromFile("View/Image/Debug/map/bounds/g8_left.png");
    // this->mapTexture[AssetType::LEFT].push_back(pTexture);

    // pTexture = new sf::Texture();
    // pTexture->loadFromFile("View/Image/Debug/map/bounds/g8_top.png");
    // this->mapTexture[AssetType::TOP].push_back(pTexture);
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
