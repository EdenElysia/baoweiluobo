#include "MonsterInit.h"
WaveMsg::WaveMsg(shared_ptr<BaseMonsterFactory>tmpFactory,float tmpWaveInterval,float tmpCount,float tmpInterval)
	:factory(tmpFactory), waveInterval(tmpWaveInterval), count(tmpCount), interval(tmpInterval) 
{
}

MonsterInit::MonsterInit() : waveMsg({
            WaveMsg(make_shared<Breed1Factory>(),0,10,20),    //ʵ�������﹤����������ˢ�ּ��������
            WaveMsg(make_shared<Breed2Factory>(),200.5,5,20),
            WaveMsg(make_shared<Breed3Factory>(),150,8,20),
            WaveMsg(make_shared<Breed4Factory>(),150,8,20),
            WaveMsg(make_shared<Breed5Factory>(),150,8,20),
            WaveMsg(make_shared<Breed6Factory>(),150,10,20)}),
            waveTimer(0),         
            monsterTimer(0),
            count(0),
            monsterCount(0),
            gameBegin(true)
{
}

bool MonsterInit::Update()
{
    //���μ�ʱ����ʱ
    waveTimer += 1;
    if (gameBegin)
    {
        if (waveTimer >= waveMsg[count].waveInterval) {
            //�����ǰ���ɹֵĸ�����������������
            if (monsterCount < waveMsg[count].count) {
                //��ʱ����ʱ
                monsterTimer += 1;
                //��ʱ����
                if (monsterTimer > waveMsg[count].interval) {
                    //���ɹ���
                    monsterList.insert(waveMsg[count].factory->buildMonster());
                    //�������++
                    monsterCount++;
                    //��ʱ������
                    monsterTimer = 0;
                    return true;
                }
            }
            else {
                //���μ�һ
                count++;
                if (count < waveMsg.size()) {
                    //�����������
                    monsterCount = 0;
                    //���μ�ʱ������
                    waveTimer = 0;
                }
                else gameBegin = false;
            }
        }
    }
    return false;
    
}

bool MonsterInit::getGameBegin()
{
    return gameBegin;
}

int MonsterInit::getCount()
{
    return count;//���ع��ﲨ��
}