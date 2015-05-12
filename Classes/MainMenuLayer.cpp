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

MainMenuLayer::MainMenuLayer(GameplayLayer *_gameplayLayer, bool _showAds)
{
    showAds = _showAds;
    gameplayLayer = _gameplayLayer;
    
    playButton = nullptr;
    optionsLayer = nullptr;
}

MainMenuLayer::~MainMenuLayer()
{
    exit();
}

void MainMenuLayer::enter()
{
    playButton = Button::create();
    playButton->setTouchEnabled(true);
    playButton->loadTextures("CloseNormal.png", "CloseSelected.png");
    playButton->Widget::setScale(2.0f);
    playButton->setPosition(Point(visibleSize.width / 2, visibleSize.height / 2) + Point(0, -50));
    playButton->addTouchEventListener(this, toucheventselector(MainMenuLayer::OnButtonPressed));
    playButton->setTag(0);
    
    addChild(playButton);
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

void MainMenuLayer::OnButtonPressed(Ref *pSender)
{
    MenuItem* item = (MenuItem*) pSender;

    switch (item->getTag()) {
            
        case PLAY_BUTTON:
        {
            TransitionToGame();
            break;
        }
            
        default:
            break;
    }

}

void MainMenuLayer::TransitionToGame()
{
    HideButtons();
    gameplayLayer->enter();
    gameplayLayer->StartGameLoop();
    setVisible(false);
    // hide ads??
}

void MainMenuLayer::HideButtons()
{
    MoveBy* move = MoveBy::create(0.5f, ccp(512 * 0.8f, 0));
    playButton->runAction((Action*) move);
}








