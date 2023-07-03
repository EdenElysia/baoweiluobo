#pragma once
#include<vector>
#include "BaseMonster.h"
class BaseTower;
using namespace std;
extern const double unit;
extern vector<vector<shared_ptr<BaseTower>>>towerList;
extern vector<vector<shared_ptr<IMAGE>>>monsterImgList;
class Monster:public BaseMonster{
public:
	
	Monster(vector<shared_ptr<IMAGE>>img, int w, int h,int health,int s, int b = 90,int sX = startX, int sY = startY) :BaseMonster(img,w,h,health,b,sX,sY),speed(s){};
	void move();                                   //移动怪物
	void draw();                                   //绘图
	                                               //被攻击
	virtual void getHit(int damage)               
	{
		this->curHealth -= min(damage,(int)curHealth);//当前血量-=攻击力/当前血量的最小值
	}
	//检测生命状态
	virtual int checkHealth()     
	{ 
		if (dam==1) return 2;                         
		if (curHealth==0) return 1;                 //当前生命值为0返回1，表示死亡
		return 0;
	}
	pair<double,double> getLocation() { return { this->lX,this->lY }; } //返回怪物图像左上角坐标
	int getDistance() { return this->distance; }                        //返回走过的距离
	virtual void getFrozen() { 
		this->frozen = 1;                                               //冻结状态
		this->freeTime = 40;                                            //持续时间
	};
	//用于范围冰冻的判断
	bool checkLoc(shared_ptr<BaseMonster>m, double range)
	{
		auto p1 = this->getLocation(), p2 = m->getLocation();
		return (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second) <= range * range;
	}
	~Monster();
private:
	int time = 0;                                             //记录怪物移动时间计时器
	int step = 0;                                             //记录怪物移动的步数
	int speed;                                                //怪物移动速度
	bool frozen = 0;                                          //判断是否冰冻
	int freeTime = 0;                                         //冰冻剩余时间
	int dam = 0;                                              //怪物能造成的伤害
};
//不同的怪物种类
class Breed1 :public Monster {
public:
	Breed1() :Monster(monsterImgList[1], unit, 0.4*unit,3*unit,0.04*unit) {};
};

class Breed2 :public Monster {
public:
	Breed2() :Monster(monsterImgList[2], unit, 0.4*unit,2*unit,0.1*unit) {};
};

class Breed3 :public Monster {
public:
	Breed3() :Monster(monsterImgList[3], unit, 0.4 * unit, 4 * unit, 0.06 * unit) {};
};

class Breed4 :public Monster {
public:
	Breed4() :Monster(monsterImgList[4], unit, 0.4 * unit, 3 * unit, 0.08 * unit) {};
};

class Breed5 :public Monster {
public:
	Breed5() :Monster(monsterImgList[5], unit, 0.4 * unit, 5 * unit, 0.08 * unit) {};
};

class Breed6 :public Monster {
public:
	Breed6() :Monster(monsterImgList[6], unit, 0.4 * unit, 10 * unit, 0.05 * unit,unit*1.3) {};
};

class Breed1Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster>buildMonster();
};

class Breed2Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster();
};

class Breed3Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster();
};

class Breed4Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster();
};

class Breed5Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster();
};

class Breed6Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster();
};