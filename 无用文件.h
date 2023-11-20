#pragma once
#include <iostream>
using namespace std;
class evolve {
public:
	//根据活细胞数目进行演化函数定义
	void lifeWeek(int map[ROWS][COLS]) {
		//准备临时数组，用来存放一次演化后的细胞分布情况
		int temp[ROWS][COLS] = { 0 };
		int num = 0;
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
};
