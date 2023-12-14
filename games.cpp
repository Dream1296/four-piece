#include <graphics.h>
#include <iostream>
#include <direct.h>  //创建文件夹
#include"piece.h"






int games() {


	//initgraph(400, 400);
	chushihua();
	int player = 1;
	beijins();  //显示界面
	int wins;
	while (true)
	{
		shuru(player,1,NULL);    //获取输入
		logic((player + 1) % 2,NULL);    //判断击败
		wins = win();   //获取胜利结果
		if (wins == 0) {
			beijins();
			MessageBox(GetHWnd(), L"黑方胜利", L"提示", MB_OK);
			beijins();
			Sleep(2000);
			closegraph();
			return 0;
		}
		else if (wins == 1)
		{
			beijins();
			MessageBox(GetHWnd(), L"白方胜利", L"提示", MB_OK);
			beijins();
			Sleep(2000);
			closegraph();
			return 1;
		}



		beijins();        //显示界面
		player = (player + 1) % 2;
	}
	beijins();
}