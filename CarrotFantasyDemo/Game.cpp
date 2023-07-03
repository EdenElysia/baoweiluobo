#include "Game.h"
vector<shared_ptr<IMAGE>>towerImgList;                           //����ͼƬָ������
vector<vector<shared_ptr<BaseTower>>>towerList;                  //��ά������������
vector<shared_ptr<IMAGE>>blockImgList;                           //��שͼƬ����
list<shared_ptr<BaseBullet>>bulletList;                          //�ڵ�����ָ������
list<shared_ptr<DeathItem>>itemList;                             //����������
unordered_set<shared_ptr<BaseMonster>>monsterList;               //�����������
vector<shared_ptr<IMAGE>>bulletImgList;                          //�ڵ�ͼƬ����
vector<vector<shared_ptr<IMAGE>>>propImgList;                    //����ͼƬ����
vector<vector<shared_ptr<Block>>>blockList;                      //��ά��ש����������ͼ
vector<vector<shared_ptr<IMAGE>>>monsterImgList;                 //��ά����ͼƬ����
vector<shared_ptr<IMAGE>>centerImg;                              //����ͼƬ����
vector<shared_ptr<IMAGE>>deathImg;                               //����ͼƬ����
vector<shared_ptr<IMAGE>>settingImg;                             //����ͼƬ����
shared_ptr<BaseMonster> centerMonster;                           //�����������ָ��
vector<shared_ptr<BaseMonsterFactory>>factory;                   //��������
vector<shared_ptr<BaseMonsterFactory>>baseFactory;               //���๤������
const double unit = 50;                                          //��λ����
int gold;                                                        //���
using namespace std;
//����ͼƬ�ĺ���
bool Game::processIuput()
{
	//���ݵ�����꣬ѡ����Ӧ��block����Ӧ����¼�
	if (MouseHit())
	{
		auto m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			int i = m.x / unit, j = m.y / unit;
			if (j >= 0 && j <= 8 && i > 0 && i <= 11)
			{
				blockList[i][j]->handleClick(m.x, m.y);
			}
			if (i >= 9 && i <= 10 && j >= 0 && j <= 1)
			{
				stop = true;
			}
			if (i >= 10 && j >= 0 && j <= 1) return true;

		}
	}
	return false;
}

