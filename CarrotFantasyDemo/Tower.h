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
//ƿ�����࣬���ɵ�����Ŀ���ӵ�
class Tower :public BaseTower{
	friend class Monster;
public:
	Tower(int x, int y) :BaseTower(x,y){
		curImage1 =towerImgList[2];
		curImage2 = towerImgList[3];
	};
	//��̨����Ŀ�����λ�ý���ת��
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
