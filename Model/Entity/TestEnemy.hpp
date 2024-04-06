#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../Component/Script/Bot/BotAction.hpp"

namespace entities {
    using namespace models;
    class TestEnemy : public GameObject {
        private:
            const int nFrameStart = 0;
            const int nFrameEnd = 8;

        public:
            TestEnemy(std::string strName, AnimatedTexture* pTexture, int ID);

        public:
            void initialize();
    };
}