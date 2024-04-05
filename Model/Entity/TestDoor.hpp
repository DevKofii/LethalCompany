#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities {
    using namespace models;
    class TestDoor : public GameObject {
        public:
            TestDoor(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
    };
}