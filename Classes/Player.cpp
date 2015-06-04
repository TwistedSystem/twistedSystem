//
//  Player.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/1/15.
//
//

#include "Player.h"

using namespace cocos2d;

Player::Player(short _playerNum, std::string _filename)
{
    // _playerNum will determine which position this player will spawn in.
    // Rect = float x, float y, float width, float height
    
    if(initWithFile(_filename.c_str(), cocos2d::Rect(0, 0, 64, 128)))
    {
        playerNum = _playerNum;
        playerModel = _filename;
        
        Size visibleSize = Director::getInstance()->getVisibleSize();
        
        auto spriteBody = PhysicsBody::createBox(getContentSize(), PhysicsMaterial(0, 1, 0));
        spriteBody->setDynamic(false);
        spriteBody->setGravityEnable(false);
        spriteBody->setRotationEnable(false);
        spriteBody->setContactTestBitmask(0xFFFFFFFF);
        setPhysicsBody(spriteBody);
        
        // Places the player in the correct "slot"
        switch (playerNum)
        {
            case 0:
                setPosition(Point(visibleSize.width * 0.82f, visibleSize.height * 0.54f));
                //cocos2d::Node::setPosition(visibleSize.width / 2, visibleSize.height / 2);
                break;
            case 1:
                setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
                break;
            case 2:
                setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
                break;
            case 3:
                setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
                break;
                
            default:
                break;
        }
        
        // placeholder animations
        runAnimation = CreateAnimation(1, 64, getTextureRect().size.height, 0, 0, true, 0.2f);
        runAnimation->retain();
        
        jumpAnimation = CreateAnimation(1, 64, getTextureRect().size.height, 0, 0, false, 0.5f);
        jumpAnimation->retain();
        
        duckAnimation = CreateAnimation(1, 64, getTextureRect().size.height, 0, 0, false, 0.5f);
        duckAnimation->retain();
        
        runAction(runAnimation);
        
        CreateActions();
    }
}

Player::~Player()
{
    
}