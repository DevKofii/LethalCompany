#pragma once

#include "../../../Config/Settings.hpp"

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Component.hpp"
#include "../../Entity/TestBoundary.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../GameObject.hpp"
#include "../../../Controller/Manager/SceneManager.hpp"
#include "../../../Controller/Manager/MapManager.hpp"

namespace components {
    using namespace models;
    using namespace managers;
    using namespace entities;
    class BoundsAction : public Component {
        protected:
            std::vector<int> vecMap;
            int nCurrentGrid;

        public:
            BoundsAction(std::string strName);

        public:
            void perform();
    };
}