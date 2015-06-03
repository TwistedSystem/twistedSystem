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
    //initWithPhysics();
    //getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 visibleOrigin = Director::getInstance()->getVisibleOrigin();
    
    //auto edgeBody = PhysicsBody::createEdgeBox(visibleSize);
    //auto edgeNode = Node::create();
    ///edgeNode->setPosition(Point(visibleSize.width / 2 + visibleOrigin.x, visibleSize.height / 2 + visibleOrigin.y));
    //edgeNode->setPhysicsBody(edgeBody);
    //addChild(edgeNode);
    
    setColor(Color3B(255, 255, 255));
    
    gameplayLayer = new GameplayLayer();
    gameplayLayer->
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

