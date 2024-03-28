#include "GameScene.hpp"

using namespace scenes;

GameScene::GameScene() : Scene(SceneTag::GAME_SCENE) {
}

void GameScene::onLoadResources() {
    TextureManager::getInstance()->loadMap();
    TextureManager::getInstance()->loadPlayer();
}


void GameScene::onLoadObjects() {
    this->createBackground();
    this->createPlayer();
}

void GameScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll(); 
}
 
void GameScene::createBackground() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::MAP_BACKGROUND));
    Background* pBackground = new Background("Background", pTexture);
    GameObjectManager::getInstance()->addObject(pBackground);
}

void GameScene::createPlayer() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER));
    Player* pPlayer = new Player("Player", pTexture);
    pPlayer->setFrame(0);
    pPlayer->setOrientationRight(false);
    pPlayer->setOrientationLeft(true);
    pPlayer->setScale({-2.0f,2.0f});
    pPlayer->setPosition({690.f,210.f});
    GameObjectManager::getInstance()->addObject(pPlayer);
}

void GameScene::createObjectPools() {
    // AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER_BULLET));
    // Ship* pShip = (Ship*)GameObjectManager::getInstance()->findObjectByName("Ship");
    // PlayerBullet* pBulletReference = new PlayerBullet("Player Bullet", pTexture, pShip);
    // GameObjectPool* pBulletPool = new GameObjectPool(PoolTag::PLAYER_BULLET, 3, pBulletReference);

    // pBulletPool->initalize();
}


