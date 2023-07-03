#include"BaseMonster.h"
BaseMonster::~BaseMonster() {};

void BaseMonster::draw()
{
	//ʵ�߱߿�
	setlinestyle(PS_SOLID, 1);   
	//��ɫ���
	setlinecolor(BLACKNESS);
	//Ѫ�����
	rectangle(mX + unit / 10 - 1, mY - unit / 10 - 1, mX + bodLen, mY + 1); 
	//��Ѫ����ɫ
	setfillcolor(RED);
	//������ɫ����
	solidrectangle(mX + unit / 10, mY - unit / 10, mX + bodLen, mY);
	setfillcolor(GREEN);
	//���ݵ�ǰ����ֵ���������ֵ�ٷֱ�ȷ�����δ�С
	solidrectangle(mX + unit / 10, mY - unit / 10, mX + unit / 10 + (bodLen - unit / 10) * (curHealth / maxHealth), mY);
	//��ӡ����ͼƬ
	putimage(mX, mY + unit / 10, mImg[0].get(), SRCAND);
	putimage(mX, mY + unit / 10, mImg[1].get(), SRCPAINT);
	//��Χforѭ��������������
	for (auto& tow : towerList)
	{
		for (auto& t : tow)
		{
			if (!(t.get())) continue;
			t->addMonster(shared_ptr<BaseMonster>(shared_from_this()));
		}
	}
}

void BaseMonster::centerDraw()//��ӡ����ͼƬ
{
	putimage(mX + width / 2 - unit / 4, mY - unit / 2, centerImg[0].get(), SRCAND);
	putimage(mX + width / 2 - unit / 4, mY - unit / 2, centerImg[1].get(), SRCPAINT);
}

void BaseMonster::getHit(int damage)
{
	this->curHealth -= min(damage, (int)curHealth);  //���㱻����������ֵ
}

int BaseMonster::checkHealth()
{
	return !curHealth ? 3 : 0;                       //���Ѫ�����жϴ�
}

pair<double, double> BaseMonster::getLocation()      
{
	return { this->lX,this->lY };                   //���ع�����������
}

int BaseMonster::getDistance()
{
	return this->distance;                          //�������ߵľ���
}

bool BaseMonster::checkLoc(shared_ptr<BaseMonster>m, double range)
{
	return false;                    
}

void BaseMonster::getFrozen() {
	return;                   
}

bool BaseMonster::checkClick(int x, int y)
{
	return x >=mX && x <= mX + width && y >= mY && y <= mY + height;
}

pair<int, int>BaseMonster::getM()
{
	return { mX,mY };               //��������
}

BaseBreed1::BaseBreed1() :BaseMonster(propImgList[0], 2 * unit, 2 * unit, 600, 2 * unit, 5 * unit, 2 * unit) {}

BaseBreed2::BaseBreed2() :BaseMonster(propImgList[1], 2 * unit, 2 * unit, 600, 2 * unit, 9 * unit, 4 * unit) {}

BaseBreed3::BaseBreed3() :BaseMonster(propImgList[2], 2 * unit, unit, 400, 2 * unit, 2 * unit, 5 * unit) {}

BaseBreed4::BaseBreed4() :BaseMonster(propImgList[3], unit, unit, 200, unit, 6 * unit, 6 * unit) {}

BaseBreed5::BaseBreed5() :BaseMonster(propImgList[4], unit, unit, 200, unit, 2 * unit, 3 * unit) {}


shared_ptr<BaseMonster> BaseBreed1Factory::buildMonster()
{
	return make_shared<BaseBreed1>();
}

shared_ptr<BaseMonster> BaseBreed2Factory::buildMonster()
{
	return make_shared<BaseBreed2>();
}

shared_ptr<BaseMonster> BaseBreed3Factory::buildMonster()
{
	return make_shared<BaseBreed3>();
}

shared_ptr<BaseMonster> BaseBreed4Factory::buildMonster()
{
	return make_shared<BaseBreed4>();
}

shared_ptr<BaseMonster> BaseBreed5Factory::buildMonster()
{
	return make_shared<BaseBreed5>();
}
