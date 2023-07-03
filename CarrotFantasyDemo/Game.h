#pragma once
#include <easyx.h>            // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <graphics.h>
#include<vector>
#include<list>
#include<string>
#include<unordered_set>
#include"BaseMonster.h"
#include"BaseTower.h"
#include"Monster.h"
#include"Bullet.h"
#include"Block.h"
#include"DeathItem.h"
#include"MonsterInit.h"

//��Ϸ������
class Game
{
public:
	
	Game();
	//����������¼�
	bool processIuput();
	//����ͼƬ
	void loadTowerImg();
	                                
	void loadMonsterImg();

	void loadBulletImg();

	void loadOptionImg();

	void loadPropImg();

	void loadDeathImg();

	void loadSettingImg();

	void loadImg();
	//��ʼ����Ϸ
	void initGame();
	//�߼�����
	void update();
	//ͼƬ����
	void render();
	//������ͣ
	void stopBreak();
	//���У��������������߼�ͼƬ����
	void going();
	//������ѡ������ص���ҳ
	bool makeEnd();
	//������Ϸ״̬
	void refresh();
	//ɾ����Ϸ����
	void deleteGame();

	~Game();

private:
	bool close;                                   //�����Ϸ�Ƿ�ر�
	bool stop;                                    //�����Ϸ�Ƿ�����ͣ״̬
	int t;                                        //�����������ڸ�����Ϸ�߼���ͼƬ
	int health;                                   //�������ֵ
	shared_ptr<MonsterInit>monsterInit;           //������������ָ��
	int monsterNum;                               //��ǰ��Ļ�ϵĹ�������
	int gameOver;                                 //�����Ϸ�Ƿ��ѽ���
};

