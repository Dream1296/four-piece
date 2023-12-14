#include <graphics.h>
#include <iostream>


int strat() {
	//清除界面内容
	//cleardevice();

	IMAGE start;
	loadimage(&start, _T("imgpiecedream\\start.png"));
	putimage(0, 0, &start);

	//setcolor(RED);
	//setfillcolor(RED);
	//POINT pst[] = { {100,100},{300,100},{300,300} ,{100,300} };
	//fillpolygon(pst, 4);

	int x = 0;
	int y = 0;
	ExMessage m;
	
	while (true)
	{
		m = getmessage(EX_MOUSE);
		
		if (m.message == WM_LBUTTONDOWN) {
			x = m.x;
			y = m.y;
			if (x > 525 && x < 722 && y > 142 && y < 204) {
				Sleep(50);
				return 1;
			}
			if (x > 525 && x < 722 && y > 230 && y < 291) {
				Sleep(50);
				return 2;
			}
		}
		
		//if (m.message == WM_MOUSEMOVE) {
		//	x = m.x;
		//	y = m.y;
		//	if (x > 525 && x < 722 && y > 142 && y < 204) {

		//	}
		//}
	}

	return 0;


}
