//
//  ObstacleManager.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/6/15.
//
//

#include "ObstacleManager.h"

using namespace cocos2d;

ObstacleManager::ObstacleManager()
{
    srand(time(nullptr));
    
    isRunning = false;
}

ObstacleManager::~ObstacleManager()
{
    for (int i = 0; i < obstacles.size(); i++)
    {
        delete obstacles[i];
    }
    
    obstacles.clear();
}

void ObstacleManager::update(float _deltaTime)
{
    // TODO
    // update positions of obstacles currently in play based on game's elapsed time. reset position of obstacle once it falls off conveyor belt.
    
    if(isRunning)
    {
        if(!obstacles.empty())
        {
            for (int i = 0; i < obstacles.size(); i++)
            {
                if(obstacles[i] != nullptr)
                {
                    Vec2 tempPos = obstacles[i]->getPosition();
                    tempPos.y -= _deltaTime * 100; // will need to multiply by some speed factor
                
                    if(tempPos.y < 0)
                    {
                        cocos2d::Node::removeChild(obstacles[i]);
                        delete obstacles[i];
                        
                        std::vector<Obstacle*>::const_iterator iterator = obstacles.begin();
                        obstacles.erase(iterator);
                    }
                    else
                    {
                        obstacles[i]->setPosition(tempPos);
                    }
                }
            }
        }
    }
}


void ObstacleManager::AddObstacle()
{
    int randomNum = (rand() % 2);
    
    Obstacle *temp;
    if(randomNum == 0)
    {
        temp = new Obstacle("Jump_Obstacle.png");
        temp->obsType = JUMP;
        obstacles.push_back(temp);
        addChild(temp, 99);
    }
    else
    {
        temp = new Obstacle("Duck_Obstacle.png");
        temp->obsType = DUCK;
        obstacles.push_back(temp);
        addChild(temp, 101);
    }
}




