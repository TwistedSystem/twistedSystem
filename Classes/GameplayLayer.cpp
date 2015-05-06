//
//  GameplayLayer.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 4/1/15.
//
//

#include "GameplayLayer.h"

GameplayLayer::GameplayLayer()
{
    
}

GameplayLayer::~GameplayLayer()
{
    exit();
}

void GameplayLayer::enter()
{
    player = new Player(0, "testPlayer.png");
    addChild(player);
    
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