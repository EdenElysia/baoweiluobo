#include "BaseBullet.h"
void BaseBullet::move()
{
	//����ƶ������й�����������ô��Ǹ��ӵ���������
	if (!monsterList.count(targetMonster))
	{
		f = 0;
		return;
	};
	//Ŀ�������ȡ�����ݴ����x��y�����ٶ�
	pair<double, double>targetLocation = targetMonster->getLocation();        //��ȡ��ǰ����Ŀ��
	double targetX = targetLocation.first, targetY = targetLocation.second;
	double disX = targetX - this->lX, disY = targetY - this->lY;             
	double dis = sqrt(disX * disX + disY * disY);                             
	//�ж��Ƿ���ײ
	if (dis <= 30)
	{

		f = 0;
		int damage = grade * 10;                                             //�˺�
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
	putimage(mX, mY, curImage1.get(), SRCAND);          //���ӵ������л�ȡͼ�񣬴�ӡ����Ӧ������
	putimage(mX, mY, curImage2.get(), SRCPAINT);
}

BaseBullet::BaseBullet(double x, double y, int gra, shared_ptr<BaseMonster>target) :mX(x), mY(y), lX(x + 10), lY(y + 10), grade(gra), targetMonster(target), f(1) {
};   //���캯�� �βΣ����꣬�ȼ����������ָ��

bool BaseBullet::checkHit() { return f; }                        //����Ƿ���ײ
void BaseBullet::hitMonster() { return; };

