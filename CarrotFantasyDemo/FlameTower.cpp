#include "FlameTower.h"

void FlameTower::draw()
{

	//攻击特效的绘制
	t+= 10;
	if (t >= range) t = 0;
	IMAGE fImg0;
	IMAGE fImg1;
	loadimage(&fImg1, L"picture/tower/flame0.png", 2*t, 2*t);
	loadimage(&fImg0, L"picture/tower/flame1.png", 2*t, 2*t);
	fireTime++;
	if (fireTime == 10)
	{
		fireTime = 0;
		fire();
	}
	if (!set.empty())
	{
		putimage(lX - t, lY - t, 2 * t, 2 * t, &fImg0, 2, 2, SRCAND);
		putimage(lX - t, lY - t, 2 * t, 2 * t, &fImg1, 2, 2, SRCPAINT);
	}
	putimage(mX, mY, 96, 96, towerImgList[8].get(), 2, 2, SRCAND);
	putimage(mX, mY, 96, 96, towerImgList[9].get(), 2, 2, SRCPAINT);
	putimage(mX, mY, 96, 96, curImage1.get(), 2, 2, SRCAND);
	putimage(mX, mY, 96, 96, curImage2.get(), 2, 2, SRCPAINT);
	//根据灯具绘制不同的炮塔
	switch (grade)  
	{
	case 1:
		curImage1 = towerImgList[10];
		curImage2 = towerImgList[11];
		break;
	case 2:
		curImage1 = towerImgList[12];
		curImage2 = towerImgList[13];
		break;
	case 3:
		curImage1 = towerImgList[14];
		curImage2 = towerImgList[15];
		break;
	default:
		break;
	}
	
}
//攻击方式为在其范围内的怪物均收到持续伤害
void FlameTower::fire()
{
	if (!set.empty())
	{
		for (auto& mon : set)
		{
			mon->getHit(damage);
		}
	}
}

void FlameTower::upgrade()
{
	if (grade == 1)
	{
		grade = 2;
		damage += 3;
		range += 10;
	}
	else if (grade == 2)
	{
		damage += 5;
		grade = 3;
		range += 10;
	}
}