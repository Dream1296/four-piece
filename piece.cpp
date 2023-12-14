#include <graphics.h>
#include <iostream>
#include "img.h"
#include <direct.h>  //创建文件夹
#include"piece.h"

//定义棋盘左上角位置和棋盘宽度和正方形棋子边长
#define mx 170
#define my 90
#define mz 150   
#define mr 23





IMAGE piece0, piece1, beijin;

//棋盘
char piece[4][4] = {
	{'A', 'B', 'C', 'D'},
	{'0', '0', '0', '0'},
	{'0', '0', '0', '0'},
	{'a', 'b', 'c', 'd'}
};

//棋子位置
int X = 0;
int Y = 0;
int* x = &X;
int* y = &Y;

//各方棋子数量
int a0 = 4;
int a1 = 4;


void chushihua() {
	loadimage(&beijin, _T("imgpiecedream\\beijin.png"));
	loadimage(&piece0, _T("imgpiecedream\\piece0.png"));
	loadimage(&piece1, _T("imgpiecedream\\piece1.png"));
	
}





#pragma comment(lib, "MSIMG32.LIB")
inline void putimgage_s(int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER , 0, 255, AC_SRC_ALPHA });

}

int win() {
	if (a0 == 1) {
		return 1;
	}
	else if (a1 == 1)
	{
		return 0;
	}
	return -1;
}


int fun(char a) {
	char arr[] = { 'A','B','C','D' };
	char acc[] = { 'a','b','c','d' };
	for (int i = 0; i < 4; i++) {
		if (arr[i] == a) {
			return 1;
		}
		if (acc[i] == a) {
			return 0;
		}
	}
	return -1;
}
void prpiece() {


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int c = fun(piece[i][j]);
			if (c == 0) {
				putimgage_s(mz * j + mx - mr, mz * i + my - mr, &piece0);  
			}
			else if (c == 1) {
				putimgage_s(mz * j + mx - mr, mz * i + my - mr, &piece1);
			}

		}
	}
}





void huaxian() {
	/*line(0, 100, 400, 100);
	line(0, 200, 400, 200);
	line(0, 300, 400, 300);
	line(0, 400, 400, 400);

	line(100, 0, 100, 400);
	line(200, 0, 200, 400);
	line(300, 0, 300, 400);
	line(400, 0, 400, 400);*/
	int x = mx;   //170
	int y = my;    //90
	int z = mz;    //150
 	line(x, y, x + 3*z, y);
	line(x, y + 1*z, x + 3*z, y + 1*z);
	line(x, y + 2*z, x + 3*z, y + 2*z);
	line(x, y + 3*z, x + 3*z, y + 3*z);

	line(x, y, x, y + 3*z);
	line(x + 1*z, y, x + 1*z, y + 3*z);
	line(x + 2*z, y, x + 2*z, y + 3*z);
	line(x + 3*z, y, x + 3*z, y + 3*z);
}


void beijins() {
	cleardevice();
	putimage(0, 0, &beijin);
	huaxian();
	prpiece();
	Sleep(10);
	prpiece();

}

void picount(int player) {
	player = (player + 1) % 2;
	if (player == 0) {
		a0 -= 1;
		//printf("01方各有%d %d ", a0, a1);
	}
	else if (player == 1)
	{
		a1 -= 1;
		//printf("01方各有%d %d ", a0, a1);
	}
}



//判断位置内棋子是否为指定方
int gpspl(int x, int y, int playeras) {
	char play0[] = { 'a','b','c','d' };
	char play1[] = { 'A','B','C','D' };
	if (!(x >= 0 && x <= 3 && y >= 0 && y <= 3) || piece[x][y] == '0') {
		return 0;
	}

	if (playeras == 0) {
		for (int i = 0; i < 4; i++) {
			if (piece[x][y] == play0[i]) {
				return 1;
			}
		}
	}
	else if (playeras == 1)
	{
		for (int i = 0; i < 4; i++) {
			if (piece[x][y] == play1[i]) {
				return 1;
			}
		}
	}
	return 0;

}

