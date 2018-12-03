//------ 작성자:김명식 ------- 최종작성일:2014년 5월 18일 일요일 --------//
#ifndef CR_StageSelect
#define CR_StageSelect

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;

//static CCDictionary s_dic;

class StageSelect : public CCLayer{
public:
	virtual bool init();

	static CCScene *scene();

	CREATE_FUNC(StageSelect);

	void CreateBackGround();
	void CreateButton();

	virtual void keyBackClicked();

	void stage01Touch(CCObject *sender);
	void stage02Touch(CCObject *sender);
	void stage03Touch(CCObject *sender);

	void introTick();
};
#endif
