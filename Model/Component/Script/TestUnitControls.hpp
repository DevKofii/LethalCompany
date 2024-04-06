#pragma once

#include <random>

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Input/TestUnitInput.hpp"
#include "../../Entity/TestUnit.hpp"
#include "../../Entity/Light.hpp"
#include "../../Entity/Shadow.hpp"
#include "../Component.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../GameObject.hpp"

namespace components {
    using namespace models;
    using namespace entities;
    class TestUnitControls : public Component {
        private:
            float fSpeed;
        
        public:
            TestUnitControls(std::string strName);

        public:
            void perform();
    };
}