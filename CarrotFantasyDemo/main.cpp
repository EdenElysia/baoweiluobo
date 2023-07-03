#include"Game.h"
void gameRunning()
{
	IMAGE* img = new IMAGE();
	loadimage(img, L"picture/settings/start.png", 12 * unit, 8 * unit);
	initgraph(12 * unit, 8 * unit);
	putimage(0, 0, img);
	int flag = 1;
	while (flag)
	{
		if (MouseHit())
		{
			auto m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				int i = m.x / unit, j = m.y / unit;
				if (i >= 3 && i <= 5 && j >= 6 && j <= 8)
				{
					Game* game = new Game();
					game->going();
					delete game;
				}
				else if (i >= 7 && i <= 9 && j >= 6 && j <= 8)
				{
					flag = 0;
				}
				putimage(0, 0, img);
			}
		}
	}
	closegraph();
}
int main()
{
	gameRunning();
    return 0;
}