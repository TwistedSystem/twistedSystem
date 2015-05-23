//
//  OptionsLayer.h
//  TwistedSystem
//
//  Created by Nicholas Cerame on 4/28/15.
//
//

#ifndef __TwistedSystem__OptionsLayer__
#define __TwistedSystem__OptionsLayer__

#include <stdio.h>
#include "BaseLayer.h"

class OptionsLayer : public BaseLayer
{
public:
    OptionsLayer();
    virtual ~OptionsLayer();
    
    virtual void enter() override;
    
    virtual void update(float _deltaTime) override;
    
    virtual void render() override;
    
    virtual void exit() override;
    
    void show();
    void hide();
    
    cocos2d::ui::Button *settingsButton;
};


#endif /* defined(__TwistedSystem__OptionsLayer__) */
