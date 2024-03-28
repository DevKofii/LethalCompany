#include "BackgroundInput.hpp"

using namespace components;

BackgroundInput::BackgroundInput(std::string strName) : GeneralInput(strName) {
    this->bInteract = false;
}
void BackgroundInput::perform() {
    switch(CEvent.type) {
        case sf::Event::KeyPressed:
            this->processKeyboardInput(CEvent.key.code, true);
            break;
        case sf::Event::KeyReleased:
            this->processKeyboardInput(CEvent.key.code, false);
            //std::cout << "Released." << std::endl;
            //this->nRandomNum = NULL;
            break;
        default:
            break;
    }
}
void BackgroundInput::processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed) {
    switch(CKey) {
        case sf::Keyboard::F:
            this->bInteract = bPressed;
            break;

        default:
            break;
    }
}

bool BackgroundInput::getInteract() {
    return this->bInteract;
}


// bool BackgroundInput::getQuit() {
//     return this->bQuit;
// }