#pragma once
#include <easyx.h>            // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <graphics.h>
#include<vector>
#include<iostream>
using namespace std;
extern vector<shared_ptr<IMAGE>>deathImg;     //�洢����ͼ��ָ�������
//���������࣬�������֡�����ͽ��ͼƬ
class DeathItem
{
public:
	DeathItem(int xx,int yy):x(xx),y(yy),time(0) {};
	void draw()                                                            //������������������֡�����ͽ��ͼƬ
	{
		if (time <= 19)                                                     //֡�ʣ�����ʱ�����ÿһ֡��
		{
			putimage(x, y+20, deathImg[(time/5+1) * 2].get(), SRCAND);      //2��3֡ʹ��SRCAND���ģʽ
			putimage(x, y+20, deathImg[(time/5+1) * 2 + 1].get(), SRCPAINT);//1��4֡ʹ��SRCPAINTģʽ
		}
		putimage(x, y, deathImg[0].get(), SRCAND);      //��ȡָ�����ͼ��
		putimage(x, y, deathImg[1].get(), SRCPAINT);    //��ȡָ�����ͼ��

		time++;
	}
	int check()                                         //��⶯���Ƿ񲥷���
	{
		return time >= 20;                                                   
	}

private:
	int x, y;                                           //����������
	int time;                                           //��������ʱ��
};

