// Copyright Florin-Cristian Motrun 334CA 2023-2024

#include "../headers/strassen.h"
#include "../headers/allocations.h"
#include "../headers/frees.h"
#include "../headers/multiply.h"

// subtracts two matrices
matrix_t subtract_matrices(matrix_t matrix_1, matrix_t matrix_2)
{
	matrix_t result;

	// check if matrices have compatible dimensions
	if (matrix_1.rows != matrix_2.rows || matrix_1.cols != matrix_2.cols) {
		// return a matrix with zeros if matrices don't match
		result.rows = matrix_1.rows;
		result.cols = matrix_1.cols;
		result.grid = alloc_grid(result.rows, result.cols);

		for (size_t i = 0; i < result.rows; ++i)
			for (size_t j = 0; j < result.cols; ++j)
				result.grid[i][j] = 0;

		return result;
	}

	// allocate memory for result matrix
	result.rows = matrix_1.rows;
	result.cols = matrix_1.cols;
	result.grid = alloc_grid(result.rows, result.cols);

	// perform subtraction
	for (size_t i = 0; i < result.rows; ++i)
		for (size_t j = 0; j < result.cols; ++j)
			result.grid[i][j] =
			modulo(matrix_1.grid[i][j] - matrix_2.grid[i][j]);

	return result;
}

// adds two matrices
matrix_t add_matrices(matrix_t matrix_1, matrix_t matrix_2)
{
	matrix_t result;

	// check if matrices have compatible dimensions
	if (matrix_1.rows != matrix_2.rows || matrix_1.cols != matrix_2.cols) {
		// return a matrix with zeros if matrices don't match
		result.rows = matrix_1.rows;
		result.cols = matrix_1.cols;
		result.grid = alloc_grid(result.rows, result.cols);

		for (size_t i = 0; i < result.rows; ++i)
			for (size_t j = 0; j < result.cols; ++j)
				result.grid[i][j] = 0;

		return result;
	}

	// allocate memory for result matrix
	result.rows = matrix_1.rows;
	result.cols = matrix_1.cols;
	result.grid = alloc_grid(result.rows, result.cols);

	// perform addition
	for (size_t i = 0; i < result.rows; ++i)
		for (size_t j = 0; j < result.cols; ++j)
			result.grid[i][j] =
			modulo(matrix_1.grid[i][j] + matrix_2.grid[i][j]);

	return result;
}

// allocates submatrices
void allocate_submatrices(matrix_t submatrices[2][2], size_t half_size)
{
	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			// allocate memory for submatrices
			submatrices[i][j].rows = half_size;
			submatrices[i][j].cols = half_size;
			submatrices[i][j].grid = alloc_grid(half_size, half_size);
		}
	}
}

// populates submatrices for Strassen case
void populate_submatrices(matrix_t submatrix[2][2], matrix_t source,
						  size_t half_size, size_t start_row,
						  size_t start_col)
{
	for (size_t i = 0; i < half_size; ++i) {
		for (size_t j = 0; j < half_size; ++j) {
			// populate submatrices from the source matrix
			submatrix[0][0].grid[i][j] =
			source.grid[i + start_row][j + start_col];

			submatrix[0][1].grid[i][j] =
			source.grid[i + start_row][j + half_size];

			submatrix[1][0].grid[i][j] =
			source.grid[i + half_size][j + start_col];

			submatrix[1][1].grid[i][j] =
			source.grid[i + half_size][j + half_size];
		}
	}
}

// calculate intermediate matrices
void calculate_intermediate_matrices(matrix_t a[2][2], matrix_t b[2][2],
									 matrix_t p[7])
{
	matrix_t temp_matrices[2];

	temp_matrices[0] = add_matrices(a[0][0], a[1][1]);
	temp_matrices[1] = add_matrices(b[0][0], b[1][1]);
	p[0] = strassen_multiply(temp_matrices[0], temp_matrices[1]);
	free_matrix(temp_matrices[0]);
	free_matrix(temp_matrices[1]);

	temp_matrices[0] = add_matrices(a[1][0], a[1][1]);
	p[1] = strassen_multiply(temp_matrices[0], b[0][0]);
	free_matrix(temp_matrices[0]);

	temp_matrices[0] = subtract_matrices(b[0][1], b[1][1]);
	p[2] = strassen_multiply(a[0][0], temp_matrices[0]);
	free_matrix(temp_matrices[0]);

	temp_matrices[0] = subtract_matrices(b[1][0], b[0][0]);
	p[3] = strassen_multiply(a[1][1], temp_matrices[0]);
	free_matrix(temp_matrices[0]);

	temp_matrices[0] = add_matrices(a[0][0], a[0][1]);
	p[4] = strassen_multiply(temp_matrices[0], b[1][1]);
	free_matrix(temp_matrices[0]);

	temp_matrices[0] = subtract_matrices(a[1][0], a[0][0]);
	temp_matrices[1] = add_matrices(b[0][0], b[0][1]);
	p[5] = strassen_multiply(temp_matrices[0], temp_matrices[1]);
	free_matrix(temp_matrices[0]);
	free_matrix(temp_matrices[1]);

	temp_matrices[0] = subtract_matrices(a[0][1], a[1][1]);
	temp_matrices[1] = add_matrices(b[1][0], b[1][1]);
	p[6] = strassen_multiply(temp_matrices[0], temp_matrices[1]);
	free_matrix(temp_matrices[0]);
	free_matrix(temp_matrices[1]);
}

