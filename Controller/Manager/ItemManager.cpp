#include "ItemManager.hpp"

using namespace managers;
using namespace models;

void ItemManager::pickupObject(GameObject* pGameObject) {
    this->invObject[pGameObject->getName()] = pGameObject;
    this->vecInvObject.push_back(pGameObject);
    if(this->currentGrid < 9) this->currentGrid += 1;
}

void ItemManager::dropObject() {
    this->vecInvObject.pop_back();
    if(this->currentGrid > 0) this->currentGrid -= 1;
}

void ItemManager::addProfit(GameObject* pGameObject) {
    this->profitObject[pGameObject->getName()] = pGameObject;
    this->vecProfitObject.push_back(pGameObject);
}

void ItemManager::calcProfit() {
    float totalProfit = 0.0f;
    for(GameObject* pGameObject : this->vecProfitObject) {
        totalProfit += pGameObject->getProfit();
    }
    std::cout << totalProfit << std::endl;
    this->currentProfit = totalProfit;
}

void ItemManager::deleteProfit(GameObject* pGameObject) {
    int index = this->findIndexByName(pGameObject->getName());
    this->vecProfitObject.erase(this->vecProfitObject.begin() + index);
}

int ItemManager::findIndexByName(std::string strName) {
    for(auto i = 0; i < this->vecProfitObject.size(); i++) {
        if(this->vecProfitObject[i]->getName() == strName) {
            return i;
        }
    }
    return NULL;
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

float ItemManager::getProfit() {
    return this->currentProfit;
}

ItemManager* ItemManager::P_SHARED_INSTANCE = NULL;

ItemManager::ItemManager() {
    this->currentGrid = 0;
    this->currentProfit = 0.0f;
}

ItemManager::ItemManager(const ItemManager&) {}

ItemManager* ItemManager::getInstance() {
    if(P_SHARED_INSTANCE  == NULL) P_SHARED_INSTANCE = new ItemManager();
    return P_SHARED_INSTANCE;
}