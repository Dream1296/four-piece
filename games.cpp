#include <graphics.h>
#include <iostream>
#include <direct.h>  //�����ļ���
#include"piece.h"






int games() {


	//initgraph(400, 400);
	chushihua();
	int player = 1;
	beijins();  //��ʾ����
	int wins;
	while (true)
	{
		shuru(player,1,NULL);    //��ȡ����
		logic((player + 1) % 2,NULL);    //�жϻ���
		wins = win();   //��ȡʤ�����
		if (wins == 0) {
			beijins();
			MessageBox(GetHWnd(), L"�ڷ�ʤ��", L"��ʾ", MB_OK);
			beijins();
			Sleep(2000);
			closegraph();
			return 0;
		}
		else if (wins == 1)
		{
			beijins();
			MessageBox(GetHWnd(), L"�׷�ʤ��", L"��ʾ", MB_OK);
			beijins();
			Sleep(2000);
			closegraph();
			return 1;
		}



		beijins();        //��ʾ����
		player = (player + 1) % 2;
	}
	beijins();
}