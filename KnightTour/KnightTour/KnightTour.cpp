// KnightTour.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#define CB_SIZE 5

int chessboard[CB_SIZE][CB_SIZE] = {
	0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0, 
	0, 0, 0, 0, 0
};

int solution_count = 0;
int step_count = 0;

void print_pad(int *pad)
{
	for (int i = 0; i < CB_SIZE; i++) {
		for (int j = 0; j < CB_SIZE; j++) {
			printf("%02d ", pad[i*CB_SIZE+j]);
		}
		printf("\n");
	}

	printf("\n");
}

int knight_tour(int x, int y, int step)
{
	if (x < 0 || y < 0 || x >= CB_SIZE || y >=CB_SIZE || chessboard[x][y] != 0) {
		return 0;
	}
	else {
		chessboard[x][y] = step;
		if (step == CB_SIZE*CB_SIZE) {
			printf("No.%d\n", ++solution_count);
			print_pad(&chessboard[0][0]);
		}
	}

	int result = knight_tour(x-1, y-2, step+1) +	// up, left
			  knight_tour(x+1, y-2, step+1) +	// up, right
			  knight_tour(x+2, y-1, step+1) +	// right, up
			  knight_tour(x+2, y+1, step+1) +	// right, down
			  knight_tour(x+1, y+2, step+1) +	// down, right
			  knight_tour(x-1, y+2, step+1) +	// down, left
			  knight_tour(x-2, y+1, step+1) +	// left, down
			  knight_tour(x-2, y-1, step+1); // left, up
	if (result <= 0) {
		chessboard[x][y] = 0;
		return 0;
	}

	return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	knight_tour(0, 0, 1);
	return 0;
}

