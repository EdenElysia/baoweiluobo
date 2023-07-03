#include "IceBullet.h"
//冰冻子弹，以目标怪物为中心造成范围伤害和冰冻
void IceBullet::hitMonster()
{
	for (auto& mon : monsterList)  //传入攻击对象的指针
	{
		if (targetMonster->checkLoc(mon,unit))
		{
			mon->getHit(damage);  //造成伤害
			mon->getFrozen();     //造成冰冻状态
		}
	}
}