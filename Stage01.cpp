//------ 작성자:김명식 ------- 최종작성일:2014년 5월 18일 일요일 --------//
#include "Stage01.h"
#include "MainMenu.h"

using namespace cocos2d;

CCScene* Stage01::scene()
{
    CCScene *scene = CCScene::create();
    Stage01 *layer = Stage01::create();
    scene->addChild(layer);
    return scene;
}

bool Stage01::init()
{
	if(CCLayer::init()==false)
	{
		return false;
	}

    winSize = CCDirector::sharedDirector()->getWinSize();

    this->scheduleOnce(schedule_selector(Stage01::TouchStart),3.0f); //3초후 터치 활성화
    this->scheduleOnce(schedule_selector(Stage01::introTick), 0.3f); //배경음 0.3초뒤에 재생

    this->setKeypadEnabled(true); //스마트폰 키패드 활성화

    this->createTileParallax(); //타일생성(패럴렉스노드)
    this->createBackground(); //배경생성
    this->createCandy(); //주인공생성
    this->DelayScroll(); //3초후 스크롤 시작
    //this->Particle01();

	scheduleUpdate();

    return true;
}

void Stage01::update(float dt) //dt(델타타임) == 초당 60번 호출
{
	CCNode *tildNode = this->getChildByTag(1);
	CCNode *worldCandy = candy;
	CCPoint candyPoint;

	candyPoint = tildNode->convertToNodeSpace(worldCandy->getPosition());
	candyCollisionSprite = CCSprite::create("candy/candy01.png");
	candyCollisionSprite->setScale(0.3);
	candyCollisionSprite->setPosition(candyPoint);

	CCLog("candy.x = %.1f",candyCollisionSprite->getPosition().x);

	if(tildNode->getPosition().x <= -20320){ //스테이지 클리어
		unscheduleAllSelectors();
		CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(2.0f, MainMenu::scene()));
	}

	//particle01->setPosition(ccp(candy->getPosition().x-10, candyCollisionSprite->getPosition().y-20));

	collisionCheck();
}

void Stage01::TouchStart() //터치 시작
{
	this->setTouchEnabled(true);
}

void Stage01::DelayScroll() //배경 스크롤링 지연
{
    //배경 3초뒤에 스크롤링
    CCDelayTime *delayAction = CCDelayTime::create(3.0f);
    CCCallFunc *callSelectorAction1 = CCCallFunc::create(this,callfunc_selector(Stage01::BGTiledscroll));
    this->runAction(CCSequence::create(delayAction,callSelectorAction1,NULL));
}

void Stage01::BGTiledscroll() //배경스크롤
{
	this->schedule(schedule_selector(Stage01::scrollBackground));
	this->schedule(schedule_selector(Stage01::scrollTiled));
}

void Stage01::introTick() //배경음 시작
{
	SimpleAudioEngine::sharedEngine()->playBackgroundMusic("music/stage01.mp3", true);
}

void Stage01::createCandy() //주인공 생성
{
	CCTexture2D *texture = CCTextureCache::sharedTextureCache()->addImage("candy/candy.png");
	CCAnimation *animation = CCAnimation::create();
	animation->setDelayPerUnit(0.03);
	for(int i=0;i<12;i++){
		animation->addSpriteFrameWithTexture(texture,CCRectMake(i*106,0,106,106.5));
	}
	candy = CCSprite::createWithTexture(texture, CCRectMake(0,0,106,106));
	candy->setPosition(ccp(400,180));
	candy->setScale(0.7);
	this->addChild(candy,2);

	CCAnimate *animate = CCAnimate::create(animation);
	CCAction* rep = CCRepeatForever::create(animate);
	candy->runAction(rep);

	CCActionInterval *Blink = CCBlink::create(3,9);
	candy->runAction(Blink);
}

void Stage01::textureLoading() //로딩기능(아직 미구현)
{
   // CCTextureCache::sharedTextureCache()->addImageAsync("background/background1.png", this, callfuncO_selector(TextureCacheTest::loadingCallBack));
   // CCTextureCache::sharedTextureCache()->addImageAsync("background/background2.png", this, callfuncO_selector(TextureCacheTest::loadingCallBack));
}

void Stage01::createTileParallax() //타일 생성(패럴렉스 노드)
{
	//타일맵
	stageMap = CCTMXTiledMap::create("tiled/stage01.tmx");
	stageMap->setAnchorPoint(ccp(0,0));
	CCParallaxNode* BackgroundNode = CCParallaxNode::create();
	BackgroundNode->addChild(stageMap,2,ccp(1.0f,0.0f),ccp(0,0));
	BackgroundNode->setTag(1);
	this->addChild(BackgroundNode,2);
}

