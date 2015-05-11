#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include <list>
#include "cocos2d.h"
#include "Line.h"
#include "Grap.h"
#include "DataDefines.h"
#include "Shake.h"
#include "StopScene.h"

using namespace std;
USING_NS_CC;

class DigScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();


    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    void setTouchLayer(Layer* layer);

    void turnDown();

    void turnHorizen(int direction);

    void Shake(Ref* pSender);

    void addEnergy(Ref* pSender);

    bool Crash(list<Line*>::iterator nextLine,int nextverID);

    void updateHp(float dt);

    void pause();

    void fail();

    void Myresume();

    // implement the "static create()" method manually
    CREATE_FUNC(DigScene);
private:
    bool isPause;
    Grap* grap;
    list<Line*> vertical;
    list<Line*>::iterator currentLine;
    int verticalID;
    EventListenerTouchOneByOne* listener;
    Grap* virtualGrap;
    float hp;
    int score;
    Label* scoreLabel;
    ProgressTimer* progressTimer;
    Sprite* timer;
    Layer* stop;
    Sprite* blackBG;
};

#endif // __HELLOWORLD_SCENE_H__
