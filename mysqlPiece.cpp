#include <iostream>
#include <mysql.h>

#include "piece.h"


//��ѯ��һ���ֵ�˭����
int getplayer(MYSQL* conn) {

    //ִ��SQL��ѯ
    mysql_query(conn, "SELECT players FROM player WHERE id = 1");

    //��ȡ��ѯ���
    MYSQL_RES* res = mysql_store_result(conn);
    MYSQL_ROW row = mysql_fetch_row(res);
    int a = atol(row[0]);


    return a;
}
//������һ���ֵ�˭����
int setplayer(MYSQL* conn, int player) {
    char query[100]; // �ʵ����������С
    snprintf(query, sizeof(query), "UPDATE player SET players = %d WHERE id = 1", player);
    mysql_query(conn, query);
    return 1;
}

//��ȡ�û���һ��������ʲô��
int getyd(MYSQL* conn, int player, playdy* acc) {   


    char query[100]; // �ʵ����������С
    sprintf(query, "SELECT * FROM piece%d ORDER BY id DESC LIMIT 1", player);
    //��ȡ��ѯ���һ����
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
    // �ͷŽ����
    mysql_free_result(res);
    return 1;
}
//�����û��ƶ���ֵ
int setdy(MYSQL* conn,int player, int x1, int y1, int x2, int y2) {
    char query[100];
    sprintf(query, "INSERT INTO piece%d (x1,y1,x2,y2) VALUES ('%d', '%d', '%d','%d')", player,x1,y1,x2,y2);
    mysql_query(conn, query);
    return 1;
}












