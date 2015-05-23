//
//  Constants.h
//  TwistedSystem
//
//  Created by Nicholas Cerame on 5/23/15.
//
//

#ifndef TwistedSystem_Constants_h
#define TwistedSystem_Constants_h

#include "cocos2d.h"

#define gEventDispatcher Director::getInstance()->getEventDispatcher()
#define ED_ADD(target, notif, handler) gEventDispatcher->addEventListenerWithSceneGraphPriority(EventListenerCustom::create(notif, handler), target);

#endif