// calculate result submatrices
void calculate_result_submatrices(matrix_t p[7], matrix_t c[2][2])
{
	matrix_t temp_matrices[2];

	temp_matrices[0] = add_matrices(p[0], p[3]);
	temp_matrices[1] = add_matrices(temp_matrices[0], p[6]);
	c[0][0] = subtract_matrices(temp_matrices[1], p[4]);
	free_matrix(temp_matrices[0]);
	free_matrix(temp_matrices[1]);

	c[0][1] = add_matrices(p[2], p[4]);
	c[1][0] = add_matrices(p[1], p[3]);

	temp_matrices[0] = subtract_matrices(p[0], p[1]);
	temp_matrices[1] = add_matrices(temp_matrices[0], p[2]);
	c[1][1] = add_matrices(temp_matrices[1], p[5]);
	free_matrix(temp_matrices[0]);
	free_matrix(temp_matrices[1]);
}

// combine result submatrices
matrix_t combine_result_submatrices(matrix_t c[2][2], size_t half_size)
{
	matrix_t result;
	result.rows = 2 * half_size;
	result.cols = 2 * half_size;
	result.grid = alloc_grid(result.rows, result.cols);

	for (size_t i = 0; i < half_size; ++i) {
		for (size_t j = 0; j < half_size; ++j) {
			result.grid[i][j] = modulo(c[0][0].grid[i][j]);
			result.grid[i][j + half_size] = modulo(c[0][1].grid[i][j]);
			result.grid[i + half_size][j] = modulo(c[1][0].grid[i][j]);
			result.grid[i + half_size][j + half_size] =
											modulo(c[1][1].grid[i][j]);
		}
	}

	return result;
}

// free memory used by submatrices
void free_submatrices(matrix_t a[2][2], matrix_t b[2][2], matrix_t c[2][2])
{
	for (size_t i = 0; i < 2; ++i) {
		for (size_t j = 0; j < 2; ++j) {
			free_matrix(a[i][j]);
			free_matrix(b[i][j]);
			free_matrix(c[i][j]);
		}
	}
}

// free memory used by intermediate matrices
void free_intermediate_matrices(matrix_t p[7])
{
	for (size_t i = 0; i < 7; ++i)
		free_matrix(p[i]);
}

// perform matrix multiplication using the Strassen algorithm
matrix_t strassen_multiply(matrix_t matrix_1, matrix_t matrix_2)
{
	// check if matrices are small - regular multiplication
	if (matrix_1.rows == 2)
		return multiply_matrices(matrix_1, matrix_2);

	size_t half_size = matrix_1.rows / 2;

	// allocate submatrices
	matrix_t a[2][2];
	matrix_t b[2][2];
	matrix_t c[2][2];

	allocate_submatrices(a, half_size);
	allocate_submatrices(b, half_size);

	// populate submatrices
	populate_submatrices(a, matrix_1, half_size, 0, 0);
	populate_submatrices(b, matrix_2, half_size, 0, 0);

	// calculate intermediate matrices
	matrix_t p[7];
	calculate_intermediate_matrices(a, b, p);

	// calculate result submatrices
	calculate_result_submatrices(p, c);

	// combine result submatrices
	matrix_t result = combine_result_submatrices(c, half_size);

	// free memory used by submatrices and intermediate matrices
	free_submatrices(a, b, c);
	free_intermediate_matrices(p);

	return result;
}

// strassen command
void strassen(arr_matrix_t *arr_matrix)
{
	// read the indices of matrices from input
	size_t idx_1, idx_2;
	scanf("%zu%zu", &idx_1, &idx_2);

	// check if indices are valid
	if (idx_1 >= arr_matrix->used || idx_2 >= arr_matrix->used) {
		printf("No matrix with the given index\n");
		return;
	}

	matrix_t matrix_1 = arr_matrix->arr[idx_1];
	matrix_t matrix_2 = arr_matrix->arr[idx_2];

	// check if matrix multiplication is possible
	if (matrix_1.cols != matrix_2.rows) {
		printf("Cannot perform matrix multiplication\n");
		return;
	}

	// perform matrix multiplication using the Strassen algorithm
	matrix_t result = strassen_multiply(matrix_1, matrix_2);

	// check if the array is full, and resize if necessary
	if (arr_matrix->used == arr_matrix->size)
		resize_arr(arr_matrix, arr_matrix->size + 1);

	// add the result matrix to the array
	arr_matrix->arr[arr_matrix->used] = result;
	arr_matrix->used++;
}
