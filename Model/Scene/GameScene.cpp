#include "GameScene.hpp"

using namespace scenes;

GameScene::GameScene() : Scene(SceneTag::GAME_SCENE) {
}

void GameScene::onLoadResources() {
    TextureManager::getInstance()->loadMap();
}


void GameScene::onLoadObjects() {
    this->createBackground();
    //this->createShip();
}

void GameScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll(); 
}
 
void GameScene::createBackground() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::MAP_BACKGROUND));
    Background* pBackground = new Background("Background", pTexture);
    GameObjectManager::getInstance()->addObject(pBackground);
}

void GameScene::createShip() {
    // AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::SHIP));
    // Ship* pEntity = new Ship("Ship", pTexture);
    // GameObjectManager::getInstance()->addObject(pEntity);
}

void GameScene::createObjectPools() {
    // AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER_BULLET));
    // Ship* pShip = (Ship*)GameObjectManager::getInstance()->findObjectByName("Ship");
    // PlayerBullet* pBulletReference = new PlayerBullet("Player Bullet", pTexture, pShip);
    // GameObjectPool* pBulletPool = new GameObjectPool(PoolTag::PLAYER_BULLET, 3, pBulletReference);

    // pBulletPool->initalize();
}