//�������������ֵȼ�����ͼƬ
void Game::loadTowerImg()
{
	//ʵ��������ͼƬ���󣬲�ʹ�ù���ָ�뱣��
	shared_ptr<IMAGE> tImg1 (new IMAGE);
	shared_ptr<IMAGE> tImg2 (new IMAGE);
	shared_ptr<IMAGE> tImg3 (new IMAGE);
	shared_ptr<IMAGE> tImg4 (new IMAGE);
	shared_ptr<IMAGE> tImg5 (new IMAGE);
	shared_ptr<IMAGE> tImg6 (new IMAGE);
	shared_ptr<IMAGE> tImg7 (new IMAGE);
	shared_ptr<IMAGE> tImg8 (new IMAGE);


	//����ͼƬ
	loadimage(tImg1.get(), L"picture/tower/tower011.png", unit, unit);
	loadimage(tImg2.get(), L"picture/tower/tower012.png", unit, unit);
	loadimage(tImg3.get(), L"picture/tower/tower111.png", unit, unit);
	loadimage(tImg4.get(), L"picture/tower/tower112.png", unit, unit);
	loadimage(tImg5.get(), L"picture/tower/tower121.png", unit, unit);
	loadimage(tImg6.get(), L"picture/tower/tower122.png", unit, unit);
	loadimage(tImg7.get(), L"picture/tower/tower131.png", unit, unit);
	loadimage(tImg8.get(), L"picture/tower/tower132.png", unit, unit);



	shared_ptr<IMAGE> tImg9 (new IMAGE);
	shared_ptr<IMAGE> tImg10 (new IMAGE);
	shared_ptr<IMAGE> tImg11 (new IMAGE);
	shared_ptr<IMAGE> tImg12 (new IMAGE);
	shared_ptr<IMAGE> tImg13 (new IMAGE);
	shared_ptr<IMAGE> tImg14 (new IMAGE);
	shared_ptr<IMAGE> tImg15 (new IMAGE);
	shared_ptr<IMAGE> tImg16 (new IMAGE);

	loadimage(tImg9.get(), L"picture/tower/tower021.png", unit, unit);
	loadimage(tImg10.get(), L"picture/tower/tower022.png", unit, unit);
	loadimage(tImg11.get(), L"picture/tower/tower211.png", unit, unit);
	loadimage(tImg12.get(), L"picture/tower/tower212.png", unit, unit);
	loadimage(tImg13.get(), L"picture/tower/tower221.png", unit, unit);
	loadimage(tImg14.get(), L"picture/tower/tower222.png", unit, unit);
	loadimage(tImg15.get(), L"picture/tower/tower231.png", unit, unit);
	loadimage(tImg16.get(), L"picture/tower/tower232.png", unit, unit);

	shared_ptr<IMAGE> tImg17 (new IMAGE);
	shared_ptr<IMAGE> tImg18 (new IMAGE);
	shared_ptr<IMAGE> tImg19 (new IMAGE);
	shared_ptr<IMAGE> tImg20 (new IMAGE);
	shared_ptr<IMAGE> tImg21 (new IMAGE);
	shared_ptr<IMAGE> tImg22 (new IMAGE);
	shared_ptr<IMAGE> tImg23 (new IMAGE);
	shared_ptr<IMAGE> tImg24 (new IMAGE);

	loadimage(tImg17.get(), L"picture/tower/tower031.png", unit, unit);
	loadimage(tImg18.get(), L"picture/tower/tower032.png", unit, unit);
	loadimage(tImg19.get(), L"picture/tower/tower311.png", unit, unit);
	loadimage(tImg20.get(), L"picture/tower/tower312.png", unit, unit);
	loadimage(tImg21.get(), L"picture/tower/tower321.png", unit, unit);
	loadimage(tImg22.get(), L"picture/tower/tower322.png", unit, unit);
	loadimage(tImg23.get(), L"picture/tower/tower331.png", unit, unit);
	loadimage(tImg24.get(), L"picture/tower/tower332.png", unit, unit);

	shared_ptr<IMAGE> tImg25 (new IMAGE);
	shared_ptr<IMAGE> tImg26 (new IMAGE);
	shared_ptr<IMAGE> tImg27 (new IMAGE);
	shared_ptr<IMAGE> tImg28 (new IMAGE);

	loadimage(tImg25.get(), L"picture/tower/upgrade10.png", 0.3 * unit, 0.36 * unit);
	loadimage(tImg26.get(), L"picture/tower/upgrade11.png", 0.3 * unit, 0.36 * unit);
	loadimage(tImg27.get(), L"picture/tower/upgrade20.png", 0.3 * unit, 0.36 * unit);
	loadimage(tImg28.get(), L"picture/tower/upgrade21.png", 0.3 * unit, 0.36 * unit);


	towerImgList = { tImg2,tImg1,tImg4,tImg3,tImg6,tImg5,tImg8,tImg7,tImg10,tImg9,tImg12,tImg11,tImg14,tImg13,tImg16,tImg15,tImg18,tImg17,tImg20,tImg19,tImg22,tImg21,tImg24,tImg23,tImg26,tImg25,tImg28,tImg27 };
}

