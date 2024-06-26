#pragma once

#include "../Config/Settings.hpp"

#include "AnimatedTexture.hpp"
#include "Enum/AssetType.hpp"
#include "Component/Component.hpp"
#include "Component/GeneralInput.hpp"
#include "Component/Renderer/Renderer.hpp"

namespace models {
    using namespace components;
    class GameObject {
        protected:
            bool bEnabled;
            std::string strName;
            sf::Sprite* pSprite;
            sf::RectangleShape* pShape;
            //sf::Texture* pTexture;
            AnimatedTexture* pTexture;
            float fSpeed;
            std::vector<Component*> vecComponents;
            int nCurrentFrame;

            bool bOrientRight;
            bool bOrientLeft;

            GameObject* pParent;
            std::vector<GameObject*> vecChildren;

            int grid;
            int posX;
            int posY;

            float profit;

        public:
            GameObject(std::string strName);
            GameObject(std::string strName, AnimatedTexture* pTexture);
            GameObject(std::string strName, float fSpeed, AnimatedTexture* pTexture);
        
        /* [TODO][1] :
           Update this class' content based on the lecture
           slides. */

        public:
            virtual void initialize() = 0;
            virtual void processEvents(sf::Event CEvent);
            virtual void update(sf::Time tDeltaTime);
            virtual void draw(sf::RenderWindow* pWindow);

        protected:
            //virtual void processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed) = 0;

        public:
            void attachComponent(Component* pComponent);
            void detachComponent(Component* pComponent);
            void attachChild(GameObject* pChild);
            void detachChild(GameObject* pChild);
            Component* findComponentByName(std::string strName);
            std::vector<Component*> getComponents(ComponentType EType);
            sf::Sprite* getSprite();
            void centerOrigin();
            void centerPosition();

        public:
            bool getEnabled();
            void setEnabled(bool bEnabled);
            std::string getName();
            void setTexture(AnimatedTexture* pTexture);

            void setSpeed(float fSpeed);
            float getSpeed();
            void setFrame(int nFrame);

            void setOrientationRight(bool bRight);
            void setOrientationLeft(bool bLeft);
            bool getOrientationRight();
            bool getOrientationLeft();

            GameObject* getParent();
            void setParent(GameObject* pParent);

            virtual sf::Vector2f getPosition();
            virtual void setPosition(sf::Vector2f vecPosition);
            virtual void setScale(sf::Vector2f vecScale);

            void resetPos();

            int getGrid();
            void setGrid(int num);
            
            void setPosX(int x);
            void setPosY(int y);

            int getPosX();
            int getPosY();

            void setProfit(float profit);
            float getProfit();
    };
}
