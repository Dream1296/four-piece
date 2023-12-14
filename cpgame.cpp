#include <graphics.h>
#include <iostream>
#include <direct.h>  //创建文件夹
#include"piece.h"
#include <mysql.h>

int cpgame();
int cpgames();
int chonkai();

int cpgamestart() {
	cleardevice();
	IMAGE cpstrat;
	loadimage(&cpstrat, _T("imgpiecedream\\shuang1.png"));
	putimage(0, 0, &cpstrat);

	Sleep(500);
	int x = 0;
	int y = 0;
	ExMessage m;

	while (true)
	{
		m = getmessage(EX_MOUSE);

		if (m.message == WM_LBUTTONDOWN) {
			x = m.x;
			y = m.y;
			if (x > 47 && x < 283 && y > 216 && y < 319) {
				chonkai();
				Sleep(50);
				cpgame();
			}
			if (x > 432 && x < 706 && y > 217 && y < 320) {
				Sleep(50);
				cpgames();
			}
		}
	}
	return 0;
}

//先手    先手为1

int cpgame() {
	chushihua();
	beijins();
	MYSQL* conn = mysql_init(NULL);
	playdy dy;

	if (mysql_real_connect(conn, "frp-man.top", "pieceon", "A16621342366", "piece", 36384, NULL, 0) == NULL) {
		//printf("Mysql状态异常，无法连接");
		return -1;
	}

	//查询轮到谁开始
	int player = getplayer(conn);
	int xianshou = 1;
	while (true)
	{
		
		if (player != 1) {
			player = getplayer(conn);
			Sleep(100); //延迟请求
			continue;
		}
		if (xianshou == 1) {   //先手
			xianshou++;
			shuru(player,2,&dy);  //获取用户输入
			beijins();
			setdy(conn, player, dy.x1, dy.y1, dy.x2, dy.y2); //将输入传入数据库
			setplayer(conn, 0);  //刷新用户标识符
			player = 0;
			continue;
		}

		getyd(conn,0,&dy);  //获取用户上一次的输入
		shurus(&dy);   //执行对方输入的
		logic(1, &dy);
		beijins();
		int winsc = win();
		if (winsc == 1) {
			MessageBox(GetHWnd(), L"游戏结束，您(黑方)输了", L"结果", MB_OK);
			return 10;
		}
		else if(winsc == 0)
		{
			MessageBox(GetHWnd(), L"游戏结束，恭喜(黑方)获得胜利", L"结果", MB_OK);
			return 11;
		}
		shuru(player, 2, &dy);  //自己执行
		logic(0, &dy);
		beijins();
		setdy(conn, player, dy.x1, dy.y1, dy.x2, dy.y2); //将输入传入数据库
		setplayer(conn, (player + 1) % 2);  //刷新用户标识符
		player = 0;   
		



	}


	return 1;
}


//后手
int cpgames() {
	chushihua();
	beijins();
	MYSQL* conn = mysql_init(NULL);
	playdy dy;

	if (mysql_real_connect(conn, "frp-man.top", "piecetr", "A16621342366", "piece", 36384, NULL, 0) == NULL) {
		//printf("Mysql状态异常，无法连接");
		return -1;
	}


	//查询轮到谁开始
	int player = getplayer(conn);
	while (true)
	{

		if (player != 0) {
			player = getplayer(conn);
			Sleep(200); //延迟请求
			continue;
		}

		getyd(conn, 1, &dy);  //获取用户上一次的输入   
		shurus(&dy);//执行对方输入的
		logic(0, &dy);
		beijins();
		int winsc = win();
		if (winsc == 0) {
			MessageBox(GetHWnd(), L"游戏结束，您(白方)输了", L"结果", MB_OK);
		}
		else if (winsc == 1)
		{
			MessageBox(GetHWnd(), L"游戏结束，恭喜(白方)获得胜利", L"结果", MB_OK);
		}
		shuru(player, 2, &dy);  //自己执行
		logic(1, &dy);
		beijins();
		setdy(conn, player, dy.x1, dy.y1, dy.x2, dy.y2); //将输入传入数据库
		setplayer(conn, 1);  //刷新用户标识符
		player = 1;
		



	}


	return 1;




}

int chonkai() {
	MYSQL* conn = mysql_init(NULL);

	if (mysql_real_connect(conn, "frp-man.top", "piecetr", "A16621342366", "piece", 36384, NULL, 0) == NULL) {
		//printf("Mysql状态异常，无法连接");
		return -1;
	}

	setplayer(conn, 1);

	return 1;




}