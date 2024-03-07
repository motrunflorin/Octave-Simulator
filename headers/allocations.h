// Copyright Florin-Cristian Motrun 334CA 2023-2024

#ifndef ALLOCATIONS_H
#define ALLOCATIONS_H

#include "utils.h"

void check_alloc(void *p);

int **alloc_grid(size_t rows, size_t cols);

void alloc_arr(arr_matrix_t **arr_matrix, size_t size);

void resize_arr(arr_matrix_t  *arr_matrix, size_t size);

#endif
