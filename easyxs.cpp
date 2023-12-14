#include <graphics.h>
#include <iostream>


int games();
int strat();
int files();


int cpgamestart();
int main() {

	files();

	initgraph(800, 600);

	int gn = 0;
	 gn = strat();
	 if (gn == 1) {
		 games();
	 }

	 if (gn == 2) {
		 cpgamestart();
	 }

	
	//chonkai();
	//cpgame();
	
	
	return 0;
	initgraph(800, 600);
	games();
	return 0;
	
	int wingame = 0;
	int a = strat();
	if (a == 1) {
		wingame =  games();
	}


	while (1) {

	}



	return 0;
}







