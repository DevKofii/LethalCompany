#pragma once

#include "../../../../Config/Settings.hpp"

#include <iostream>
#include <chrono>
#include <thread>
#include <cmath>
#include "SFML/Graphics.hpp"
#include "../../Component.hpp"
#include "../../../Enum/ComponentType.hpp"
#include "../../../Enum/BotTag.hpp"
#include "../../../GameObject.hpp"
#include "../../../Entity/TestEnemy.hpp"
#include "../../../Entity/TestBoundary.hpp"

#include "../../../../Controller/Manager/GameObjectManager.hpp"
#include "../../../../Controller/Manager/MapManager.hpp"

namespace components {
    using namespace managers;
    using namespace models;
    using namespace entities;
    using namespace std::this_thread;
    using namespace std::chrono_literals;
    using std::chrono::system_clock;
    class BotAction : public Component {
        protected:
            float fSpeed;
            BotTag ETag;
            sf::Clock delayTimer;
            float delayTimerMax;
            int select;

            int debug;

            int randomDest;
            int currentPosX;
            int currentPosY;

            int destX_L;
            int destX_R;
            int destY_T;
            int destY_B;

        public:
            BotAction(std::string strName);

        public:
            void perform();

            int random();

            void spawnEnemy();
            void selectState();
            void performState();
            void checkCollision();

        public:
            void setTag(BotTag ETag);
            const bool getDelayTimer();
    };
}
