//
//  Enemy.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/1/15.
//
//

#include "Enemy.h"

Enemy::Enemy(short _playerNum, std::string filename)
{
    if(initWithFile(filename.c_str()))
    {
        playerNum = _playerNum;
        
        // TODO:
        // figure out the model name from filename and assign to playerModel
        
        
        //CreateAnimations();
        CreateActions();
    }
}

Enemy::~Enemy()
{
    
}