//------ 작성자:김명식 ------- 최종작성일:2014년 5월 18일 일요일 --------//
#ifndef CR_Option
#define CR_Option

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;
//static CCDictionary s_dic;

class Option : public CCLayer{
public:
	virtual bool init();

	static CCScene *scene();

	CREATE_FUNC(Option);

	void CreateBackGround();
	void CreateButton();

	void SoundTouch(CCObject *sender);
	void EffectTouch(CCObject *sender);
	void SpriteIntroduceTouch(CCObject *sender);

	void introTick();

	virtual void keyBackClicked();
};
#endif
