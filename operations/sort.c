// Copyright Florin-Cristian Motrun 334CA 2023-2024

#include "../headers/sort.h"

// sort the matrices
void sort_matrices(arr_matrix_t *arr_matrix)
{
	// check if there are more than one matrix to sort
	if (arr_matrix->used > 1)
		// iterate through each matrix in the array
		for (size_t i = 0; i < (arr_matrix->used - 1); i++)
			// compare the sum of elements in the matrix with
			// the sum of subsequent matrices
			for (size_t j = i + 1; j < arr_matrix->used; j++)
				// if the sum of the j-th matrix is less than the sum of the
				// i-th matrix, swap the positions of the matrices in the array
				if (sum_matrix(arr_matrix, j) < sum_matrix(arr_matrix, i))
					swap_matrix(&arr_matrix->arr[j], &arr_matrix->arr[i]);
}
