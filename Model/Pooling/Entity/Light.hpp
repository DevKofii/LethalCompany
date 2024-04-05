#pragma once

#include <SFML/Graphics.hpp>
#include "../../AnimatedTexture.hpp"
#include "../PoolableObject.hpp"
#include "../../Entity/TestUnit.hpp"
#include "../../Enum/PoolTag.hpp"

namespace entities {
    class TestUnit;
}

namespace poolables{
    using namespace models;
    using namespace entities;
    using namespace components;
    class Light : public PoolableObject {
        private:
            TestUnit* pPlayer;

        public:
            Light(std::string strName, AnimatedTexture* pTexture, TestUnit* pPlayer);

        public:
            void initialize();

        public:
            void onActivate();
            void onRelease();
            PoolableObject* clone();
        
    };
}