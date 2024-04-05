#pragma once

#include <random>

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Input/TestUnitInput.hpp"
#include "../../Entity/TestUnit.hpp"
#include "../../Entity/Light.hpp"
#include "../../Pooling/Entity/TestBullet_R.hpp"
#include "../Component.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../GameObject.hpp"

namespace components {
    using namespace models;
    using namespace entities;
    using namespace poolables;
    class TestUnitControls : public Component {
        protected:
            TestUnit* pUnitOwner;
            TestUnitInput* pUnitInput;

        private:
            float fSpeed;
        
        public:
            TestUnitControls(std::string strName);

        public:
            void perform();
            sf::Vector2f randomPos();
    };
}