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

class GameplayLayer;

class ObstacleManager : public cocos2d::Sprite
{
public:
    ObstacleManager(GameplayLayer *_pGS);
    ~ObstacleManager();
    
    void update(float _deltaTime);
    
    void AddObstacle();
    
    std::vector<Obstacle*> obstacles;
    
    bool isRunning;
    
    GameplayLayer *pGS;
};

#endif /* defined(__TwistedSystem__ObstacleManager__) */
