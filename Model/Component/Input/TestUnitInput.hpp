#pragma once

#include <iostream>
#include "SFML/Graphics.hpp"
#include "../../Enum/ComponentType.hpp"
#include "../GeneralInput.hpp"

namespace components{
    class TestUnitInput : public GeneralInput {
        private:
            bool bUp;
            bool bDown;
            bool bLeft;
            bool bRight;
            bool bShoot;
            bool bInteract;
            bool bDrop;
            bool bSpace;
        
        public:
            TestUnitInput(std::string strName);

        public:
            void perform();

        private:
            void processKeyInput(bool bPressed);

        public:
            void resetShoot();
            void resetReturnHub();
            void resetInteract();
            void resetDrop();

            bool getUp();
            bool getDown();
            bool getLeft();
            bool getRight();
            bool getReturnHub();
            bool getInteract();
            bool getDrop();
            bool getShoot();
    };
}