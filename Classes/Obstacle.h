//
//  Obstacle.h
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/6/15.
//
//

#ifndef __TwistedSystem__Obstacle__
#define __TwistedSystem__Obstacle__

#include <stdio.h>
#include "cocos2d.h"

class Obstacle : public cocos2d::Sprite
{
public:
    Obstacle(std::string _filename);
    ~Obstacle();
    
    cocos2d::Sprite *mySprite;
};

#endif /* defined(__TwistedSystem__Obstacle__) */
