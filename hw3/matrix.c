/**
 * @file matrix.c
 * @author Joseph Shao
 * @brief
 * @version 0.1
 * @date 2022-04-16
 *
 * @copyright Copyright (c) 2022
 *
 */

#include <stdio.h>
#include <assert.h>

#define M 256 // number of rows
#define N 216 // number of columns

/*
 * Given a 2-D matrix of size M rows and N columns. Fill the matrix such
 * that each entry in the matrix is equal to the row index times the column
 * index.
 */
void populate(int matrix[M][N])
{
	int *element = &matrix[0][0];
	int i, j;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			*element = i * j; // assign i * j to be the value stored at pointer element
			element++;		  // move the pointer pointing to the begining address of the next element in the array
		}
	}
}

/*
 * Given the first argument is a 2-D matrix of size M rows
 * and N columns populated with integers, this function returns
 * the value of the integer at row r and column c of this matrix.
 */
int get_elem(int matrix[M][N], int r, int c)
{
	return matrix[r][c];
}

/*
 * Small program to show how to use the get_elem() function.
 */
int main(int argc, char *argv[])
{

	int array2D[M][N];
	populate(array2D);
	int result = get_elem(array2D, 8, 8);
	printf("result is: %d\n", result);

	result = get_elem(array2D, M - 1, N - 1);
	assert(result == (M - 1) * (N - 1));

	result = get_elem(array2D, 25, N - 1);
	assert(result == 25 * (N - 1));

	result = get_elem(array2D, 0, 0);
	assert(result == 0);

	result = get_elem(array2D, 200, 200);
	assert(result == 200 * 200);

	result = get_elem(array2D, M - 1, 25);
	assert(result == (M - 1) * 25);

	return 0;
}
