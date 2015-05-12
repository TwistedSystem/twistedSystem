//
//  GameplayLayer.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 4/1/15.
//
//

#include "GameplayLayer.h"

using namespace cocos2d;
using namespace ui;

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
    
    // TODO:
    // create player entity's based off filenames determined by other clients
    
    if(player == nullptr)
    {
        player = new Player(0, "Player_Atlas_Black.png");
        addChild(player, 100);
    }
    
    jumpButton = Button::create();
    jumpButton->setTouchEnabled(true);
    jumpButton->loadTextures("CloseNormal.png", "CloseSelected.png");
    jumpButton->Widget::setScale(3.0f);
    jumpButton->setPosition(Point(visibleSize.width - 200, visibleSize.height - 200));
    jumpButton->addTouchEventListener(this, toucheventselector(GameplayLayer::OnButtonPressed));
    jumpButton->setTag(0);
    
    addChild(jumpButton);
    
    duckButton = Button::create();
    duckButton->setTouchEnabled(true);
    duckButton->loadTextures("CloseNormal.png", "CloseSelected.png");
    duckButton->Widget::setScale(3.0f);
    duckButton->setPosition(Point(visibleSize.width - 200, 200));
    duckButton->addTouchEventListener(this, toucheventselector(GameplayLayer::OnButtonPressed));
    duckButton->setTag(1);
    
    addChild(duckButton);
}

void GameplayLayer::update(float _deltaTime)
{
    int u = 8;
    u *= _deltaTime;
    
    player->update(_deltaTime);
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

void GameplayLayer::OnButtonPressed(Ref *pSender)
{
    MenuItem* item = (MenuItem*) pSender;
    
    switch (item->getTag()) {
            
        case JUMP_BUTTON:
        {
            player->ApplyMovement(JUMP_BUTTON);
            break;
        }
        case DUCK_BUTTON:
        {
            player->ApplyMovement(DUCK_BUTTON);
            break;
        }
        case PAUSE_BUTTON:
        {
            break;
        }
            
        default:
            break;
    }
    
}


