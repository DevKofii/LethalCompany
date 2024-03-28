#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Script/PlayerMovement.hpp"
#include "../Component/Input/PlayerInput.hpp"
#include "../Component/Renderer/Renderer.hpp"

#include "../Component/Script/CollisionManager.hpp"
#include "../Component/Script/FrameAnimation.hpp"

namespace entities {
    using namespace models;

    class Player : public GameObject {
        public:
            Player(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();
    };
}
