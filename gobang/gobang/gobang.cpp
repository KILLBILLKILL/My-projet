#include<graphics.h>//图形库头文件
#include<stdlib.h>
#include<stdio.h>
//#include<mmsystem.h>//播放音乐要用到的头文件
//#pragma comment(lib,"winmm.lib")//播放音乐用到的库文件
void initGame();
void playChess();
int flag = 0;//记录轮到谁下棋
int board[20][20] = { 0 };//没有下棋
int judgewin(int a, int b);

int main()
{
	initGame();
	playChess();
	system("pause");
	return 0;
}
void initGame()
{
	//自己创建一个窗口
	initgraph(600, 500);
	loadimage(NULL, "背景.jpg");
	//mciSendString("open 万里长城.mp3",0,0,0);
	//mciSendString("play 万里长城.mp3",0,0,0);
	//改一下线的颜色
	setlinecolor(BLACK);
	//绘制棋盘 循环
	for (int i = 1; i <20; ++i){

		line(i * 25, 0, 25 * i, 500);
		line(0, i * 25, 500, i * 25);

	}
	line(500, 0, 500, 500);
	line(501, 0, 501, 500);//加深线条
	outtextxy(512, 60, "玩家1：黑棋");
	outtextxy(512, 100, "玩家2：白棋");

}

//下棋
void playChess()
{
	//鼠标左键点击
	MOUSEMSG m;
	int a, b;
	int x, y;
	HWND hwnd;//窗口句柄
	hwnd = GetHWnd();//窗口至前
	while (1)
	
	{
		m = GetMouseMsg();//获取一个鼠标消息


		//绝对值
		for (int i = 1; i < 20; ++i)
		{
			for (int j = 1; j < 20; ++j)
			{

				if (abs(m.x - i * 25) < 12 && abs(m.y - j * 25) < 12){

					a = i;//行列号
					b = j;//行列号
					x = i * 25;//坐标
					y = j * 25;//坐标


				}

			}


		}
		if (m.uMsg == WM_LBUTTONDOWN)//判断当前鼠标消息是不是左键按下
		{
			if (board[a][b] != 0){

				MessageBox(hwnd, "这里已经被人占了，请重新选择", "五子棋", MB_OK);
				//退出循环
				continue;//不能直接break


			}


			if (flag % 2 == 0)//
			{
				setfillcolor(BLACK);
				solidcircle(x, y, 10);
				board[a][b] = 1;
			}
			else{
				setfillcolor(WHITE);
				solidcircle(x, y, 10);
				board[a][b] = 2;
			}
			++flag;//1  3  5  2  4  6

		}
		if (judgewin(a, b))
		{
			if (flag % 2 == 1)
			{
				MessageBox(hwnd, "玩家1胜利", "游戏结束", MB_OK);

				exit(0);//退出程序
			}

			else{
				MessageBox(hwnd, "玩家2胜利", "游戏结束", MB_OK);
				exit(0);//退出程序


			}


		}
	}
}
//判断输赢
int judgewin(int a, int b)
{    //a-4 a-3              
	//a- 3 a-2 a-1 a a+1
	//a-2 a-1 a a+1 a+2 a+3
	//
	//
	int i, j;
	int t = 2 - flag % 2;
	//横着方向的判断
	for (i = a - 4, j = b; i <= a; ++i){

		if (i >= 1 && i <= 15 && t == board[i][j] && t == board[i + 1][j] && t == board[i + 2][j] && t == board[i + 3][j] && t == board[i + 4][j]){

			return 1;
		}
	}
	for (i = a, j = b - 4; j <= b; ++j){

		if (i >= 1 && i <= 15 && t == board[i][j] && t == board[i][j + 1] && t == board[i][j + 2] && t == board[i][j + 3] && t == board[i][j + 4]){

			return 1;
		}
		for (i = a - 4, j = b - 4; i <= a, j <= b; ++i, ++j)
		{
			if (i >= 1 && i <= 15 && j >= 1 && j <= 15 && t == board[i][j] & t == board[i + 1][j + 1] && t == board[i + 2][j + 2] && t == board[i + 3][j + 3] && t == board[i + 4][j + 4]){

				return 1;
			}


		}
		for (i = a - 4, j = b + 4; i <= a, j >= 1; ++i, --j)
		{
			if (i >= 1 && i <= 15 && j >= 1 && j <= 15 && t == board[i][j] & t == board[i + 1][j - 1] && t == board[i + 2][j - 2] && t == board[i + 3][j - 3] && t == board[i + 4][j - 4]){

				return 1;
			}


		}
		return 0;


	}






}