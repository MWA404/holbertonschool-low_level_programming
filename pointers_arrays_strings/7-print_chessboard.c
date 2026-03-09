#include "main.h"
#include <stdio.h>

/**
 * print_chessboard - prints a chessboard
 * @a: pointer to the 2D array
 */
void print_chessboard(char (*a)[8])
{
	int i;
	int j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			printf("%c", a[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
