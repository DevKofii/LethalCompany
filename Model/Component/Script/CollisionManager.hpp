#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Input/TestUnitInput.hpp"
#include "../../Entity/TestUnit.hpp"
#include "../../Entity/TestEnemy.hpp"
#include "../../Entity/TestBoundary.hpp"
#include "../Component.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../GameObject.hpp"
#include "../../../Controller/Manager/GameObjectManager.hpp"


namespace components {
    using namespace managers;
    using namespace models;
    using namespace entities;
    class CollisionManager : public Component {
        protected:
            int nFrame;
            int nLastFrame;

            int currentGrid;
            int nextGrid;
            int prevGrid;

            bool debug;

        public:
            CollisionManager(std::string strName);

        public:
            void perform();

        public:
            void windowBounds();
            void mapBounds();
            void mapTraversal(int debug);
    };
}