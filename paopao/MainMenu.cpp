//
//  MainMenu.cpp
//  paopao
//
//  Created by gavin on 14-2-12.
//
//

#include "MainMenu.h"
#include "GameScene.h"


using namespace cocos2d;

CCScene *MainMenu::scene()
{
    CCScene *scene = CCScene::create();
    
    MainMenu *layer = MainMenu::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool MainMenu::init()
{
    //super init
    if (!CCLayer::init()) {
        return false;
    }
    
    CCSize size = CCDirector::sharedDirector()->getWinSize();
    // CCMenuItem
    CCMenuItemImage *imageItemStart=CCMenuItemImage::create("restart_btn.png", "restart_btn.png",this,menu_selector(MainMenu::menu_game_start));
//    imageItemStart->setPosition(ccp( size.width/2 , size.height/2));
    imageItemStart->setPosition(CCPointZero);
    
    CCMenuItemImage *imageItemSet=CCMenuItemImage::create("restart_btn.png", "restart_btn.png",this,menu_selector(MainMenu::menu_game_seting));
    imageItemSet->setPosition(ccp(0, size.height/4));
    
    CCMenuItemImage *imageItemExit=CCMenuItemImage::create("restart_btn.png", "restart_btn.png",this,menu_selector(MainMenu::menu_game_exit));
    imageItemExit->setPosition(ccp(0, size.height/8));
    
    
    
    CCMenu *menu = CCMenu::create(imageItemStart,imageItemSet,imageItemExit,NULL);
    addChild(menu);
    
    return true;
}


void MainMenu::menu_game_start()
{
    CCLog("game start ~~");
    CCScene *pScene = GameScene::scene();
    CCTransitionFade* transitionScene = CCTransitionFade::create(1.0, pScene,ccWHITE);
    CCDirector::sharedDirector()->replaceScene(transitionScene);
}

void MainMenu::menu_game_seting()
{
    CCLog("seting ~~ ");
}

void MainMenu::menu_game_exit()
{
    CCLog("exit ~~");
}

