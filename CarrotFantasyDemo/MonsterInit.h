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
//�洢���ι��������Ϣ
class WaveMsg
{
public:
    WaveMsg(shared_ptr<BaseMonsterFactory>tmpFactory, float tmpWaveInterval,float tmpCount, float tmpInterval);
    //�ò������ɵĹ���
    shared_ptr<BaseMonsterFactory>factory;
    //ʱ����
    float waveInterval;
    //���ɸ���
    float count;
    //���ɼ��
    float interval;

};
//���������
class MonsterInit {
public:

    MonsterInit();                
    bool Update();                                  //����״̬�����ɹ���
    bool getGameBegin();                            //��ȡ��Ϸ״̬
    int getCount();                                 //��ȡ�����������ֵ
private:
    //������Ϣ
    vector<WaveMsg>waveMsg;
    //ÿ����֮���ʱ���ʱ��
    float waveTimer;
    //ÿ����֮ǰ��ʱ���ʱ��
    float monsterTimer;
    //���μ�����
    int count;
    //�������������
    int monsterCount;
    //��Ϸ����
    bool gameBegin;
};
