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

class BaseEntity : public cocos2d::Sprite
{
public:    
    BaseEntity();
    ~BaseEntity();
    
    virtual void update(float _deltaTime);
    
    virtual void CreateAnimations();
    virtual void CreateActions();
    
    virtual void ApplyMovement(int _typeOfMovement);
    virtual void Knockback();
    
    short health;
    short score;
    short playerNum;
    
    std::string playerModel;
    
    cocos2d::Texture2D *playerAtlas;
    
    cocos2d::Action *runAnimation;
    cocos2d::Action *jumpAnimation;
    cocos2d::Action *duckAnimation;
    
    cocos2d::JumpBy *jumpAction;
    cocos2d::Action *duckAction;
    
    // do we need this??
    //cocos2d::Action *hitAnimation;
    
};

#endif /* defined(__TwistedSystem__BaseEntity__) */
