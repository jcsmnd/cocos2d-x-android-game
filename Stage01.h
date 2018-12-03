//------ 작성자:김명식 ------- 최종작성일:2014년 5월 18일 일요일 --------//
#ifndef CR_Stage01
#define CR_Stage01

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

static CCDictionary s_dic;

class Stage01 : public CCLayer
{
public:
	virtual bool init();

	static CCScene* scene();

	CREATE_FUNC(Stage01);

	void update(float dt);

	//터치 메소드
	virtual void ccTouchesBegan(CCSet *pTouches, CCEvent *event);
	virtual void ccTouchesMoved(CCSet *pTouches, CCEvent *event);
	virtual void ccTouchesEnded(CCSet *pTouches, CCEvent *event);

	//백그라운드 노드
	CCNode *BackgroundNode;

	//배경음 1초후 재생
	void introTick();

	//타일맵
	CCTMXTiledMap *stageMap;
	CCPoint World;

	void createTileParallax();
	void scrollTiled();
	void textureLoading();
	void createBackground();
	void scrollBackground();

	void BGTiledscroll();
	void DelayScroll();

	//파티클
	CCParticleSystem *particle01;
	void Particle01();
	void Particle02();

	CCSprite *background1;
	CCSprite *cloud1;

	//점프 콜백 메소드
	void JumpEnd();

	//점프 여부
	bool jumpYN;

	//화면 사이즈
	CCSize winSize;

	//버튼 눌름 여부 확인
	bool isJumpPressed;

	//주인공
	CCSprite *candy;
	CCSprite *candyCollisionSprite;

	void createCandy();

	//게임 피니쉬,오버
	void CandyDead();
	void GameFinish();
	void GameOver();

	//뒤로가기 버튼
	void BackButton();
	void BackTouch(CCObject *sender);

	//터치시작
	void TouchStart();

	//스마트폰 뒤로가기 버튼
	virtual void keyBackClicked();

	void collisionCheck();

};
#endif
