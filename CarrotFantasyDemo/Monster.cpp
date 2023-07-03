#include "Monster.h"
void Monster::move()
{
	if (freeTime > 0)
	{
		if(--freeTime==0) frozen=0;

	}
	int speed = frozen ? this->speed/2 : this->speed;
	if (step == 0)
	{
		mY += speed;
		if (mY >= 6 * (double)unit) step++;
	}
	else if (step == 1)
	{
		mX += speed;
		if (mX >= 5 * (double)unit)step++;
	}
	else if (step == 2)
	{
		mY -= speed;
		if (mY <= 4 * (double)unit)step++;
	}
	else if (step == 3)
	{
		mX += speed;
		if (mX >= 7 * (double)unit)step++;
	}
	else if (step == 4)
	{
		mY -= speed;
		if (mY <= 2 * (double)unit)step++;
	}
	else if (step == 5)
	{
		mX += speed;
		if (mX >= 8 * (double)unit)step++;
	}
	else if (step == 6)
	{
		mY += speed;
		if (mY >= 3 * (double)unit)step++;
	}
	else if (step == 7)
	{
		mX += speed;
		if (mX >= 10 * (double)unit)step++;
	}
	if (step == 8) dam = 1;
	lX = mX + width/2;
	lY = mY + height/2;
	this->distance += speed;
	for (auto& tow : towerList)
	{
		for (auto&t : tow)
		{
			if (!t) continue;
			t->addMonster(shared_ptr<BaseMonster>(shared_from_this()));
		}
		
	}
}
Monster::~Monster() {
	for (auto& t : towerList)
	{
		for (auto& tow : t)
		{
			if (!tow) continue;
			if (tow->targetMonster.get() == this) tow->targetMonster.reset();
		}
		
	}
}
void Monster::draw()//绘制怪物图像
{
	move();
	//绘制血条
	rectangle(mX + unit/10-1, mY - unit/10-1, mX + unit+1, mY + 1);
	setfillcolor(RED);
	solidrectangle(mX + unit/10, mY - unit/10, mX + unit, mY);
	setfillcolor(GREEN);
	solidrectangle(mX + unit/10, mY - unit/10, mX + unit - 0.9*unit * (1 - curHealth / maxHealth), mY);
	
	if (time < 5)
	{
		putimage(mX, mY, mImg[0].get(), SRCAND);
		putimage(mX, mY, mImg[1].get(), SRCPAINT);
	}
	else
	{
		putimage(mX, mY, mImg[2].get(), SRCAND);
		putimage(mX, mY, mImg[3].get(), SRCPAINT);
	}
	//被冻结进入绘制冻结图片
	if (frozen)
	{
		putimage(mX+unit/10, mY + unit/2, monsterImgList[0][0].get(), SRCAND);
		putimage(mX+unit/10, mY + unit/2, monsterImgList[0][1].get(), SRCPAINT);
	}
	time++;
	if (time == 10) time = 0;
}
//实例化怪物对象，并返回对象指针
shared_ptr<BaseMonster> Breed1Factory::buildMonster()
{
	return make_shared<Breed1>();
}
shared_ptr<BaseMonster> Breed2Factory::buildMonster()
{
	return make_shared<Breed2>();
}
shared_ptr<BaseMonster> Breed3Factory::buildMonster()
{
	return make_shared<Breed3>();
}
shared_ptr<BaseMonster> Breed4Factory::buildMonster()
{
	return make_shared<Breed4>();
}
shared_ptr<BaseMonster> Breed5Factory::buildMonster()
{
	return make_shared<Breed5>();
}
shared_ptr<BaseMonster> Breed6Factory::buildMonster()
{
	return make_shared<Breed6>();
}