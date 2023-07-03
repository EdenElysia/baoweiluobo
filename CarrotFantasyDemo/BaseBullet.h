#pragma once
//#include"Monster.h"
#include <easyx.h>
#include <conio.h>
#include <graphics.h>
#include<vector>
#include<unordered_set>
#include"BaseMonster.h"
using namespace std;
class BaseMonster;
extern vector<shared_ptr<IMAGE>>bulletImgList;           //储存怪物图像指针的容器
extern unordered_set<shared_ptr<BaseMonster>>monsterList;//存储怪物对象指针的容器
//子弹基类
class BaseBullet {
public:
	//初始化，指定坐标、等级、目标怪物
	BaseBullet(double x, double y, int gra, shared_ptr<BaseMonster>target);
	//输出图片
	void draw();
	//判断是否与怪物碰撞
	bool checkHit();
	//碰撞函数
	virtual void hitMonster();
	//子弹（朝着怪物）移动
	void move();
protected:
	//目标怪物
	shared_ptr<BaseMonster>targetMonster;
	//速度，画图坐标，物理坐标
	double speed = 10, mX, mY, lX, lY;
	//子弹图片
	shared_ptr<IMAGE>curImage1, curImage2;
	//子弹等级
	int grade;
	//子弹伤害
	int damage;
	//碰撞判断
	bool f;
};
