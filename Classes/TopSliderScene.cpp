//
//  TopSliderScene.cpp
//  Slider
//
//  Created by MAEDAHAJIME on 2015/02/11.
//
//

#include "TopSliderScene.h"
#include <ui/CocosGUI.h>
USING_NS_CC;     // cocos2d
using namespace ui;
using namespace std; // String*

// _/_/_/ コンストラクタ プロパティー _/_/_/
TopSliderScene::TopSliderScene()
{
    
}

// MainScene デストラクタで解放 メモリーリークを防ぐ
TopSliderScene::~TopSliderScene()
{
    
}

// createSceneはLayerをSceneに貼り付けて返すクラスメソッドです。
// 自分自身(TopSliderScene)を生成し、空のSceneに貼り付けて返す簡単な処理を行っているだけです。
// これでほかのシーンからの遷移が楽に行えます。
Scene* TopSliderScene::createScene()
{
    
    auto scene = Scene::create();
    auto layer = TopSliderScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool TopSliderScene::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    
    // 画面サイズサイズを取得
    auto window_size = Director::getInstance()->getVisibleSize();
    
    // バックグランドカラー
    auto background = LayerColor::create(Color4B::BLUE,
                                         window_size.width,
                                         window_size.height);
    // バックグランドカラー 第2引数は表示順
    this->addChild(background, 0);
    
    
    // スライダーラベルを生成
    auto label1 = Label::createWithSystemFont("スライダー", "Arial", 80);
    // ラベルの色
    label1->setColor(Color3B::WHITE);
    // ラベルの設置
    label1->setPosition(Vec2(window_size.width / 2 ,window_size.height - 160));
    // ラベルタイトルを追加
    this->addChild(label1,1);
    
    // 0ラベルを生成
    auto label2 = Label::createWithSystemFont("0", "Arial", 80);
    // ラベルの色
    label2->setColor(Color3B::WHITE);
    // ラベルの設置
    label2->setPosition(Vec2(window_size.width / 2 - 289 ,window_size.height - 320));
    // ラベルタイトルを追加
    this->addChild(label2,1);
    
    // 100ラベルを生成
    auto label3 = Label::createWithSystemFont("100", "Arial", 80);
    // ラベルの色
    label3->setColor(Color3B::WHITE);
    // ラベルの設置
    label3->setPosition(Vec2(window_size.width / 2 + 289 ,window_size.height - 320));
    // ラベルタイトルを追加
    this->addChild(label3,1);
    
    
    auto slider = Slider::create();
    // スライダーバック画像
    slider->loadBarTexture("sliderTrack.png"); // 空のマップ
    // スライダーのボール
    slider->loadSlidBallTextures("sliderThumb.png", "", "");
    // スライダー進捗画像
    slider->loadProgressBarTexture("sliderProgress.png"); // 完全な姿
    // 配置位置
    slider->setPosition(Vec2(window_size.width / 2.0f,
                             window_size.height / 2.3f/* + slider->getSize().height * 3.0f*/));
    // スライダーの取得数値
    slider->addEventListener([](Ref* ref,Slider::EventType type){
        
        // スライダーのキャスト変換
        auto s = static_cast<Slider*>(ref);
        // 数値をログ表示
        log("数値 %d", s->getPercent());
        
        // スライダーのキャスト変換
        Slider* slider = dynamic_cast<Slider*>(ref);
        int percent = slider->getPercent();
        // 数値をログ表示
        log("percent 数値:%d",percent);
        
    });
    
    // スライダー表示
    addChild(slider);
    
    return true;
}
