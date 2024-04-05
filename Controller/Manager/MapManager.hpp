#pragma once

#include "../../Config/Settings.hpp"

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
                bOneLock, bTwoLock, bThreeLock,
                bFourLock, bFiveLock, bSixLock,
                bSevenLock, bEightLock, bNineLock
            ;

            int nActiveGrid;
            bool bActive;

        public:
            void loadMap();
            void loadSixRooms();
            void loadSevenRooms();
            void loadEightRooms();
            void loadNineRooms();
            void loadRooms();

        public:
            int findGridByNum(int nGrid);

            std::vector<int> getMap();
            int getMapGrid(int nGrid);
            int getRoomSize();
            
            bool getLock(int nGrid);
            void setLock(int nGrid, bool bLock);

            int getActiveGrid();
            void setActiveGrid(int nActiveGrid);

            bool isValidLeft(int nGrid, int nFrame);
            bool isValidRight(int nGrid, int nFrame);
            bool isValidTop(int nGrid, int nFrame);
            bool isValidBottom(int nGrid, int nFrame);

        private:
            static MapManager* P_SHARED_INSTANCE;
            MapManager();
            MapManager(const MapManager&);
            MapManager& operator = (const MapManager&);

        public:
            static MapManager* getInstance();

    };
}