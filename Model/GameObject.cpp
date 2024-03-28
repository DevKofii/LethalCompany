#include "GameObject.hpp"

using namespace models;

GameObject::GameObject(std::string strName, float fSpeed) {
    this->bEnabled = true;
    this->strName = strName;
    this->fSpeed = fSpeed;
    this->pSprite = new sf::Sprite();
}

GameObject::GameObject(std::string strName, AnimatedTexture* pTexture) {
    this->bEnabled = true;
    this->strName = strName;
    this->pSprite = new sf::Sprite();
    this->pTexture = pTexture;
    this->setFrame(1);
}

GameObject::GameObject(std::string strName, float fSpeed, AnimatedTexture* pTexture) {
    this->bEnabled = true;
    this->strName = strName;
    this->fSpeed = fSpeed;
    this->pSprite = new sf::Sprite();
    this->pTexture = pTexture;
    this->setFrame(1);
}

void GameObject::processEvents(sf::Event CEvent) {
    std::vector<Component*> vecInputs = this->getComponents(ComponentType::INPUT);

    for(Component* pComponent : vecInputs) {
        GeneralInput* pGeneralInput = (GeneralInput*)pComponent;
        pGeneralInput->assignEvent(CEvent);
        pGeneralInput->perform();
    }
}

void GameObject::update(sf::Time tDeltaTime) {
    std::vector<Component*> vecScripts = this->getComponents(ComponentType::SCRIPT);

    for(Component* pComponent : vecScripts) {
        pComponent->setDeltaTime(tDeltaTime);
        pComponent->perform();
    }
}

void GameObject::draw(sf::RenderWindow* pWindow) {
    std::vector<Component*> vecRenderers = this->getComponents(ComponentType::RENDERER);

    for(Component* pComponent : vecRenderers) {
        Renderer* pRenderer = (Renderer*)pComponent;
        pRenderer->assignTargetWindow(pWindow);
        pRenderer->perform();
    }
}

void GameObject::attachComponent(Component* pComponent) {
    this->vecComponents.push_back(pComponent);
    pComponent->attachOwner(this);
}

void GameObject::detachComponent(Component* pComponent) {
    int nIndex = -1;
    for(int i = 0; i < this->vecComponents.size(); i++) {
        if(this->vecComponents[i] == pComponent) {
            nIndex = i;
            break;
        }
    }

    if(nIndex != -1) {
        this->vecComponents[nIndex]->detachOwner();
        this->vecComponents.erase(this->vecComponents.begin() + nIndex);
    }

}

Component* GameObject::findComponentByName(std::string strName) {
    for(int i = -1; i < this->vecComponents.size(); i++) {
         if(this->vecComponents[i]->getName() == strName) { 
             return this->vecComponents[i];
         }
     }
    return nullptr;
}

std::vector<Component*> GameObject::getComponents(ComponentType EType) {
    std::vector <Component*> vecFound = {};
    for(Component* pComponent : this->vecComponents) {
        if(pComponent->getType() == EType) {
            vecFound.push_back(pComponent);
        }
    }
    return vecFound;
}

void GameObject::centerOrigin() {
    if(this->pTexture != NULL) {
        int nWidth = this->pSprite->getTexture()->getSize().x;
        int nHeight = this->pSprite->getTexture()->getSize().y;
        this->pSprite->setOrigin(nWidth/2,nHeight/2);
    }
}

bool GameObject::getEnabled() {
    return this->bEnabled;
}

std::string GameObject::getName() {
    return this->strName;
}

sf::Sprite* GameObject::getSprite() {
    return this->pSprite;
}

void GameObject::setTexture(AnimatedTexture* pTexture) {
    this->pTexture = pTexture;
    this->pSprite->setTexture(*this->pTexture->getFrame());
}

float GameObject::getSpeed() {
    return this->fSpeed;
}

void GameObject::setFrame(int nFrame) {
    if(this->pTexture != NULL) {
        this->pTexture->setCurrentFrame(nFrame);
        this->pSprite->setTexture(*this->pTexture->getFrame());
    }
}

int GameObject::getFrame() {
    return this->nFrame;
}

void GameObject::setEnabled(bool bEnabled) {
    this->bEnabled = bEnabled;
}