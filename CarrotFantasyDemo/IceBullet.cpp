#include "IceBullet.h"
//�����ӵ�����Ŀ�����Ϊ������ɷ�Χ�˺��ͱ���
void IceBullet::hitMonster()
{
	for (auto& mon : monsterList)  //���빥�������ָ��
	{
		if (targetMonster->checkLoc(mon,unit))
		{
			mon->getHit(damage);  //����˺�
			mon->getFrozen();     //��ɱ���״̬
		}
	}
}