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
        setPosition(Point(visibleSize.width / 2, visibleSize.height + 64));
        setVisible(true);
    }
}

Obstacle::~Obstacle()
{
    
}