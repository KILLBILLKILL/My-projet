#include<stdio.h>
#include<time.h>
#include<graphics.h>//easyX图形界面库
#define NUM 10 //雷的总数
IMAGE img[12];// 0 1 2 3 4 5 6 7 8 雷 地图 标记 
void DrawMap();
int Playgame();
int map[12][12];
void GameInit();
int  hitNum;
void fun(int x, int y);
#include<stdlib.h>
//主函数
int main(){

	initgraph(500, 500);
	int flag;
	HWND hwnd = GetHWnd();
	//打开一个窗口 宽度 高度
	while (1)
	{
		GameInit();
		while (1){
			DrawMap();
			flag = Playgame();//9 
			if (flag == 9){
				DrawMap();
				MessageBox(hwnd, "你输了，朋友", "", MB_OK);
				break;

			}//hitNum 点开的个数+ Num雷的数量=100
			else if (100 - hitNum == NUM){

				MessageBox(hwnd, "你赢了，朋友", "", MB_OK);
				break;

			}
		}
		if (MessageBox(hwnd, "再玩一局？", "", MB_RETRYCANCEL) == IDCANCEL)

			break;

	}
	GameInit();
	while (1){
		DrawMap();
		flag = Playgame();//9 
		if (flag == 9){
			DrawMap();
			MessageBox(hwnd, "你输了，朋友", "", MB_OK);
			break;

		}//hitNum 点开的个数+ Num雷的数量=100
		else if (100 - hitNum == NUM){

			MessageBox(hwnd, "你赢了，朋友", "", MB_OK);
			break;

		}
	}


	system("pause");
	return 0;
}

//游戏初始化
void GameInit(){
	  hitNum=0;
	int i, j, m, n;
	//随机数种子
	srand((unsigned int)time(NULL));
	//初始化数组
	hitNum = 0;//点开的为0

	for (i = 0; i < 12; ++i){
		for (j = 0; j < 12; j++){
			map[i][j] = 0;



		}


	}
	//埋雷 1.中间的十行十列，2.十个雷
	for (i = 0; i < NUM;){

		m = rand() % 10 + 1;//行
		n = rand() % 10 + 1;//列

		if (map[m][n] == 0)//没有埋过雷
		{
			map[m][n] = -1;//-1表示雷
			++i;
		}

	}
	//根据雷的分布情况，去填充数组的元素
	for (i = 1; i <= 10; ++i)//遍历10行10列
	{

		for (j = 1; j <= 10; ++j){

			if (map[i][j] == 0)//不是雷
			{
				//遍历9宫格
				for (m = i - 1; m <= i + 1; ++m)//3行
				{
					for (n = j - 1; n <= j + 1; ++n)//3列
					{
						if (map[m][n] == -1)
						{
							++map[i][j];

						}
					}
				}
			}
		}
	}
	//加载图片 
	loadimage(&img[0], "./res/0.jpg", 50, 50);
	loadimage(&img[1], "./res/1.jpg", 50, 50);
	loadimage(&img[2], "./res/2.jpg", 50, 50);
	loadimage(&img[3], "./res/3.jpg", 50, 50);
	loadimage(&img[4], "./res/4.jpg", 50, 50);
	loadimage(&img[5], "./res/5.jpg", 50, 50);
	loadimage(&img[6], "./res/6.jpg", 50, 50);
	loadimage(&img[7], "./res/7.jpg", 50, 50);
	loadimage(&img[8], "./res/8.jpg", 50, 50);
	loadimage(&img[9], "./res/雷.jpg", 50, 50);
	loadimage(&img[10], "./res/地图.jpg", 50, 50);
	loadimage(&img[11], "./res/标记.jpg", 50, 50);
}
//绘制地图，10*10
void DrawMap()
{


	for (int i = 1; i <= 10; ++i)
	{

		for (int j = 1; j <= 10; ++j)
		{

			if (map[i][j] > 20)//标记的图片

				putimage((i - 1) * 50, (j - 1) * 50, &img[11]);
			else{






				switch (map[i][j])//根据二维数组的元素来绘制 
				{
				case 9://最简单的加密+10   -10解密 最简单的加密解密
					putimage((i - 1) * 50, (j - 1) * 50, &img[9]);
					break;
				case 10:
					putimage((i - 1) * 50, (j - 1) * 50, &img[0]);
					break;
				case 11:
					putimage((i - 1) * 50, (j - 1) * 50, &img[1]);
					break;
				case 12:
					putimage((i - 1) * 50, (j - 1) * 50, &img[2]);
					break;
				case 13:
					putimage((i - 1) * 50, (j - 1) * 50, &img[3]);
					break;
				case 14:
					putimage((i - 1) * 50, (j - 1) * 50, &img[4]);
					break;
				case 15:
					putimage((i - 1) * 50, (j - 1) * 50, &img[5]);
					break;
				case 16:
					putimage((i - 1) * 50, (j - 1) * 50, &img[6]);
					break;
				case 17:
					putimage((i - 1) * 50, (j - 1) * 50, &img[7]);
					break;
				case 18:
					putimage((i - 1) * 50, (j - 1) * 50, &img[8]);
					break;
				default:
					putimage((i - 1) * 50, (j - 1) * 50, &img[10]);
					break;
				}
			}
		}
	}
}
//玩游戏
int Playgame()
{
	//定义一个鼠标消息
	MOUSEMSG m;//一个结构体 F12
	m = GetMouseMsg();//获取鼠标消息
	switch (m.uMsg)
	{
		//鼠标的左键点击   翻开
	case WM_LBUTTONDBLCLK:// L left BUTTON DOWN 按下
		if (map[m.x / 50 + 1][m.y / 50 + 1] == 0)
		{
			fun(m.x / 50 + 1, m.y / 50 + 1);





		}

		else if (map[m.x / 50 + 1][m.y / 50 + 1] < 9)// 9之前是盖着的
		{

			map[m.x / 50 + 1][m.y / 50 + 1] += 10;// 9 10  11 12 13 14 15
			hitNum++;
		}

			return map[m.x / 50 + 1][m.y / 50 + 1] ;//9
			break;
		

	case WM_RBUTTONDBLCLK: //鼠标的右键点击 标记 确定某一个位置是雷 右键标记
		if (map[m.x / 50 + 1][m.y / 50 + 1] < 9)
		{

			map[m.x / 50 + 1][m.y / 50 + 1] += 30;

		}
		else if (map[m.x / 50 + 1][m.y / 50 + 1] >20){

			map[m.x / 50 + 1][m.y / 50 + 1] -= 30;

		}
		break;
	}
}

void fun(int x, int y)
{
	//先打开点击的0；

	map[x][y]+=10;
	hitNum++;
	for (int m = x - 1; m <= x + 1; m++)
	{

		for (int n = y - 1; n <= y + 1; n++)
		{
			if (m >= 1 && m <= 10 && n >= 1 && n <= 10)
			{
				if (map[m][n] <= 9)
				{

					if (map[m][n] != 0){
						map[m][n] += 10;
						hitNum++;
					}
					else
					{
						fun(m, n);


					}

				}
			}

		}
	}
	

}

