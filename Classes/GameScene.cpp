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
    gameplayLayer = new GameplayLayer();
    addChild(gameplayLayer, GAMEPLAY_Z_ORDER);
    
    mainMenuLayer = new MainMenuLayer(gameplayLayer, showAds);
    mainMenuLayer->enter();
    mainMenuLayer->setVisible(true);
    addChild(mainMenuLayer, MENU_Z_ORDER);
}

GameScene::~GameScene()
{
    delete gameplayLayer;
    delete mainMenuLayer;
}

GameScene* GameScene::scene(bool showAds)
{
    GameScene* scene = new GameScene(showAds);
    scene->autorelease();
    return scene;
}

