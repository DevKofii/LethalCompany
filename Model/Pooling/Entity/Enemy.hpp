#pragma once

#include <SFML/Graphics.hpp>
#include "../../AnimatedTexture.hpp"
#include "../PoolableObject.hpp"
#include "../../Entity/TestEnemy.hpp"
#include "../../Enum/PoolTag.hpp"
#include "../../Component/Script/EnemyMovement.hpp"
#include "../../../Controller/Manager/TextureManager.hpp"

namespace poolables{
    using namespace models;
    using namespace entities;
    using namespace managers;
    using namespace components;

    class Enemy : public PoolableObject {
        public:
            Enemy(std::string strName, AnimatedTexture* pTexture);

            void initialize() override;
            void onActivate() override;
            void onRelease() override;

            PoolableObject* clone() override;


    };
}
