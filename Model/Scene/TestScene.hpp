#pragma once

#include "../Scene.hpp"
#include "../AnimatedTexture.hpp"
#include "../Enum/SceneTag.hpp"
#include "../Entity/TestUnit.hpp"
#include "../Entity/TestEnemy.hpp"
#include "../Entity/TestBackground.hpp"
#include "../Entity/TestBoundary.hpp"
#include "../Entity/TestDoor.hpp"
#include "../Entity/TestBounds.hpp"
#include "../Entity/Light.hpp"
#include "../Entity/TestItem.hpp"

#include "../../Controller/Manager/TextureManager.hpp"
#include "../../Controller/Manager/ObjectPoolManager.hpp"
#include "../../Controller/Manager/MapManager.hpp"

#include "../../Controller/Pooling/GameObjectPool.hpp"

namespace scenes {
    using namespace managers;
    using namespace entities;
    using namespace models;
    class TestScene : public Scene {
        public:
            TestScene();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();

        private:
            void createBackground();
            void createBoundaries();
            void createDoor();
            void spawnItem();
            void spawnEnemies();
            void createExtraBoundary();
            void spawnUnit();
            

            void setPosition(GameObject* pEntity);
    };
}