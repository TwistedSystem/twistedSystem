//
//  BaseEntity.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/1/15.
//
//

#include "BaseEntity.h"

using namespace cocos2d;

BaseEntity::BaseEntity()
{
    health = 4;
    score = 0;
        
    playerModel = "";
    
    currentState = RUN_STATE;
    
    playerAtlas = nullptr;
        
    jumpAction = nullptr;
    duckAction = nullptr;
    
    runAnimation = nullptr;
    jumpAnimation = nullptr;
    duckAnimation = nullptr;
}

BaseEntity::~BaseEntity()
{
    
}

void BaseEntity::update(float _deltaTime)
{
    if(currentState == JUMP_STATE && jumpAnimation->isDone())
    {
        if(runAnimation != nullptr)
        {
            runAction(runAnimation);
        }
        currentState = RUN_STATE;
    }
    else if(currentState == DUCK_STATE && duckAnimation->isDone())
    {
        if(runAnimation != nullptr)
        {
            runAction(runAnimation);
        }
        currentState = RUN_STATE;
    }

}

cocos2d::Action* BaseEntity::CreateAnimation(int _numFrames, int _frameWidth, int _frameHeight, int _offsetX, int _offsetY, bool _repeat, float _frameLength)
{
    Vector<SpriteFrame*> animFrames(_numFrames);
    
    for(int i = 0; i < _numFrames; i++)
    {
        // TODO:
        // locate and iterate through each frame of animation in the atlas and use locations in the create function
        
        SpriteFrame *frame = SpriteFrame::create(playerModel, Rect(_offsetX + (i * _frameWidth), _offsetY, _frameWidth, _frameHeight));
        animFrames.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(animFrames, _frameLength);
    Animate *animate = Animate::create(animation);
    
    if(_repeat)
        return RepeatForever::create(animate);
    else
        return animate;
}

void BaseEntity::CreateActions()
{
    jumpAction = JumpBy::create(0.5f, Vec2(0, 0), 100.0f, 1);
    jumpAction->retain();
    
    // TODO:
    // create the ducking action
    // Most likely, there won't be a ducking action. The animation will show the character ducking and the collision box will change.
    
    
    // TODO:
    // create the knockback action
}

void BaseEntity::ApplyMovement(int _typeOfMovement)
{
    // TODO:
    // identify the type of movement and apply that to the player
    
    if(_typeOfMovement == 0)
    {
        // jump

        // I don't think isDone is the right thing to use here.
        if(jumpAnimation != nullptr && runAnimation != nullptr && currentState != JUMP_STATE)
        {
            currentState = JUMP_STATE;
            
            stopAction(runAnimation);
            runAction(jumpAnimation);
            runAction(jumpAction);
            // play sound effect here
        }
    }
    else if(_typeOfMovement == 1)
    {
        // duck
        
        // I don't think isDone is the right thing to use here.
        if(duckAnimation != nullptr && runAnimation != nullptr && currentState != DUCK_STATE)
        {
            currentState = DUCK_STATE;
            
            stopAction(runAnimation);
            runAction(duckAnimation);
            //runAction(duckAction);
            // play sound effect here
        }

    }
}

void BaseEntity::Knockback()
{
    health--;
    score--;
    
    // TODO:
    // create an action/animation to move the player backwards on the conveyor belt
    
    
}
