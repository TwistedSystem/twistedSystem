//
//  BaseEntity.h
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/1/15.
//
//

#ifndef __TwistedSystem__BaseEntity__
#define __TwistedSystem__BaseEntity__

#include <stdio.h>
#include "cocos2d.h"

enum PlayerState
{
    RUN_STATE = 0,
    JUMP_STATE = 1,
    DUCK_STATE = 2,
    HIT_STATE = 3
};

class BaseEntity : public cocos2d::Sprite
{
public:    
    BaseEntity();
    ~BaseEntity();
    
    virtual void update(float _deltaTime);
    
    virtual cocos2d::Action* CreateAnimation(int _numFrames, int _frameWidth, int _frameHeight, int _offsetX, int _offsetY, bool _repeat, float _frameLength);
    virtual void CreateActions();
    
    virtual void ApplyMovement(int _typeOfMovement);
    virtual void Knockback();
    
    short health;
    short score;
    short playerNum;
    
    bool isInvulnerable;
    float invulnerableTimer;
    
    bool isAlive;
    float deathTimer;
    
    std::string playerModel;
    
    cocos2d::Texture2D *playerAtlas;
    
    cocos2d::Action *runAnimation;
    cocos2d::Action *jumpAnimation;
    cocos2d::Action *duckAnimation;
    
    cocos2d::JumpBy *jumpAction;
    cocos2d::Action *duckAction;
    cocos2d::MoveBy *knockbackAction;
    
    PlayerState currentState;
    
    // do we need this??
    //cocos2d::Action *hitAnimation;
    
};

#endif /* defined(__TwistedSystem__BaseEntity__) */
