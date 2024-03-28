#pragma once

#include "iostream"
#include "SFML/Graphics.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../GeneralInput.hpp"

namespace components {
    class PlayerInput : public GeneralInput {
        private:
            bool bLeft;
            bool bRight;
            bool bUp;
            bool bDown;

        public:
            PlayerInput(std::string strName);

        public:
            void perform();

        private:
            void processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed);


        public:
            bool getLeft();
            bool getRight();
            bool getUp();
            bool getDown();
    };
}
