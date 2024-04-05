#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Input/BackgroundInput.hpp"
#include "../Component.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../Enum/SceneTag.hpp"
#include "../../Entity/TestBackground.hpp"
#include "../../Entity/TestBoundary.hpp"
#include "../../Entity/TestBounds.hpp"
#include "../../Entity/TestUnit.hpp"
#include "../../Entity/TestItem.hpp"
#include "../../GameObject.hpp"
#include "../../../Controller/Manager/GameObjectManager.hpp"
#include "../../../Controller/Manager/SceneManager.hpp"
#include "../../../Controller/Manager/MapManager.hpp"

namespace components {
    using namespace managers;
    using namespace models;
    using namespace entities;
    class BackgroundAction : public Component {
        protected:
            int nFrame;
            int nLastFrame;
            bool bDebug;

        public:
            BackgroundAction(std::string strName);

        public:
            void perform();
            void objSpawn();

            void spawn(TestItem* pItem);
    };
}