#include "TestScene.hpp"

using namespace scenes;

TestScene::TestScene() : Scene(SceneTag::TEST_SCENE) {}

void TestScene::onLoadResources() {
    TextureManager::getInstance()->loadTest();
}

void TestScene::onLoadObjects() {
    this->createBackground();
    this->createBoundaries();
    this->loadMisc();
    this->spawnEnemies();
    this->createExtraBoundary();
    this->createDoor();
    this->createUI();
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
    MapManager::getInstance()->setActiveGrid(MapManager::getInstance()->getMapGrid(0));

    int currentGrid = MapManager::getInstance()->getActiveGrid();
    int nextGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(currentGrid) + 1);
    int prevGrid = MapManager::getInstance()->getMapGrid(MapManager::getInstance()->findGridByNum(currentGrid) - 1);

    std::cout << "Current Grid: " << currentGrid << std::endl;
    std::cout << "Next Grid: " << nextGrid << std::endl;
    std::cout << "Last Grid: " << prevGrid << std::endl << std::endl;
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

void TestScene::loadMisc() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::SHADOW));
    Shadow* pShadow = new Shadow("Shadow",pTexture);
    GameObjectManager::getInstance()->addObject(pShadow);

    pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::LIGHT));
    Light* pLight = new Light("Light",pTexture);
    GameObjectManager::getInstance()->addObject(pLight);

}

void TestScene::spawnEnemies() {
    //DISCARD PTEXTURE1, TRANSFER OVER YOURS (dont forget to put the textures at texturemanager)
    AnimatedTexture* pEnemyTexture1 = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::ENEMY_1));
    AnimatedTexture* pEnemyTexture2 = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::ENEMY_2));
    AnimatedTexture* pEnemyTexture3 = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::ENEMY_3));
    AnimatedTexture* pEnemyTexture4 = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::ENEMY_4));
    AnimatedTexture* pTexture2 = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::SHADOW));
    TestEnemy* pTestEnemy;
    Shadow* pShadow;

    int random = (rand() % (10 - 1 + 1)) + 1;
    int randomNum, grid;
    int maxSize = MapManager::getInstance()->getRoomSize();

    bool Lock;
    float val;
 
    for(int i = 0; i < random; i++) {
        pShadow = new Shadow("Shadow" + std::to_string(i), pTexture2);
        GameObjectManager::getInstance()->addObject(pShadow);

        val = rand() / ( RAND_MAX + 1.0f);

        //CHANGE PTEXTURE# BELOW ARIGATOU
        if(val <= 0.05f) {
            pTestEnemy = new TestEnemy("TestEnemy" + std::to_string(i), pEnemyTexture1, i);
            pTestEnemy->setFrame(0);
            pTestEnemy->setScale({2.0f,2.0f});
        }
        else if(val <= 0.25f) { //Change pTexture
            pTestEnemy = new TestEnemy("TestEnemy" + std::to_string(i), pEnemyTexture2, i);
            pTestEnemy->setFrame(0);
            pTestEnemy->setScale({2.0f,2.0f});
        }
        else if(val <= 0.55f) { //Change pTexture
            pTestEnemy = new TestEnemy("TestEnemy" + std::to_string(i), pEnemyTexture3, i);
            pTestEnemy->setFrame(0);
            pTestEnemy->setScale({2.0f,2.0f});
        }
        else if(val <= 0.45f) { //Change pTexture
            pTestEnemy = new TestEnemy("TestEnemy" + std::to_string(i), pEnemyTexture4, i);
            pTestEnemy->setFrame(0);
            pTestEnemy->setScale({2.0f,2.0f});
        }
        
        Lock = true;
        // Randomize Grid based on the min grid (1) and its max room size
        // Avoid Enemy spawning in first tile
        while(Lock == true) {
            randomNum = (rand() % (maxSize - 2 + 1)) + 2; 
            if(this->getGridLock(randomNum) == true) randomNum = (rand() % (maxSize - 2 + 1)) + 2; 

            //Find Index based on random num
            if(MapManager::getInstance()->findGridByNum(randomNum) == NULL) Lock == true;
            else {
                Lock = false;
                grid = MapManager::getInstance()->findGridByNum(randomNum);
            }
        }

        pTestEnemy->setGrid(randomNum);
        this->setGridLock(randomNum,true);
        this->setPosition(pTestEnemy);
        pTestEnemy->setPosition({pTestEnemy->getPosX(),pTestEnemy->getPosY()});
        GameObjectManager::getInstance()->addObject(pTestEnemy);
    }
}