void Game::loadMonsterImg()
{
	//����
	//rotateimage(&imgb, &imgb, 30);
	shared_ptr<IMAGE>mImgf0( new IMAGE);
	shared_ptr<IMAGE>mImgf1(new IMAGE);
	loadimage(mImgf0.get(), L"picture/monster/ice0.png", 0.8 * unit, 0.5 * unit);
	loadimage(mImgf1.get(), L"picture/monster/ice1.png", 0.8 * unit, 0.5 * unit);

	shared_ptr<IMAGE> mImg11(new IMAGE);
	shared_ptr<IMAGE> mImg12(new IMAGE);
	shared_ptr<IMAGE> mImg13(new IMAGE);
	shared_ptr<IMAGE> mImg14(new IMAGE);

	loadimage(mImg11.get(), L"picture/monster/monster111.png", unit, 0.8 * unit);
	loadimage(mImg12.get(), L"picture/monster/monster112.png", unit, 0.8 * unit);
	loadimage(mImg13.get(), L"picture/monster/monster121.png", unit, 0.8 * unit);
	loadimage(mImg14.get(), L"picture/monster/monster122.png", unit, 0.8 * unit);

	shared_ptr<IMAGE> mImg21(new IMAGE);
	shared_ptr<IMAGE> mImg22(new IMAGE);
	shared_ptr<IMAGE> mImg23(new IMAGE);
	shared_ptr<IMAGE> mImg24(new IMAGE);

	loadimage(mImg21.get(), L"picture/monster/monster211.png", unit, 0.5 * unit);
	loadimage(mImg22.get(), L"picture/monster/monster212.png", unit, 0.5 * unit);
	loadimage(mImg23.get(), L"picture/monster/monster221.png", unit, 0.5 * unit);
	loadimage(mImg24.get(), L"picture/monster/monster222.png", unit, 0.5 * unit);

	shared_ptr<IMAGE> mImg31(new IMAGE);
	shared_ptr<IMAGE> mImg32(new IMAGE);
	shared_ptr<IMAGE> mImg33(new IMAGE);
	shared_ptr<IMAGE> mImg34(new IMAGE);

	loadimage(mImg31.get(), L"picture/monster/monster311.png", unit, unit);
	loadimage(mImg32.get(), L"picture/monster/monster312.png", unit, unit);
	loadimage(mImg33.get(), L"picture/monster/monster321.png", unit, unit);
	loadimage(mImg34.get(), L"picture/monster/monster322.png", unit, unit);

	shared_ptr<IMAGE> mImg41(new IMAGE);
	shared_ptr<IMAGE> mImg42(new IMAGE);
	shared_ptr<IMAGE> mImg43(new IMAGE);
	shared_ptr<IMAGE> mImg44(new IMAGE);

	loadimage(mImg41.get(), L"picture/monster/monster411.png", unit, 0.8 * unit);
	loadimage(mImg42.get(), L"picture/monster/monster412.png", unit, 0.8 * unit);
	loadimage(mImg43.get(), L"picture/monster/monster421.png", unit, 0.8 * unit);
	loadimage(mImg44.get(), L"picture/monster/monster422.png", unit, 0.8 * unit);

	shared_ptr<IMAGE> mImg51(new IMAGE);
	shared_ptr<IMAGE> mImg52(new IMAGE);
	shared_ptr<IMAGE> mImg53(new IMAGE);
	shared_ptr<IMAGE> mImg54(new IMAGE);

	loadimage(mImg51.get(), L"picture/monster/monster511.png", 0.8 * unit, 1.1 * unit);
	loadimage(mImg52.get(), L"picture/monster/monster512.png", 0.8 * unit, 1.1 * unit);
	loadimage(mImg53.get(), L"picture/monster/monster521.png", 0.8 * unit, 1.1 * unit);
	loadimage(mImg54.get(), L"picture/monster/monster522.png", 0.8 * unit, 1.1 * unit);

	shared_ptr<IMAGE> mImg61(new IMAGE);
	shared_ptr<IMAGE> mImg62(new IMAGE);
	shared_ptr<IMAGE> mImg63(new IMAGE);
	shared_ptr<IMAGE> mImg64(new IMAGE);

	loadimage(mImg61.get(), L"picture/monster/monster611.png", 1.6 * unit, unit);
	loadimage(mImg62.get(), L"picture/monster/monster612.png", 1.6 * unit, unit);
	loadimage(mImg63.get(), L"picture/monster/monster621.png", 1.6 * unit, unit);
	loadimage(mImg64.get(), L"picture/monster/monster622.png", 1.6 * unit, unit);

	monsterImgList = { {mImgf1,mImgf0}, {mImg12,mImg11,mImg14,mImg13}, {mImg22,mImg21,mImg24,mImg23}, {mImg32,mImg31,mImg34,mImg33}, {mImg42,mImg41,mImg44,mImg43}, {mImg52,mImg51,mImg54,mImg53}, {mImg62,mImg61,mImg64,mImg63} };
	//����
	shared_ptr<IMAGE> cImg1(new IMAGE),cImg2(new IMAGE);
	loadimage(cImg1.get(), L"picture/monster/target0.png", 0.3 * unit, 0.3 * unit);
	loadimage(cImg2.get(), L"picture/monster/target1.png", 0.3 * unit, 0.3 * unit);
	centerImg = { cImg2,cImg1 };
}

