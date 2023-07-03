#include"Tower.h"

void Tower::rotate()
{
	//��������������ת��Ƕ�
	if (!targetMonster) return;
	pair<int, int>targetLocation = targetMonster->getLocation();          //��ȡ���ﵱǰ����    
	int targetX = targetLocation.first, targetY = targetLocation.second;  //�ֱ��ŵ�ǰ�����������
	const double pi = 3.14159;                                            //Բ����
	double radian;                                                        //��
	double disX = this->lX - targetX, disY = this->lY - targetY;          //�����������
	if (disY == 0 && disX >= 0) radian = pi / 2;                          //
	else if (disY == 0 && disX < 0)radian = -pi / 2;
	else if (disY > 0) radian = atan(disX / disY);
	else radian = atan(disX / disY) + pi;
	rotateimage(curImage1.get(), curImage1.get(), radian, WHITE);         //��ת��̨
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
		curImage1 = towerImgList[2];     //��ȡ��̨ͼ��
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
{                                       //�������ù���Ŀ��
	resetTarget();
	if (!targetMonster) return;         //��������ֹͣ����
	                                    //ʵ�����ڵ����󣬲���ָ���ŵ�����
	bulletList.push_back(make_shared<Bullet>(this->lX - unit / 6, this->lY - unit / 6, grade, targetMonster));
	
}

void Tower::upgrade()
{
	if (grade == 1)
	{
		grade = 2;         //����
		range += 10;       //���ӹ�����Χ
	}
	else if (grade == 2)
	{
		grade = 3;         //����
		range += 20;       //���ӹ�����Χ
	}
}
