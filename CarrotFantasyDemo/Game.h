#pragma once
#include <easyx.h>            // 引用图形库头文件
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

//游戏运行类
class Game
{
public:
	
	Game();
	//处理鼠标点击事件
	bool processIuput();
	//加载图片
	void loadTowerImg();
	                                
	void loadMonsterImg();

	void loadBulletImg();

	void loadOptionImg();

	void loadPropImg();

	void loadDeathImg();

	void loadSettingImg();

	void loadImg();
	//初始化游戏
	void initGame();
	//逻辑更新
	void update();
	//图片更新
	void render();
	//处理暂停
	void stopBreak();
	//运行，包括处理点击，逻辑图片更新
	void going();
	//结束后选项，重玩或回到主页
	bool makeEnd();
	//重置游戏状态
	void refresh();
	//删除游戏对象
	void deleteGame();

	~Game();

private:
	bool close;                                   //标记游戏是否关闭
	bool stop;                                    //标记游戏是否处于暂停状态
	int t;                                        //计数器，用于更新游戏逻辑和图片
	int health;                                   //玩家生命值
	shared_ptr<MonsterInit>monsterInit;           //怪物生成器的指针
	int monsterNum;                               //当前屏幕上的怪物数量
	int gameOver;                                 //标记游戏是否已结束
};

