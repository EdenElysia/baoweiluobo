#pragma once
#include <easyx.h>
#include <conio.h>
#include <graphics.h>
#include"BaseMonster.h"
#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<unordered_set>
#include"BaseBullet.h"
using namespace std;
extern const double unit;
class BaseBullet;
extern vector<shared_ptr<IMAGE>>towerImgList;
extern list<shared_ptr<BaseBullet>>bulletList;
extern int gold;
class BaseMonster;
class BaseTower                 //��������
{
	friend class BaseMonster;   //���޻���Ϊ��Ԫ
public:
	//���캯����ʼ���б�
	BaseTower(int x, int y) : mX(x), mY(y), lX(x + unit / 2), lY(y + unit / 2), grade(1), range(unit*1.8), curImage1(new IMAGE()), curImage2(new IMAGE()), targetMonster(){};
	
	virtual void draw()=0;
	//�ж��Ƿ��ڷ�Χ��
	bool checkRange(shared_ptr<BaseMonster>monster) const;
	void addMonster(shared_ptr<BaseMonster>monster);  //�����빥����Χ�Ĺ�����ӵ�set��
	//������ʾ����Χ��ʾ
	void remind();                                    //��ʾ������ʾ
	void drawCircle();                                //��Բ��ʾ������Χ
	virtual void upgrade()=0;
	//ǰ�������Զ��ı�Ŀ�꣬�������ڸ���Ϊ���ָ����Ŀ��
	virtual void resetTarget();
	void resetTarget(shared_ptr<BaseMonster>monster); //�������ù���Ŀ��
	virtual void fire()=0;                            //���乥��
	shared_ptr<BaseMonster>targetMonster;             //��ǰ�������Ĺ������
	unordered_set<shared_ptr<BaseMonster>>set;        //���ڴ洢�ڹ�����Χ�ڵĹ��Ｏ��
	virtual ~BaseTower();
protected:
	const int mX, mY;                                            
	const int lX, lY;                                 //�������Ͻ�����
	int range;                                        //����������Χ
	int grade;                                        //�����ȼ�
	int fireTime = 0;                                 //����(������������ȴʱ��)
	int remindTime = 0;                               //��������������ʾʱ��

	shared_ptr<IMAGE>curImage1,curImage2;             //�����ӵ�ͼ��
};

class BaseTowerFactory
{
public:
	virtual shared_ptr<BaseTower> buildTower(int x,int y) = 0;//������������
};
