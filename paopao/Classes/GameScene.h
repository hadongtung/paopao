#ifndef __GameScene_SCENE_H__
#define __GameScene_SCENE_H__

#include "cocos2d.h"
#include "PaopaoSprite.h"

using namespace cocos2d;

class GameScene : public cocos2d::CCLayer
{
    
    CCSpriteBatchNode * _gameBatchNode;
    
    CCArray *_columns;
    CCArray *_matched;
    float _boxOffsetX;
    float _boxOffsetY;
    
    PaopaoSprite *_selected;
    PaopaoSprite *_invalid;
    
    //用于泡泡交换
    PaopaoSprite *_exchanged1;
    
    //效果们
    CCArray *_eliminatePool;
    int _eliminateIdx;
    
    float _blinkTimer;
    
    bool _isMute;
    bool _running;
    CCSize _screenSize;
    
    int _score;
    int _highestScore;
    
    //画面元素
    CCSprite *_backgroundBox;
    CCLabelBMFont * _scoreDisplay;
    CCLabelBMFont * _highestScoreDisplay;
    CCLabelBMFont * _messageDisplay;
    CCMenu * _bottomMenu;
    CCArray * _cheerStrings;
    
    void createGameScreen();
    void resetGame();
    
    CC_SYNTHESIZE(bool, _userInteractEnabled, UserInteractEnabled);
    
    //检查并将消除的泡泡打标记，如果有消除返回true
    bool markAnyMatched();
    void findMatched();
    //检查是否还存在进一步消除的可能
    bool hasCandidate();
    //根据xy得到泡泡
    PaopaoSprite *paopaoByXY(int x, int y);
    void removePaopaoFromScreen(PaopaoSprite *sender);
    int fillColumn(int idx);
    void afterFillDone(CCNode *sender);
    //交换
    void exchange(PaopaoSprite *selected1, PaopaoSprite *selected2, SEL_CallFuncND sel);
    void afterExchange(CCNode *sender, PaopaoSprite *paopao);
    void revertExchange(CCNode *sender, PaopaoSprite *paopao);
    
    void toggleMute();
    void cheerMessage();
    
public:
    
    void print();
    GameScene();
    ~GameScene();
    // Method 'init' in cocos2d-x returns bool, instead of 'id' in cocos2d-iphone (an object pointer)
    virtual bool init();

    // there's no 'id' in cpp, so we recommend to return the class instance pointer
    static cocos2d::CCScene* scene();

    // preprocessor macro for "static create()" constructor ( node() deprecated )
    CREATE_FUNC(GameScene);
    void update (float dt);
    virtual void ccTouchesBegan(CCSet* pTouches, CCEvent* event);
    
    //////
    void onEnterTransitionDidFinish();
    
    ////
    bool isMuted();
};

#endif // __GameScene_SCENE_H__
