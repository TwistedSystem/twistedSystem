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
    
}

void BaseEntity::CreateAnimations()
{
    //////
    // Creates the running animation Action
    
    Vector<SpriteFrame*> animFrames(4);
    //char str[100] = {0};
    for(int i = 1; i < 4; i++)
    {
        //sprintf(str, "conveyor_%01d.png",i);
        //SpriteFrame *frame = SpriteFrame::create(str,Rect(0,0,512,64));
        
        // TODO:
        // locate and iterate through each frame of animation in the atlas and use locations in the create function
        
        SpriteFrame *frame = SpriteFrame::createWithTexture(playerAtlas, Rect(0,0,512,64));
        animFrames.pushBack(frame);
    }
    
    Animation *animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
    Animate *animate = Animate::create(animation);
    runAnimation = RepeatForever::create(animate);
    
    //////
    // Creates the jumping animation Action
    
    animFrames.clear();
    
    for(int i = 1; i < 4; i++)
    {
        // TODO:
        // locate and iterate through each frame of animation in the atlas and use locations in the create function
        
        SpriteFrame *frame = SpriteFrame::createWithTexture(playerAtlas, Rect(0,0,512,64));
        animFrames.pushBack(frame);
    }
    
    // This may be leaking memory ???
    animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
    animate = Animate::create(animation);
    jumpAnimation = Repeat::create(animate, 1);
    
    //////
    // Creates the ducking animation Action
    
    animFrames.clear();
    
    for(int i = 1; i < 4; i++)
    {
        // TODO:
        // locate and iterate through each frame of animation in the atlas and use locations in the create function
        
        SpriteFrame *frame = SpriteFrame::createWithTexture(playerAtlas, Rect(0,0,512,64));
        animFrames.pushBack(frame);
    }
    
    // This may be leaking memory ???
    animation = Animation::createWithSpriteFrames(animFrames, 0.1f);
    animate = Animate::create(animation);
    duckAnimation = Repeat::create(animate, 1);
}

void BaseEntity::CreateActions()
{
    jumpAction = JumpBy::create(0.6f, Vec2(0, 0), 100.0f, 1);
    
    // TODO:
    // create the ducking action
    
    
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
        if(jumpAnimation != nullptr && runAnimation != nullptr && jumpAnimation->isDone())
        {
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
        if(duckAnimation != nullptr && runAnimation != nullptr && duckAnimation->isDone())
        {
            stopAction(runAnimation);
            runAction(duckAnimation);
            runAction(duckAction);
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
