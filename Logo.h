//------ 작성자:김명식 ------- 최종작성일:2014년 5월 18일 일요일 --------//
#ifndef CR_Logo
#define CR_Logo

#include "cocos2d.h"
#include "SimpleAudioEngine.h"

using namespace cocos2d;
using namespace CocosDenshion;

class Logo : public CCLayer{
public:
	virtual bool init();
	static CCScene *scene();
	CREATE_FUNC(Logo);

	void introTick();
};

#endif
