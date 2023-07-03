#include "BaseBullet.h"
void BaseBullet::move()
{
	//如果移动过程中怪物死亡，那么标记该子弹即将销毁
	if (!monsterList.count(targetMonster))
	{
		f = 0;
		return;
	};
	//目标坐标获取，并据此求得x，y方向速度
	pair<double, double>targetLocation = targetMonster->getLocation();        //获取当前怪物目标
	double targetX = targetLocation.first, targetY = targetLocation.second;
	double disX = targetX - this->lX, disY = targetY - this->lY;             
	double dis = sqrt(disX * disX + disY * disY);                             
	//判断是否碰撞
	if (dis <= 30)
	{

		f = 0;
		int damage = grade * 10;                                             //伤害
		hitMonster();
		return;
	}
	
	this->lX += (double)speed * disX / dis;
	this->lY += (double)speed * disY / dis;
	this->mX = this->lX - 10;      
	this->mY = this->lY - 10;
}

void BaseBullet::draw()                      
{
	move();
	putimage(mX, mY, curImage1.get(), SRCAND);          //从子弹容器中获取图像，打印到对应的坐标
	putimage(mX, mY, curImage2.get(), SRCPAINT);
}

BaseBullet::BaseBullet(double x, double y, int gra, shared_ptr<BaseMonster>target) :mX(x), mY(y), lX(x + 10), lY(y + 10), grade(gra), targetMonster(target), f(1) {
};   //构造函数 形参；坐标，等级，怪物对象指针

bool BaseBullet::checkHit() { return f; }                        //检测是否碰撞
void BaseBullet::hitMonster() { return; };

