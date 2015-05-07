//
//  ObstacleManager.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/6/15.
//
//

#include "ObstacleManager.h"

ObstacleManager::ObstacleManager()
{
    // creates 6 obstacles when the game state loads for use at any time during gameplay.
    
    Obstacle *temp;
    
    for (int i = 0; i < 6; i++)
    {
        if(i < 3)
        {
            temp = new Obstacle("JumpObstacle.png");
            obstacles.push_back(temp);
        }
        else
        {
            temp = new Obstacle("DuckObstacle.png");
            obstacles.push_back(temp);
        }
        
        // TODO
        // position obstacle at the back of the conveyor belt. figure out a way to not render obstacle until it is in play.
    }
    
    
    
}

ObstacleManager::~ObstacleManager()
{
    for (int i = 0; i < 6; i++) {
        delete obstacles[i];
    }
    obstacles.clear();
}

void ObstacleManager::update(float _deltaTime)
{
    // TODO
}