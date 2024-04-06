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
#include "../Entity/Shadow.hpp"

#include "../../Controller/Manager/TextureManager.hpp"
#include "../../Controller/Manager/ObjectPoolManager.hpp"
#include "../../Controller/Manager/MapManager.hpp"

#include "../../Controller/Pooling/GameObjectPool.hpp"

namespace scenes {
    using namespace managers;
    using namespace entities;
    using namespace models;
    class TestScene : public Scene {
        protected:
            bool
                two, three, four,
                five, six, seven,
                eight, nine
            ;

        public:
            TestScene();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();

        private:
            void createBackground();
            void createBoundaries();
            void loadMisc();
            void spawnItem();
            void spawnEnemies();
            void createExtraBoundary();
            void createDoor();
            void spawnUnit();
            
            void setPositionEnemy(TestEnemy* pEntity);
            void setPosition(GameObject* pEntity);

            void setGridLock(int num, bool bLock);
            bool getGridLock(int num);
    };
}