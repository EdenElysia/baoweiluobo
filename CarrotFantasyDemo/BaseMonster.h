
#pragma once
#include <easyx.h>            // 引用图形库头文件
#include <conio.h>
#include <graphics.h>
#include<iostream>
#include<vector>
#include "BaseTower.h"
class BaseTower;
using namespace std;
extern const double unit;                                           //单位长度
const int startX = unit * 1;                                        
extern vector<vector<shared_ptr<BaseTower>>>towerList;              //嵌套  炮塔对象指针的容器  不同炮塔列表
extern vector<shared_ptr<IMAGE>>centerImg;                          
const int startY = unit * 3;
class BaseMonster;
extern shared_ptr<BaseMonster>centerMonster;             
extern vector<vector<shared_ptr<IMAGE>>>propImgList;                
//怪物基类，也是道具类（道具=不会移动的怪物）
class BaseMonster :public enable_shared_from_this<BaseMonster> {
public:
	friend class BaseTower;
	BaseMonster(vector<shared_ptr<IMAGE>>& img, int w, int h, double health, int b = unit, int sX = startX, int sY = startY) :bodLen(b), width(w), height(h), mX(sX), mY(sY), lX(mX + width / 2), lY(mY + height / 2), mImg(img), maxHealth(health), curHealth(health), distance(0) {};
	virtual void draw();
	                                                                 //鼠标选取的怪物的特有画图操作
	void centerDraw();
	                                                                 //被攻击
	virtual void getHit(int damage);
	                                                                 //检测血量
	virtual int checkHealth();
	                                                                 //获取坐标
	pair<double, double> getLocation();
	                                                                 //获取行走的距离
	int getDistance();
	virtual bool checkLoc(shared_ptr<BaseMonster> m, double range);
	                                                                 //检测是否被冰冻
	virtual void getFrozen();
	                                                                 //检测是否被点击
	bool checkClick(int x, int y);
	                                                                 
	pair<int, int>getM();
	virtual ~BaseMonster();

protected:
	//图片、面积、坐标、行进距离、生命值
	vector<shared_ptr<IMAGE>>mImg;
	double width, height;                                            //怪物图像的宽高
	double mX, mY, lX, lY;                                           //图像左上角坐标及中心坐标
	int distance;                                                    //走过的距离
	double bodLen;                                                   //怪物身体长度
	double maxHealth;                                                //最大生命值
	double curHealth;                                                //当前生命值
};

class BaseBreed1 :public BaseMonster {
public:
	BaseBreed1();
};

class BaseBreed2 :public BaseMonster {
public:
	BaseBreed2();
};

class BaseBreed3 :public BaseMonster {
public:
	BaseBreed3();
};

class BaseBreed4 :public BaseMonster {
public:
	BaseBreed4();
};

class BaseBreed5 :public BaseMonster {
public:
	BaseBreed5();
};

class BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster() = 0;
};

class BaseBreed1Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster() override;
};

class BaseBreed2Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster()override;
};

class BaseBreed3Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster()override;
};

class BaseBreed4Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster()override;
};

class BaseBreed5Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster()override;
}; 