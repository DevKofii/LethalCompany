#pragma once

#include "../Scene.hpp"
#include "../AnimatedTexture.hpp"
#include "../Enum/SceneTag.hpp"
#include "../Entity/TestUnit.hpp"
#include "../Entity/TestEnemy.hpp"
#include "../Entity/TestBackground.hpp"
#include "../Entity/TestBoundary.hpp"
#include "../Entity/TestDoor.hpp"

#include "../Pooling/Entity/Enemy.hpp"
#include "../Pooling/Entity/TestBullet_R.hpp"
#include "../Pooling/Entity/TestBullet_L.hpp"

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
            void createEnemyPool();
            void createDoor();
            void spawnUnit();
            void spawnBot();
            void spawnEnemies();
            void createObjectPools();
            void checkCollision();
    };
}