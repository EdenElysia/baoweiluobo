#include "BaseTower.h"
//�жϷ�Χ
bool BaseTower::checkRange(shared_ptr<BaseMonster>monster) const
{
	double d = (double)range * (double)range;
	double d1 = (monster->mX - this->lX) * (monster->mX - this->lX) + (monster->mY - this->lY) * (monster->mY - this->lY);
	double d2 = (monster->mX+monster->width - this->lX) * (monster->mX + monster->width - this->lX) + (monster->mY - this->lY) * (monster->mY - this->lY);
	double d3 = (monster->mX - this->lX) * (monster->mX - this->lX) + (monster->mY+ monster->height - this->lY) * (monster->mY + monster->height - this->lY);
	double d4 = (monster->mX + monster->width - this->lX) * (monster->mX + monster->width - this->lX) + (monster->mY + monster->height - this->lY) * (monster->mY + monster->height - this->lY);
	return d >= d1|| d>= d2|| d >= d3 || d >= d4 ;
}

void BaseTower::addMonster(shared_ptr<BaseMonster>monster)
{
	if (++remindTime >= 80) remindTime = 0;  //��ʾ������ʱ��                   
	if (checkRange(monster)) set.insert(monster);
	else if (set.count(monster)) //����ù����߳�����Χ����̨��Ŀ��Ҳ�Ǵ˹����Ŀ������ÿ�
	{
		if (this->targetMonster.get() == monster.get()) this->targetMonster.reset();
		set.erase(monster);
	}
}

void BaseTower::resetTarget()
{
	//��Ŀ�����Ϊ�գ����ڼ�������Ѱ��ǰ��Ĺ�����Ϊ��Ŀ��
	if (!this->targetMonster)
	{
		int maxDistance = 0;
		for (auto& monster : set)
		{
			if (!monster) set.erase(monster);
			if (monster->getDistance() > maxDistance)
			{
				targetMonster = monster;
				maxDistance = monster->getDistance();
			}
		}
	}
}

void BaseTower::drawCircle()
{
	setlinestyle(PS_SOLID, 1);
	setlinecolor(BLACKNESS);
	circle(lX, lY, range);
}
//���¹�����Χ��Ŀ��
void BaseTower::resetTarget(shared_ptr<BaseMonster>monster)
{
	if (checkRange(monster)) this->targetMonster = monster;
}

void BaseTower::remind()
{
	if ((grade == 1 && gold >= 180)|| (grade == 2 && gold >= 220))
	{
		if (remindTime >= 40)
		{
			putimage(mX+unit/3, mY-unit/3,  towerImgList[24].get(), SRCAND);
			putimage(mX+ unit / 3, mY- unit / 3, towerImgList[25].get(),  SRCPAINT);
		}
		else
		{
			putimage(mX+ unit / 3, mY-unit/3,  towerImgList[26].get(),  SRCAND);
			putimage(mX+ unit / 3, mY-unit/3,  towerImgList[27].get(), SRCPAINT);
		}
	}
}

BaseTower::~BaseTower()
{

}