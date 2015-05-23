//
//  OptionsLayer.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 4/28/15.
//
//

#include "OptionsLayer.h"
#include "MainMenuLayer.h"

using namespace cocos2d;
using namespace ui;


OptionsLayer::OptionsLayer()
{
    backButton = nullptr;
    isSetup = false;
    
    auto OptionHandler = [=](EventCustom *e)
    {
        this->enter();
    };
    
    ED_ADD(this, "OPEN_OPTIONS_MENU", OptionHandler);

    setOpacity(0);
}

OptionsLayer::~OptionsLayer()
{
    exit();
}

void OptionsLayer::enter()
{
    if(!isSetup)
    {
        backButton = Button::create();
        backButton->loadTextures("Options_Background.png", "Options_Background.png");
        backButton->Widget::setScale(1.0f);
        backButton->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
        backButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
        {
            switch (type)
            {
                case ui::Widget::TouchEventType::BEGAN:
                    OnButtonPressed(backButton->getTag());
                    break;
                case ui::Widget::TouchEventType::ENDED:
                    break;
                default:
                    break;
            }
        });
        backButton->setTag(0);
    
        addChild(backButton);
        
        isSetup = true;
    }
    
    show();
}

void OptionsLayer::show()
{
    setVisible(true);
    backButton->setTouchEnabled(true);
    scheduleUpdate();
}

void OptionsLayer::hide()
{
    setVisible(false);
    backButton->setTouchEnabled(false);
    unscheduleUpdate();
    gEventDispatcher->dispatchCustomEvent("RESUME_MAIN_MENU");
}

void OptionsLayer::exit()
{
    
}

void OptionsLayer::update(float _deltaTime)
{
    int x = 0;
    x += 5;
}

void OptionsLayer::render()
{
    
}

void OptionsLayer::OnButtonPressed(int _tag)
{
    switch (_tag)
    {
        case BACK_BUTTON:
        {
            hide();
            break;
        }
            
        default:
            break;
    }
}




