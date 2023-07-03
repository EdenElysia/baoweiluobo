#pragma once
//#include"Monster.h"
#include <easyx.h>
#include <conio.h>
#include <graphics.h>
#include<vector>
#include<unordered_set>
#include"BaseMonster.h"
using namespace std;
class BaseMonster;
extern vector<shared_ptr<IMAGE>>bulletImgList;           //�������ͼ��ָ�������
extern unordered_set<shared_ptr<BaseMonster>>monsterList;//�洢�������ָ�������
//�ӵ�����
class BaseBullet {
public:
	//��ʼ����ָ�����ꡢ�ȼ���Ŀ�����
	BaseBullet(double x, double y, int gra, shared_ptr<BaseMonster>target);
	//���ͼƬ
	void draw();
	//�ж��Ƿ��������ײ
	bool checkHit();
	//��ײ����
	virtual void hitMonster();
	//�ӵ������Ź���ƶ�
	void move();
protected:
	//Ŀ�����
	shared_ptr<BaseMonster>targetMonster;
	//�ٶȣ���ͼ���꣬��������
	double speed = 10, mX, mY, lX, lY;
	//�ӵ�ͼƬ
	shared_ptr<IMAGE>curImage1, curImage2;
	//�ӵ��ȼ�
	int grade;
	//�ӵ��˺�
	int damage;
	//��ײ�ж�
	bool f;
};
