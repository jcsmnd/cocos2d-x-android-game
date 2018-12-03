//------ 작성자:김명식 ------- 최종작성일:2014년 5월 18일 일요일 --------//
#include "Stage01.h"
#include "StageSelect.h"

CCScene* StageSelect::scene()
{
	CCScene* Scene = CCScene::create();
	StageSelect* Layer = StageSelect::create();
	Scene->addChild(Layer);
	return Scene;
}

bool StageSelect::init()
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

void StageSelect::CreateBackGround()
{
	CCSprite *BackGroundImage1 = CCSprite::create("background/stageselect.png");
	BackGroundImage1->setAnchorPoint(ccp(0,0));
	BackGroundImage1->setPosition(ccp(0,0));
	this->addChild(BackGroundImage1);
}

void StageSelect::CreateButton()
{
	CCMenuItemImage *stage01 = CCMenuItemImage::create(
			"button/s1.png",
			"button/s1d.png",
			this,
			menu_selector(StageSelect::stage01Touch)
	);
	stage01->setPosition(ccp(300,300));

	CCMenuItemImage *stage02 = CCMenuItemImage::create(
			"button/s2.png",
			"button/s2d.png",
			this,
			menu_selector(StageSelect::stage02Touch)
	);
	stage02->setPosition(ccp(600,300));

	CCMenuItemImage *stage03 = CCMenuItemImage::create(
			"button/s3.png",
			"button/s3d.png",
			this,
			menu_selector(StageSelect::stage03Touch)
	);
	stage03->setPosition(ccp(900,300));

	CCMenu *Menu = CCMenu::create(stage01,stage02,stage03,NULL);
	Menu->setPosition(ccp(0,0));
	this->addChild(Menu);
}

void StageSelect::stage01Touch(CCObject *sender)
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0f, Stage01::scene()));
}

void StageSelect::stage02Touch(CCObject *sender)
{

}

void StageSelect::stage03Touch(CCObject *sender)
{

}

void StageSelect::keyBackClicked()
{
	CCDirector::sharedDirector()->popScene();
}