void Game::loadBulletImg()
{
	//�ӵ������ֵȼ����ӵ�
	shared_ptr<IMAGE> bImg1 (new IMAGE);
	shared_ptr<IMAGE> bImg2 (new IMAGE);
	shared_ptr<IMAGE> bImg3 (new IMAGE);
	shared_ptr<IMAGE> bImg4 (new IMAGE);
	shared_ptr<IMAGE> bImg5 (new IMAGE);
	shared_ptr<IMAGE> bImg6 (new IMAGE);
	loadimage(bImg1.get(), L"picture/bullet/bullet10.png", 0.2 * unit, 0.2 * unit);
	loadimage(bImg2.get(), L"picture/bullet/bullet11.png", 0.2 * unit, 0.2 * unit);
	loadimage(bImg3.get(), L"picture/bullet/bullet10.png", 0.3 * unit, 0.3 * unit);
	loadimage(bImg4.get(), L"picture/bullet/bullet11.png", 0.3 * unit, 0.3 * unit);
	loadimage(bImg5.get(), L"picture/bullet/bullet10.png", 0.4 * unit, 0.4 * unit);
	loadimage(bImg6.get(), L"picture/bullet/bullet11.png", 0.4 * unit, 0.4 * unit);
	
	shared_ptr<IMAGE> bImg7 (new IMAGE);
	shared_ptr<IMAGE> bImg8 (new IMAGE);
	shared_ptr<IMAGE> bImg9 (new IMAGE);
	shared_ptr<IMAGE> bImg10 (new IMAGE);
	shared_ptr<IMAGE> bImg11 (new IMAGE);
	shared_ptr<IMAGE> bImg12 (new IMAGE);
	loadimage(bImg7.get(), L"picture/bullet/bullet20.png", 0.4 * unit, 0.4 * unit);
	loadimage(bImg8.get(), L"picture/bullet/bullet21.png", 0.4 * unit, 0.4 * unit);
	loadimage(bImg9.get(), L"picture/bullet/bullet20.png", 0.5 * unit, 0.5 * unit);
	loadimage(bImg10.get(), L"picture/bullet/bullet21.png", 0.5 * unit, 0.5 * unit);
	loadimage(bImg11.get(), L"picture/bullet/bullet20.png", 0.6 * unit, 0.6 * unit);
	loadimage(bImg12.get(), L"picture/bullet/bullet21.png", 0.6 * unit, 0.6 * unit);

	bulletImgList = { bImg2,bImg1,bImg4,bImg3, bImg6,bImg5,bImg8,bImg7,bImg10,bImg9, bImg12,bImg11 };
}

