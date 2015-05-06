//
//  GameplayLayer.h
//  TwistedSystem
//
//  Created by Nicholas Cerame on 4/1/15.
//
//

#ifndef __TwistedSystem__GameplayLayer__
#define __TwistedSystem__GameplayLayer__

#include <stdio.h>
#include "HudLayer.h"
#include "PauseLayer.h"
#include "BaseLayer.h"
#include "Player.h"
#include "Enemy.h"

class GameplayLayer : public BaseLayer
{
public:
    GameplayLayer();
    virtual ~GameplayLayer();
    
    virtual void enter() override;
    
    virtual void update(float _deltaTime) override;
    
    virtual void render() override;
    
    virtual void exit() override;
    
    void StartGameLoop();
    
    
    Player *player;
    std::vector<Enemy*> enemies;
};

#endif /* defined(__TwistedSystem__GameplayLayer__) */
