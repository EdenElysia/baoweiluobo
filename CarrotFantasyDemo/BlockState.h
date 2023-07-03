#pragma once
#include <easyx.h>
#include <conio.h>
#include <graphics.h>
#include"Block.h"
#include"Tower.h"
#include<vector>
#include "BaseTower.h"
#include"FlameTower.h"
#include"IceTower.h"
#include"BaseMonster.h"
class Block;
class Tower;
using namespace std;
extern vector<vector<shared_ptr<Block>>>blockList;
extern vector<shared_ptr<IMAGE>>blockImgList;
extern vector<vector<shared_ptr<BaseTower>>>towerList;
extern unordered_set<shared_ptr<BaseMonster>>monsterList;
class BaseMonster;
extern shared_ptr<BaseMonster>centerMonster;
extern int gold;
extern const double unit;

class BlockState {
public:
	virtual void handleClick(int i, int j,int x,int y) { return; }  //检测点击
	virtual void draw(int i, int j) { return; }                     
	virtual bool preHandle(int x, int y);
	void updateState();
	int f = 0;
};
//不能建造炮台的状态（道路）
class BanState :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
};
//可以建造炮台
class EmptyState :public BlockState {
public:
	virtual void handleClick(int i, int j,int x,int y);
	virtual void draw(int i, int j);
};
//建有一、二、三级炮台
class BasicCannon :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
	virtual void draw(int i, int j);
};
class MiddleCannon :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
	virtual void draw(int i, int j);
};
class SeniorCannon :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
	virtual void draw(int i, int j);
};
//一、二、三级升级标识
class BasicUpgrade :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
	virtual void draw(int i, int j);
};
class MiddleUpgrade :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
	virtual void draw(int i, int j);
};
class SeniorUpgrade :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
	virtual void draw(int i, int j);
};
//一、二、三级炮台出售
class BasicSold :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
	virtual void draw(int i, int j);
};
class MiddleSold :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
	virtual void draw(int i, int j);
};
class SeniorSold :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
	virtual void draw(int i, int j);
};
//添加炮台
class Add :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
	virtual void draw(int i, int j);
};
//炮台选项1、2、3
class SelectFirst :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
	virtual void draw(int i, int j);
private:
};
class SelectSecond :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
	virtual void draw(int i, int j);
};
class SelectThird :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
	virtual void draw(int i, int j);
};
