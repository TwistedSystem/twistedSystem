//
//  Player.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/1/15.
//
//

#include "Player.h"

Player::Player(short _playerNum, std::string filename)
{
    if(initWithFile(filename.c_str()))
    {
        playerNum = _playerNum;
        
        CreateAnimations();
        CreateActions();
    }
}

Player::~Player()
{
    
}