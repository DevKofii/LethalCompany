#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../Component/Script/Bot/BotAction.hpp"
#include "../Enum/BotTag.hpp"

namespace entities {
    using namespace models;
    class TestEnemy : public GameObject {
        private:
            const int nFrameStart = 0;
            const int nFrameEnd = 8;
            BotTag ETag;
            int random;
            int ID;

        public:
            TestEnemy(std::string strName, AnimatedTexture* pTexture, int ID);

        public:
            void initialize();

            int getRandom();
            void setRandom();

            BotTag getTag();
            void setTag(BotTag ETag);

            int getID();
    };
}