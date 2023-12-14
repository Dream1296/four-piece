#ifndef PIECE_H
#define PIECE_H


#include <graphics.h>
#include <mysql.h>

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
} playdy;

//加载对应的图片
void chushihua();

//放置图片
inline void putimgage_s(int x, int y, IMAGE* img);

//获取改棋子是哪一方的
int fun(char a);

//判断哪一方胜利
int win();

//根据数组棋盘摆放棋子
void prpiece();

//画出棋盘线
void huaxian();

//显示背景
void beijins();

//更改双方棋子数
void picount(int player);

//判断位置内棋子是否为指定方
int gpspl(int x, int y, int playeras);

//判断吃子
void logic(int player, playdy* dy);

//获取用户输入
int shuru(int player, int cp , playdy * dy);

//指定输入内容修改棋盘
int shurus(playdy* dy);

//查询下一步轮到谁操作
int getplayer(MYSQL* conn);

//传入下一个轮到谁操作
int setplayer(MYSQL* conn, int player);

//获取用户上一步输入了什么。
int getyd(MYSQL* conn, int player, playdy* acc);

//传入用户移动的值
int setdy(MYSQL* conn, int player, int x1, int y1, int x2, int y2);





#endif