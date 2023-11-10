#include<iostream>
#include<graphics.h>
using namespace std;
#include"head.h"
//主函数
//bool isContinue;
//int map[ROWS][COLS];
int main(){
	map[ROWS][COLS] = 0;
	isContinue = true;
	initgraph(COLS * SPACE, SPACE * ROWS);
	while (isContinue) {
		drawMap(map);
		Sleep(10);
		getAndSet(map);
	}
	settextcolor(RED);
	outtextxy(400, 500, "开始演示");
	while (1) {//循环演化
		//求出来每个细胞周围存活数量
		//然后判断 设置
		lifeWeek(map);
		//显示
		drawMap(map);
		Sleep(10);//停顿百分之一秒
	}
return 0;
}
