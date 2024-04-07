#pragma once

#include "../../../../Config/Settings.hpp"

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../Component.hpp"
#include "../../../Enum/ComponentType.hpp"
#include "../../../GameObject.hpp"
#include "../../../Entity/TestItem.hpp"
#include "../../../Entity/TestUnit.hpp"

#include "../../Input/TestUnitInput.hpp"

#include "../../../../Controller/Manager/GameObjectManager.hpp"
#include "../../../../Controller/Manager/MapManager.hpp"

namespace components {
    using namespace managers;
    using namespace models;
    using namespace entities;
    class ItemAction : public Component {
        protected:
            bool bEnabled;
            int itemCount;

        public:
            ItemAction(std::string strName);

        public:
            void perform();

            void spawnItem();
            void dropItem();
            void checkCollision();
            void setPosition(std::string strName, int Grid);
    };
}
