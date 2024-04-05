#include "TestScene.hpp"

using namespace scenes;

TestScene::TestScene() : Scene(SceneTag::TEST_SCENE) {}

void TestScene::onLoadResources() {
    TextureManager::getInstance()->loadTest();
}

void TestScene::onLoadObjects() {
    this->createBackground();
    this->createBoundaries();
    this->createDoor();
    this->spawnItem();
    this->spawnUnit();
}

void TestScene::onUnloadResources() {
    TextureManager::getInstance()->unloadAll(); 
}

void TestScene::createBackground() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TEST_BACKGROUND));
    TestBackground* pTestBackground = new TestBackground("TestBackground", pTexture);
    GameObjectManager::getInstance()->addObject(pTestBackground); //First Grid loaded here

    std::vector<int> vecMap = MapManager::getInstance()->getMap();

    for(int i = 0; i < vecMap.size(); i++) std::cout << vecMap[i] << " ";
    std::cout << std::endl;

    // Set Active Grid
    // std::cout << MapManager::getInstance()->getMapGrid(0) << std::endl;
    MapManager::getInstance()->setActiveGrid(MapManager::getInstance()->getMapGrid(0));
    // std::cout << "Current Grid: " << MapManager::getInstance()->getActiveGrid() << std::endl;
    // std::cout << "Current Frame: 0" << std::endl << std::endl;

    int currentGrid = MapManager::getInstance()->getActiveGrid();
    int nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(currentGrid) + 1);
    int prevGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(currentGrid) - 1);
    //int prevGrid = currentGrid;

    std::cout << "Current Grid: " << currentGrid << std::endl;
    std::cout << "Next Grid: " << nextGrid << std::endl;
    std::cout << "Last Grid: " << prevGrid << std::endl << std::endl;
    // MapManager::getInstance()->loadBoundaries();
}

void TestScene::createBoundaries() {
    //Load Boundaries | Initialize
    AnimatedTexture* pTexture;
    TestBoundary* pTestBoundary;

    //LeftBounds
    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::LEFT));
    pTestBoundary = new TestBoundary("LeftBounds", pTexture);
    GameObjectManager::getInstance()->addObject(pTestBoundary);

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::RIGHT));
    pTestBoundary = new TestBoundary("RightBounds", pTexture);
    GameObjectManager::getInstance()->addObject(pTestBoundary);

    //TopBounds
    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TOP));
    pTestBoundary = new TestBoundary("TopBounds", pTexture);
    GameObjectManager::getInstance()->addObject(pTestBoundary);

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BOTTOM));
    pTestBoundary = new TestBoundary("BottomBounds", pTexture);
    GameObjectManager::getInstance()->addObject(pTestBoundary);
}

void TestScene::createDoor() {
    AnimatedTexture* pTexture;
    TestDoor* pDoor;

    //LEFT AND RIGHT
    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::DOOR));
    pDoor = new TestDoor("DoorLeft", pTexture);
    GameObjectManager::getInstance()->addObject(pDoor);
    pDoor->getSprite()->setOrigin(pDoor->getSprite()->getTexture()->getSize().x/2, 0.f);

    pDoor = new TestDoor("DoorRight", pTexture);
    GameObjectManager::getInstance()->addObject(pDoor);
    pDoor->getSprite()->setOrigin(pDoor->getSprite()->getTexture()->getSize().x/2, 0.f);

    //TOP AND BOTTOM
    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::DOOR_ALT));
    pDoor = new TestDoor("DoorTop", pTexture);
    GameObjectManager::getInstance()->addObject(pDoor);
    pDoor->getSprite()->setOrigin(0.f, pDoor->getSprite()->getTexture()->getSize().y/2);

    pDoor = new TestDoor("DoorBottom", pTexture);
    GameObjectManager::getInstance()->addObject(pDoor);
    pDoor->getSprite()->setOrigin(0.f, pDoor->getSprite()->getTexture()->getSize().y/2);
}

