//------ 작성자:김명식 ------- 최종작성일:2014년 5월 18일 일요일 --------//
#ifndef CR_MainMenu
#define CR_MainMenu

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;
//static CCDictionary s_dic;

class MainMenu : public CCLayer{
public:
	virtual bool init();

	static CCScene *scene();

	CREATE_FUNC(MainMenu);

	void CreateBackGround();
	void CreateButton();

	void StartTouch(CCObject *sender);
	void OptionTouch(CCObject *sender);
	void ExitTouch(CCObject *sender);

	void introTick();

	virtual void keyBackClicked();
};
#endif
