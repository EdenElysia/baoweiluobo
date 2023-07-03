#include "MonsterInit.h"
WaveMsg::WaveMsg(shared_ptr<BaseMonsterFactory>tmpFactory,float tmpWaveInterval,float tmpCount,float tmpInterval)
	:factory(tmpFactory), waveInterval(tmpWaveInterval), count(tmpCount), interval(tmpInterval) 
{
}

MonsterInit::MonsterInit() : waveMsg({
            WaveMsg(make_shared<Breed1Factory>(),0,10,20),    //实例化怪物工厂，并传入刷怪间隔，波次
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
    //波次计时器计时
    waveTimer += 1;
    if (gameBegin)
    {
        if (waveTimer >= waveMsg[count].waveInterval) {
            //如果当前生成怪的个数不够，继续生成
            if (monsterCount < waveMsg[count].count) {
                //计时器计时
                monsterTimer += 1;
                //计时结束
                if (monsterTimer > waveMsg[count].interval) {
                    //生成怪物
                    monsterList.insert(waveMsg[count].factory->buildMonster());
                    //怪物个数++
                    monsterCount++;
                    //计时器清零
                    monsterTimer = 0;
                    return true;
                }
            }
            else {
                //波次加一
                count++;
                if (count < waveMsg.size()) {
                    //怪物个数清零
                    monsterCount = 0;
                    //波次计时器清零
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
    return count;//返回怪物波次
}