//
//  GameplayLayer.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 4/1/15.
//
//

#include "GameplayLayer.h"
#include <iostream>

using namespace cocos2d;
using namespace ui;

GameplayLayer::GameplayLayer()
{
    player = nullptr;
    ship = nullptr;
    startTimer = 5.0f;
    obsTimer = 1.5f;
    
    startTimerLabel = cocos2d::Label::createWithBMFont("CartonSixBMP.fnt", "3");
    startTimerLabel->setPosition(Point(100, visibleSize.height / 2));
    startTimerLabel->setColor(ccBLACK);
    startTimerLabel->setVisible(false);
    addChild(startTimerLabel, 101);
    
    
    
    auto StartGameHandler = [=](EventCustom *e)
    {
        this->enter();
    };
    
    // Registers GameplayLayer to listen for a specific event.
    ED_ADD(this, "START_GAME", StartGameHandler);
    
    auto EndGameHandler = [=](EventCustom *e)
    {
        this->EndGame();
    };
    
    ED_ADD(this, "END_GAME", EndGameHandler);
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
        //player = new Player(0, "Player_Atlas_Black.png");
        player = new Player(0, "Test_Character.png");
        addChild(player, 101);
    }
    
    obsManager = new ObstacleManager(this);
    //addChild(obsManager, 100);
    
    jumpButton = Button::create();
    jumpButton->setTouchEnabled(true);
    jumpButton->loadTextures("CloseNormal.png", "CloseSelected.png");
    jumpButton->Widget::setScale(3.0f);
    jumpButton->setPosition(Point(200, visibleSize.height - 200));
    jumpButton->addTouchEventListener(this, toucheventselector(GameplayLayer::OnButtonPressed));
    jumpButton->setTag(0);
    addChild(jumpButton);
    
    duckButton = Button::create();
    duckButton->setTouchEnabled(true);
    duckButton->loadTextures("CloseNormal.png", "CloseSelected.png");
    duckButton->Widget::setScale(3.0f);
    duckButton->setPosition(Point(200, 200));
    duckButton->addTouchEventListener(this, toucheventselector(GameplayLayer::OnButtonPressed));
    duckButton->setTag(1);
    addChild(duckButton);
    
    ship = Sprite::create("Ship.png");
    ship->setPosition(Point(visibleSize.width - ship->getTextureRect().size.width * 0.5f, visibleSize.height - ship->getTextureRect().size.height  * 0.5f));
    addChild(ship);

    
    startTimerLabel->setVisible(true);
    
    StartGameLoop();
}

void GameplayLayer::update(float _deltaTime)
{
    if (startTimer >= 0.0f)
    {
        startTimer -= _deltaTime;
        
        if(startTimer > 2.0f)
            startTimerLabel->setString(String::createWithFormat("%d", (int)startTimer - 1)->getCString());
        
        else if(startTimer < 2.0f && startTimer > 1.9f)
            startTimerLabel->setString("Go!");
        
        else if(startTimer < 0.0f)
        {
            removeChild(startTimerLabel);
            obsManager->isRunning = true;
        }
    }
    else
    {
        obsTimer -= _deltaTime;
        if(obsTimer < 0.0f)
        {
            obsManager->AddObstacle();
            obsTimer = 3.0f;  // find a way to exponentially decrease this timer number.
        }
    }
    
    obsManager->update(_deltaTime);
    player->update(_deltaTime);
    
    CheckCollision();
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

void GameplayLayer::CheckCollision()
{
    if(!player->isAlive)
        return;
    
    float playerY = player->getPositionY();
    
    for (int i = 0; i < obsManager->obstacles.size(); i++)
    {
        Obstacle *currentObs = obsManager->obstacles[i];
        float obsY = currentObs->getPositionY() - currentObs->getContentSize().height;
        
        if(obsY < playerY + (player->getContentSize().height / 2) /*&& obsY > playerY - (player->getContentSize().height / 2)*/)
        {
            if(currentObs->getTextureRect().intersectsRect(player->getTextureRect()) && !player->isInvulnerable)
            {
                //if(player->jumpAnimation->isDone())
                //{
                    player->Knockback();
                    std::cout << "Player Hit" << std::endl;
                break;
                //}
            }
        }
    }
}


void GameplayLayer::EndGame()
{
    //RestartGame();
    
    //setVisible(false);
    //gEventDispatcher->dispatchCustomEvent("RESUME_MAIN_MENU");
}

void GameplayLayer::RestartGame()
{
    setVisible(true);
    
    startTimer = 5.0f;
    obsTimer = 1.5f;
}



