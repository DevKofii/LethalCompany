#pragma once
#include "iostream"
#include "unordered_map"
#include "SFML/Graphics.hpp"
#include "../../Model/Enum/AssetType.hpp"

namespace managers{
    class TextureManager{
        protected:
            int nRooms;
            int nGrid;
            int nRandomNum;
            int nCurrent;
            std::vector<int> vecMap;

            bool
                bOne, bTwo, bThree,
                bFour, bFive, bSix,
                bSeven, bEight, bNine
            ;

        private:
            std::unordered_map<AssetType, std::vector<sf::Texture*>> mapTexture;
            std::vector<AssetType> vecAssetTypes;

        public:
            void loadAll();
            void loadMap();
            void loadNineRooms();
            void loadRooms();
            void loadMainMenu();
            void loadGame();
            void unloadAll();

        public:
            std::vector<sf::Texture*> getTexture(AssetType EKey);
            sf::Texture* getTextureAt(AssetType EKey, int nFrame);
            
            bool getLock(int nGrid);
            void setLock(int nGrid, bool bLock);

        private:
            static TextureManager* P_SHARED_INSTANCE;
            TextureManager();
            TextureManager(const TextureManager&);
            TextureManager& operator = (const TextureManager&);

        public:
            static TextureManager* getInstance();

    };
}