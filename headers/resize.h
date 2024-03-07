// Copyright Florin-Cristian Motrun 334CA 2023-2024

#ifndef RESIZE_H
#define RESIZE_H

#include "utils.h"

void resize_matrix(arr_matrix_t *arr_matrix);

matrix_t resize_columns(matrix_t original, size_t *col_indices,
						size_t new_cols);

matrix_t resize_rows(matrix_t original, size_t *row_indices, size_t new_rows);

size_t *read_indices(size_t count);

matrix_t resize_matrix_indices(matrix_t original, size_t *row_indices,
							   size_t new_rows, size_t *col_indices,
							   size_t new_cols);

#endif
