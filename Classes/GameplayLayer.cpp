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
USING_NS_CC;


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
    
    playerScoreLabel = cocos2d::Label::createWithBMFont("CartonSixBMP.fnt", "0");
    playerScoreLabel->setPosition(Point(100, 500));
    playerScoreLabel->setColor(ccBLACK);
    playerScoreLabel->setVisible(false);
    addChild(playerScoreLabel, 101);
    
    
    
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
    
    ship = Sprite::create("Ship.png");
    ship->setPosition(Point(visibleSize.width - ship->getTextureRect().size.width * 0.5f, visibleSize.height - ship->getTextureRect().size.height  * 0.5f));
    addChild(ship);
    
    jumpButton = Button::create();
    jumpButton->setTouchEnabled(true);
    jumpButton->loadTextures("CloseNormal.png", "CloseSelected.png");
    jumpButton->Widget::setScale(3.0f);
    jumpButton->setPosition(Point(200, visibleSize.height - 200));
    jumpButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
                                      {
                                          switch (type)
                                          {
                                              case ui::Widget::TouchEventType::BEGAN:
                                                  GameplayLayer::OnButtonPressed(jumpButton);
                                                  break;
                                              case ui::Widget::TouchEventType::MOVED:
                                                  break;
                                              case ui::Widget::TouchEventType::CANCELED:
                                                  break;
                                              case ui::Widget::TouchEventType::ENDED:
                                                  break;
                                          }
                                      });
    jumpButton->setTag(0);
    addChild(jumpButton);
    
    duckButton = Button::create();
    duckButton->setTouchEnabled(true);
    duckButton->loadTextures("CloseNormal.png", "CloseSelected.png");
    duckButton->Widget::setScale(3.0f);
    duckButton->setPosition(Point(200, 200));
    duckButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
                                      {
                                          switch (type)
                                          {
                                              case ui::Widget::TouchEventType::BEGAN:
                                                  GameplayLayer::OnButtonPressed(duckButton);
                                                  break;
                                              case ui::Widget::TouchEventType::MOVED:
                                                  break;
                                              case ui::Widget::TouchEventType::CANCELED:
                                                  break;
                                              case ui::Widget::TouchEventType::ENDED:
                                                  break;
                                          }
                                      });
    duckButton->setTag(1);
    addChild(duckButton);

    startTimerLabel->setVisible(true);
    playerScoreLabel->setVisible(true);
    
    auto contactListener = EventListenerPhysicsContact::create();
    contactListener->onContactBegin = CC_CALLBACK_1(GameplayLayer::onContactBegin, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
    
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

bool GameplayLayer::onContactBegin(const PhysicsContact& contact)
{
    return HandleCollision(contact);
}

bool GameplayLayer::HandleCollision(const PhysicsContact& contact)
{
    if(!player->isAlive || player->isInvulnerable)
        return false;
    
    if(contact.getShapeA()->getTag() == 3 || contact.getShapeB()->getTag() == 3)
    {
        if(!player->jumpAnimation->isDone())
        {
            player->IncreaseScore();
            playerScoreLabel->setString(String::createWithFormat("%d", (int)player->score)->getCString());
            CCLOG("JUMP");
            return false;
        }
    }
    else if(contact.getShapeA()->getTag() == 4 || contact.getShapeB()->getTag() == 4)
    {
        if(!player->duckAnimation->isDone())
        {
            player->IncreaseScore();
            playerScoreLabel->setString(String::createWithFormat("%d", (int)player->score)->getCString());
            CCLOG("DUCK");
            return false;
        }
    }
    
    player->Knockback();
    std::cout << "Player Hit" << std::endl;
    return false;
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



