#include "ItemAction.hpp"

using namespace components;
using namespace std;

ItemAction::ItemAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->bEnabled = false;
    this->itemCount = 0;
}

void ItemAction::perform() {
    TestItem* pItem = (TestItem*)this->pOwner;
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");

    if(pItem == NULL) std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    else {
        this->spawnItem();
        if(this->bEnabled == true) {
            this->checkCollision();
        }
    }
}

void ItemAction::spawnItem() {
    TestItem* pItem = (TestItem*)this->pOwner;
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");
    TestUnitInput* pInput = (TestUnitInput*)pPlayer->findComponentByName(pPlayer->getName() + " Input");
    if(pItem->getEnabled() == true) {
        int currentActive = MapManager::getInstance()->getActiveGrid();

        int x = pItem->getPosX();
        int y = pItem->getPosY();

        if(pItem->getGrid() == currentActive) {
            pItem->getSprite()->setColor(sf::Color(255,255,255,255));
            pItem->setPosition({x,y});
            this->bEnabled = true;
        }
        else { 
            pItem->getSprite()->setColor(sf::Color(0,0,0,0));
            pItem->resetPos();
            this->bEnabled = false;
        }
    }
    else {
        if(pInput->getDrop()) {
            this->dropItem();
            ItemManager::getInstance()->dropObject();
            pInput->resetDrop();
        }
    }
}

void ItemAction::dropItem() {
    TestItem* pItem = (TestItem*)ItemManager::getInstance()->returnLastObject();
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");
    int currentActive = MapManager::getInstance()->getActiveGrid();

    std::cout << "Dropped " << pItem->getName() << std::endl;

    //Set Pos
    pItem->setPosX(pPlayer->getPosition().x);
    pItem->setPosY(pPlayer->getPosition().y);

    int x = pItem->getPosX();
    int y = pItem->getPosY();
    pItem->setPosition({x,y});

    //Set Active Grid
    pItem->setGrid(currentActive);

    //Set Enable Again
    pItem->setEnabled(true);

    //Check if grid is 0
    if(pItem->getGrid() == 0) {
        ItemManager::getInstance()->addProfit(pItem);
        ItemManager::getInstance()->calcProfit();
    }
}

void ItemAction::checkCollision() {
    TestItem* pItem = (TestItem*)this->pOwner;
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");
    TestUnitInput* pInput = (TestUnitInput*)pPlayer->findComponentByName(pPlayer->getName() + " Input");

    int currentInvGrid; 

    //Item Collision
    if(pPlayer->getSprite()->getGlobalBounds().intersects(pItem->getSprite()->getGlobalBounds()) && pItem->getEnabled()) { 
        //Pickup Item
        if(pInput->getInteract()) {
            std::cout << "Picked Up " << pItem->getName() << std::endl;
            std::cout << "Value: " << pItem->getProfit() << std::endl << std::endl;

            //If pickuped item is in grid 0, delete from profit
            if(pItem->getGrid() == 0) { 
                ItemManager::getInstance()->deleteProfit(pItem);
                ItemManager::getInstance()->pickupObject(pItem);
            }
            else { 
                ItemManager::getInstance()->pickupObject(pItem);
            }

            currentInvGrid = ItemManager::getInstance()->getGrid();
            this->setPosition(pItem->getName(), currentInvGrid);
            pItem->setEnabled(false);

            pInput->resetInteract();
        }
    }
}

void ItemAction::setPosition(std::string strName, int Grid) {
    TestItem* pItem = (TestItem*)GameObjectManager::getInstance()->findObjectByName(strName);

    switch(Grid) {
        case 1:
            pItem->setPosX(INV_BOX1_X);
            break;
        case 2:
            pItem->setPosX(INV_BOX2_X);
            break;
        case 3:
            pItem->setPosX(INV_BOX3_X);
            break;
        case 4:
            pItem->setPosX(INV_BOX4_X);
            break;
        case 5:
            pItem->setPosX(INV_BOX5_X);
            break;
        case 6:
            pItem->setPosX(INV_BOX6_X);
            break;
        case 7:
            pItem->setPosX(INV_BOX7_X);
            break;
        case 8:
            pItem->setPosX(INV_BOX8_X);
            break;
        case 9:
            pItem->setPosX(INV_BOX9_X);
            break;
    }

    pItem->setPosY(INV_BOX_Y);
    int x = pItem->getPosX();
    int y = pItem->getPosY();
    pItem->setPosition({x,y});
}