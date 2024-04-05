#pragma once

#include "../GameObject.hpp"
#include "../AnimatedTexture.hpp"
#include "../Component/Renderer/Renderer.hpp"

namespace entities {
    using namespace models;
    class TestItem : public GameObject {
        protected:
            int grid;
            int posX;
            int posY;

        public:
            TestItem(std::string strName, AnimatedTexture* pTexture);

        public:
            void initialize();

        public:
            int getGrid();
            void setGrid(int num);

            void resetPos();
            void setPosX(int x);
            void setPosY(int y);

            int getPosX();
            int getPosY();
    };
}