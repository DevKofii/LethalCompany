#include "PlayerInput.hpp"

using namespace components;

PlayerInput::PlayerInput(std::string strName) : GeneralInput(strName){
    this->bLeft = false;
    this->bRight = false;
    this->bUp = false;
    this->bDown = false;
}

void PlayerInput::perform() {
    switch(CEvent.type) {
        case sf::Event::KeyPressed:
            this->processKeyboardInput(CEvent.key.code, true);
            break;

        case sf::Event::KeyReleased:
            this->processKeyboardInput(CEvent.key.code, false);
            break;
        
        default:
            break;
    }
}

void PlayerInput::processKeyboardInput(sf::Keyboard::Key CKey, bool bPressed) {
    switch(CKey) {
        case sf::Keyboard::A:
            this->bLeft = bPressed;
            break;
        
        case sf::Keyboard::D:
            this->bRight = bPressed;
            break;

        case sf::Keyboard::W:
            this->bUp = bPressed;
            break;

        case sf::Keyboard::S:
            this->bDown = bPressed;
            break;

        default:
            break;
    }
}

bool PlayerInput::getLeft() {
    return this->bLeft;
}

bool PlayerInput::getRight() {
    return this->bRight;
}

bool PlayerInput::getUp() {
    return this->bUp;
}

bool PlayerInput::getDown() {
    return this->bDown;
}