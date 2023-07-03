#pragma once
//#include"Monster.h"
#include "BaseBullet.h"
using namespace std;
class BaseMonster;
class BaseBullet;

extern vector<shared_ptr<IMAGE>>bulletImgList;               
extern unordered_set<shared_ptr<BaseMonster>>monsterList;  //存储怪物对象指针的容器
//冰冻塔，发射范围冰冻子弹
class IceBullet :public BaseBullet {
public:
	IceBullet(double x, double y, int gra, shared_ptr<BaseMonster>target) :BaseBullet(x,y,gra,target){
		curImage1 = bulletImgList[grade * 2 +4];      //1级冰冻炮弹图像
		curImage2 = bulletImgList[grade * 2 +5];      //2级冰冻炮弹图像
		damage = 2 * grade;                           //伤害
	};
	virtual void hitMonster();                        //子弹命中造成伤害并减速
};

