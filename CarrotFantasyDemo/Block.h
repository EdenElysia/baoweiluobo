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
//���࣬���ڴ��������
class Block{
public:
	Block(int j, int i);                                    //�����ͼ��
	void handleClick(int x,int y);                          //����������¼�
	void draw();                                            //���Ƶ�ͼ��
	void resetState(shared_ptr<BlockState>state);           //���õ�ǰ״̬
	void resetStaticState(shared_ptr<BlockState>state);     //���þ�ֹ״̬
	void updateState();                                     //���µ�ǰ״̬
private:
	//���״̬��״̬��ͬ������������Ľ����ͬ
	shared_ptr<BlockState>curState;                          //��ʾ��ǰ״̬��������������Ľ��
	shared_ptr<BlockState>staticState;                       //��ʾ��̬״̬�����������Ӱ��
	int row, col;                                            //��ǰ�������
};