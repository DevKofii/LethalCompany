#include "TextureManager.hpp"
using namespace managers;

void TextureManager::loadAll() {}

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

    //Character Asset From https://penusbmic.itch.io/sci-fi-character-pack-12
    //Load char
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/char/anims/idle/idle.png");
    this->mapTexture[AssetType::PLAYER].push_back(pTexture);

    for(int i = 1; i <= 8; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Debug/char/anims/move/frame" + std::to_string(i) + ".png");
        this->mapTexture[AssetType::PLAYER].push_back(pTexture);
    }

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/char/anims/hit/hit.png");
    this->mapTexture[AssetType::PLAYER].push_back(pTexture);

    //Enemy Assets From https://luizmelo.itch.io/monsters-creatures-fantasy
    //Load enemy
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/enemy/anims/idle/enemy_idle.png");
    this->mapTexture[AssetType::ENEMY_1].push_back(pTexture);

    for(int i = 0; i <= 3; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Debug/enemy/anims/move/tile00" + std::to_string(i) + ".png");
        this->mapTexture[AssetType::ENEMY_1].push_back(pTexture);
    }

    //Load enemy
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/enemy2/anims/idle/enemy_idle.png");
    this->mapTexture[AssetType::ENEMY_2].push_back(pTexture);

    for(int i = 0; i <= 7; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Debug/enemy2/anims/move/tile00" + std::to_string(i) + ".png");
        this->mapTexture[AssetType::ENEMY_2].push_back(pTexture);
    }

    //Load enemy
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/enemy3/anims/idle/enemy_idle.png");
    this->mapTexture[AssetType::ENEMY_3].push_back(pTexture);

    for(int i = 0; i <= 7; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Debug/enemy3/anims/move/tile00" + std::to_string(i) + ".png");
        this->mapTexture[AssetType::ENEMY_3].push_back(pTexture);
    }

    //Load enemy
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/enemy4/anims/idle/enemy_idle.png");
    this->mapTexture[AssetType::ENEMY_4].push_back(pTexture);

    for(int i = 0; i <= 3; i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Debug/enemy4/anims/move/tile00" + std::to_string(i) + ".png");
        this->mapTexture[AssetType::ENEMY_4].push_back(pTexture);
    }

    //Load shadow
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/char/anims/parts/shadow.png");
    pTexture->setSmooth(1);
    this->mapTexture[AssetType::SHADOW].push_back(pTexture);

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

    // Load More Boundaries
    for(int i = 0; i < vecMap.size(); i++) {
        pTexture = new sf::Texture();
        pTexture->loadFromFile("View/Image/Debug/map/spec_bounds/grid" + std::to_string(vecMap[i]) + ".png");
        this->mapTexture[AssetType::BOUNDS].push_back(pTexture);
    }

    // Load Door
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/map/door.png");
    this->mapTexture[AssetType::DOOR].push_back(pTexture);

    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/map/door_alt.png");
    this->mapTexture[AssetType::DOOR_ALT].push_back(pTexture);

    // Load Flashlight
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/parts/items/light/light.png");
    this->mapTexture[AssetType::LIGHT].push_back(pTexture);

    // Load Pickup
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/parts/items/barrel/barrel.png");
    this->mapTexture[AssetType::BARREL].push_back(pTexture);

    // Load UI
    // Inventory
    pTexture = new sf::Texture();
    pTexture->loadFromFile("View/Image/Debug/ui/inv/inv.png");
    this->mapTexture[AssetType::INV].push_back(pTexture);
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
