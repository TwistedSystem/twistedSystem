//
//  BaseLayer.h
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/1/15.
//
//

#ifndef __TwistedSystem__BaseLayer__
#define __TwistedSystem__BaseLayer__

#include <stdio.h>
#include "cocos2d.h"

class BaseLayer : public cocos2d::Layer
{
public:
    BaseLayer();
    virtual ~BaseLayer() = 0;
    
    virtual void enter() = 0;
    
    virtual void update(float _deltaTime) = 0;
    
    virtual void render() = 0;
    
    virtual void exit() = 0;
    
    bool showAds;
};

#endif /* defined(__TwistedSystem__BaseLayer__) */
