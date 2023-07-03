#pragma once
#include "BaseBullet.h"
using namespace std;
class BaseMonster;
extern vector<shared_ptr<IMAGE>>bulletImgList;            //�洢�ڵ�ͼ��ָ�������
extern unordered_set<shared_ptr<BaseMonster>>monsterList; //����������ָ�������
//ƿ�����ӵ�
class Bullet:public BaseBullet{
public:
	Bullet(double x, double y, int gra, shared_ptr<BaseMonster>target) :BaseBullet(x,y,gra,target){
		curImage1 = bulletImgList[grade*2-2];   //��ȡ�ڵ�ͼ��
		curImage2 = bulletImgList[grade*2-1 ];  
		damage = 2*gra;                         //�˺�
	};
	virtual void hitMonster()                    //���й������˺�
	{
		targetMonster->getHit(damage);          
	}
};

