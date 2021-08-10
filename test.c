#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void menu() {
	printf("********************************************\n");
	printf("************       1. play       ***********\n");
	printf("************       0. exit       ***********\n");
	printf("********************************************\n");
}

void game() {
	//布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };
	//排查出的雷的信息
	char show[ROWS][COLS] = { 0 };
	int choose = 0;
	//初始化
	//之所以初始时ROW和COL的值都在棋盘大小上加2是因为其放0对游戏无影响，而且打印时坐标为1——9，和图上能对应起来
	InitBoard(mine, ROWS, COLS, '0');//传时传全部，但操作只操作其中的9*9
	InitBoard(show, ROWS, COLS, '*');
	//打印棋盘
	//DisplayBoard(mine, ROW, COL);//打印雷数组的初始
	//printf("\n\n");
	DisplayBoard(show, ROW, COL);
	//布置
	SetMine(mine, ROW, COL);
	printf("是否开启作弊模式(1/0)：");
	scanf("%d", &choose);
	printf("\n");
	if (choose == 1) {
		DisplayBoard(mine, ROW, COL);
	}
	//扫雷
	FindMine(mine, show, ROW, COL);

}

void test() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			printf("\n");
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("输入有误，请重新输入！！！\n");
			break;
		}
	} while (input);
}

int main() {
	test();

	return 0;
}