void logic(int player , playdy * dy) {
	//刷新用户刚才移动的棋子当前的位置
	char play0[] = { 'a','b','c','d' };
	char play1[] = { 'A','B','C','D' };
	//0为空或越界，1为友方，2为地方，A为移动的棋子，

	//初始化
	int cx = 0;
	int cy = 0;

	//player = (player + 1) % 2;

	if (dy == NULL) {
		cx = *x;
		cy = *y;
	}
	else
	{
		cy = dy->x2;
		cx = dy->y2;
	}

	




	//水平方向
	//通过左边攻击右边1       0 1 A 2 0
	int a = gpspl(cx, cy - 1, player);   //左边有己方棋子
	int b = gpspl(cx, cy + 1, (player + 1) % 2);  //右边有敌方棋子
	int c = gpspl(cx, cy + 2, player);  //右边2格越界或为空
	int d = gpspl(cx, cy - 2, player); //左2格为空或越界
	printf("\n abc分别为:%d%d%d\n", a, b, c);
	if (a && b && !c && !d) {
		printf("这个代码运行了\n");
		piece[cx][cy + 1] = '0';
		picount(player);  //刷新棋子数量
	}
	//TCHAR arr[20];
	//TCHAR ass[20];
	//_stprintf_s(arr, _T("%d %d"), *x, *y);
	//_stprintf_s(ass, _T("%d %d %d %d"), a, b, c, d);
	//outtextxy(200, 200, arr);
	//outtextxy(300, 300, ass);

	//Sleep(2000);
	// 
	//通过左边攻击右边2       0 A 1 2 0 
	a = gpspl(cx, cy - 1, player);    //0
	b = gpspl(cx, cy + 1, player);  //1
	c = gpspl(cx, cy + 2, (player + 1) % 2); //2
	d = gpspl(cx, cy + 3, player); //0
	if (!a && b && c && !d) {
		piece[cx][cy + 2] = '0';
		picount(player);  //刷新棋子数量
	}
	//右攻击左1      0 2 1 A 0
	a = gpspl(cx, cy - 3, player);   //0
	b = gpspl(cx, cy - 2, (player + 1) % 2);  //2
	c = gpspl(cx, cy - 1, player);  //1
	d = gpspl(cx, cy + 1, player);  //0
	if (!a && b && c && !d) {
		piece[cx][cy - 2] = '0';
		picount(player);  //刷新棋子数量
	}

	//右攻击左2     0 2 A 1 0
	a = gpspl(cx, cy - 2, player);
	b = gpspl(cx, cy - 1, (player + 1) % 2);
	c = gpspl(cx, cy + 1, player);
	d = gpspl(cx, cy + 2, player);

	if (!a && b && c && !d) {
		piece[cx][cy - 1] = '0';
		picount(player);  //刷新棋子数量
	}
	//垂直方向

	//上攻击下1     0 A 1 2 0 (从上到下)
	a = gpspl(cx - 1, cy, player);
	b = gpspl(cx + 1, cy, player);
	c = gpspl(cx + 2, cy, (player + 1) % 2);
	d = gpspl(cx + 3, cy, player);
	if (!a && b && c && !d) {
		printf("满足上攻击下1\n");
		piece[cx + 2][cy] = '0';
		picount(player);  //刷新棋子数量
	}

	//上攻击下2     0 1 A 2 0
	a = gpspl(cx - 2, cy, player);
	b = gpspl(cx - 1, cy, player);
	c = gpspl(cx + 1, cy, (player + 1) % 2);
	d = gpspl(cx + 2, cy, player);
	if (!a && b && c && !d) {
		printf("满足上攻击下2\n");
		printf("%d %d %d %d\n", a, b, c, d);
		piece[cx + 1][cy] = '0';
		picount(player);   //刷新棋子数量
	}

	//下攻击上1     0  2 1 A 0
	a = gpspl(cx - 3, cy, player);
	b = gpspl(cx - 2, cy, (player + 1) % 2);
	c = gpspl(cx - 1, cy, player);
	d = gpspl(cx + 1, cy, player);
	if (!a && b && c && !d) {
		printf("满足下攻击上1\n");
		piece[cx - 2][cy] = '0';
		picount(player);   //刷新棋子数量
	}
	//TCHAR arr[20];
	//TCHAR ass[20];
	//_stprintf_s(arr, _T("%d %d"), cx, cy);
	//_stprintf_s(ass, _T("%d %d %d %d"), a, b, c, d);     // 2 3 0101
	//outtextxy(200, 200, arr);
	//outtextxy(300, 300, ass);
	//Sleep(5000);

	//下攻上2        0 2 1 A 0
	a = gpspl(cx - 2, cy, player);
	b = gpspl(cx - 1, cy, (player + 1) % 2);
	c = gpspl(cx + 1, cy, player);
	d = gpspl(cx + 2, cy, player);
	if (!a && b && c && !d) {
		printf("满足下攻击上2\n");
		piece[cx - 1][cy] = '0';
		picount(player);   //刷新棋子数量
	}
}



