//
//  Player.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/1/15.
//
//

#include "Player.h"

using namespace cocos2d;

Player::Player(short _playerNum, std::string filename)
{
    // Rect = float x, float y, float width, float height
    if(initWithFile(filename.c_str(), cocos2d::Rect(0, 0, 64, 128)))
    {
        playerNum = _playerNum;
        
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Point visibleOrigin = Director::getInstance()->getVisibleOrigin();
        
        setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
        setVisible(true);
        
        //playButton->addTouchEventListener(this, toucheventselector(MainMenuLayer::OnButtonPressed));
        
        CreateAnimations();
        CreateActions();
    }
}

Player::~Player()
{
    
}