#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities {
    using namespace models;
    class Light : public GameObject {
        public:
            Light(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
    };
}