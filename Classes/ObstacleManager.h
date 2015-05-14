//
//  ObstacleManager.h
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/6/15.
//
//

#ifndef __TwistedSystem__ObstacleManager__
#define __TwistedSystem__ObstacleManager__

#include <stdio.h>
#include "Obstacle.h"

class ObstacleManager : public cocos2d::Sprite
{
public:
    ObstacleManager();
    ~ObstacleManager();
    
    void update(float _deltaTime);
    
    void AddObstacle();
    
    std::vector<Obstacle*> obstacles;
    
    bool isRunning;
};

#endif /* defined(__TwistedSystem__ObstacleManager__) */
