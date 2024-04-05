#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities {
    using namespace models;
    class TestItem : public GameObject {
        public:
            TestItem(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();

    };
}