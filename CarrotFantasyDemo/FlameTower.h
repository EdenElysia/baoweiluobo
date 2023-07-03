#pragma once
#include"BaseTower.h"
using namespace std;
extern const double unit;
extern vector<shared_ptr<IMAGE>>towerImgList;          //存储炮塔图像指针的容器
class BaseMonster;                                     
class BaseTower;
//太阳花炮台
class FlameTower :public BaseTower {
	friend class BaseMonster;
public:
	FlameTower(int x, int y) :BaseTower(x, y),damage(5),t(0)  {  
		curImage1 = towerImgList[10];                            //获取1级炮塔图像
		curImage2 = towerImgList[11];                            //获取2级炮塔图像
	};
	virtual void draw();                                         //绘制炮塔
	virtual void upgrade();                                      //升级炮塔
	virtual void fire();                                         //发射炮弹
private:
	int damage;                                                  //攻击力
	double t;                                                    //控制攻击间隔（攻速）
};

class FlameTowerFactory :public BaseTowerFactory                //太阳花炮塔工厂类
{
public:
	virtual shared_ptr<BaseTower> buildTower(int x, int y)    
	{
		return make_shared<FlameTower>(x, y);                  //返回一个太阳花炮塔类对象指针
	}
};