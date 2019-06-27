#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dos.h>


#define BOARD_WIDTH 20//Высота игрового поля
#define BOARD_HEIGHT 20//Ширина игрового поля

//инициация начального поля
void initboard(int board[][BOARD_HEIGHT]) {
	int	i, j;
	srand(time(NULL));
	for (i = 0; i < BOARD_WIDTH; i++) for (j = 0; j < BOARD_HEIGHT; j++)
		board[i][j] = rand() % 2;
}

//выведение поля
void print(int board[][BOARD_HEIGHT]) {
	int	i, j;

	for (j = 0; j < BOARD_HEIGHT; j++) {

		for (i = 0; i < BOARD_WIDTH; i++) {
			printf("%c ", board[i][j] ? 'o' : ' ');
		}
		printf("\n");
	}
}


//замена полей
void cpy(int currgen[BOARD_WIDTH][BOARD_HEIGHT], int nextgen[BOARD_WIDTH][BOARD_HEIGHT]) {
	for (int i = 0; i < BOARD_WIDTH; i++) for (int j = 0; j < BOARD_HEIGHT; j++) {
		currgen[i][j] = nextgen[i][j];
	}
}

//подсчет кол-ва живых соседей клетки (i,j) на данном массиве
int nbrs(int board[][BOARD_HEIGHT], int i, int j) {
	int	k, l, count;

	count = 0;

	//обход вокруг клетки

	for (k = -1; k <= 1; k++) for (l = -1; l <= 1; l++)
		if (k || l)
			if (board[i + k][j+l]) count++;
	return count;
}

//обработка первого поля по правилам игры и помещение результата во второй массив
void turn(int currgen[BOARD_WIDTH][BOARD_HEIGHT], int nextgen[BOARD_WIDTH][BOARD_HEIGHT]) {

	int	i, j, a;

	//применяем правила для каждой клетки

	for (i = 0; i < BOARD_WIDTH; i++) for (j = 0; j < BOARD_HEIGHT; j++) {
		a = nbrs(currgen, i, j);
		if (a == 2) nextgen[i][j] = currgen[i][j];
		if (a == 3) nextgen[i][j] = 1;
		if ((a < 2)||(a > 3)) nextgen[i][j] = 0;

	}
}
	void swap(int currgen[BOARD_WIDTH][BOARD_HEIGHT], int nextgen[BOARD_WIDTH][BOARD_HEIGHT]) {
		int	i, j;
	for (i = 0; i < BOARD_WIDTH; i++) for (j = 0; j < BOARD_HEIGHT; j++) {
		currgen[i][j] = nextgen[i][j];
	}
}

//проверка отсутствия жизни
int ifnull(int nextgen[BOARD_WIDTH][BOARD_HEIGHT]){
	int cnt = 0;
	for (int i = 0; i < BOARD_WIDTH; i++) for (int j = 0; j < BOARD_HEIGHT; j++) {
		if (nextgen[i][j] != 0) cnt += 1;
	}
	return cnt;
}


int main() {
	int	currgen[BOARD_WIDTH][BOARD_HEIGHT], nextgen[BOARD_WIDTH][BOARD_HEIGHT], a;

	initboard(currgen);

	//процесс игры
	
	do {
		system("cls");
		print(currgen);
		turn(currgen, nextgen);
        a = ifnull(nextgen)

        } while (a != 0);//Добавить условия выхода из цикла
	
}