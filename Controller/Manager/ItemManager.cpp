#include "ItemManager.hpp"

using namespace managers;
using namespace models;

void ItemManager::pickupObject(GameObject* pGameObject) {
    this->invObject[pGameObject->getName()] = pGameObject;
    this->vecInvObject.push_back(pGameObject);
}

void ItemManager::dropObject(std::string strName) {
    delete this->invObject[strName];
}

GameObject* ItemManager::findObjectByName(std::string strName) {
    if(this->invObject[strName] != NULL) return this->invObject[strName];
    else return NULL;
}

GameObject* ItemManager::returnLastObject() {
    return this->vecInvObject.back();
}

ItemManager* ItemManager::P_SHARED_INSTANCE = NULL;

ItemManager::ItemManager() {}

ItemManager::ItemManager(const ItemManager&) {}

ItemManager* ItemManager::getInstance() {
    if(P_SHARED_INSTANCE  == NULL) P_SHARED_INSTANCE = new ItemManager();
    return P_SHARED_INSTANCE;
}