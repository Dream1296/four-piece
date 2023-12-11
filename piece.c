#include<stdio.h>
#include"piece.h"

//棋盘
char piece[4][4] = {
    {'A', 'B', 'C', 'D'},
    {'-', '-', '-', '-'},
    {'-', '-', '-', '-'},
    {'a', 'b', 'c', 'd'}
};
//棋子和移动代码
char A = 'A';
char W = 'W';
char* a = &A;
char* w = &W;

//棋子位置
int X = 0;
int Y = 0;
int* x = &X;
int* y = &Y;

//各方棋子数量
int a0 = 4;
int a1 = 4;


void picount(int player) {
    player = (player + 1) % 2;
    if (player == 0) {
        a0 -= 1;
        printf("01方各有%d %d ", a0, a1);
    }
    else if(player == 1)
    {
        a1 -= 1;
        printf("01方各有%d %d ", a0, a1);
    }
}

int win() {
    if(a0 == 1){
        return 1;
    }
    else if(a1 == 0)
    {
        return 0;
    }
    return -1;
}


//显示棋盘
void prpiece() {
    printf("\n-----\n\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%c", piece[i][j]);
        }
        printf("\n");
    }
    printf("\n-----\n");
}

//刷新棋子位置
void gps() {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (piece[i][j] == *a) {
                *x = i;
                *y = j;
                return;
            }
        }
    }
}

//根据用户输入进行移动
int AMobile() {
    //刷新位置
    gps();
    if ( W == 'w' || W == 'W') {
        if (*x != 0 && piece[*x - 1][*y] == '-') {
            piece[*x - 1][*y] = piece[*x][*y];
            piece[*x][*y] = '-';
            return 1;
        }
        return 0;

    }
    else if (W == 's' || W == 'S' ) {
        if (*x != 3 && piece[*x + 1][*y] == '-') {
            piece[*x + 1][*y] = piece[*x][*y];
            piece[*x][*y] = '-';
            return 1;
        }
        return 0;
    }
    else if ( W == 'a' || W == 'A') {
        if (*y != 0 && piece[*x][*y - 1] == '-') {
            piece[*x][*y - 1] = piece[*x][*y];
            piece[*x][*y] = '-';
            return 1;
        }
        return 0;
    }
    else if (W == 'd' || W == 'D') {
        if (*y != 3 && piece[*x][*y + 1] == '-') {
            piece[*x][*y + 1] = piece[*x][*y];
            piece[*x][*y] = '-';
            return 1;
        }
        return 0;
    }
    return 0;
 
}
//获取用户输入 0为小写字母，1为大写字母
int shuru(int player) {
    while (1)
    {
        printf("输入棋子代码:\n");
        *a = getchar();
        getchar();     //因为输入一个参数回车后，会将回车留在缓存区，然后这个getchar是获取回车。
        printf("输入移动代码:\n");
        *w = getchar();
        getchar();
        printf("\n--输入的棋子代码为%c,移动代码为%c\n", *a, *w);
        char ars[] = { 'W','S','A','D','w','s','a','d' };
        if (players(*a, player)) {
            for (int i = 0; i < 8; i++) {
                if (ars[i] == *w) {
                    return 1;
                }
            }
        }
        else
        {
            printf("不能移动对方棋子\n");
        }
        
   
        printf("非法输入，请重试\n");
    }



}



//输入棋子代号，玩家代码，判断这个棋子是否为这个玩家的
int players(char q, int p) {
    char play0[] = { 'a','b','c','d' };
    char play1[] = { 'A','B','C','D' };
    if (p == 0) {
        for (int i = 0; i < 4; i++) {
            if (play0[i] == q) {
                return 1;
            }
            
        }
        return 0;
    }
    else if (p == 1) {
        for (int i = 0; i < 4; i++) {
            if (play1[i] == q) {
                return 1;
            }

        }
        return 0;
    }
    return -1;
     

}

//判断位置内棋子是否为指定方
int gpspl(int x , int y ,int player) {
    char play0[] = { 'a','b','c','d' };
    char play1[] = { 'A','B','C','D' };
    if (!(x >= 0 && x <= 3 && y >= 0 && y <= 3) || piece[x][y] == '-') {
        return 0;
    }
    if (piece[x][y] == '-') {
        return 0;
    }
    if(player == 0){
        for (int i = 0; i < 4; i++) {
            if (piece[x][y] == play0[i]) {
                return 1;
            }
        }
    }
    else if(player == 1)
    {
        for (int i = 0; i < 4; i++) {
            if (piece[x][y] == play1[i]) {
                return 1;
            }
        }
    }
        return 0;

}

