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

int main() {
	int	currgen[BOARD_WIDTH][BOARD_HEIGHT], nextgen[BOARD_WIDTH][BOARD_HEIGHT];

	initboard(currgen);

	//процесс игры
	
	do {
		system("cls");
		print(currgen);
		
	
}