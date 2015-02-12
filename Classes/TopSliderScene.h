//
//  TopSliderScene.h
//  Slider
//
//  Created by MAEDAHAJIME on 2015/02/11.
//
//

#ifndef __Slider__TopSliderScene__
#define __Slider__TopSliderScene__

#include "cocos2d.h"
USING_NS_CC;

class TopSliderScene :public Layer
{
protected:
    // コンストラクタ
    TopSliderScene();
    // デストラクタ
    virtual ~TopSliderScene();
    // メソッド CREATE_FUNCとの連携
    bool init() override;
    
public:
    static cocos2d::Scene* createScene();
    
    CREATE_FUNC(TopSliderScene);
};

#endif /* defined(__Slider__TopSliderScene__) */
