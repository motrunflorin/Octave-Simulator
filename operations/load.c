// Copyright Florin-Cristian Motrun 334CA 2023-2024

#include "../headers/load.h"
#include "../headers/allocations.h"

// adds a new matrix to the array
void add_matrix(arr_matrix_t *arr_matrix)
{
	// check if the array is full, and resize if necessary
	if (arr_matrix->used == arr_matrix->size)
		resize_arr(arr_matrix, arr_matrix->size + 1);

	// read rows and columns for the new matrix
	size_t rows, cols;
	scanf("%zu%zu", &rows, &cols);

	// allocate memory for the new matrix
	arr_matrix->arr[arr_matrix->used].rows = rows;
	arr_matrix->arr[arr_matrix->used].cols = cols;
	arr_matrix->arr[arr_matrix->used].grid = alloc_grid(rows, cols);

	// populate the new matrix with values from input
	for (size_t i = 0; i < rows; i++)
		for (size_t j = 0; j < cols; ++j)
			scanf("%d", &arr_matrix->arr[arr_matrix->used].grid[i][j]);

	// increment the used count for the array
	arr_matrix->used++;
}