int shuru(int player , int cp , playdy * dy) {
	int ind = 1;
	int x1 = 0;
	int y1 = 0;
	int x2 = 0;
	int y2 = 0;
	int pcl = 0;
	//TCHAR dy[50];
	ExMessage m;
	int amx = mx - (mz / 2);
	int amy = my - (mz / 2);

	while (1) {
		while (ind <= 2)
		{
			m = getmessage(EX_MOUSE);
			if (m.message == WM_LBUTTONDOWN) {
				int x = m.x - amx; 
				int y = m.y - amy;
				
				if (ind == 1) {
					x1 = x / mz;
					y1 = y / mz;
				}
				else
				{
					x2 = x / mz;
					y2 = y / mz;
				}
				ind++;
				circle( mz * (x / mz) + mx , mz * (y / mz) + my , 35);
			}
		}
		if (fun(piece[y1][x1]) == player) {
			ind = 1;
			beijins();
			MessageBox(GetHWnd(), L"你不能移动对方的棋子", L"提示", MB_OK);
			continue;
		}
		//不能移动到别人身上
		if (piece[y2][x2] != '0') {
			ind = 1;
			beijins();
			MessageBox(GetHWnd(), L"你不能骑在她身上！", L"提示", MB_OK);
			continue;
		}
		if (!((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1) == 1)) {
			ind = 1;
			beijins();
			MessageBox(GetHWnd(), L"你只能移动一格！", L"提示", MB_OK);
			continue;
		}




		//获取输入到这里结束
		pcl = fun(piece[y1][x1]);
		if (pcl == 0) {
			piece[y2][x2] = piece[y1][x1];
			piece[y1][x1] = '0';
		}
		else
		{
			piece[y2][x2] = piece[y1][x1];
			piece[y1][x1] = '0';
		}
		beijins();

		//判断输入是否合法，是则将值转为字符串类型存入全局
		//否则还原字符串赋值。
		Sleep(10);


		//*a = piece[y1][x1];
		*x = y2;
		*y = x2;
		if (cp == 2) {
			dy->x1 = x1;
			dy->y1 = y1;
			dy->x2 = x2;
			dy->y2 = y2;
		}
		return 1;
		Sleep(10);
		ind = 1;
		Sleep(50);
	}

}

int shurus(playdy * dy ) {
	int x1 = dy->x1;
	int y1 = dy->y1;
	int x2 = dy->x2;
	int y2 = dy->y2;

	piece[y2][x2] = piece[y1][x1];
	piece[y1][x1] = '0';

	return 1;

}
