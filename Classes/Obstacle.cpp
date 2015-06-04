//
//  Obstacle.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/6/15.
//
//

#include "Obstacle.h"

using namespace cocos2d;

Obstacle::Obstacle(std::string _filename)
{
    if(initWithFile(_filename.c_str()))
    {
        Size visibleSize = Director::getInstance()->getVisibleSize();
        setPosition(Point(visibleSize.width, visibleSize.height * 0.9f));
        setRotation(52.0f);
        setVisible(true);
        
        auto spriteBody = PhysicsBody::createBox(getContentSize(), PhysicsMaterial(0, 0, 0));
        spriteBody->setDynamic(true);
        spriteBody->setGravityEnable(false);
        spriteBody->setRotationEnable(false);
        spriteBody->setContactTestBitmask(0xFFFFFFFF);
        setPhysicsBody(spriteBody);
    }
}

Obstacle::~Obstacle()
{
    
}