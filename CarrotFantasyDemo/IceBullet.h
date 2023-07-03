#pragma once
//#include"Monster.h"
#include "BaseBullet.h"
using namespace std;
class BaseMonster;
class BaseBullet;

extern vector<shared_ptr<IMAGE>>bulletImgList;               
extern unordered_set<shared_ptr<BaseMonster>>monsterList;  //�洢�������ָ�������
//�����������䷶Χ�����ӵ�
class IceBullet :public BaseBullet {
public:
	IceBullet(double x, double y, int gra, shared_ptr<BaseMonster>target) :BaseBullet(x,y,gra,target){
		curImage1 = bulletImgList[grade * 2 +4];      //1�������ڵ�ͼ��
		curImage2 = bulletImgList[grade * 2 +5];      //2�������ڵ�ͼ��
		damage = 2 * grade;                           //�˺�
	};
	virtual void hitMonster();                        //�ӵ���������˺�������
};

