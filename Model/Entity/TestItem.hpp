#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"
#include "../Component/Script/Item/ItemAction.hpp"

namespace entities {
    using namespace models;
    class TestItem : public GameObject {
        private:
            bool bEnabled;
            int ID;
            float profit;

        public:
            TestItem(std::string strName, AnimatedTexture* pTexture, int ID);

        public:
            void initialize();
            int getID();

            bool getEnabled();
            void setEnabled(bool bEnabled);
    };
}