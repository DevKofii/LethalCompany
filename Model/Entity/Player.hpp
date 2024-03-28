#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Script/PlayerMovement.hpp"
#include "../Component/Input/PlayerInput.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities {
    using namespace models;

    class Player : public GameObject {
        private:
            //bool bMovingLeft;
            //bool bMovingRight;

        public:
            Player(std::string strName);
            Player(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();

        protected:
            //void processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed);

        public:
            //bool getMovingLeft();
            //void setMovingLeft(bool bMovingLeft);
            //bool getMovingRight();
            //void setMovingRight(bool bMovingRight);
    };
}
