#include "BackgroundAction.hpp"

using namespace components;

BackgroundAction::BackgroundAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->bDebug = false;
}

void BackgroundAction::perform() {
    BackgroundInput* pBackgroundInput = (BackgroundInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0]; 
    if(pBackgroundInput == NULL) std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    else {
        this->debug();
        if(pBackgroundInput->getInteract()) {
            this->bDebug = true;
        }
        else this->bDebug = false;
    }
}

void BackgroundAction::debug() {
    if(this->bDebug) std::cout << "Debug Press" << std::endl;
}