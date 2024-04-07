#pragma once

#include "iostream"
#include "unordered_map"
#include "../../Model/Enum/AssetType.hpp"
#include "../../Model/GameObject.hpp"

namespace managers {
    using namespace models;

    class ItemManager {
        private:
            std::unordered_map<std::string, GameObject*> invObject;
            std::vector<GameObject*> vecInvObject;

            std::unordered_map<std::string, GameObject*> profitObject;
            std::vector<GameObject*> vecProfitObject;


            int currentGrid;
        
        public:
            void pickupObject(GameObject* pGameObject);
            void dropObject();

            void addProfit(GameObject* pGameObject);
            void calcProfit();
            void deleteProfit();

            GameObject* findObjectByName(std::string strName);
            GameObject* returnLastObject();

        public:
            int getGrid();
            
        private:
            static ItemManager* P_SHARED_INSTANCE;
            ItemManager();
            ItemManager(const ItemManager&);
            ItemManager& operator = (const ItemManager&);

        public:
            static ItemManager* getInstance();
    };
}
