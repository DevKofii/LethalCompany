#include <iostream>
#include <unordered_map>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Controller/Game.cpp"
#include "Controller/Manager/TextureManager.cpp"
#include "Controller/Manager/GameObjectManager.cpp"
#include "Controller/Manager/ObjectPoolManager.cpp"
#include "Controller/Manager/SceneManager.cpp"
#include "Controller/Manager/MapManager.cpp"

#include "Controller/Pooling/GameObjectPool.cpp"

#include "Model/GameObject.cpp"
#include "Model/AnimatedTexture.cpp"

#include "Model/Entity/Background.cpp"
#include "Model/Entity/TestBackground.cpp"
#include "Model/Entity/TestUnit.cpp"
#include "Model/Entity/TestEnemy.cpp"
#include "Model/Entity/TestBoundary.cpp"
#include "Model/Entity/TestDoor.cpp"
#include "Model/Entity/TestBounds.cpp"
#include "Model/Entity/Light.cpp"

#include "Model/Entity/TestItem.cpp"

#include "Model/Pooling/PoolableObject.cpp"

#include "Model/Scene.cpp"
#include "Model/Scene/TestScene.cpp"

#include "Model/Component/Component.cpp"
#include "Model/Component/GeneralInput.cpp"

#include "Model/Component/Input/BackgroundInput.cpp"
#include "Model/Component/Input/TestUnitInput.cpp"

#include "Model/Component/Script/BackgroundAction.cpp"
#include "Model/Component/Script/BoundsAction.cpp"

#include "Model/Component/Script/BulletMovement.cpp"
#include "Model/Component/Script/TestBulletMovement_R.cpp"
#include "Model/Component/Script/TestBulletMovement_L.cpp"

#include "Model/Component/Script/TestUnitControls.cpp"
#include "Model/Component/Script/FrameAnimation.cpp"
#include "Model/Component/Script/CollisionManager.cpp"

#include "Model/Component/Script/Bot/BotAction.cpp"

#include "Model/Component/Renderer/Renderer.cpp"

using namespace controllers;
int main() {
    Game CGame;
    CGame.run();
    return 0;
}

