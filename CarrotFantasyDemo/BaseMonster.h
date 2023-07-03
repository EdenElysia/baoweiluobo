
#pragma once
#include <easyx.h>            // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <graphics.h>
#include<iostream>
#include<vector>
#include "BaseTower.h"
class BaseTower;
using namespace std;
extern const double unit;                                           //��λ����
const int startX = unit * 1;                                        
extern vector<vector<shared_ptr<BaseTower>>>towerList;              //Ƕ��  ��������ָ�������  ��ͬ�����б�
extern vector<shared_ptr<IMAGE>>centerImg;                          
const int startY = unit * 3;
class BaseMonster;
extern shared_ptr<BaseMonster>centerMonster;             
extern vector<vector<shared_ptr<IMAGE>>>propImgList;                
//������࣬Ҳ�ǵ����ࣨ����=�����ƶ��Ĺ��
class BaseMonster :public enable_shared_from_this<BaseMonster> {
public:
	friend class BaseTower;
	BaseMonster(vector<shared_ptr<IMAGE>>& img, int w, int h, double health, int b = unit, int sX = startX, int sY = startY) :bodLen(b), width(w), height(h), mX(sX), mY(sY), lX(mX + width / 2), lY(mY + height / 2), mImg(img), maxHealth(health), curHealth(health), distance(0) {};
	virtual void draw();
	                                                                 //���ѡȡ�Ĺ�������л�ͼ����
	void centerDraw();
	                                                                 //������
	virtual void getHit(int damage);
	                                                                 //���Ѫ��
	virtual int checkHealth();
	                                                                 //��ȡ����
	pair<double, double> getLocation();
	                                                                 //��ȡ���ߵľ���
	int getDistance();
	virtual bool checkLoc(shared_ptr<BaseMonster> m, double range);
	                                                                 //����Ƿ񱻱���
	virtual void getFrozen();
	                                                                 //����Ƿ񱻵��
	bool checkClick(int x, int y);
	                                                                 
	pair<int, int>getM();
	virtual ~BaseMonster();

protected:
	//ͼƬ����������ꡢ�н����롢����ֵ
	vector<shared_ptr<IMAGE>>mImg;
	double width, height;                                            //����ͼ��Ŀ��
	double mX, mY, lX, lY;                                           //ͼ�����Ͻ����꼰��������
	int distance;                                                    //�߹��ľ���
	double bodLen;                                                   //�������峤��
	double maxHealth;                                                //�������ֵ
	double curHealth;                                                //��ǰ����ֵ
};

class BaseBreed1 :public BaseMonster {
public:
	BaseBreed1();
};

class BaseBreed2 :public BaseMonster {
public:
	BaseBreed2();
};

class BaseBreed3 :public BaseMonster {
public:
	BaseBreed3();
};

class BaseBreed4 :public BaseMonster {
public:
	BaseBreed4();
};

class BaseBreed5 :public BaseMonster {
public:
	BaseBreed5();
};

class BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster() = 0;
};

class BaseBreed1Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster() override;
};

class BaseBreed2Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster()override;
};

class BaseBreed3Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster()override;
};

class BaseBreed4Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster()override;
};

class BaseBreed5Factory :public BaseMonsterFactory
{
public:
	virtual shared_ptr<BaseMonster> buildMonster()override;
}; 