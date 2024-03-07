// Copyright Florin-Cristian Motrun 334CA 2023-2024

#include "../headers/resize.h"
#include "../headers/frees.h"
#include "../headers/allocations.h"

// reads indices from input
size_t *read_indices(size_t count)
{
	size_t *indices = calloc(count, sizeof(size_t));

	for (size_t i = 0; i < count; ++i)
		scanf("%zu", &indices[i]);

	return indices;
}

// resizes rows of a matrix
matrix_t resize_rows(matrix_t original, size_t *row_indices, size_t new_rows)
{
	matrix_t resized;
	resized.rows = new_rows;
	resized.cols = original.cols;
	resized.grid = alloc_grid(new_rows, resized.cols);

	for (size_t i = 0; i < new_rows; ++i) {
		// check if the row index is within bounds
		if (row_indices[i] < original.rows) {
			for (size_t j = 0; j < resized.cols; ++j)
				resized.grid[i][j] = original.grid[row_indices[i]][j];
		} else {
			// handle invalid row index
			printf("No matrix with the given index\n");
			free_matrix(resized);
			resized.rows = 0;
			resized.cols = 0;
			break;
		}
	}

	return resized;
}

// resizes columns of a matrix
matrix_t resize_columns(matrix_t original, size_t *col_indices, size_t new_cols)
{
	matrix_t resized;
	resized.rows = original.rows;
	resized.cols = new_cols;
	resized.grid = alloc_grid(original.rows, new_cols);

	for (size_t i = 0; i < original.rows; ++i) {
		for (size_t j = 0; j < new_cols; ++j) {
			// check if the column index is within bounds
			if (col_indices[j] < original.cols) {
				resized.grid[i][j] = original.grid[i][col_indices[j]];
			} else {
				// handle invalid column index
				printf("No matrix with the given index\n");
				free_matrix(resized);
				resized.rows = 0;
				resized.cols = 0;
				break;
			}
		}
	}

	return resized;
}

// resizes a matrix based on row and column indices
matrix_t resize_matrix_indices(matrix_t original, size_t *row_indices,
							   size_t new_rows, size_t *col_indices,
							   size_t new_cols)
{
	matrix_t resized_rows = resize_rows(original, row_indices, new_rows);
	if (resized_rows.rows == 0 || resized_rows.cols == 0) {
		// error occurred during row resizing, exit
		free(row_indices);
		free(col_indices);
		return resized_rows;
	}

	matrix_t resized_cols = resize_columns(resized_rows, col_indices, new_cols);
	if (resized_cols.rows == 0 || resized_cols.cols == 0) {
		// error occurred during column resizing, exit
		free_matrix(resized_rows);
		free(row_indices);
		free(col_indices);
		return resized_cols;
	}

	// create a copy of the resized matrix before freeing it
	matrix_t result = resized_cols;

	// free memory of the resized matrices
	free_matrix(resized_rows);

	// free rows and columns arrays
	free(row_indices);
	free(col_indices);

	return result;
}

// resizes a matrix
void resize_matrix(arr_matrix_t *arr_matrix)
{
	// get matrix index from input
	size_t idx;
	scanf("%zu", &idx);

	// get the number of rows for resizing
	size_t nr_rows;
	scanf("%zu", &nr_rows);
	size_t *row_indices = read_indices(nr_rows);

	// get the number of columns for resizing
	size_t nr_cols;
	scanf("%zu", &nr_cols);
	size_t *col_indices = read_indices(nr_cols);

	// check if index is within bounds
	if (idx >= arr_matrix->used) {
		printf("No matrix with the given index\n");
		free(row_indices);
		free(col_indices);
		return;
	}

	// resize the matrix based on row and column indices
	matrix_t resized_matrix = resize_matrix_indices(arr_matrix->arr[idx],
													row_indices, nr_rows,
													col_indices, nr_cols);

	// free memory of the original matrix
	free_matrix(arr_matrix->arr[idx]);

	// update the original matrix with the resized matrix
	arr_matrix->arr[idx] = resized_matrix;
}
