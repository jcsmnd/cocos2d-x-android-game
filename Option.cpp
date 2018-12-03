//------ 작성자:김명식 ------- 최종작성일:2014년 5월 18일 일요일 --------//
#include "MainMenu.h"
#include "Option.h"

CCScene* Option::scene()
{
	CCScene* Scene = CCScene::create();
	Option* Layer = Option::create();
	Scene->addChild(Layer);
	return Scene;
}

bool Option::init()
{
	if(CCLayer::init()==false)
	{
		return false;
	}

	this->setKeypadEnabled(true);
	this->CreateBackGround();
	this->CreateButton();

	return true;
}


void Option::CreateBackGround(){
	CCSprite *BackGroundImage = CCSprite::create("background/option.png");
	BackGroundImage->setAnchorPoint(ccp(0,0));
	this->setPosition(ccp(0,0));
	this->addChild(BackGroundImage,0);
}

void Option::CreateButton(){

	CCMenuItemImage *Sound = CCMenuItemImage::create(
			"button/on.png",
			"button/off.png",
			this,
			menu_selector(Option::SoundTouch)
	);
	Sound->setPosition(ccp(780,430));

	CCMenuItemImage *Effect = CCMenuItemImage::create(
			"button/on.png",
			"button/off.png",
			this,
			menu_selector(Option::EffectTouch)
	);
	Effect->setPosition(ccp(780,290));

	CCMenuItemImage *MemberIntroduce = CCMenuItemImage::create(
			"button/create.png",
			"button/create.png",
			this,
			menu_selector(Option::SpriteIntroduceTouch)
	);
	MemberIntroduce->setScale(2.0);
	MemberIntroduce->setPosition(ccp(640,150));

	CCMenu *Menu = CCMenu::create(Sound,Effect,MemberIntroduce,NULL);
	Menu->setPosition(ccp(0,0));
	this->addChild(Menu);
}

void Option::SoundTouch(CCObject *sender)
{

}

void Option::EffectTouch(CCObject *sender)
{

}

void Option::SpriteIntroduceTouch(CCObject *sender)
{

}

void Option::keyBackClicked()
{
	CCDirector::sharedDirector()->popScene();
}
