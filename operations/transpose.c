// Copyright Florin-Cristian Motrun 334CA 2023-2024

#include "../headers/transpose.h"
#include "../headers/allocations.h"
#include "../headers/frees.h"

// transposes the matrix
void matrix_transpose(arr_matrix_t *arr_matrix)
{
	// read the index of the matrix to be transposed
	size_t idx;
	scanf("%zu", &idx);

	// check if the index is valid
	if (idx > arr_matrix->used - 1) {
		printf("No matrix with the given index\n");
		return;
	}

	// get the dimensions of the original matrix
	size_t rows = arr_matrix->arr[idx].rows;
	size_t cols = arr_matrix->arr[idx].cols;

	// temporary matrix to store the transposed elements
	matrix_t tmp_matrix;
	tmp_matrix.cols = rows;
	tmp_matrix.rows = cols;
	tmp_matrix.grid = alloc_grid(cols, rows);

	// perform the transpose by swapping rows and columns
	for (size_t i = 0; i < cols; ++i)
		for (size_t j = 0; j < rows; ++j)
			tmp_matrix.grid[i][j] = arr_matrix->arr[idx].grid[j][i];

	// free the memory of the original matrix
	free_matrix(arr_matrix->arr[idx]);

	// update the matrix in the array with transposed dimensions and elements
	arr_matrix->arr[idx].cols = rows;
	arr_matrix->arr[idx].rows = cols;
	arr_matrix->arr[idx].grid = tmp_matrix.grid;
}
