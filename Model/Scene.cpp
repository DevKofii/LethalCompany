#include "Scene.hpp"

using namespace models;

Scene::Scene(SceneTag ETag) {
    this->ETag = ETag;
}

void Scene::onUnloadObjects() {

}

void Scene::registerObject(GameObject* pGameObject){
    GameObjectManager::getInstance()->addObject(pGameObject);
}

SceneTag Scene::getTag() {
    return this->ETag;
}