#include <iostream>
#include<graphics.h>
#include"head.h"
//int map[ROWS][COLS] ={0};
//填充矩形函数的定义
void drawRect(int x, int y, int flag) {
	if (flag) {
		setfillcolor(WHITE);
	}
	else {
		setfillcolor(BLACK);
	}
	fillrectangle(x * SPACE, y * SPACE, x * SPACE + SPACE, y * SPACE + SPACE);
}
//绘制网格界面的函数定义
void drawMap(int map[ROWS][COLS]) {
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			drawRect(j, i, map[i][j]);
		}
	}
}
//获取鼠标信息，与界面交互
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
//获取周围活细胞数目函数定义
int getRoundAlive(int map[ROWS][COLS], int i, int j) {
	int num = 0;
	if (i > 0 && j > 0 && map[i - 1][j - 1]) { num++; }//左上角
	else if (i > 0 && map[i - 1][j]) { num++; }//正上方
	else if (i > 0 && j < COLS - 1 && map[i - 1][j + 1]) { num++; }//右上方
	else if (j > 0 && map[i][j - 1]) { num++; }//正左方
	else if (j < COLS - 1 && map[i][j + 1]) { num++; }//正右方
	else if (i < ROWS - 1 && j > 0 && map[i + 1][j - 1]) {num++;}//左下方
	else if (i < ROWS - 1 && map[i + 1][j]) { num++; }//正下方
	if (i < ROWS - 1 && j < COLS - 1 && map[i + 1][j + 1]) { num++; }//右下方
	return num;
}
//根据活细胞数目进行演化函数定义
void lifeWeek(int map[ROWS][COLS]) {
	//准备临时数组，用来存放一次演化后的细胞分布情况
	int temp[ROWS][COLS] = { 0 };
	int num=0;
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			num = getRoundAlive(map, i, j);
			if (3 == num) {//如果细胞周围有3个存活的细胞   
				temp[i][j] = 1;//存活
			}
			else if (2 == num) {//如果细胞周围有2个存活的细胞   
				temp[i][j] = map[i][j];//维持不变
			}
			else {//如果是其他情况			    
				temp[i][j] = 0;//不存活
			}
		}
	}
	//将临时数组的细胞分布情况拷贝到原来数组上
	for (int i = 0; i < ROWS; i++) {
		for (int j = 0; j < COLS; j++) {
			map[i][j] = temp[i][j];
		}
	}
}
