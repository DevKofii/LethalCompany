#include "ItemAction.hpp"

using namespace components;
using namespace std;

ItemAction::ItemAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->bEnabled = false;
    this->itemCount = 0;
}

void ItemAction::perform() {
    TestItem* pItem = (TestItem*)this->pOwner;
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

void ItemAction::pickupItem(std::string strName) {
    TestItem* pItem = (TestItem*)GameObjectManager::getInstance()->findObjectByName(strName);

    // Set UI here later on
    pItem->setPosX(10);
    pItem->setPosY(10);

    int x = pItem->getPosX();
    int y = pItem->getPosY();
    pItem->setPosition({x,y});
    
    pItem->setEnabled(false);
}

void ItemAction::dropItem() {
    TestItem* pItem = (TestItem*)ItemManager::getInstance()->returnLastObject();
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");

    std::cout << "Dropped " << pItem->getName() << std::endl;

    // Set UI here later on
    pItem->setPosX(pPlayer->getPosition().x);
    pItem->setPosY(pPlayer->getPosition().y);

    int x = pItem->getPosX();
    int y = pItem->getPosY();
    pItem->setPosition({x,y});
    
    pItem->setEnabled(true);
}

void ItemAction::checkCollision() {
    TestItem* pItem = (TestItem*)this->pOwner;
    TestUnit* pPlayer = (TestUnit*)GameObjectManager::getInstance()->findObjectByName("TestUnit");
    TestUnitInput* pInput = (TestUnitInput*)pPlayer->findComponentByName(pPlayer->getName() + " Input");

    //Item Collision
    if(pPlayer->getSprite()->getGlobalBounds().intersects(pItem->getSprite()->getGlobalBounds()) && pItem->getEnabled()) { 
        if(pInput->getInteract()) {
            std::cout << "Picked Up " << pItem->getName() << std::endl;
            ItemManager::getInstance()->pickupObject(pItem);
            this->pickupItem(pItem->getName());
            pInput->resetInteract();
        }
    }
    if(pInput->getDrop()) {
        this->dropItem();
        pInput->resetDrop();
    }
}
