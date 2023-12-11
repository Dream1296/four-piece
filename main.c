#include<stdio.h>
#include"piece.h"


int main() {



    //用户标志符
    int player = 0;
    while (1)
    {
        //打印棋盘
        prpiece();
        //获取输入
        if (player == 0) {
            printf("小写移动\n");
        }
        else
        {
            printf("大写移动\n");
        }
        shuru(player);
        //执行移动
        int bl = AMobile();
        //判断是否有击败
        logic(player);
        //判断是否获胜
        int wins = win();
        if (wins == 0) {
            printf("0小写获胜\n");
            break;
        }
        else if (wins == 1)
        {
            printf("1大写获胜");
            break;
        }

        if (bl == 1) {
            //切换用户输入
            player = (player + 1) % 2;
        }
        else
        {
            printf("移动失败，请重新输入\n");
        }




    }


    return 0;
}