#pragma once

#include <cstdlib>
#include "time.h"

#include "../../../../Config/Settings.hpp"
#include "../../../Enum/ComponentType.hpp"
#include "../../../Pooling/PoolableObject.hpp"
#include "../../Component.hpp"
#include "../../../../Controller/Manager/ObjectPoolManager.hpp"
#include "../../../../Controller/Manager/MapManager.hpp"

namespace components {
    using namespace models;
    using namespace managers;
    using namespace poolables;
    class BotAction : public Component {
        private:
            float fFrameInterval;
            float fTicks;
            float fSpeed;

        public:
            BotAction(std::string strName);

        public:
            void perform();

        protected:
            sf::Vector2f randomPos();
    };
}
