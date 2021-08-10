#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void menu() {
	printf("********************************************\n");
	printf("************       1. play       ***********\n");
	printf("************       0. exit       ***********\n");
	printf("********************************************\n");
}

void game() {
	//���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };
	//�Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	int choose = 0;
	//��ʼ��
	//֮���Գ�ʼʱROW��COL��ֵ�������̴�С�ϼ�2����Ϊ���0����Ϸ��Ӱ�죬���Ҵ�ӡʱ����Ϊ1����9����ͼ���ܶ�Ӧ����
	InitBoard(mine, ROWS, COLS, '0');//��ʱ��ȫ����������ֻ�������е�9*9
	InitBoard(show, ROWS, COLS, '*');
	//��ӡ����
	//DisplayBoard(mine, ROW, COL);//��ӡ������ĳ�ʼ
	//printf("\n\n");
	DisplayBoard(show, ROW, COL);
	//����
	SetMine(mine, ROW, COL);
	printf("�Ƿ�������ģʽ(1/0)��");
	scanf("%d", &choose);
	printf("\n");
	if (choose == 1) {
		DisplayBoard(mine, ROW, COL);
	}
	//ɨ��
	FindMine(mine, show, ROW, COL);

}

void test() {
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
			printf("\n");
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("�����������������룡����\n");
			break;
		}
	} while (input);
}

int main() {
	test();

	return 0;
}