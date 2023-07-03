#pragma once
#include"Monster.h"
#include<unordered_map>
using namespace std;
extern unordered_set<shared_ptr<BaseMonster>>monsterList;
class BaseMonsterFactory;
class Breed1Factory;
class Breed2Factory;
class Breed3Factory;
class Breed4Factory;
class Breed5Factory;
class Breed6Factory;
class BaseMonster;
//存储波次怪物孵化信息
class WaveMsg
{
public:
    WaveMsg(shared_ptr<BaseMonsterFactory>tmpFactory, float tmpWaveInterval,float tmpCount, float tmpInterval);
    //该波次生成的怪物
    shared_ptr<BaseMonsterFactory>factory;
    //时间间隔
    float waveInterval;
    //生成个数
    float count;
    //生成间隔
    float interval;

};
//怪物孵化器
class MonsterInit {
public:

    MonsterInit();                
    bool Update();                                  //更新状态并生成怪物
    bool getGameBegin();                            //获取游戏状态
    int getCount();                                 //获取怪物计数器的值
private:
    //波次信息
    vector<WaveMsg>waveMsg;
    //每波怪之间的时间计时器
    float waveTimer;
    //每个怪之前的时间计时器
    float monsterTimer;
    //波次计数器
    int count;
    //怪物个数计数器
    int monsterCount;
    //游戏开关
    bool gameBegin;
};