void TestScene::createExtraBoundary() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BOUNDS));
    TestBounds* pTestBounds = new TestBounds("Bounds", pTexture);
    GameObjectManager::getInstance()->addObject(pTestBounds);
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

void TestScene::spawnItem() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::BARREL));
    TestItem* pBarrel;

    int random = (rand() % (20 - 5 + 1)) + 5;
    int randomGrid;

    float val;

    for(int i = 0; i < random; i++) {
        pBarrel = new TestItem("Barrel" + std::to_string(i), pTexture, i);
        randomGrid = (rand() % (9 - 2 + 1)) + 2; // Avoid Item spawning in first tile
        pBarrel->setGrid(randomGrid);
        this->setPosition(pBarrel);

        val = (rand() / ( RAND_MAX + 1.0f)) * 100;
        pBarrel->setProfit(val);
        
        GameObjectManager::getInstance()->addObject(pBarrel);
    }
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

void TestScene::createUI() {
    AnimatedTexture* pTexture = new AnimatedTexture(TextureManager::getInstance()->getTexture(AssetType::INV));
    TestUI* pInv = new TestUI("Inventory", pTexture);
    pInv->setPosition({INV_X, INV_Y});
    GameObjectManager::getInstance()->addObject(pInv);
}

void TestScene::setPosition(GameObject* pEntity) {
    int grid = pEntity->getGrid();
    int randomPosX, randomPosY, temp_min_x, temp_max_x, temp_min_y, temp_max_y;

    switch(grid) {
        case 0: // Debug
            temp_min_x = GRID0_X+75.f;
            temp_max_x = (GRID0_WIDTH + GRID0_X) - 75.f;

            temp_min_y = GRID0_Y+50.f;
            temp_max_y = (GRID0_HEIGHT + GRID0_Y) - 50.f;

            randomPosX = (rand() % (temp_max_x - temp_min_x + 1)) + temp_min_x;
            randomPosY = (rand() % (temp_max_y - temp_min_y + 1)) + temp_min_y;

            pEntity->setPosX(randomPosX);
            pEntity->setPosY(randomPosY);
            break;

        case 1: // Debug
            temp_min_x = GRID1_X+75.f;
            temp_max_x = (GRID1_WIDTH + GRID1_X) - 75.f;

            temp_min_y = GRID1_Y+50.f;
            temp_max_y = (GRID1_HEIGHT + GRID1_Y) - 50.f;

            randomPosX = (rand() % (temp_max_x - temp_min_x + 1)) + temp_min_x;
            randomPosY = (rand() % (temp_max_y - temp_min_y + 1)) + temp_min_y;

            pEntity->setPosX(randomPosX);
            pEntity->setPosY(randomPosY);
            break;

        case 2:
            temp_min_x = GRID2_X+75.f;
            temp_max_x = (GRID2_WIDTH + GRID2_X) - 75.f;

            temp_min_y = GRID2_Y+50.f;
            temp_max_y = (GRID2_HEIGHT + GRID2_Y) - 50.f;

            randomPosX = (rand() % (temp_max_x - temp_min_x + 1)) + temp_min_x;
            randomPosY = (rand() % (temp_max_y - temp_min_y + 1)) + temp_min_y;

            pEntity->setPosX(randomPosX);
            pEntity->setPosY(randomPosY);
            break;
        case 3:
            temp_min_x = GRID3_X+75.f;
            temp_max_x = (GRID3_WIDTH + GRID3_X) - 75.f;

            temp_min_y = GRID3_Y+50.f;
            temp_max_y = (GRID3_HEIGHT + GRID3_Y) - 50.f;

            randomPosX = (rand() % (temp_max_x - temp_min_x + 1)) + temp_min_x;
            randomPosY = (rand() % (temp_max_y - temp_min_y + 1)) + temp_min_y;

            pEntity->setPosX(randomPosX);
            pEntity->setPosY(randomPosY);
            break;
        case 4:
            temp_min_x = GRID4_X+75.f;
            temp_max_x = (GRID4_WIDTH + GRID4_X) - 75.f;

            temp_min_y = GRID4_Y+50.f;
            temp_max_y = (GRID4_HEIGHT + GRID4_Y) - 50.f;

            randomPosX = (rand() % (temp_max_x - temp_min_x + 1)) + temp_min_x;
            randomPosY = (rand() % (temp_max_y - temp_min_y + 1)) + temp_min_y;

            pEntity->setPosX(randomPosX);
            pEntity->setPosY(randomPosY);
            break;
        case 5:
            temp_min_x = GRID5_X+75.f;
            temp_max_x = (GRID5_WIDTH + GRID5_X) - 75.f;

            temp_min_y = GRID5_Y+50.f;
            temp_max_y = (GRID5_HEIGHT + GRID5_Y) - 50.f;

            randomPosX = (rand() % (temp_max_x - temp_min_x + 1)) + temp_min_x;
            randomPosY = (rand() % (temp_max_y - temp_min_y + 1)) + temp_min_y;

            pEntity->setPosX(randomPosX);
            pEntity->setPosY(randomPosY);
            break;
        case 6:
            temp_min_x = GRID6_X+75.f;
            temp_max_x = (GRID6_WIDTH + GRID6_X) - 75.f;

            temp_min_y = GRID6_Y+50.f;
            temp_max_y = (GRID6_HEIGHT + GRID6_Y) - 50.f;

            randomPosX = (rand() % (temp_max_x - temp_min_x + 1)) + temp_min_x;
            randomPosY = (rand() % (temp_max_y - temp_min_y + 1)) + temp_min_y;

            pEntity->setPosX(randomPosX);
            pEntity->setPosY(randomPosY);
            break;
        case 7:
            temp_min_x = GRID7_X+75.f;
            temp_max_x = (GRID7_WIDTH + GRID7_X) - 75.f;

            temp_min_y = GRID7_Y+50.f;
            temp_max_y = (GRID7_HEIGHT + GRID7_Y) - 50.f;

            randomPosX = (rand() % (temp_max_x - temp_min_x + 1)) + temp_min_x;
            randomPosY = (rand() % (temp_max_y - temp_min_y + 1)) + temp_min_y;

            pEntity->setPosX(randomPosX);
            pEntity->setPosY(randomPosY);
            break;
        case 8:
            temp_min_x = GRID8_X+75.f;
            temp_max_x = (GRID8_WIDTH + GRID8_X) - 75.f;

            temp_min_y = GRID8_Y+50.f;
            temp_max_y = (GRID8_HEIGHT + GRID8_Y) - 50.f;

            randomPosX = (rand() % (temp_max_x - temp_min_x + 1)) + temp_min_x;
            randomPosY = (rand() % (temp_max_y - temp_min_y + 1)) + temp_min_y;

            pEntity->setPosX(randomPosX);
            pEntity->setPosY(randomPosY);
            break;
        case 9:
            temp_min_x = GRID9_X+75.f;
            temp_max_x = (GRID9_WIDTH + GRID9_X) - 75.f;

            temp_min_y = GRID9_Y+50.f;
            temp_max_y = (GRID9_HEIGHT + GRID9_Y) - 50.f;

            randomPosX = (rand() % (temp_max_x - temp_min_x + 1)) + temp_min_x;
            randomPosY = (rand() % (temp_max_y - temp_min_y + 1)) + temp_min_y;

            pEntity->setPosX(randomPosX);
            pEntity->setPosY(randomPosY);
            break;
    }
}

void TestScene::setGridLock(int num, bool bLock) {
    switch(num) {
        case 1:
            this->one = bLock;
            break;
        case 2:
            this->two = bLock;
            break;
        case 3:
            this->three = bLock;
            break;
        case 4:
            this->four = bLock;
            break;
        case 5:
            this->five = bLock;
            break;
        case 6:
            this->six = bLock;
            break;
        case 7:
            this->seven = bLock;
            break;
        case 8:
            this->eight = bLock;
            break;
        case 9:
            this->nine = bLock;
            break;
    }
}

bool TestScene::getGridLock(int num) {
    switch(num) {
        case 1:
            return this->one;
            break;
        case 2:
            return this->two;
            break;
        case 3:
            return this->three;
            break;
        case 4:
            return this->four;
            break;
        case 5:
            return this->five;
            break;
        case 6:
            return this->six;
            break;
        case 7:
            return this->seven;
            break;
        case 8:
            return this->eight;
            break;
        case 9:
            return this->nine;
            break;
    }
}

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