void Game::loadOptionImg()
{

	//�飺ѡ��
	shared_ptr<IMAGE> oImg1 (new IMAGE);
	shared_ptr<IMAGE> oImg2 (new IMAGE);
	shared_ptr<IMAGE> oImg3 (new IMAGE);
	shared_ptr<IMAGE> oImg4 (new IMAGE);
	shared_ptr<IMAGE> oImg5 (new IMAGE);
	shared_ptr<IMAGE> oImg6 (new IMAGE);
	shared_ptr<IMAGE> oImg7 (new IMAGE);
	shared_ptr<IMAGE> oImg8 (new IMAGE);
	shared_ptr<IMAGE> oImg9 (new IMAGE);
	shared_ptr<IMAGE> oImg10 (new IMAGE);
	shared_ptr<IMAGE> oImg11 (new IMAGE);
	shared_ptr<IMAGE> oImg12 (new IMAGE);
	shared_ptr<IMAGE> oImg13 (new IMAGE);
	shared_ptr<IMAGE> oImg14 (new IMAGE);
	shared_ptr<IMAGE> oImg15 (new IMAGE);
	shared_ptr<IMAGE> oImg16 (new IMAGE);
	shared_ptr<IMAGE> oImg17 (new IMAGE);
	shared_ptr<IMAGE> oImg18 (new IMAGE);
	shared_ptr<IMAGE> oImg19 (new IMAGE);
	shared_ptr<IMAGE> oImg20 (new IMAGE);
	shared_ptr<IMAGE> oImg21 (new IMAGE);
	shared_ptr<IMAGE> oImg22 (new IMAGE);
	shared_ptr<IMAGE> oImg23 (new IMAGE);
	shared_ptr<IMAGE> oImg24 (new IMAGE);
	shared_ptr<IMAGE> oImg25 (new IMAGE);
	shared_ptr<IMAGE> oImg26 (new IMAGE);
	shared_ptr<IMAGE> oImg27 (new IMAGE);
	shared_ptr<IMAGE> oImg28 (new IMAGE);
	shared_ptr<IMAGE> oImg29 (new IMAGE);
	shared_ptr<IMAGE> oImg30 (new IMAGE);
	//����ѡ��
	loadimage(oImg1.get(), L"picture/option/upgrade11.png", unit, unit);
	loadimage(oImg2.get(), L"picture/option/upgrade12.png", unit, unit);
	loadimage(oImg3.get(), L"picture/option/upgrade21.png", unit, unit);
	loadimage(oImg4.get(), L"picture/option/upgrade22.png", unit, unit);
	loadimage(oImg5.get(), L"picture/option/upgrade31.png", unit, unit);
	loadimage(oImg6.get(), L"picture/option/upgrade32.png", unit, unit);
	//����ѡ��
	loadimage(oImg7.get(), L"picture/option/sold11.png", unit, unit);
	loadimage(oImg8.get(), L"picture/option/sold12.png", unit, unit);
	loadimage(oImg9.get(), L"picture/option/sold21.png", unit, unit);
	loadimage(oImg10.get(), L"picture/option/sold22.png", unit, unit);
	loadimage(oImg11.get(), L"picture/option/sold31.png", unit, unit);
	loadimage(oImg12.get(), L"picture/option/sold32.png", unit, unit);
	//����ѡ��
	loadimage(oImg13.get(), L"picture/option/add1.png", unit, unit);
	loadimage(oImg14.get(), L"picture/option/add2.png", unit, unit);
	//�����������
	loadimage(oImg15.get(), L"picture/option/tower11.png", unit, unit);
	loadimage(oImg16.get(), L"picture/option/tower12.png", unit, unit);
	loadimage(oImg17.get(), L"picture/option/tower31.png", unit, unit);
	loadimage(oImg18.get(), L"picture/option/tower32.png", unit, unit);
	loadimage(oImg19.get(), L"picture/option/tower21.png", unit, unit);
	loadimage(oImg20.get(), L"picture/option/tower22.png", unit, unit);
	loadimage(oImg21.get(), L"picture/option/untower11.png", unit, unit);
	loadimage(oImg22.get(), L"picture/option/untower12.png", unit, unit);
	loadimage(oImg23.get(), L"picture/option/untower21.png", unit, unit);
	loadimage(oImg24.get(), L"picture/option/untower22.png", unit, unit);
	loadimage(oImg25.get(), L"picture/option/untower31.png", unit, unit);
	loadimage(oImg26.get(), L"picture/option/untower32.png", unit, unit);
	loadimage(oImg27.get(), L"picture/option/unupgrade11.png", unit, unit);
	loadimage(oImg28.get(), L"picture/option/unupgrade12.png", unit, unit);
	loadimage(oImg29.get(), L"picture/option/unupgrade21.png", unit, unit);
	loadimage(oImg30.get(), L"picture/option/unupgrade22.png", unit, unit);
	blockImgList = { oImg2,oImg1,oImg4,oImg3, oImg6,oImg5, oImg8,oImg7, oImg10,oImg9, oImg12,oImg11, oImg14,oImg13, oImg16,oImg15, oImg18,oImg17, oImg20,oImg19,oImg22,oImg21, oImg24,oImg23, oImg26,oImg25, oImg28,oImg27, oImg30,oImg29 };
}

//����ͼƬ
void Game::loadPropImg()
{
	shared_ptr<IMAGE>pImg1 (new IMAGE);
	shared_ptr<IMAGE>pImg2 (new IMAGE);
	shared_ptr<IMAGE>pImg3 (new IMAGE);
	shared_ptr<IMAGE>pImg4 (new IMAGE);
	shared_ptr<IMAGE>pImg5 (new IMAGE);
	shared_ptr<IMAGE>pImg6 (new IMAGE);
	shared_ptr<IMAGE>pImg7 (new IMAGE);
	shared_ptr<IMAGE>pImg8 (new IMAGE);
	shared_ptr<IMAGE>pImg9 (new IMAGE);
	shared_ptr<IMAGE>pImg10 (new IMAGE);

	loadimage(pImg1.get(), L"picture/prop/prop10.png", 2 * unit, 2 * unit);
	loadimage(pImg2.get(), L"picture/prop/prop11.png", 2 * unit, 2 * unit);
	loadimage(pImg3.get(), L"picture/prop/prop20.png", 2 * unit, 2 * unit);
	loadimage(pImg4.get(), L"picture/prop/prop21.png", 2 * unit, 2 * unit);
	loadimage(pImg5.get(), L"picture/prop/prop30.png", 2 * unit, unit);
	loadimage(pImg6.get(), L"picture/prop/prop31.png", 2 * unit, unit);
	loadimage(pImg7.get(), L"picture/prop/prop40.png", unit, unit);
	loadimage(pImg8.get(), L"picture/prop/prop41.png", unit, unit);
	loadimage(pImg9.get(), L"picture/prop/prop50.png", unit, unit);
	loadimage(pImg10.get(), L"picture/prop/prop51.png", unit, unit);

	propImgList = { {pImg2,pImg1},{pImg4,pImg3}, {pImg6,pImg5}, {pImg8,pImg7}, {pImg10,pImg9} };
}