void Stage01::scrollTiled() //타일 움직임
{
	CCNode *BackgroundNode = this->getChildByTag(1);
	BackgroundNode->setPosition(ccp(BackgroundNode->getPosition().x-8, BackgroundNode->getPosition().y));
}

void Stage01::createBackground() //배경 생성
{
	background1 = CCSprite::create("background/background1.png");
	background1->setAnchorPoint(ccp(0,0));
	background1->setPosition(ccp(0,0));

	CCSprite* background2 = CCSprite::create("background/background1.png");
	background2->setAnchorPoint(ccp(0,0));
	background2->setPosition(ccp(background1->getContentSize().width,0));

	cloud1 = CCSprite::create("background/cloud1.png");
	cloud1->setAnchorPoint(ccp(0,0));
	cloud1->setPosition(ccp(0,0));

	CCSprite* cloud2 = CCSprite::create("background/cloud1.png");
	cloud2->setAnchorPoint(ccp(0,0));
	cloud2->setPosition(ccp(cloud1->getContentSize().width,0));

	this->addChild(background1,1);
	background1->addChild(background2,1);

	this->addChild(cloud1,0);
	cloud1->addChild(cloud2,1);
}

void Stage01::scrollBackground() //배경과 구름 무한 스크롤
{
	background1->setPosition(ccp(background1->getPosition().x-3, 0));

	if (background1->getPosition().x < -background1->getContentSize().width){
		background1->setPosition(ccp(0,0));
	}

	cloud1->setPosition(ccp(cloud1->getPosition().x-1, 0));

	if (cloud1->getPosition().x < -cloud1->getContentSize().width){
		cloud1->setPosition(ccp(0,0));
	}
}

void Stage01::ccTouchesBegan(CCSet *pTouches, CCEvent* event) //스마트폰 화면에 터치시 호출
{
	CCSetIterator it = pTouches->begin();
	CCTouch* touch = (CCTouch*)(*it);
	CCPoint touchPoint = touch->getLocation();

	if(jumpYN==false){
		jumpYN=true;
		SimpleAudioEngine::sharedEngine()->playEffect("music/jump_02.ogg"); //효과음 출처 http://opengameart.org/content/platformer-jumping-sounds
		CCActionInterval *Jump=CCJumpBy::create(0.5f,ccp(0,0),130,1); //속도,위치,높이,점프 횟수
		CCCallFunc *JumpEndCallback = CCCallFunc::create(this, callfunc_selector(Stage01::JumpEnd));
		candy->runAction(CCSequence::create(Jump,JumpEndCallback,NULL));
	}
}

void Stage01::ccTouchesMoved(CCSet *pTouches, CCEvent* event) //스마트폰 화면에 터치한 상태에서 드래그시 호출
{

}

void Stage01::ccTouchesEnded(CCSet *pTouches,CCEvent *event) //스마트폰 화면에서 터치를 땠을때 호출
{

}

void Stage01::JumpEnd() //점프 콜백용
{
	jumpYN = false;
}

void Stage01::keyBackClicked() //스마트폰 뒤로가기 터치시
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(1.0f, MainMenu::scene()));
}

void Stage01::Particle01() //파티클 효과1
{
	particle01 = CCParticleSystemQuad::create("particle/ex01/particle02.plist");
	particle01->setScale(0.5);
	this->addChild(particle01,1);
}

void Stage01::Particle02() //파티클 효과2
{
	CCParticleSystem *particle02 = CCParticleSystemQuad::create("particle/ex01/particle01.plist");
	particle02->setPosition(candy->getPosition());
	this->addChild(particle02,2);
}

void Stage01::CandyDead() //캔디 사망 효과
{
	candy->setVisible(false);
	this->setTouchEnabled(false);
	Particle02();
	unscheduleAllSelectors();
	this->scheduleOnce(schedule_selector(Stage01::GameOver),2.0f);
}

void Stage01::GameOver() //게임 오버
{
	CCDirector::sharedDirector()->replaceScene(CCTransitionFade::create(0.5f, Stage01::scene()));
}

void Stage01::collisionCheck() //함정 충돌 체크
{
	CCTMXLayer *blocklayer = stageMap->layerNamed("floor");

	CCSprite *trap01 = blocklayer->tileAt(ccp(26,7));
	if(candyCollisionSprite->boundingBox().intersectsRect(trap01->boundingBox())) CandyDead();

	CCLog("trap01.x = %.1f",trap01->getPosition().x);
}