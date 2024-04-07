#include "ItemManager.hpp"

using namespace managers;
using namespace models;

void ItemManager::pickupObject(GameObject* pGameObject) {
    this->invObject[pGameObject->getName()] = pGameObject;
    this->vecInvObject.push_back(pGameObject);

    if(this->currentGrid < 9) this->currentGrid += 1;
}

void ItemManager::dropObject() {
    //delete this->invObject[strName];
    this->vecInvObject.pop_back();

    if(this->currentGrid > 0) this->currentGrid -= 1;
}

GameObject* ItemManager::findObjectByName(std::string strName) {
    if(this->invObject[strName] != NULL) return this->invObject[strName];
    else return NULL;
}

GameObject* ItemManager::returnLastObject() {
    return this->vecInvObject.back();
}

int ItemManager::getGrid() {    
    return this->currentGrid;
}

ItemManager* ItemManager::P_SHARED_INSTANCE = NULL;

ItemManager::ItemManager() {
    this->currentGrid = 0;
}

ItemManager::ItemManager(const ItemManager&) {}

ItemManager* ItemManager::getInstance() {
    if(P_SHARED_INSTANCE  == NULL) P_SHARED_INSTANCE = new ItemManager();
    return P_SHARED_INSTANCE;
}