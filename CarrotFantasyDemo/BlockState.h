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
	virtual void handleClick(int i, int j,int x,int y) { return; }  //�����
	virtual void draw(int i, int j) { return; }                     
	virtual bool preHandle(int x, int y);
	void updateState();
	int f = 0;
};
//���ܽ�����̨��״̬����·��
class BanState :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
};
//���Խ�����̨
class EmptyState :public BlockState {
public:
	virtual void handleClick(int i, int j,int x,int y);
	virtual void draw(int i, int j);
};
//����һ������������̨
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
//һ����������������ʶ
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
//һ������������̨����
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
//�����̨
class Add :public BlockState {
public:
	virtual void handleClick(int i, int j, int x, int y);
	virtual void draw(int i, int j);
};
//��̨ѡ��1��2��3
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
