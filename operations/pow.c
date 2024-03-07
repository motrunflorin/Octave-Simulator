// Copyright Florin-Cristian Motrun 334CA 2023-2024

#include "../headers/pow.h"
#include "../headers/multiply.h"
#include "../headers/frees.h"
#include "../headers/allocations.h"

// reads matrix index and power from input
int read_matrix_and_power(arr_matrix_t *arr_matrix, size_t *idx, int *power)
{
	if (scanf("%zu %d", idx, power) != 2) {
		// error in reading input
		printf("Error reading matrix index and power\n");
		return 0;
	}

	// check if the matrix index is valid
	if (*idx >= arr_matrix->used) {
		printf("No matrix with the given index\n");
		return 0;
	}

	// check if the power is positive
	if (*power < 0) {
		printf("Power should be positive\n");
		return 0;
	}

	// get matrix dimensions
	size_t rows = arr_matrix->arr[*idx].rows;
	size_t cols = arr_matrix->arr[*idx].cols;

	// check if the matrix is square
	if (rows != cols) {
		printf("Cannot perform matrix multiplication\n");
		return 0;
	}

	// check if power is 1 - no change to the matrix
	if (*power == 1)
		return 1;

	return 1;
}

// raises a matrix to a power
void pow_matrix(arr_matrix_t *arr_matrix)
{
	// read matrix index and power from input
	size_t idx;
	int power;

	// if there was an error during input, return
	if (!read_matrix_and_power(arr_matrix, &idx, &power))
		return;

	// initialize result matrix as an identity matrix
	matrix_t result;
	result.cols = arr_matrix->arr[idx].rows;
	result.rows = arr_matrix->arr[idx].rows;
	result.grid = alloc_grid(result.rows, result.cols);

	for (size_t i = 0; i < result.rows; ++i)
		result.grid[i][i] = 1;

	matrix_t tmp;

	// exponentiation by squaring algorithm
	while (power > 0) {
		if (power % 2 == 0) {
			// if power is even, square the matrix
			power /= 2;

			// save the original matrix
			tmp = arr_matrix->arr[idx];

			// square the matrix
			arr_matrix->arr[idx] = multiply_matrices(arr_matrix->arr[idx],
													 arr_matrix->arr[idx]);

			// free memory used by the original matrix
			free_matrix(tmp);

		} else {
			// if power is odd, multiply result by the matrix
			// and square the matrix
			power--;

			// save the current result matrix
			tmp = result;

			// multiply result by the matrix
			result = multiply_matrices(result, arr_matrix->arr[idx]);

			// divide power by 2
			power /= 2;

			// free memory used by the previous result matrix
			free_matrix(tmp);

			// save the original matrix
			tmp = arr_matrix->arr[idx];

			// square the matrix
			arr_matrix->arr[idx] = multiply_matrices(arr_matrix->arr[idx],
													 arr_matrix->arr[idx]);

			// free memory used by the original matrix
			free_matrix(tmp);
		}
	}

	// copy the final result to the original matrix
	for (size_t i = 0; i < result.rows; ++i)
		for (size_t j = 0; j < result.cols; ++j)
			arr_matrix->arr[idx].grid[i][j] = result.grid[i][j];

	// free memory used by the result matrix
	free_matrix(result);
}