void logic(int player) {
    //刷新用户刚才移动的棋子当前的位置
    gps();
    char play0[] = { 'a','b','c','d' };
    char play1[] = { 'A','B','C','D' };
    //0为空或越界，1为友方，2为地方，A为移动的棋子，
    
    //水平方向
    //通过左边攻击右边1       0 1 A 2 0
         int a = gpspl(*x, *y - 1, player);   //左边有己方棋子
         int b = gpspl(*x, *y + 1, (player + 1) % 2);  //右边有敌方棋子
         int c = gpspl(*x, *y + 2, player);  //右边2格越界或为空
         int d = gpspl(*x, *y - 2, player); //左2格为空或越界
         printf("\n abc分别为:%d%d%d\n", a, b, c);
         if (a  && b  && !c && !d ) {
             printf("这个代码运行了\n");
             piece[*x][*y + 1] = '-';
             picount(player);  //刷新棋子数量
         }
    //通过左边攻击右边2       0 A 1 2 0 
         a = gpspl(*x, *y - 1, player);    //0
         b = gpspl(*x, *y + 1, player);  //1
         c = gpspl(*x, *y + 2, (player + 1) % 2); //2
         d = gpspl(*x, *y + 3, player); //0
         if ( !a  && b  && c && !d ) {
             piece[*x][*y + 2] = '-';
             picount(player);  //刷新棋子数量
         }
    //右攻击左1      0 2 1 A 0
         a = gpspl(*x, *y - 3, player);   //0
         b = gpspl(*x, *y - 2, (player + 1) % 2);  //2
         c = gpspl(*x, *y - 1, player);  //1
         d = gpspl(*x, *y + 1, player);  //0
         if (!a && b && c && !d) {
             piece[*x][*y - 2] = '-';
             picount(player);  //刷新棋子数量
         }

    //右攻击左2     0 2 A 1 0
         a = gpspl(*x, *y - 2, player);
         b = gpspl(*x, *y - 1, (player + 1) % 2);
         c = gpspl(*x, *y + 1, player);
         d = gpspl(*x, *y + 2, player);

         if (!a && b && c && !d) {
             piece[*x][*y - 1] = '-';
             picount(player);  //刷新棋子数量
         }
    //垂直方向

    //上攻击下1     0 A 1 2 0 (从上到下)
         a = gpspl(*x - 1, *y, player);
         b = gpspl(*x + 1, *y, player);
         c = gpspl(*x + 2, *y, (player + 1) % 2);
         d = gpspl(*x + 3, *y, player);
         if (!a && b && c && !d) {
             printf("满足上攻击下1\n");
             piece[*x - 2][*y] = '-';
             picount(player);  //刷新棋子数量
         }

    //上攻击下2     0 1 A 2 0
         a = gpspl(*x - 2, *y, player);
         b = gpspl(*x - 1, *y, player);
         c = gpspl(*x + 1, *y, (player + 1) % 2);
         d = gpspl(*x + 2, *y, player);
         if (!a && b && c && !d) {
             printf("满足上攻击下2\n");
             printf("%d %d %d %d\n", a, b, c, d);
             piece[*x + 1][*y] = '-';
             picount(player);   //刷新棋子数量
         }

    //下攻击上1     0  2 1 A 0
         a = gpspl(*x - 3, *y, player);
         b = gpspl(*x - 2, *y, (player + 1) % 2);
         c = gpspl(*x - 1, *y, player);
         d = gpspl(*x + 1, *y, player);
         if (!a && b && c && !d) {
             printf("满足下攻击上1\n");
             piece[*x - 2][*y] = '-';
             picount(player);   //刷新棋子数量
         }
    
    //下攻上2        0 2 1 A 0
         a = gpspl(*x - 2, *y, player);
         b = gpspl(*x - 1, *y, (player + 1) % 2);
         c = gpspl(*x + 1, *y, player);
         d = gpspl(*x + 2, *y, player);
         if (!a && b && c && !d) {
             printf("满足下攻击上2\n");
             piece[*x - 1][*y] = '-';
             picount(player);   //刷新棋子数量
         }














}



