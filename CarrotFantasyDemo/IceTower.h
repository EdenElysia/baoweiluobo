#pragma once
#include"BaseTower.h"
#include "IceBullet.h"
#include "Tower.h"
using namespace std;
extern const double unit;
class IceBullet;
class Tower;
class BaseBullet;
extern vector<shared_ptr<IMAGE>>towerImgList;    
extern list<shared_ptr<BaseBullet>>bulletList;
class Monster;
class BaseTower;
class IceTower :public BaseTower {
	friend class Monster;
public:
	IceTower(int x, int y) :BaseTower(x, y) {
		curImage1 = towerImgList[18];     
		curImage2 = towerImgList[19];
	};
	virtual void draw();
	virtual void upgrade();
	virtual void fire();
};

class IceTowerFactory :public BaseTowerFactory
{
public:
	virtual shared_ptr<BaseTower> buildTower(int x, int y)
	{
		return make_shared<IceTower>(x, y);
	}
};