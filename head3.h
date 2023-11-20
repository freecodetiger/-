#pragma once
#include <iostream>
using namespace std;
//获取周围活细胞数目
class getAliveNum{
public:
int getRoundAlive(int map[ROWS][COLS], int i, int j) {
	int num = 0;
	if (i > 0 && j > 0 && map[i - 1][j - 1]) { num++; }//左上角
	else if (i > 0 && map[i - 1][j]) { num++; }//正上方
	else if (i > 0 && j < COLS - 1 && map[i - 1][j + 1]) { num++; }//右上方
	else if (j > 0 && map[i][j - 1]) { num++; }//正左方
	else if (j < COLS - 1 && map[i][j + 1]) { num++; }//正右方
	else if (i < ROWS - 1 && j > 0 && map[i + 1][j - 1]) { num++; }//左下方
	else if (i < ROWS - 1 && map[i + 1][j]) { num++; }//正下方
	if (i < ROWS - 1 && j < COLS - 1 && map[i + 1][j + 1]) { num++; }//右下方
	return num;
}
};
