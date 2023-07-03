#pragma once
#include"BaseTower.h"
#include"Bullet.h"
using namespace std;
extern const double unit;
class Bullet;
class BaseBullet;
extern vector<shared_ptr<IMAGE>>towerImgList;
extern list<shared_ptr<BaseBullet>>bulletList;
class Monster;
class BaseTower;
//瓶子炮类，生成单体有目标子弹
class Tower :public BaseTower{
	friend class Monster;
public:
	Tower(int x, int y) :BaseTower(x,y){
		curImage1 =towerImgList[2];
		curImage2 = towerImgList[3];
	};
	//炮台随着目标怪物位置进行转向
	void rotate();
	virtual void draw();
	virtual void upgrade();
	virtual void fire();
};

class TowerFactory:public BaseTowerFactory
{
public:
	virtual shared_ptr<BaseTower> buildTower(int x,int y)
	{
		return make_shared<Tower>(x,y);
	}
};
