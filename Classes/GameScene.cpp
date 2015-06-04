//
//  GameScene.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 4/1/15.
//
//

#include "GameScene.h"

using namespace cocos2d;

GameScene::GameScene(bool showAds)
{
    if(!Scene::initWithPhysics())
    {
        return;
    }
    getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    getPhysicsWorld()->setGravity(Vec2(0, 0));
    
    setColor(Color3B(255, 255, 255));
    
    gameplayLayer = new GameplayLayer();
    addChild(gameplayLayer, GAMEPLAY_Z_ORDER);
    
    optionsLayer = new OptionsLayer();
    optionsLayer->setVisible(false);
    addChild(optionsLayer, OPTIONS_Z_ORDER);
    
    mainMenuLayer = new MainMenuLayer(gameplayLayer, optionsLayer, showAds);
    mainMenuLayer->enter();
    mainMenuLayer->setVisible(true);
    optionsLayer->pMenu = mainMenuLayer;
    addChild(mainMenuLayer, MENU_Z_ORDER);
}

GameScene::~GameScene()
{
    delete gameplayLayer;
    delete mainMenuLayer;
    delete optionsLayer;
}

GameScene* GameScene::scene(bool showAds)
{
    GameScene* scene = new GameScene(showAds);
    scene->autorelease();
    return scene;
}

