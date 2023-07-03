#include"Tower.h"

void Tower::rotate()
{
	//依靠相对坐标计算转向角度
	if (!targetMonster) return;
	pair<int, int>targetLocation = targetMonster->getLocation();          //获取怪物当前坐标    
	int targetX = targetLocation.first, targetY = targetLocation.second;  //分别存放当前怪物横纵坐标
	const double pi = 3.14159;                                            //圆周率
	double radian;                                                        //弧
	double disX = this->lX - targetX, disY = this->lY - targetY;          //计算相对坐标
	if (disY == 0 && disX >= 0) radian = pi / 2;                          //
	else if (disY == 0 && disX < 0)radian = -pi / 2;
	else if (disY > 0) radian = atan(disX / disY);
	else radian = atan(disX / disY) + pi;
	rotateimage(curImage1.get(), curImage1.get(), radian, WHITE);         //旋转炮台
	rotateimage(curImage2.get(), curImage2.get(), radian, BLACK);         
}
void Tower::draw()
{
	
	fireTime++;
	if (fireTime == 4)
	{
		fireTime = 0;
		fire();
	}
	rotate();
	putimage(mX, mY, unit-2, unit-2, towerImgList[0].get(), 2, 2, SRCAND);  
	putimage(mX, mY, unit - 2, unit - 2, towerImgList[1].get(), 2, 2, SRCPAINT);
	putimage(mX, mY, unit - 2, unit - 2, curImage1.get(), 2, 2, SRCAND);
	putimage(mX, mY, unit - 2, unit - 2, curImage2.get(), 2, 2, SRCPAINT);
	switch (grade)
	{
	case 1:
		curImage1 = towerImgList[2];     //获取炮台图像
		curImage2 = towerImgList[3];
		break;
	case 2:
		curImage1 = towerImgList[4];
		curImage2 = towerImgList[5];
		break;
	case 3:
		curImage1 =towerImgList[6];
		curImage2 = towerImgList[7];
		break;
	default:
		break;
	}
}

void Tower::fire()
{                                       //重新设置攻击目标
	resetTarget();
	if (!targetMonster) return;         //怪物死亡停止开火
	                                    //实例化炮弹对象，并将指针存放到容器
	bulletList.push_back(make_shared<Bullet>(this->lX - unit / 6, this->lY - unit / 6, grade, targetMonster));
	
}

void Tower::upgrade()
{
	if (grade == 1)
	{
		grade = 2;         //升级
		range += 10;       //增加攻击范围
	}
	else if (grade == 2)
	{
		grade = 3;         //升级
		range += 20;       //增加攻击范围
	}
}
