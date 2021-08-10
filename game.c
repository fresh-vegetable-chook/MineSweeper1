#define _CRT_SECURE_NO_WARNINGS

#include"game.h"

void InitBoard(char board[ROWS][COLS], int rows, int cols, char c) {
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++) {
		for (j = 0; j < cols; j++) {
			board[i][j] = c;
		}
	}
}

void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	int i = 0;
	int j = 0;
	//��ӡ�к�
	for (i = 0; i <= col; i++) {
		printf("%.2d  ", i);
	}
	printf("\n\n");
	for (i = 1; i <= row; i++) {
		printf("%.2d  ", i);//��ӡ�к�
		for (j = 1; j <= col; j++) {
			printf("%c   ", board[i][j]);
			if (j == col) {
				printf("\n");
			}
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS], int row, int col) {
	int count = EASY_COUNT;
	while (count) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}

//ע��'1' - '0' = 1
int get_mine_count(char board[ROWS][COLS], int x, int y) {

	    return board[x - 1][y] 
		+ board[x - 1][y - 1]
		+ board[x][y - 1]
		+ board[x + 1][y - 1]
		+ board[x + 1][y]
		+ board[x + 1][y + 1]
		+ board[x][y + 1]
		+ board[x - 1][y + 1] - 8 * '0';
}

void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col-EASY_COUNT) {
		printf("\n�������Ų��׵����꣺>");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= col && y >= 1 && y <= row) {
			//����Ϸ�

			//1.����
			if (mine[x][y] == '1') {
				printf("\n���ź����㱻ը���ˣ�����\n\n");
				DisplayBoard(mine, row, col);
				break;
			}
			//������
			else if (mine[x][y] == '0') {
				show[x][y] = get_mine_count(mine, x, y) + '0';
				OpenMine(mine, show, x, y);
				printf("\n");
				DisplayBoard(show, row, col);
			}
		}
		else {
			printf("��������Ƿ������������룡\n");
		}
	}
	if (win == row * col - EASY_COUNT) {
		printf("��ϲ�㣬���׳ɹ�������\n\n");
		DisplayBoard(mine, row, col);
	}
}

void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y) {
	if (x >= 1 && x <= ROW && y >= 1 && y <= COL) { // �ݹ��ֹԽ��
		if (get_mine_count(mine, x, y) + '0' == '0') {
			show[x][y] = ' ';
			if (show[x - 1][y - 1] == '*')
			{
				OpenMine(mine, show, x - 1, y - 1);
			}
			if (show[x - 1][y] == '*')
			{
				OpenMine(mine, show, x - 1, y);
			}
			if (show[x - 1][y + 1] == '*')
			{
				OpenMine(mine, show, x - 1, y + 1);
			}
			if (show[x][y - 1] == '*')
			{
				OpenMine(mine, show, x, y - 1);
			}
			if (show[x][y + 1] == '*')
			{
				OpenMine(mine, show, x, y + 1);
			}
			if (show[x + 1][y - 1] == '*')
			{
				OpenMine(mine, show, x + 1, y - 1);
			}
			if (show[x + 1][y] == '*')
			{
				OpenMine(mine, show, x + 1, y);
			}
			if (show[x + 1][y + 1] == '*')
			{
				OpenMine(mine, show, x + 1, y + 1);
			}
		}
		else {
			show[x][y] = get_mine_count(mine, x, y) + '0';
		}
	}
}