void TestScene::spawnUnit() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::PLAYER));
    TestUnit* pTestUnit = new TestUnit("TestUnit", pTexture);
    pTestUnit->setFrame(0);
    pTestUnit->setOrientationRight(true);
    pTestUnit->setOrientationLeft(false);
    pTestUnit->setScale({2.0f,2.0f});
    pTestUnit->setPosition({640.f,360.f});
    GameObjectManager::getInstance()->addObject(pTestUnit);
}

<<<<<<< HEAD
void TestScene::createEnemyPool() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::ENEMY_1));

    Enemy* pEnemyRef = new Enemy("Enemy", pTexture);
    GameObjectPool* pEnemyPool = new GameObjectPool(PoolTag::ENEMY, 5, pEnemyRef);
    pEnemyPool->initalize();
    ObjectPoolManager::getInstance()->registerObjectPool(pEnemyPool);
}

void TestScene::spawnEnemies() {
    int currentGrid = MapManager::getInstance()->getActiveGrid();
    int nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(currentGrid) + 1);
    int prevGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(currentGrid) - 1);
    int randomGrid = rand() % 3 + currentGrid; // Randomly select a grid between the current grid and the next two grids

    int numEnemies = rand() % 5 + 1; // Spawn a random number of enemies between 1 and 5

    for (int i = 0; i < numEnemies; ++i) {
        GameObjectPool* pEnemyPool = ObjectPoolManager::getInstance()->getPool(PoolTag::ENEMY);
        GameObject* pEnemy = pEnemyPool->requestPoolable();

        // Set the enemy's position based on the random grid
        if (randomGrid == currentGrid) {
            pEnemy->setPosition({0.f, 0.f});
        }
    }
void TestScene::spawnItem() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::LIGHT));
    Light* pLight = new Light("Light",pTexture);
    GameObjectManager::getInstance()->addObject(pLight);
}

=======
>>>>>>> parent of d2b0c64 (hi nikko pls check thanks)
// void TestScene::spawnBot() {
//     AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TEST_UNIT));
//     TestEnemy* pTestBot = new TestEnemy("TestBot", pTexture);
//     pTestBot->setFrame(0);
//     pTestBot->setOrientationRight(false);
//     pTestBot->setOrientationLeft(true);
//     pTestBot->setScale({-2.0f,2.0f});
//     pTestBot->setPosition({690.f,210.f});
//     GameObjectManager::getInstance()->addObject(pTestBot);
// }

// void TestScene::createObjectPools() {
//     AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::TEST_BULLET));
//     TestUnit* pTestUnit = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");

//     TestBullet_R* pTestBulletRef_R = new TestBullet_R("Test Bullet R",pTexture,pTestUnit);
//     GameObjectPool* pTestBulletPool_R = new GameObjectPool(PoolTag::TEST_BULLET_R, 3, pTestBulletRef_R);
//     pTestBulletPool_R->initalize();
//     ObjectPoolManager::getInstance()->registerObjectPool(pTestBulletPool_R);

//     TestBullet_L* pTestBulletRef_L = new TestBullet_L("Test Bullet L",pTexture,pTestUnit);
//     GameObjectPool* pTestBulletPool_L = new GameObjectPool(PoolTag::TEST_BULLET_L, 3, pTestBulletRef_L);
//     pTestBulletPool_L->initalize();
//     ObjectPoolManager::getInstance()->registerObjectPool(pTestBulletPool_L);
    
//     // GameObjectPool* pRetrievedPool_R = ObjectPoolManager::getInstance()->getPool(PoolTag::TEST_BULLET_R);
//     // pRetrievedPool_R->requestPoolable();

//     // GameObjectPool* pRetrievedPool_L = ObjectPoolManager::getInstance()->getPool(PoolTag::TEST_BULLET_L);
//     // pRetrievedPool_L->requestPoolable();
// }