//��������ͼƬ����
void Game::loadDeathImg()
{
	shared_ptr<IMAGE> img1(new IMAGE), img2 (new IMAGE),  img3 (new IMAGE),  img4 (new IMAGE), img5 (new IMAGE),  img6 (new IMAGE),  img7 (new IMAGE),  img8 (new IMAGE),  img9 (new IMAGE), img10 (new IMAGE);
	loadimage(img1.get(), L"picture/monster/gold0.png", unit,  unit/2);
	loadimage(img2.get(), L"picture/monster/gold1.png", unit,  unit/2);
	loadimage(img3.get(), L"picture/monster/death6.png", unit,  unit);
	loadimage(img4.get(), L"picture/monster/death7.png", unit,  unit);
	loadimage(img5.get(), L"picture/monster/death4.png", unit, unit);
	loadimage(img6.get(), L"picture/monster/death5.png", unit, unit);
	loadimage(img7.get(), L"picture/monster/death2.png", unit, unit);
	loadimage(img8.get(), L"picture/monster/death3.png", unit, unit);
	loadimage(img9.get(), L"picture/monster/death0.png", unit, unit);
	loadimage(img10.get(), L"picture/monster/death1.png", unit, unit);

	deathImg = { img2,img1,img4,img3, img6,img5, img8,img7, img10,img9 };
}

//��������
void Game::loadSettingImg()
{
	shared_ptr<IMAGE>img(new IMAGE), topImg(new IMAGE), stop0(new IMAGE), stop1(new IMAGE), cont0(new IMAGE), cont1(new IMAGE), longBlock0(new IMAGE), longBlock1(new IMAGE), home0(new IMAGE), home1(new IMAGE), gameover00(new IMAGE), gameover01(new IMAGE), gameover10(new IMAGE), gameover11(new IMAGE);
	loadimage(img.get(), L"./picture/background.jpg", 12 * unit, 7 * unit);                                 //����ͼƬ
	loadimage(topImg.get(), L"./picture/settings/topItem.png", 12 * unit, unit);                 
	loadimage(stop0.get(), L"./picture/settings/stop0.png", unit, unit);                                     //ֹͣ����ͼƬ
	loadimage(stop1.get(), L"./picture/settings/stop1.png", unit, unit);
	loadimage(cont0.get(), L"./picture/settings/continue0.png", unit, unit);                                 //��������ͼƬ
	loadimage(cont1.get(), L"./picture/settings/continue1.png", unit, unit);
	loadimage(home0.get(), L"./picture/settings/home0.png", 1.3 * unit, unit);                               //������ҳͼƬ
	loadimage(home1.get(), L"./picture/settings/home1.png", 1.3 * unit, unit);
	loadimage(longBlock0.get(), L"./picture/settings/longBlock0.png", 4 * unit, 0.7 * unit);                 //����
	loadimage(longBlock1.get(), L"./picture/settings/longBlock1.png", 4 * unit, 0.7 * unit);
	loadimage(gameover00.get(), L"./picture/settings/gameover00.png", 4 * unit, 3 * unit);                   //��Ϸ����ͼƬ
	loadimage(gameover01.get(), L"./picture/settings/gameover01.png", 4 * unit, 3 * unit);
	loadimage(gameover10.get(), L"./picture/settings/gameover10.png", 4 * unit, 3 * unit);                   
	loadimage(gameover11.get(), L"./picture/settings/gameover11.png", 4* unit, 3 * unit);
	settingImg = { img,topImg,stop1,stop0,cont1,cont0,home1,home0 ,longBlock1,longBlock0 ,gameover01 ,gameover00 ,gameover11 ,gameover10 };
}

