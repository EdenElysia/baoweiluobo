#pragma once
#include <easyx.h>            // 引用图形库头文件
#include <conio.h>
#include <graphics.h>
#include<vector>
#include<iostream>
using namespace std;
extern vector<shared_ptr<IMAGE>>deathImg;     //存储动画图像指针的容器
//死亡动画类，输出死亡帧动画和金币图片
class DeathItem
{
public:
	DeathItem(int xx,int yy):x(xx),y(yy),time(0) {};
	void draw()                                                            //绘制死亡动画，包括帧动画和金币图片
	{
		if (time <= 19)                                                     //帧率（根据时间输出每一帧）
		{
			putimage(x, y+20, deathImg[(time/5+1) * 2].get(), SRCAND);      //2，3帧使用SRCAND混合模式
			putimage(x, y+20, deathImg[(time/5+1) * 2 + 1].get(), SRCPAINT);//1，4帧使用SRCPAINT模式
		}
		putimage(x, y, deathImg[0].get(), SRCAND);      //获取指针输出图像
		putimage(x, y, deathImg[1].get(), SRCPAINT);    //获取指针输出图像

		time++;
	}
	int check()                                         //检测动画是否播放完
	{
		return time >= 20;                                                   
	}

private:
	int x, y;                                           //动画的坐标
	int time;                                           //动画播放时间
};

