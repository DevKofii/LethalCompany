#include <iostream>
#include <unordered_map>
#include <vector>

#include <SFML/Graphics.hpp>

#include "Controller/Game.cpp"
#include "Controller/Manager/TextureManager.cpp"
#include "Controller/Manager/MapManager.cpp"
#include "Controller/Manager/GameObjectManager.cpp"
#include "Controller/Manager/SceneManager.cpp"

#include "Controller/Pooling/GameObjectPool.cpp"

#include "Model/GameObject.cpp"
#include "Model/AnimatedTexture.cpp"

#include "Model/Entity/Player.cpp"
#include "Model/Entity/Background.cpp"
#include "Model/Entity/Ship.cpp"

#include "Model/Pooling/PoolableObject.cpp"
#include "Model/Pooling/Entity/PlayerBullet.cpp"

#include "Model/Scene.cpp"
#include "Model/Scene/MainMenuScene.cpp"
#include "Model/Scene/GameScene.cpp"

#include "Model/Component/Component.cpp"
#include "Model/Component/GeneralInput.cpp"

#include "Model/Component/Input/PlayerInput.cpp"
#include "Model/Component/Input/BackgroundInput.cpp"
#include "Model/Component/Input/ShipInput.cpp"

#include "Model/Component/Script/PlayerMovement.cpp"
#include "Model/Component/Script/BackgroundAction.cpp"
#include "Model/Component/Script/BulletMovement.cpp"
#include "Model/Component/Script/ShipControls.cpp"
#include "Model/Component/Script/CollisionManager.cpp"
#include "Model/Component/Script/FrameAnimation.cpp"

//#include "Model/Component/Pooling/PoolableObject.cpp"

#include "Model/Component/Renderer/Renderer.cpp"
//#include "../.cpp"

using namespace controllers;
int main() {
    Game CGame;
    CGame.run();
    return 0;
}