//�ܼ���ͼƬ����
void Game::loadImg()
{
	loadTowerImg();
	loadMonsterImg();
	loadBulletImg();
	loadOptionImg();
	loadPropImg();
	loadDeathImg();
	loadSettingImg();
}

//������Ϸ
void Game::refresh()
{
	//��Ϸ����
	t = 0;
	close = false;
	stop=false;
	health = 10;
	monsterInit.reset(new MonsterInit);
	monsterNum = 0;
	gameOver = 0;
}

//��ʼ����Ϸ״̬
void Game::initGame()
{
	gold = 650;
	loadImg();
	//���ʼ��  
	for (int i = 0; i < 12; i++)
	{
		vector<shared_ptr<Block>>tmp;
		for (int j = 0; j < 8; j++)
		{
			tmp.push_back(make_shared<Block>(i,j));
		}
		blockList.push_back(tmp);
	}
	//��̨��ʼ��
	towerList.assign(12, vector<shared_ptr<BaseTower>>(7, nullptr));

	factory.push_back(make_shared<Breed1Factory>());
	factory.push_back(make_shared<Breed2Factory>());
	factory.push_back(make_shared<Breed3Factory>());
	factory.push_back(make_shared<Breed4Factory>());
	factory.push_back(make_shared<Breed5Factory>());
	factory.push_back(make_shared<Breed6Factory>());

	baseFactory.push_back(make_shared<BaseBreed1Factory>());
	baseFactory.push_back(make_shared<BaseBreed2Factory>());
	baseFactory.push_back(make_shared<BaseBreed3Factory>());
	baseFactory.push_back(make_shared<BaseBreed4Factory>());
	baseFactory.push_back(make_shared<BaseBreed5Factory>());

	for (auto& p : baseFactory)
	{
		if(p) monsterList.insert(p->buildMonster());
		
	}
}

//��Ϸ���ݵ�ʵʱ����
void Game::update()
{
	if (monsterInit->Update()) monsterNum++;

	for (auto it = bulletList.begin(); it != bulletList.end();)
	{
		if (!((*(it))->checkHit()))
		{
			it = bulletList.erase(it); //����ӵ���������ײ�������ɾ��
		}
		else
		{
			it++;
		}
	}
	vector<shared_ptr<BaseMonster>>del;
	for (auto& mon : monsterList)
	{
		if (mon->checkHealth()!=0)
		{
			if (mon->checkHealth() == 1)
			{
				//��������
				itemList.push_back(shared_ptr<DeathItem>(new DeathItem(mon->getM().first, mon->getM().second)));
				del.push_back(mon);
				monsterNum--;
				gold += 50;
			}
			else if (mon->checkHealth() == 2)
			{
				//���ﵽ���ܲ�
				del.push_back(mon);
				if (--health <= 0)
				{
					stop = true;
					monsterNum--;
					gameOver = 1;
				}
			}
			else if (mon->checkHealth() == 3)
			{
				//���ߡ�������
				itemList.push_back(shared_ptr<DeathItem>(new DeathItem(mon->getM().first, mon->getM().second)));
				del.push_back(mon);
				gold += 50;
			}
			
		}
	}
	for (auto& mon : del)
	{
		monsterList.erase(mon);
		if (centerMonster == mon) centerMonster.reset();
		for (auto& t : towerList)
		{
			for (auto& tow : t)
			{
				if (!(tow.get())) continue;
				if (tow->targetMonster == mon)
				{
					tow->targetMonster.reset();
				}
				if (tow->set.count(shared_ptr<BaseMonster>(mon))) tow->set.erase(shared_ptr<BaseMonster>(mon));
			}
		}
	}
	//����
	for (auto it = itemList.begin(); it != itemList.end();)
	{
		if (((*it)->check()))
		{
			it = itemList.erase(it); // ͨ��erase�����ķ���ֵ����ȡ��һ��Ԫ�ص�λ��
		}
		else
		{
			it++;
		}
	}

	if (!monsterInit->getGameBegin()&&monsterNum<=0)
	{
		stop = 1;
		gameOver = 2;
	}
}

