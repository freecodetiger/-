#ifndef HEAD_H
#define HEAD_H
#define SPACE 20
#define ROWS 40
#define COLS 40
bool isContinue;
int map[ROWS][COLS];
void drawRect(int x, int y, int flag);//����һ������
void drawMap(int map[ROWS][COLS]);//����һ������
void getAndSet(int map[ROWS][COLS]);
void lifeWeek(int map[ROWS][COLS]);
int getRoundAlive(int map[ROWS][COLS], int i, int j);
#endif 