#pragma once
#include "iostream"
#include "unordered_map"
#include "SFML/Graphics.hpp"
#include "../../Model/Enum/AssetType.hpp"

namespace managers{
    class MapManager{
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

        public:
            void loadMap();
            void loadNineRooms();
            void loadRooms();

        public:
            // std::vector<sf::Texture*> getTexture(AssetType EKey);
            // sf::Texture* getTextureAt(AssetType EKey, int nFrame);
            std::vector<int> getMap();
            int getRoomSize();
            
            bool getLock(int nGrid);
            void setLock(int nGrid, bool bLock);

        private:
            static MapManager* P_SHARED_INSTANCE;
            MapManager();
            MapManager(const MapManager&);
            MapManager& operator = (const MapManager&);

        public:
            static MapManager* getInstance();

    };
}