void Game::render()
{
	BeginBatchDraw();
	putimage(0, unit, settingImg[0].get());
	putimage(0, 0, settingImg[1].get());
	putimage(10.5 * unit, 0, settingImg[6].get(), SRCAND);
	putimage(10.5 * unit, 0, settingImg[7].get(), SRCPAINT);
	putimage(4 * unit, 0.1 * unit, settingImg[8].get(), SRCAND);
	putimage(4 * unit, 0.1 * unit, settingImg[9].get(), SRCPAINT);
	
	for (auto& mon : monsterList)
	{
		mon->draw();
	}
	if (centerMonster) centerMonster->centerDraw();
	for (auto& bul : bulletList)
	{
		bul->draw();
	}
	for (auto& tow : towerList)
	{
		for (auto& t : tow)
		{
			if (!(t.get())) continue;
			t->draw();
		}

	}
	for (auto& row : blockList)
	{
		for (auto& block : row)
		{
			block->draw();
		}
	}
	for (auto& tow : towerList)
	{
		for (auto& t : tow)
		{
			if (!(t.get())) continue;
			t->remind();
		}
	}
	for (auto& p : itemList)
	{
		p->draw();
	}
	setbkmode(TRANSPARENT);

	settextstyle(unit/2, 0, _T("����"));
	wchar_t num[20];
	_itow_s(gold, num, 10);
	outtextxy(unit*1.2, unit/5, num);

	settextstyle(unit / 3, 0, _T("����"));
	wchar_t curHealth[20];
	_itow_s(health, curHealth, 10);
	outtextxy(unit * 11.5, 2.9*unit, curHealth);

	wchar_t count[20];
	_itow_s(monsterInit->getCount(), count, 10);
	outtextxy(unit * 6, unit / 5, count);

	outtextxy(unit * 5, unit/5, L"������ /6������");
	if (!stop)
	{
		putimage(9 * unit, 0, settingImg[2].get(), SRCAND);
		putimage(9 * unit, 0, settingImg[3].get(), SRCPAINT);
	}
	else
	{
		putimage(9 * unit, 0, settingImg[4].get(), SRCAND);
		putimage(9 * unit, 0, settingImg[5].get(), SRCPAINT);
		if (gameOver == 2)
		{
			putimage(4 * unit, 3 * unit, settingImg[10].get(), SRCAND);
			putimage(4 * unit, 3 * unit, settingImg[11].get(), SRCPAINT);
		}
		else if (gameOver == 1)
		{
			putimage(4 * unit, 3 * unit, settingImg[12].get(), SRCAND);
			putimage(4 * unit, 3 * unit, settingImg[13].get(), SRCPAINT);
		}
	}

	EndBatchDraw();
}

bool Game::makeEnd()
{
	if (gameOver)
	{
		while (1)
		{
			if (MouseHit())
			{
				auto m = GetMouseMsg();
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					if (m.x / unit >= 5 && m.x / unit <= 6.6 && m.y / unit >= 4.2 && m.y / unit <= 4.7)
					{
						deleteGame();
						refresh();
						initGame();
						return false;
					}
					else if (m.x / unit >= 5 && m.x / unit <= 6.6 && m.y / unit >= 4.9 && m.y / unit <= 5.4) return true;
				}
			}
		}
	}
	return false;
}

void Game::stopBreak()
{
	//��ͣ���Ĵ���
	if (stop&&gameOver==0)
	{
		while (1)
		{
			if (MouseHit())
			{
				auto m = GetMouseMsg();
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					if (m.x / unit >= 5 && m.x / unit <= 10 && m.y / unit >= 0 && m.y / unit <= 1)
					{
						stop = false;
						break;
					}
					
				}
			}
		}
	}
}

void Game::deleteGame()
{
	//�ͷ��ڴ�
	towerImgList.clear();
	towerList.clear();
	blockImgList.clear();
	bulletList.clear();
	itemList.clear();
	bulletImgList.clear();
	propImgList.clear();
	blockList.clear();
	monsterImgList.clear();
	centerImg.clear();
	deathImg.clear();
	factory.clear();
	baseFactory.clear();
	monsterList.clear();
}

void Game::going()
{
	//��Ϸ��������
	loadImg();
	srand(time(NULL));
	initGame();
	while (1)
	{
		if(processIuput()) break;
		update();
		render();
		stopBreak();
		if (makeEnd())break;
		Sleep(50);
		
	}
}

Game::~Game()
{
	deleteGame();
}

Game::Game() :t(0), close(false),stop(false) ,health(10),monsterInit(new MonsterInit),monsterNum(0),gameOver(0){};