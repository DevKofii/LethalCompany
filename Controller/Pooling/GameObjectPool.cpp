#include "GameObjectPool.hpp"

using namespace poolables;

GameObjectPool::GameObjectPool(PoolTag ETag, int nPoolSize, PoolableObject* pPoolableReference) {
    this->ETag = ETag;
    this->nPoolSize = nPoolSize;
    this->pPoolableReference = pPoolableReference;
    this->vecAvailableObject = {};
    this->vecUsedObject = {};
}

void GameObjectPool::initalize() {
    //0 to less than pool size 
    for(int i = 0; i < this->nPoolSize; i++) {
        PoolableObject* pClone = this->pPoolableReference->clone();
        GameObjectManager::getInstance()->addObject(pClone);
        this->setEnabled(pClone,false);
        this->vecAvailableObject.push_back(pClone);
    }
}

PoolableObject* GameObjectPool::requestPoolable() {
    if(this->hasAvailable(1)) {
        PoolableObject* pPoolableObject = this->vecAvailableObject[0];
        this->vecUsedObject.push_back(pPoolableObject);
        this->vecAvailableObject.erase(this->vecAvailableObject.begin());

        this->setEnabled(pPoolableObject,true);

        return pPoolableObject;
    }
    return NULL;
}

std::vector<PoolableObject*> GameObjectPool::requestPoolableBatch(int nRequestSize) {
    
}

void GameObjectPool::releasePoolable(PoolableObject* pPoolableObject) {}


bool GameObjectPool::hasAvailable(int nRequestSize) {
    if(this->vecAvailableObject.size() >= nRequestSize) return true;
    return false;
}

void GameObjectPool::setEnabled(PoolableObject* pPoolableObject, bool bEnabled) {
    pPoolableObject->setEnabled(bEnabled);
    if(bEnabled) pPoolableObject->onActivate();
    else pPoolableObject->onRelease();
}

PoolTag GameObjectPool::getTag() {
    return this->ETag;
}
