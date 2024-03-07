// Copyright Florin-Cristian Motrun 334CA 2023-2024

#include "../headers/print.h"

// prints the matrix
void print_matrix(arr_matrix_t *arr_matrix)
{
	// get the matrix index from input
	size_t idx;
	scanf("%zu", &idx);

	// check if the index is valid
	if (idx > arr_matrix->used - 1 || arr_matrix->used == 0) {
		printf("No matrix with the given index\n");
		return;
	}

	// get matrix dimensions
	size_t rows = arr_matrix->arr[idx].rows;
	size_t cols = arr_matrix->arr[idx].cols;

	// print the matrix elements
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j)
			printf("%d ", arr_matrix->arr[idx].grid[i][j]);

		printf("\n");
	}
}
