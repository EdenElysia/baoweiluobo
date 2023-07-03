#pragma once
#include "BaseBullet.h"
using namespace std;
class BaseMonster;
extern vector<shared_ptr<IMAGE>>bulletImgList;            //存储炮弹图像指针的容器
extern unordered_set<shared_ptr<BaseMonster>>monsterList; //储存怪物对象指针的容器
//瓶子炮子弹
class Bullet:public BaseBullet{
public:
	Bullet(double x, double y, int gra, shared_ptr<BaseMonster>target) :BaseBullet(x,y,gra,target){
		curImage1 = bulletImgList[grade*2-2];   //获取炮弹图像
		curImage2 = bulletImgList[grade*2-1 ];  
		damage = 2*gra;                         //伤害
	};
	virtual void hitMonster()                    //击中怪物，造成伤害
	{
		targetMonster->getHit(damage);          
	}
};

