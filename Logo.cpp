//------ 작성자:김명식 ------- 최종작성일:2014년 5월 18일 일요일 --------//
#include "MainMenu.h"
#include "Logo.h"

CCScene* Logo::scene()
{
	CCScene* Scene = CCScene::create();
	Logo* Layer = Logo::create();
	Scene->addChild(Layer);
	return Scene;
}

bool Logo::init()
{
	if(CCLayer::init()==false)
	{
		return false;
	}

	CCSprite *BackGroundImage = CCSprite::create("background/logo.png");
	BackGroundImage->setAnchorPoint(ccp(0,0));
	this->setPosition(ccp(0,0));
	this->addChild(BackGroundImage,0);
	this->scheduleOnce(schedule_selector(Logo::introTick), 3.0f);

	return true;
}

void Logo::introTick()
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0f, MainMenu::scene()));
}
