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
class BaseTower                 //炮塔基类
{
	friend class BaseMonster;   //怪兽基类为友元
public:
	//构造函数初始化列表
	BaseTower(int x, int y) : mX(x), mY(y), lX(x + unit / 2), lY(y + unit / 2), grade(1), range(unit*1.8), curImage1(new IMAGE()), curImage2(new IMAGE()), targetMonster(){};
	
	virtual void draw()=0;
	//判断是否在范围内
	bool checkRange(shared_ptr<BaseMonster>monster) const;
	void addMonster(shared_ptr<BaseMonster>monster);  //将进入攻击范围的怪物添加到set中
	//升级提示、范围表示
	void remind();                                    //显示升级提示
	void drawCircle();                                //画圆显示攻击范围
	virtual void upgrade()=0;
	//前者用于自动改变目标，后者用于更改为鼠标指定的目标
	virtual void resetTarget();
	void resetTarget(shared_ptr<BaseMonster>monster); //重新设置攻击目标
	virtual void fire()=0;                            //发射攻击
	shared_ptr<BaseMonster>targetMonster;             //当前被攻击的怪物对象
	unordered_set<shared_ptr<BaseMonster>>set;        //用于存储在攻击范围内的怪物集合
	virtual ~BaseTower();
protected:
	const int mX, mY;                                            
	const int lX, lY;                                 //炮塔左上角坐标
	int range;                                        //炮塔攻击范围
	int grade;                                        //炮塔等级
	int fireTime = 0;                                 //攻速(防御塔攻击冷却时间)
	int remindTime = 0;                               //防御塔升级的显示时间

	shared_ptr<IMAGE>curImage1,curImage2;             //炮塔子弹图像
};

class BaseTowerFactory
{
public:
	virtual shared_ptr<BaseTower> buildTower(int x,int y) = 0;//创建炮塔对象
};
