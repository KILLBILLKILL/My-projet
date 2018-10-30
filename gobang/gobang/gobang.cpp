#include<graphics.h>//ͼ�ο�ͷ�ļ�
#include<stdlib.h>
#include<stdio.h>
//#include<mmsystem.h>//��������Ҫ�õ���ͷ�ļ�
//#pragma comment(lib,"winmm.lib")//���������õ��Ŀ��ļ�
void initGame();
void playChess();
int flag = 0;//��¼�ֵ�˭����
int board[20][20] = { 0 };//û������
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
	//�Լ�����һ������
	initgraph(600, 500);
	loadimage(NULL, "����.jpg");
	//mciSendString("open ���ﳤ��.mp3",0,0,0);
	//mciSendString("play ���ﳤ��.mp3",0,0,0);
	//��һ���ߵ���ɫ
	setlinecolor(BLACK);
	//�������� ѭ��
	for (int i = 1; i <20; ++i){

		line(i * 25, 0, 25 * i, 500);
		line(0, i * 25, 500, i * 25);

	}
	line(500, 0, 500, 500);
	line(501, 0, 501, 500);//��������
	outtextxy(512, 60, "���1������");
	outtextxy(512, 100, "���2������");

}

//����
void playChess()
{
	//���������
	MOUSEMSG m;
	int a, b;
	int x, y;
	HWND hwnd;//���ھ��
	hwnd = GetHWnd();//������ǰ
	while (1)
	
	{
		m = GetMouseMsg();//��ȡһ�������Ϣ


		//����ֵ
		for (int i = 1; i < 20; ++i)
		{
			for (int j = 1; j < 20; ++j)
			{

				if (abs(m.x - i * 25) < 12 && abs(m.y - j * 25) < 12){

					a = i;//���к�
					b = j;//���к�
					x = i * 25;//����
					y = j * 25;//����


				}

			}


		}
		if (m.uMsg == WM_LBUTTONDOWN)//�жϵ�ǰ�����Ϣ�ǲ����������
		{
			if (board[a][b] != 0){

				MessageBox(hwnd, "�����Ѿ�����ռ�ˣ�������ѡ��", "������", MB_OK);
				//�˳�ѭ��
				continue;//����ֱ��break


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
				MessageBox(hwnd, "���1ʤ��", "��Ϸ����", MB_OK);

				exit(0);//�˳�����
			}

			else{
				MessageBox(hwnd, "���2ʤ��", "��Ϸ����", MB_OK);
				exit(0);//�˳�����


			}


		}
	}
}
//�ж���Ӯ
int judgewin(int a, int b)
{    //a-4 a-3              
	//a- 3 a-2 a-1 a a+1
	//a-2 a-1 a a+1 a+2 a+3
	//
	//
	int i, j;
	int t = 2 - flag % 2;
	//���ŷ�����ж�
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