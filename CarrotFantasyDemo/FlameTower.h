#pragma once
#include"BaseTower.h"
using namespace std;
extern const double unit;
extern vector<shared_ptr<IMAGE>>towerImgList;          //�洢����ͼ��ָ�������
class BaseMonster;                                     
class BaseTower;
//̫������̨
class FlameTower :public BaseTower {
	friend class BaseMonster;
public:
	FlameTower(int x, int y) :BaseTower(x, y),damage(5),t(0)  {  
		curImage1 = towerImgList[10];                            //��ȡ1������ͼ��
		curImage2 = towerImgList[11];                            //��ȡ2������ͼ��
	};
	virtual void draw();                                         //��������
	virtual void upgrade();                                      //��������
	virtual void fire();                                         //�����ڵ�
private:
	int damage;                                                  //������
	double t;                                                    //���ƹ�����������٣�
};

class FlameTowerFactory :public BaseTowerFactory                //̫��������������
{
public:
	virtual shared_ptr<BaseTower> buildTower(int x, int y)    
	{
		return make_shared<FlameTower>(x, y);                  //����һ��̫�������������ָ��
	}
};