// Copyright Florin-Cristian Motrun 334CA 2023-2024

#include "../headers/frees.h"

// frees the memory occupied by a single matrix
void free_matrix(matrix_t matrix)
{
	// free memory for each row in the matrix
	for (size_t i = 0; i < matrix.rows; i++)
		free(matrix.grid[i]);

	// free memory for the array of rows
	free(matrix.grid);
}

// frees the memory occupied by the array of matrices
void free_arr(arr_matrix_t *arr_matrix)
{
	// get the number of matrices in the array
	size_t count = arr_matrix->used;

	// free memory for each matrix in the array
	for (size_t i = 0; i < count ; ++i)
		free_matrix(arr_matrix->arr[i]);

	// free memory for the array of matrices
	free(arr_matrix->arr);

	// free memory for the array structure
	free(arr_matrix);
}
