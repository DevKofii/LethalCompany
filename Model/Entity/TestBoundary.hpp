#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../../Controller/Manager/MapManager.hpp"

namespace entities{
    using namespace managers;
    using namespace components;
    using namespace models;
    class TestBoundary : public GameObject{
        public:
            TestBoundary(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
    };
}