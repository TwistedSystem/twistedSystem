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

class ObstacleManager
{
public:
    ObstacleManager();
    ~ObstacleManager();
    
    void update(float _deltaTime);
    
    std::vector<Obstacle*> obstacles;
    
};

#endif /* defined(__TwistedSystem__ObstacleManager__) */
