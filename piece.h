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

//���ض�Ӧ��ͼƬ
void chushihua();

//����ͼƬ
inline void putimgage_s(int x, int y, IMAGE* img);

//��ȡ����������һ����
int fun(char a);

//�ж���һ��ʤ��
int win();

//�����������̰ڷ�����
void prpiece();

//����������
void huaxian();

//��ʾ����
void beijins();

//����˫��������
void picount(int player);

//�ж�λ���������Ƿ�Ϊָ����
int gpspl(int x, int y, int playeras);

//�жϳ���
void logic(int player, playdy* dy);

//��ȡ�û�����
int shuru(int player, int cp , playdy * dy);

//ָ�����������޸�����
int shurus(playdy* dy);

//��ѯ��һ���ֵ�˭����
int getplayer(MYSQL* conn);

//������һ���ֵ�˭����
int setplayer(MYSQL* conn, int player);

//��ȡ�û���һ��������ʲô��
int getyd(MYSQL* conn, int player, playdy* acc);

//�����û��ƶ���ֵ
int setdy(MYSQL* conn, int player, int x1, int y1, int x2, int y2);





#endif