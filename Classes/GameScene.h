//
//  GameScene.h
//  TwistedSystem
//
//  Created by Nicholas Cerame on 4/1/15.
//
//

#ifndef __TwistedSystem__GameScene__
#define __TwistedSystem__GameScene__

#include "cocos2d.h"

#include "MainMenuLayer.h"
#include "GameplayLayer.h"
#include "OptionsLayer.h"

enum
{
    OPTIONS_Z_ORDER = 10000,
    MENU_Z_ORDER = 9999,
    HUD_Z_ORDER = 999,
    GAMEPLAY_Z_ORDER = 99
};

class GameScene : public cocos2d::Scene
{
private:
    GameScene(bool showAds = false);
    ~GameScene();
    
public:
    static GameScene* scene(bool showAds = false);
    
    GameplayLayer* gameplayLayer;
    MainMenuLayer* mainMenuLayer;
    OptionsLayer* optionsLayer;
    
};

#endif /* defined(__TwistedSystem__GameScene__) */
