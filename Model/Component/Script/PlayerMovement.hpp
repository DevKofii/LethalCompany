#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../Input/PlayerInput.hpp"
#include "../../Entity/Player.hpp"
#include "../Component.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../../GameObject.hpp"

namespace components {
    class PlayerMovement : public Component {
        protected:
            Player* pPlayer;
            PlayerInput* pInput;

        private:
            float fSpeed;

        public:
            PlayerMovement(std::string strName);

        public:
            void perform();
    };
}
