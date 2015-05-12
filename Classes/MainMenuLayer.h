//
//  MainMenuLayer.h
//  TwistedSystem
//
//  Created by Nicholas Cerame on 4/1/15.
//
//

#ifndef __TwistedSystem__MainMenuLayer__
#define __TwistedSystem__MainMenuLayer__

#include <stdio.h>
#include "GameplayLayer.h"
#include "OptionsLayer.h"
#include "BaseLayer.h"

enum MenuButtons
{
    PLAY_BUTTON = 0,
    OPTIONS_BUTTON = 1,
};

class MainMenuLayer : public BaseLayer
{
public:
    MainMenuLayer(GameplayLayer* _gameplayLayer, bool _showAds = false);
    virtual ~MainMenuLayer();
    
    virtual void enter() override;
    
    virtual void update(float _deltaTime) override;
    
    virtual void render() override;
    
    virtual void exit() override;
    
private:
    void OnButtonPressed(Ref *pSender);
    void TransitionToGame();
    void HideButtons();
    
    
    // cocos2d::Sprite* logo;
    
    cocos2d::ui::Button *playButton;
    
    GameplayLayer* gameplayLayer;
    OptionsLayer* optionsLayer;
};


#endif /* defined(__TwistedSystem__MainMenuLayer__) */
