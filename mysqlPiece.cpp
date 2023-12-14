#include <iostream>
#include <mysql.h>

#include "piece.h"


//查询下一步轮到谁操作
int getplayer(MYSQL* conn) {

    //执行SQL查询
    mysql_query(conn, "SELECT players FROM player WHERE id = 1");

    //获取查询结果
    MYSQL_RES* res = mysql_store_result(conn);
    MYSQL_ROW row = mysql_fetch_row(res);
    int a = atol(row[0]);


    return a;
}
//传入下一个轮到谁操作
int setplayer(MYSQL* conn, int player) {
    char query[100]; // 适当调整数组大小
    snprintf(query, sizeof(query), "UPDATE player SET players = %d WHERE id = 1", player);
    mysql_query(conn, query);
    return 1;
}

//获取用户上一步输入了什么。
int getyd(MYSQL* conn, int player, playdy* acc) {   


    char query[100]; // 适当调整数组大小
    sprintf(query, "SELECT * FROM piece%d ORDER BY id DESC LIMIT 1", player);
    //获取查询最后一步的
    mysql_query(conn, query);
    MYSQL_RES* res = mysql_store_result(conn);
    MYSQL_ROW row = mysql_fetch_row(res);

    int x1 =atol( row[1]);       
    int y1 = atol(row[2]);
    int x2 = atol(row[3]);
    int y2 = atol(row[4]);
    acc->x1 = x1;
    acc->y1 = y1;
    acc->x2 = x2;
    acc->y2 = y2;
    // 释放结果集
    mysql_free_result(res);
    return 1;
}
//传入用户移动的值
int setdy(MYSQL* conn,int player, int x1, int y1, int x2, int y2) {
    char query[100];
    sprintf(query, "INSERT INTO piece%d (x1,y1,x2,y2) VALUES ('%d', '%d', '%d','%d')", player,x1,y1,x2,y2);
    mysql_query(conn, query);
    return 1;
}












