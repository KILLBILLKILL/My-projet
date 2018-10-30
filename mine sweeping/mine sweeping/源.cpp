#include<stdio.h>
#include<time.h>
#include<graphics.h>//easyXͼ�ν����
#define NUM 10 //�׵�����
IMAGE img[12];// 0 1 2 3 4 5 6 7 8 �� ��ͼ ��� 
void DrawMap();
int Playgame();
int map[12][12];
void GameInit();
int  hitNum;
void fun(int x, int y);
#include<stdlib.h>
//������
int main(){

	initgraph(500, 500);
	int flag;
	HWND hwnd = GetHWnd();
	//��һ������ ��� �߶�
	while (1)
	{
		GameInit();
		while (1){
			DrawMap();
			flag = Playgame();//9 
			if (flag == 9){
				DrawMap();
				MessageBox(hwnd, "�����ˣ�����", "", MB_OK);
				break;

			}//hitNum �㿪�ĸ���+ Num�׵�����=100
			else if (100 - hitNum == NUM){

				MessageBox(hwnd, "��Ӯ�ˣ�����", "", MB_OK);
				break;

			}
		}
		if (MessageBox(hwnd, "����һ�֣�", "", MB_RETRYCANCEL) == IDCANCEL)

			break;

	}
	GameInit();
	while (1){
		DrawMap();
		flag = Playgame();//9 
		if (flag == 9){
			DrawMap();
			MessageBox(hwnd, "�����ˣ�����", "", MB_OK);
			break;

		}//hitNum �㿪�ĸ���+ Num�׵�����=100
		else if (100 - hitNum == NUM){

			MessageBox(hwnd, "��Ӯ�ˣ�����", "", MB_OK);
			break;

		}
	}


	system("pause");
	return 0;
}

//��Ϸ��ʼ��
void GameInit(){
	  hitNum=0;
	int i, j, m, n;
	//���������
	srand((unsigned int)time(NULL));
	//��ʼ������
	hitNum = 0;//�㿪��Ϊ0

	for (i = 0; i < 12; ++i){
		for (j = 0; j < 12; j++){
			map[i][j] = 0;



		}


	}
	//���� 1.�м��ʮ��ʮ�У�2.ʮ����
	for (i = 0; i < NUM;){

		m = rand() % 10 + 1;//��
		n = rand() % 10 + 1;//��

		if (map[m][n] == 0)//û�������
		{
			map[m][n] = -1;//-1��ʾ��
			++i;
		}

	}
	//�����׵ķֲ������ȥ��������Ԫ��
	for (i = 1; i <= 10; ++i)//����10��10��
	{

		for (j = 1; j <= 10; ++j){

			if (map[i][j] == 0)//������
			{
				//����9����
				for (m = i - 1; m <= i + 1; ++m)//3��
				{
					for (n = j - 1; n <= j + 1; ++n)//3��
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
	//����ͼƬ 
	loadimage(&img[0], "./res/0.jpg", 50, 50);
	loadimage(&img[1], "./res/1.jpg", 50, 50);
	loadimage(&img[2], "./res/2.jpg", 50, 50);
	loadimage(&img[3], "./res/3.jpg", 50, 50);
	loadimage(&img[4], "./res/4.jpg", 50, 50);
	loadimage(&img[5], "./res/5.jpg", 50, 50);
	loadimage(&img[6], "./res/6.jpg", 50, 50);
	loadimage(&img[7], "./res/7.jpg", 50, 50);
	loadimage(&img[8], "./res/8.jpg", 50, 50);
	loadimage(&img[9], "./res/��.jpg", 50, 50);
	loadimage(&img[10], "./res/��ͼ.jpg", 50, 50);
	loadimage(&img[11], "./res/���.jpg", 50, 50);
}
//���Ƶ�ͼ��10*10
void DrawMap()
{


	for (int i = 1; i <= 10; ++i)
	{

		for (int j = 1; j <= 10; ++j)
		{

			if (map[i][j] > 20)//��ǵ�ͼƬ

				putimage((i - 1) * 50, (j - 1) * 50, &img[11]);
			else{






				switch (map[i][j])//���ݶ�ά�����Ԫ�������� 
				{
				case 9://��򵥵ļ���+10   -10���� ��򵥵ļ��ܽ���
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
//����Ϸ
int Playgame()
{
	//����һ�������Ϣ
	MOUSEMSG m;//һ���ṹ�� F12
	m = GetMouseMsg();//��ȡ�����Ϣ
	switch (m.uMsg)
	{
		//����������   ����
	case WM_LBUTTONDBLCLK:// L left BUTTON DOWN ����
		if (map[m.x / 50 + 1][m.y / 50 + 1] == 0)
		{
			fun(m.x / 50 + 1, m.y / 50 + 1);





		}

		else if (map[m.x / 50 + 1][m.y / 50 + 1] < 9)// 9֮ǰ�Ǹ��ŵ�
		{

			map[m.x / 50 + 1][m.y / 50 + 1] += 10;// 9 10  11 12 13 14 15
			hitNum++;
		}

			return map[m.x / 50 + 1][m.y / 50 + 1] ;//9
			break;
		

	case WM_RBUTTONDBLCLK: //�����Ҽ���� ��� ȷ��ĳһ��λ������ �Ҽ����
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
	//�ȴ򿪵����0��

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

