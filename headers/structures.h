// Copyright Florin-Cristian Motrun 334CA 2023-2024

#ifndef STRUCTURES_H
#define STRUCTURES_H

#include <stdio.h>
#include <stdlib.h>

// structure for matrix
typedef struct {
	size_t rows;
	size_t cols;
	int **grid;
} matrix_t;

// structure for array of matrices
typedef struct {
	matrix_t *arr;
	size_t size;
	size_t used;
} arr_matrix_t;

#endif
