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
#include "CocosGUI.h"
#include "Constants.h"

class BaseLayer : public cocos2d::LayerColor
{
public:
    BaseLayer();
    virtual ~BaseLayer() = 0;
    
    virtual void enter() = 0;
    
    virtual void update(float _deltaTime) = 0;
    
    virtual void render() = 0;
    
    virtual void exit() = 0;
    
    bool showAds;
    cocos2d::Size visibleSize;
};

#endif /* defined(__TwistedSystem__BaseLayer__) */
