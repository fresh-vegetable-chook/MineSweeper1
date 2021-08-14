#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define ROW 9
#define COL 9

#define ROWS ROW+2
#define COLS COL+2

#define EASY_COUNT 1

void InitBoard(char board[ROWS][COLS], int rows, int cols, char c);
void DisplayBoard(char board[ROWS][COLS], int rows, int cols);
void SetMine(char board[ROWS][COLS], int row, int col);
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);
int get_mine_count(char board[ROWS][COLS], int x, int y);
void OpenMine(char mine[ROWS][COLS], char show[ROWS][COLS], int x, int y, int* win);