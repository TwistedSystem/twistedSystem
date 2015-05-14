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
        
        setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
        
        // placeholder animations
        runAnimation = CreateAnimation(1, 64, 128, 0, 0, true, 0.2f);
        runAnimation->retain();
        
        jumpAnimation = CreateAnimation(1, 64, 128, 128, 0, false, 0.5f);
        jumpAnimation->retain();
        
        duckAnimation = CreateAnimation(1, 64, 128, 64, 0, false, 0.5f);
        duckAnimation->retain();
        
        runAction(runAnimation);
        
        CreateActions();
    }
}

Player::~Player()
{
    
}