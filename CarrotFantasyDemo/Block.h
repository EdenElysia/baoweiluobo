#pragma once
#include"BlockState.h"
#include<vector>
#include<unordered_set>
#include<memory>
using namespace std;
class BlockState;
class BaseMonster;
class BaseTower;
class BanState;
class EmptyState;
extern int gold;
//块类，用于处理鼠标点击
class Block{
public:
	Block(int j, int i);                                    //构造地图块
	void handleClick(int x,int y);                          //处理鼠标点击事件
	void draw();                                            //绘制地图块
	void resetState(shared_ptr<BlockState>state);           //重置当前状态
	void resetStaticState(shared_ptr<BlockState>state);     //重置静止状态
	void updateState();                                     //更新当前状态
private:
	//块的状态，状态不同则鼠标点击产生的结果不同
	shared_ptr<BlockState>curState;                          //表示当前状态，即鼠标点击产生的结果
	shared_ptr<BlockState>staticState;                       //表示静态状态，不受鼠标点击影响
	int row, col;                                            //当前块的行列
};