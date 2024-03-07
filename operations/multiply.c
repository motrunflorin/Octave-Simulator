// Copyright Florin-Cristian Motrun 334CA 2023-2024

#include "../headers/multiply.h"
#include "../headers/allocations.h"
#include "../headers/frees.h"

// multiplies two matrices and returns the result
matrix_t multiply_matrices(matrix_t matrix_1, matrix_t matrix_2)
{
	matrix_t result;
	result.rows = matrix_1.rows;
	result.cols = matrix_2.cols;
	result.grid = alloc_grid(result.rows, result.cols);

	for (size_t i = 0; i < matrix_1.rows; ++i) {
		for (size_t k = 0; k < matrix_2.rows; ++k) {
			for (size_t j = 0; j < matrix_2.cols; ++j) {
				// perform matrix multiplication and apply modulo
				result.grid[i][j] += matrix_1.grid[i][k] * matrix_2.grid[k][j];
				result.grid[i][j] = modulo(result.grid[i][j]);
			}
		}
	}

	return result;
}

// performs matrix multiplication on matrices at given indices
void multiply_matrices_command(arr_matrix_t *arr_matrix)
{
	size_t idx_1, idx_2;
	scanf("%zu%zu", &idx_1, &idx_2);

	// check if the indices are within bounds
	if (idx_1 >= arr_matrix->used || idx_2 >= arr_matrix->used) {
		printf("No matrix with the given index\n");
		return;
	}

	// check if matrix multiplication is possible
	if (arr_matrix->arr[idx_1].cols != arr_matrix->arr[idx_2].rows) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}

	// resize the array if needed
	if (arr_matrix->used == arr_matrix->size)
		resize_arr(arr_matrix, arr_matrix->size + 1);

	// initialize rows and columns for the result matrix
	size_t rows = arr_matrix->arr[idx_1].rows;
	size_t cols = arr_matrix->arr[idx_2].cols;

	// allocate memory for the result matrix
	arr_matrix->arr[arr_matrix->used].rows = rows;
	arr_matrix->arr[arr_matrix->used].cols = cols;
	arr_matrix->arr[arr_matrix->used].grid = alloc_grid(rows, cols);

	// perform matrix multiplication and store the result
	matrix_t tmp_matrix = multiply_matrices(arr_matrix->arr[idx_1],
											arr_matrix->arr[idx_2]);

	for (size_t i = 0; i < rows; ++i)
		for (size_t j = 0; j < cols; ++j)
			arr_matrix->arr[arr_matrix->used].grid[i][j] =
			tmp_matrix.grid[i][j];

	// free the memory used by the temporary matrix
	free_matrix(tmp_matrix);

	// increment the used count for the array
	arr_matrix->used++;
}
