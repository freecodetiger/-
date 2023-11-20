#include<iostream>
#include<graphics.h>
using namespace std;
#include"head1.h"
#include"head2.h"
#include"head3.h"
//主函数
DrawMap a;
GetAndSet b;
getAliveNum c;
int main(){
	map[ROWS][COLS] = 0;
	isContinue = true;
	initgraph(COLS * SPACE, SPACE * ROWS);
	while (isContinue) {
		a.drawMap(map);
		Sleep(10);
		b.getAndSet(map);
	}
	settextcolor(RED);
	outtextxy(400, 500, "开始演示");
	while (1) {//循环演化
		//求出来每个细胞周围存活数量
		//然后判断 设置
		c.lifeWeek(map);
		//显示
		a.drawMap(map);
		Sleep(10);//停顿百分之一秒
	}
return 0;
}
