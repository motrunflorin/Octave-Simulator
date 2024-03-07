// Copyright Florin-Cristian Motrun 334CA 2023-2024

#include "../headers/allocations.h"

// checks if memory allocation is successful
void check_alloc(void *p)
{
	if (!p) {
		perror("alloc failed");
		exit(EXIT_FAILURE);
	}
}

// allocates a 2D grid of integers with the specified rows and columns
int **alloc_grid(size_t rows, size_t cols)
{
	// allocate memory for the array of row pointers
	int **grid = calloc(rows, sizeof(int *));
	check_alloc(grid);

	// allocate memory for each row
	for (size_t i = 0; i < rows; ++i) {
		grid[i] = calloc(cols, sizeof(int));
		check_alloc(grid[i]);
	}

	return grid;
}

// allocates memory for the array of matrices
void alloc_arr(arr_matrix_t **arr_matrix, size_t size)
{
	// allocate memory for the array structure
	*arr_matrix = calloc(1, sizeof(arr_matrix_t));
	check_alloc(*arr_matrix);

	// allocate memory for the array of matrices
	(*arr_matrix)->arr = calloc(size, sizeof(matrix_t));
	check_alloc((*arr_matrix)->arr);

	// set the initial size of the array
	(*arr_matrix)->size = size;
}

// resizes the array of matrices to the specified size
void resize_arr(arr_matrix_t  *arr_matrix, size_t size)
{
	// resize the array of matrices
	matrix_t *new_arr = realloc(arr_matrix->arr,
								size * sizeof(matrix_t));
	check_alloc(new_arr);

	// update the array and its size
	arr_matrix->arr = new_arr;
	arr_matrix->size = size;
}
