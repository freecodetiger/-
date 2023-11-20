#pragma once
#include <iostream>
using namespace std;
class drawMap {
public:
	void play1() {
    //绘制一个格子
    //定义格子的颜色由布尔数flag确定，布尔数为1则填充为白色，否则填充黑色（与后来的鼠标交互有呼应）
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
	}

};
