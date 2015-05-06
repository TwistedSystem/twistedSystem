//
//  Enemy.h
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/1/15.
//
//

#ifndef __TwistedSystem__Enemy__
#define __TwistedSystem__Enemy__

#include <stdio.h>
#include "BaseEntity.h"

class Enemy : public BaseEntity
{
public:
    Enemy(short _playerNum, std::string filename);
    ~Enemy();
    
    
};

#endif /* defined(__TwistedSystem__Enemy__) */
