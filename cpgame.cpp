#include <graphics.h>
#include <iostream>
#include <direct.h>  //�����ļ���
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

//����    ����Ϊ1

int cpgame() {
	chushihua();
	beijins();
	MYSQL* conn = mysql_init(NULL);
	playdy dy;

	if (mysql_real_connect(conn, "frp-man.top", "pieceon", "A16621342366", "piece", 36384, NULL, 0) == NULL) {
		//printf("Mysql״̬�쳣���޷�����");
		return -1;
	}

	//��ѯ�ֵ�˭��ʼ
	int player = getplayer(conn);
	int xianshou = 1;
	while (true)
	{
		
		if (player != 1) {
			player = getplayer(conn);
			Sleep(100); //�ӳ�����
			continue;
		}
		if (xianshou == 1) {   //����
			xianshou++;
			shuru(player,2,&dy);  //��ȡ�û�����
			beijins();
			setdy(conn, player, dy.x1, dy.y1, dy.x2, dy.y2); //�����봫�����ݿ�
			setplayer(conn, 0);  //ˢ���û���ʶ��
			player = 0;
			continue;
		}

		getyd(conn,0,&dy);  //��ȡ�û���һ�ε�����
		shurus(&dy);   //ִ�жԷ������
		logic(1, &dy);
		beijins();
		int winsc = win();
		if (winsc == 1) {
			MessageBox(GetHWnd(), L"��Ϸ��������(�ڷ�)����", L"���", MB_OK);
			return 10;
		}
		else if(winsc == 0)
		{
			MessageBox(GetHWnd(), L"��Ϸ��������ϲ(�ڷ�)���ʤ��", L"���", MB_OK);
			return 11;
		}
		shuru(player, 2, &dy);  //�Լ�ִ��
		logic(0, &dy);
		beijins();
		setdy(conn, player, dy.x1, dy.y1, dy.x2, dy.y2); //�����봫�����ݿ�
		setplayer(conn, (player + 1) % 2);  //ˢ���û���ʶ��
		player = 0;   
		



	}


	return 1;
}


//����
int cpgames() {
	chushihua();
	beijins();
	MYSQL* conn = mysql_init(NULL);
	playdy dy;

	if (mysql_real_connect(conn, "frp-man.top", "piecetr", "A16621342366", "piece", 36384, NULL, 0) == NULL) {
		//printf("Mysql״̬�쳣���޷�����");
		return -1;
	}


	//��ѯ�ֵ�˭��ʼ
	int player = getplayer(conn);
	while (true)
	{

		if (player != 0) {
			player = getplayer(conn);
			Sleep(200); //�ӳ�����
			continue;
		}

		getyd(conn, 1, &dy);  //��ȡ�û���һ�ε�����   
		shurus(&dy);//ִ�жԷ������
		logic(0, &dy);
		beijins();
		int winsc = win();
		if (winsc == 0) {
			MessageBox(GetHWnd(), L"��Ϸ��������(�׷�)����", L"���", MB_OK);
		}
		else if (winsc == 1)
		{
			MessageBox(GetHWnd(), L"��Ϸ��������ϲ(�׷�)���ʤ��", L"���", MB_OK);
		}
		shuru(player, 2, &dy);  //�Լ�ִ��
		logic(1, &dy);
		beijins();
		setdy(conn, player, dy.x1, dy.y1, dy.x2, dy.y2); //�����봫�����ݿ�
		setplayer(conn, 1);  //ˢ���û���ʶ��
		player = 1;
		



	}


	return 1;




}

int chonkai() {
	MYSQL* conn = mysql_init(NULL);

	if (mysql_real_connect(conn, "frp-man.top", "piecetr", "A16621342366", "piece", 36384, NULL, 0) == NULL) {
		//printf("Mysql״̬�쳣���޷�����");
		return -1;
	}

	setplayer(conn, 1);

	return 1;




}