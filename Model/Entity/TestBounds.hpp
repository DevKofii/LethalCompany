#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../Component/Script/BoundsAction.hpp"
#include "../../Controller/Manager/MapManager.hpp"

namespace entities{
    using namespace managers;
    using namespace components;
    using namespace models;
    class TestBounds : public GameObject{
        public:
            TestBounds(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
    };
}