#include "BackgroundAction.hpp"

using namespace components;

BackgroundAction::BackgroundAction(std::string strName) : Component(strName, ComponentType::SCRIPT) {
    this->nFrame = 0;
}

void BackgroundAction::perform() {
    BackgroundInput* pBackgroundInput = (BackgroundInput*)this->getOwner()->getComponents(ComponentType::INPUT)[0]; 
    if(pBackgroundInput == NULL) std::cout << "[ERROR] : One or more dependencies are missing." << std::endl;
    else {
        if(pBackgroundInput->getInteract()) {
            // this->getOwner()->setFrame(this->nFrame);
            // this->nFrame += 1;
        }
    }
}