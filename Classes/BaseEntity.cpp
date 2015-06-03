//
//  BaseEntity.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/1/15.
//
//

#include "BaseEntity.h"
#include "Constants.h"

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
    
    isInvulnerable = false;
    invulnerableTimer = 1.5f;
    
    isAlive = true;
    deathTimer = 3.0f;
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
            setScale(1.0f);
            setPositionY(getPositionY() + 25);
        }
        currentState = RUN_STATE;
    }

    if(isInvulnerable)
    {
        invulnerableTimer -= _deltaTime;
        if(invulnerableTimer <= 0.0f)
        {
            invulnerableTimer = 1.5f;
            isInvulnerable = false;
        }
    }
    
    if(!isAlive)
    {
        //deathTimer -= _deltaTime;
        //if(deathTimer <= 0.0f)
        //{
            // Send event to open post-game stats
            // but for now it will bring us to the main menu.
            gEventDispatcher->dispatchCustomEvent("END_GAME");
        //}
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
    // NEED TO CHANGE FOR IPHONE6 and 6+
    knockbackAction = MoveBy::create(0.2f, cocos2d::Vec2(-45.0f, -30.0f));
    knockbackAction->retain();
}

void BaseEntity::ApplyMovement(int _typeOfMovement)
{
    // TODO:
    // identify the type of movement and apply that to the player
    
    if(!isAlive)
        return;
    
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
            setScale(0.5f);
            setPositionY(getPositionY() - 25);
            //runAction(duckAction);
            // play sound effect here
        }

    }
}

void BaseEntity::Knockback()
{
    health--;
    if(health == 0)
        isAlive = false;
    
    std::cout << "Player Health: " << health << std::endl;
    
    isInvulnerable = true;
    runAction(knockbackAction);
    
    // TODO:
    // create an action/animation to move the player backwards on the conveyor belt
    
    
}
