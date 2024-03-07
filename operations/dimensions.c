// Copyright Florin-Cristian Motrun 334CA 2023-2024

#include "../headers/dimensions.h"

// prints the dimensions of a matrix at the specified index
void dim_matrix(arr_matrix_t *arr_matrix)
{
	// read the index of the matrix
	size_t idx;
	scanf("%zu", &idx);

	// check if the index is valid
	if (idx > arr_matrix->used - 1 || arr_matrix->used == 0) {
		printf("No matrix with the given index\n");
		return;
	}

	// print the dimensions of the matrix
	printf("%zu %zu\n", arr_matrix->arr[idx].rows, arr_matrix->arr[idx].cols);
}
