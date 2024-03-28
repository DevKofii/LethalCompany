#pragma once

#include "../Scene.hpp"
#include "../AnimatedTexture.hpp"
#include "../Enum/SceneTag.hpp"
#include "../Enum/PoolTag.hpp"
#include "../Entity/Player.hpp"
#include "../Entity/Background.hpp"
#include "../Pooling/Entity/PlayerBullet.hpp"
#include "../../Controller/Manager/TextureManager.hpp"
#include "../../Controller/Pooling/GameObjectPool.hpp"

namespace scenes {
    using namespace managers;
    using namespace entities;
    using namespace poolables;
    class GameScene : public Scene {
        public:
            GameScene();

        public:
            void onLoadResources();
            void onLoadObjects();
            void onUnloadResources();
        
        private:
            void createBackground();
            void createPlayer();
            void createObjectPools();

        public:

    };
}
