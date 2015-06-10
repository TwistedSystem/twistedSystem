//
//  GameplayLayer.h
//  TwistedSystem
//
//  Created by Nicholas Cerame on 4/1/15.
//
//

#ifndef __TwistedSystem__GameplayLayer__
#define __TwistedSystem__GameplayLayer__

#include <stdio.h>
#include "PauseLayer.h"
#include "BaseLayer.h"
#include "Player.h"
#include "Enemy.h"
#include "ObstacleManager.h"

enum GameplayButtons
{
    JUMP_BUTTON = 0,
    DUCK_BUTTON = 1,
    PAUSE_BUTTON = 2
};

class GameplayLayer : public BaseLayer
{
public:
    GameplayLayer();
    virtual ~GameplayLayer();
    
    virtual void enter() override;
    
    virtual void update(float _deltaTime) override;
    
    virtual void render() override;
    
    virtual void exit() override;
    
    void StartGameLoop();
    void OnButtonPressed(Ref *pSender);
    
    bool HandleCollision(const cocos2d::PhysicsContact& contact);
    bool onContactBegin(const cocos2d::PhysicsContact& contact);
    
    void EndGame();
    void RestartGame();
    
    
    float startTimer;
    float obsTimer;
    
    Player *player;
    std::vector<Enemy*> enemies;
    
    cocos2d::Label *startTimerLabel;
    cocos2d::Label *playerScoreLabel;
    
    cocos2d::ui::Button *jumpButton;
    cocos2d::ui::Button *duckButton;
    
    cocos2d::Sprite *ship;
    
    ObstacleManager *obsManager;
};

#endif /* defined(__TwistedSystem__GameplayLayer__) */
