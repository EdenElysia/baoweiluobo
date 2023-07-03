#include "IceTower.h"


void IceTower::draw()
{
	fireTime++;
	if (fireTime == 15)
	{
		fireTime = 0;
		fire();
	}
	putimage(mX, mY, unit*2-4, unit * 2 - 4, towerImgList[16].get(), 2, 2, SRCAND);
	putimage(mX, mY, unit * 2 - 4, unit * 2 - 4, towerImgList[17].get(), 2, 2, SRCPAINT);
	putimage(mX, mY, unit * 2 - 4, unit * 2 - 4, curImage1.get(), 2, 2, SRCAND);
	putimage(mX, mY, unit * 2 - 4, unit * 2 - 4, curImage2.get(), 2, 2, SRCPAINT);
	switch (grade)
	{
	case 1:
		curImage1 = towerImgList[18];
		curImage2 = towerImgList[19];
		break;
	case 2:
		curImage1 = towerImgList[20];
		curImage2 = towerImgList[21];
		break;
	case 3:
		curImage1 = towerImgList[22];
		curImage2 = towerImgList[23];
		break;
	default:
		break;
	}
	
}

void IceTower::fire()
{
	resetTarget();
	if (!targetMonster) return;
	bulletList.push_back(make_shared<IceBullet>(this->lX - unit/6, this->lY - unit/6, grade, targetMonster));

}

void IceTower::upgrade()
{
	if (grade == 1)
	{
		grade = 2;
		range += unit/5;
	}
	else if (grade == 2)
	{
		grade = 3;
		range += unit/5;
	}
}