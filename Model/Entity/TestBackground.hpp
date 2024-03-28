#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../Component/Input/BackgroundInput.hpp"
#include "../Component/Script/BackgroundAction.hpp"

namespace entities{
    using namespace components;
    using namespace models;
    class TestBackground : public GameObject{
        public:
            TestBackground(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
    };
}