// Copyright Florin-Cristian Motrun 334CA 2023-2024

#include "../headers/utils.h"

// calculates the modulo of a number
int modulo(int x)
{
	// ensure x is within the modulo range
	x %= MODULO;

	// adjust negative result to the positive range
	if (x < 0)
		x += MODULO;

	return x;
}

// swaps two matrices
void swap_matrix(matrix_t *x, matrix_t *y)
{
	matrix_t tmp = *x;
	*x = *y;
	*y = tmp;
}

// calculates the sum of elements in a matrix
int sum_matrix(arr_matrix_t *arr_matrix, size_t idx)
{
	int sum = 0;
	size_t rows = arr_matrix->arr[idx].rows;
	size_t cols = arr_matrix->arr[idx].cols;

	// iterate through the matrix and accumulate the sum
	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < cols; ++j) {
			sum += arr_matrix->arr[idx].grid[i][j];
			sum = modulo(sum);
		}

	return sum;
}
