//
//  MainMenuLayer.cpp
//  TwistedSystem
//
//  Created by Nicholas Cerame on 4/1/15.
//
//

#include "MainMenuLayer.h"

using namespace cocos2d;
using namespace ui;

MainMenuLayer::MainMenuLayer(GameplayLayer *_gameplayLayer, OptionsLayer *_optionsLayer, bool _showAds)
{
    showAds = _showAds;
    gameplayLayer = _gameplayLayer;
    optionsLayer = _optionsLayer;
    
    playButton = nullptr;
}

MainMenuLayer::~MainMenuLayer()
{
    exit();
}

void MainMenuLayer::enter()
{
    background = Sprite::create("Main_Background.png");
    background->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2));
    addChild(background);
    
    playButton = Button::create();
    playButton->setTouchEnabled(true);
    playButton->loadTextures("CloseNormal.png", "CloseSelected.png");
    playButton->Widget::setScale(2.0f);
    playButton->setPosition(Point(visibleSize.width / 2 + 100, visibleSize.height / 2 - 175));
    playButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
    {
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                OnButtonPressed(playButton->getTag());
                break;
            case ui::Widget::TouchEventType::ENDED:
                break;
            default:
                break;
        }
    });
    playButton->setTag(0);
    
    addChild(playButton);
    
    optionsButton = Button::create();
    optionsButton->setTouchEnabled(true);
    optionsButton->loadTextures("CloseNormal.png", "CloseSelected.png");
    optionsButton->Widget::setScale(2.0f);
    optionsButton->setPosition(Point(visibleSize.width / 2 - 100, visibleSize.height / 2 - 175));
    optionsButton->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type)
    {
        switch (type)
        {
            case ui::Widget::TouchEventType::BEGAN:
                OnButtonPressed(optionsButton->getTag());
                break;
            case ui::Widget::TouchEventType::ENDED:
                break;
            default:
                break;
        }
    });
    optionsButton->setTag(1);
    
    addChild(optionsButton);
    
    auto MenuHandler = [=](EventCustom *e)
    {
        this->ShowButtons();
    };
    
    ED_ADD(this, "RESUME_MAIN_MENU", MenuHandler);
}

void MainMenuLayer::update(float _deltaTime)
{
    
}

void MainMenuLayer::render()
{
    
}

void MainMenuLayer::exit()
{
    
}

void MainMenuLayer::OnButtonPressed(int _tag)
{
    switch (_tag)
    {
        case PLAY_BUTTON:
        {
            TransitionToGame();
            break;
        }
        case OPTIONS_BUTTON:
        {
            TransitionToOptions();
            break;
        }
            
        default:
            break;
    }
}

void MainMenuLayer::TransitionToGame()
{
    //HideButtons();
    gEventDispatcher->dispatchCustomEvent("START_GAME");
    setVisible(false);
    // hide ads??
}

void MainMenuLayer::TransitionToOptions()
{
    HideButtons();
    gEventDispatcher->dispatchCustomEvent("OPEN_OPTIONS_MENU");

    // hide ads??
}

void MainMenuLayer::HideButtons()
{
    //MoveBy* move = MoveBy::create(0.5f, Vec2(512 * 0.8f, 0));
    //playButton->runAction((Action*) move);
    playButton->setTouchEnabled(false);
}

void MainMenuLayer::ShowButtons()
{
    playButton->setTouchEnabled(true);
    setVisible(true);
}








