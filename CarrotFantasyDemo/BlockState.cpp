#include"BlockState.h"
//用于充值状态，例如点击空地会生成三个选项，在选择完炮台之后，其他选项清除，回归原来的（空/有炮台）状态
void BlockState::updateState()
{
	for (auto& v : blockList)
	{
		for (auto& block : v)
		{
			block->updateState();
		}
	}
	f = 0;
}
//前置判断，例如block是空的，但是有道具，那么就首先处理目标道具
bool BlockState::preHandle(int x, int y)
{
	for (auto& m : monsterList)
	{
		if (m->checkClick(x, y))
		{
			centerMonster = m;
			for (auto& tow : towerList)
			{
				for (auto& t : tow)
				{
					if (!t) continue;
					t->resetTarget(m);
				}
			}
			return true;
		}
	}
	return false;
}

void BanState::handleClick(int i, int j, int x, int y)
{
	preHandle(x, y);
}

//空地点击
void EmptyState::handleClick(int i, int j,int x,int y)
{
	if (!preHandle(x, y))
	{
		updateState();
		//空地状态变为加号，左上变成炮台1选项，中上变为炮台2选项，右上变为炮台3选项
		blockList[i][j]->resetState(make_shared<Add>());
		blockList[i - 1][j - 1]->resetState(make_shared<SelectFirst>());
		blockList[i][j - 1]->resetState(make_shared<SelectSecond>());
		blockList[i + 1][j - 1]->resetState(make_shared<SelectThird>());
	}
}
void EmptyState::draw(int i, int j)
{
	return;
}

//有炮台的状态，点击后，中上改为升级，中下改为出售
void BasicCannon::handleClick(int i, int j, int x, int y)
{
	if (f == 0)
	{
		updateState();
		blockList[i][j - 1]->resetState(make_shared<BasicUpgrade>());
		blockList[i][j + 1]->resetState(make_shared<BasicSold>());
		f = 1;
	}
	else
	{
		updateState();
		f = 0;
	}
	
}
void BasicCannon::draw(int i, int j)
{
	if(f==1)towerList[i][j]->drawCircle();
}

void MiddleCannon::handleClick(int i, int j, int x, int y)
{
	if (f == 0)
	{
		updateState();
		blockList[i][j - 1]->resetState(make_shared<MiddleUpgrade>());
		blockList[i][j + 1]->resetState(make_shared<MiddleSold>());
		f = 1;
	}
	else
	{
		updateState();
		f = 0;
	}

	
}
void MiddleCannon::draw(int i, int j)
{
	if(f==1)towerList[i][j]->drawCircle();
}

void  SeniorCannon::handleClick(int i, int j, int x, int y)
{
	if (f == 0)
	{
		updateState();
		blockList[i][j - 1]->resetState(make_shared<SeniorUpgrade>());
		blockList[i][j + 1]->resetState(make_shared<SeniorSold>());
		f = 1;
	}
	else
	{
		updateState();
		f = 0;
	}
	
}
void SeniorCannon::draw(int i, int j)
{
	if(f==1)towerList[i][j]->drawCircle();
	
}




//升级状态，点击后相应位置的炮台进行升级
void  BasicUpgrade::handleClick(int i, int j, int x, int y)
{
	
	if (gold >= 180)
	{
		towerList[i][j + 1]->upgrade();
		blockList[i][j + 1]->resetStaticState(make_shared<MiddleCannon>());
		updateState();
		gold -= 180;
	}
	
}
void BasicUpgrade::draw(int i, int j)
{
	if (gold >= 180)
	{
		putimage(unit * i, unit * j, blockImgList[0].get(), SRCAND);
		putimage(unit * i, unit * j, blockImgList[1].get(), SRCPAINT);
	}
	else
	{
		putimage(unit * i, unit * j, blockImgList[26].get(), SRCAND);
		putimage(unit * i, unit * j, blockImgList[27].get(), SRCPAINT);
	}
	
}


void MiddleUpgrade::handleClick(int i, int j, int x, int y)
{
	if (gold >= 220)
	{
		towerList[i][j + 1]->upgrade();
		blockList[i][j + 1]->resetStaticState(make_shared<SeniorCannon>());
		updateState();
		gold -= 220;
	}
	
}

void MiddleUpgrade::draw(int i, int j)
{
	if (gold >= 180)
	{
		putimage(unit * i, unit * j, blockImgList[2].get(), SRCAND);
		putimage(unit * i, unit * j, blockImgList[3].get(), SRCPAINT);
	}
	else
	{
		putimage(unit * i, unit * j, blockImgList[28].get(), SRCAND);
		putimage(unit * i, unit * j, blockImgList[29].get(), SRCPAINT);
	}
}

void SeniorUpgrade::handleClick(int i, int j, int x, int y)
{
	updateState();
}

void SeniorUpgrade::draw(int i, int j)
{
	putimage(unit * i, unit * j, blockImgList[4].get(), SRCAND);
	putimage(unit * i, unit * j, blockImgList[5].get(), SRCPAINT);
}




