#ifndef __TOOLS_H__
#define __TOOLS_H__

#include "cocos2d.h"
USING_NS_CC;

/*
��ʱ��
��飺��ʱ��
ʹ�ã�start�������������أ��޲����Ľ���ʱ���в����Ĵ��� ��ʱʱ�䣬�ص����� ��
*/
class CallbackTimeCounter : public Node
{
public:
	CREATE_FUNC(CallbackTimeCounter);
	virtual bool init();
	virtual void update(float dt);
	void start(float CBtime, std::function<void()> func);//��ʱ�ӻص�
	void start();//����ʱ
	float getTime();
	bool isCounting();
private:
	float m_Time;
	float m_CBTime;
	bool m_isCounting;

	std::function<void()> m_func;

};
/******************************************************************/

class RandomProducer : public Node
{
public:
	CREATE_FUNC(RandomProducer);
	static RandomProducer* getInstance();
	virtual bool init();
	int getRandom(int start, int end);
private:
	unsigned int m_randseed;
};


#endif