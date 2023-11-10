#include <iostream>
#include<graphics.h>
#include"head.h"
//int map[ROWS][COLS] ={0};
//�����κ����Ķ���
void drawRect(int x, int y, int flag) {
	if (flag) {
		setfillcolor(WHITE);
	}
	else {
		setfillcolor(BLACK);
	}
	fillrectangle(x * SPACE, y * SPACE, x * SPACE + SPACE, y * SPACE + SPACE);
}
//�����������ĺ�������
void drawMap(int map[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			drawRect(j, i, map[i][j]);
		}
	}
}
//��ȡ�����Ϣ������潻��
void getAndSet(int map[ROWS][COLS]) {
	MOUSEMSG msg;
	while (isContinue) {
		msg = GetMouseMsg();
		if (msg.mkLButton) {
			map[msg.y / SPACE][msg.x / SPACE] = 1;
		}
		else if(msg.mkRButton) {
			map[msg.y / SPACE][msg.x / SPACE] = 0;
		}
	}
}
//��ȡ��Χ��ϸ����Ŀ��������
int getRoundAlive(int map[ROWS][COLS], int i, int j) {
	int num = 0;
	if (i > 0 && j > 0 && map[i - 1][j - 1]) { num++; }//���Ͻ�
	else if (i > 0 && map[i - 1][j]) { num++; }//���Ϸ�
	else if (i > 0 && j < COLS - 1 && map[i - 1][j + 1]) { num++; }//���Ϸ�
	else if (j > 0 && map[i][j - 1]) { num++; }//����
	else if (j < COLS - 1 && map[i][j + 1]) { num++; }//���ҷ�
	else if (i < ROWS - 1 && j > 0 && map[i + 1][j - 1]) {num++;}//���·�
	else if (i < ROWS - 1 && map[i + 1][j]) { num++; }//���·�
	if (i < ROWS - 1 && j < COLS - 1 && map[i + 1][j + 1]) { num++; }//���·�
	return num;
}
//���ݻ�ϸ����Ŀ�����ݻ���������
void lifeWeek(int map[ROWS][COLS]) {
	//׼����ʱ���飬�������һ���ݻ����ϸ���ֲ����
	int temp[ROWS][COLS] = { 0 };
	int num=0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			num = getRoundAlive(map, i, j);
			if (3 == num) {//���ϸ����Χ��3������ϸ��   
				temp[i][j] = 1;//���
			}
			else if (2 == num) {//���ϸ����Χ��2������ϸ��   
				temp[i][j] = map[i][j];//ά�ֲ���
			}
			else {//������������			    
				temp[i][j] = 0;//�����
			}
		}
	}
	//����ʱ�����ϸ���ֲ����������ԭ��������
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			map[i][j] = temp[i][j];
		}
	}
}
