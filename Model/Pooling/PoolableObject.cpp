#include "PoolableObject.hpp"

using namespace poolables;

PoolableObject::PoolableObject(PoolTag ETag, std::string strName, AnimatedTexture* pTexture) : GameObject(strName, pTexture) {
    this->ETag = ETag;
}

PoolableObject::~PoolableObject() {}

PoolTag PoolableObject::getTag() {
    return this->ETag;
}

