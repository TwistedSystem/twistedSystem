//
//  Player.h
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/1/15.
//
//

#ifndef __TwistedSystem__Player__
#define __TwistedSystem__Player__

#include <stdio.h>
#include "BaseEntity.h"

class Player : public BaseEntity
{
public:
    Player(short _playerNum, std::string _filename);
    ~Player();
    
};

#endif /* defined(__TwistedSystem__Player__) */
