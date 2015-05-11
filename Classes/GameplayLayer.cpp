//
//  GameplayLayer.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 4/1/15.
//
//

#include "GameplayLayer.h"
#include "CocosGUI.h"

using namespace cocos2d;

GameplayLayer::GameplayLayer()
{
    player = nullptr;
}

GameplayLayer::~GameplayLayer()
{
    exit();
}

void GameplayLayer::enter()
{
    setVisible(true);
    
    if(player == nullptr)
    {
        player = new Player(0, "Player_Atlas_Black.png");
        addChild(player, 100);
    }
    
    // TODO:
    // create enemy entity's based off filenames determined by other clients
}

void GameplayLayer::update(float _deltaTime)
{
    int u = 8;
    u *= _deltaTime;
}

void GameplayLayer::render()
{
    
}

void GameplayLayer::exit()
{
    unscheduleUpdate();
}

void GameplayLayer::StartGameLoop()
{
    scheduleUpdate();
}