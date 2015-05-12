//
//  BaseLayer.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/1/15.
//
//

#include "BaseLayer.h"

BaseLayer::BaseLayer()
{
    if(initWithColor(cocos2d::Color4B(255,255,255,255)))
    {
        showAds = false;
        visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    }
}

BaseLayer::~BaseLayer()
{
}

void BaseLayer::enter()
{
}

void BaseLayer::update(float _deltaTime)
{
}

void BaseLayer::render()
{
}

void BaseLayer::exit()
{
}