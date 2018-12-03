//------ 작성자:김명식 ------- 최종작성일:2014년 5월 18일 일요일 --------//
#include "StageSelect.h"
#include "MainMenu.h"
#include "Option.h"

CCScene* MainMenu::scene()
{
	CCScene* Scene = CCScene::create();
	MainMenu* Layer = MainMenu::create();
	Scene->addChild(Layer);
	return Scene;
}

bool MainMenu::init()
{
	if(CCLayer::init()==false)
	{
		return false;
	}

	this->setKeypadEnabled(true);
	this->CreateBackGround();
	this->CreateButton();
	this->scheduleOnce(schedule_selector(MainMenu::introTick), 0.1f);

	return true;
}

void MainMenu::introTick()
{
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/mainmenu.ogg", true);
}

void MainMenu::CreateBackGround(){
	CCSprite *BackGroundImage = CCSprite::create("background/manimenu.png");
	BackGroundImage->setAnchorPoint(ccp(0,0));
	this->setPosition(ccp(0,0));
	this->addChild(BackGroundImage,0);
}

void MainMenu::CreateButton(){

	CCMenuItemImage *Start = CCMenuItemImage::create(
			"button/start1.png",
			"button/start2.png",
			this,
			menu_selector(MainMenu::StartTouch)
	);
	Start->setPosition(ccp(640,400));

	CCMenuItemImage *Option = CCMenuItemImage::create(
			"button/option1.png",
			"button/option2.png",
			this,
			menu_selector(MainMenu::OptionTouch)
	);
	Option->setPosition(ccp(640,250));

	CCMenuItemImage *Exit = CCMenuItemImage::create(
			"button/exit1.png",
			"button/exit2.png",
			this,
			menu_selector(MainMenu::ExitTouch)
	);
	Exit->setPosition(ccp(640,100));

	CCMenu *Menu = CCMenu::create(Start,Option,Exit,NULL);
	Menu->setPosition(ccp(0,0));
	this->addChild(Menu);
}

void MainMenu::StartTouch(CCObject *sender)
{
	CCDirector::sharedDirector()->pushScene(CCTransitionFade::create(0.5f, StageSelect::scene()));
}

void MainMenu::OptionTouch(CCObject *sender)
{
	CCDirector::sharedDirector()->pushScene(Option::scene());
}

void MainMenu::ExitTouch(CCObject *sender)
{
	CCDirector::sharedDirector()->end();
}

void MainMenu::keyBackClicked()
{
    //CCDirector::sharedDirector()->end();
}
