//
//  ObstacleManager.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/6/15.
//
//

#include "ObstacleManager.h"
#include "GameplayLayer.h"

using namespace cocos2d;

ObstacleManager::ObstacleManager(GameplayLayer *_pGS)
{
    pGS = _pGS;
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
                    tempPos.y -= _deltaTime * 140; // will need to multiply by some speed factor
                    tempPos.x -= _deltaTime * 210; // ~2:3 ratio
                
                    if(tempPos.y < 50)
                    {
                        pGS->removeChild(obstacles[i]);
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
        temp->setTag(0);
        temp->getPhysicsBody()->getShape(0)->setTag(3);
        obstacles.push_back(temp);
        pGS->addChild(temp, 99);
    }
    else
    {
        temp = new Obstacle("Duck_Obstacle.png");
        temp->obsType = DUCK;
        temp->setTag(1);
        temp->getPhysicsBody()->getShape(0)->setTag(4);
        obstacles.push_back(temp);
        pGS->addChild(temp, 102);
    }
}