//加号状态，点击后刷新状态
void Add::handleClick(int i, int j, int x, int y)
{
	updateState();
}
void Add::draw(int i, int j)
{
	putimage(unit * i, unit * j, blockImgList[12].get(), SRCAND);
	putimage(unit * i, unit * j, blockImgList[13].get(), SRCPAINT);
}


//选择炮台状态，点击后在相应位置建造炮台
void SelectFirst::handleClick(int i, int j, int x, int y)
{
	if (gold >= 100)
	{
		shared_ptr<BaseTowerFactory>tf(make_shared<TowerFactory>());
		towerList[i + 1][j + 1] = tf->buildTower((i + 1) * unit, (j + 1) * unit);
		blockList[i + 1][j + 1]->resetState(make_shared<BasicCannon>());
		blockList[i + 1][j + 1]->resetStaticState(make_shared<BasicCannon>());
		updateState();
		gold -= 100;

	}
}
void SelectFirst::draw(int i, int j)
{
	if (gold >= 100)
	{
		putimage(unit * i, unit * j, blockImgList[14].get(), SRCAND);
		putimage(unit * i, unit * j, blockImgList[15].get(), SRCPAINT);
	}
	else
	{
		putimage(unit * i, unit * j, blockImgList[20].get(), SRCAND);
		putimage(unit * i, unit * j, blockImgList[21].get(), SRCPAINT);
	}
	
}
void SelectSecond::handleClick(int i, int j, int x, int y)
{
	if (gold >= 180)
	{
		shared_ptr<BaseTowerFactory>tf(make_shared<FlameTowerFactory>());
		towerList[i][j + 1]=tf->buildTower(i * unit, (j + 1) * unit);
		blockList[i][j + 1]->resetState(make_shared<BasicCannon>());
		blockList[i][j + 1]->resetStaticState(make_shared<BasicCannon>());
		updateState();
		gold -= 180;
	}
}
void SelectSecond::draw(int i, int j)
{
	if (gold >= 180)
	{
		putimage(unit * i, unit * j, blockImgList[16].get(), SRCAND);
		putimage(unit * i, unit * j, blockImgList[17].get(), SRCPAINT);
	}
	else
	{
		putimage(unit * i, unit * j, blockImgList[24].get(), SRCAND);
		putimage(unit * i, unit * j, blockImgList[25].get(), SRCPAINT);
	}
}
void SelectThird::handleClick(int i, int j, int x, int y)
{
	if (gold >= 180)
	{
		shared_ptr<BaseTowerFactory>tf(make_shared<IceTowerFactory>());
		towerList[i - 1][j + 1] = tf->buildTower((i - 1) * unit, (j + 1) * unit);
		blockList[i - 1][j + 1]->resetState(make_shared<BasicCannon>());
		blockList[i - 1][j + 1]->resetStaticState(make_shared<BasicCannon>());
		updateState();
		gold -= 180;
	}
}
void SelectThird::draw(int i, int j)
{
	if (gold >= 180)
	{
		putimage(unit * i, unit * j, blockImgList[18].get(), SRCAND);
		putimage(unit * i, unit * j, blockImgList[19].get(), SRCPAINT);
	}
	else
	{
		putimage(unit * i, unit * j, blockImgList[22].get(), SRCAND);
		putimage(unit * i, unit * j, blockImgList[23].get(), SRCPAINT);
	}
}


//出售炮台状态，点击后相应位置摧毁炮台
void  BasicSold::handleClick(int i, int j, int x, int y)
{
	blockList[i][j-1]->resetState(make_shared<EmptyState>());
	blockList[i][j-1]->resetStaticState(make_shared<EmptyState>());
	towerList[i][j-1].reset();
	updateState();
	gold += 80;
}
void BasicSold::draw(int i, int j)
{
	putimage(unit * i, unit * j, blockImgList[6].get(), SRCAND);
	putimage(unit * i, unit * j, blockImgList[7].get(), SRCPAINT);
}

void MiddleSold::handleClick(int i, int j, int x, int y)
{
	blockList[i][j-1]->resetState(make_shared<EmptyState>());
	blockList[i][j-1]->resetStaticState(make_shared<EmptyState>());
	towerList[i][j - 1].reset();
	updateState();
	gold += 208;
}

void MiddleSold::draw(int i, int j)
{
	putimage(unit * i, unit * j, blockImgList[8].get(), SRCAND);
	putimage(unit * i, unit * j, blockImgList[9].get(), SRCPAINT);
}

void SeniorSold::handleClick(int i, int j, int x, int y)
{
	blockList[i][j-1]->resetState(make_shared<EmptyState>());
	blockList[i][j-1]->resetStaticState(make_shared<EmptyState>());
	towerList[i][j - 1].reset();
	updateState();
	gold += 352;
}

void SeniorSold::draw(int i, int j)
{
	putimage(unit * i, unit * j, blockImgList[10].get(), SRCAND);
	putimage(unit * i, unit * j, blockImgList[11].get(), SRCPAINT);
}