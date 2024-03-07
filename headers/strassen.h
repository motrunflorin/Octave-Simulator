// Copyright Florin-Cristian Motrun 334CA 2023-2024

#ifndef STRASSEN_H
#define STRASSEN_H

#include "utils.h"

matrix_t subtract_matrices(matrix_t matrix_1, matrix_t matrix_2);
matrix_t add_matrices(matrix_t matrix_1, matrix_t matrix_2);
matrix_t strassen_multiply(matrix_t matrix_1, matrix_t matrix_2);
matrix_t combine_result_submatrices(matrix_t c[2][2], size_t half_size);
void calculate_intermediate_matrices(matrix_t a[2][2], matrix_t b[2][2],
									 matrix_t p[7]);
void calculate_result_submatrices(matrix_t p[7], matrix_t c[2][2]);
void free_submatrices(matrix_t a[2][2], matrix_t b[2][2], matrix_t c[2][2]);
void free_intermediate_matrices(matrix_t p[7]);
void strassen(arr_matrix_t *arr_matrix);

#endif
