// Copyright Florin-Cristian Motrun 334CA 2023-2024

#include "../headers/delete.h"
#include "../headers/allocations.h"
#include "../headers/frees.h"

// deletes a matrix at the specified index from the array
void delete_matrix(arr_matrix_t *arr_matrix)
{
	// read the index of the matrix to be deleted
	int idx;
	scanf("%d", &idx);

	// check if the index is valid
	if ((size_t)idx > arr_matrix->used - 1 ||
		arr_matrix->used == 0 || idx < 0) {
		printf("No matrix with the given index\n");
		return;
	}

	// check if the array contains only one element
	if (idx == 0 && arr_matrix->used == 1) {
		// delete the only element
		free_matrix(arr_matrix->arr[0]);
	} else {
		// move matrix at the end of array
		if ((size_t)idx != arr_matrix->used - 1)
			for (size_t i = (size_t)idx; i < arr_matrix->used - 1 ; ++i)
				swap_matrix(&arr_matrix->arr[i], &arr_matrix->arr[i + 1]);

		// delete last matrix
		free_matrix(arr_matrix->arr[arr_matrix->used - 1]);

		// resize the array if necessary
		if (arr_matrix->used - 1 == arr_matrix->size - 1)
			resize_arr(arr_matrix, arr_matrix->size - 1);
	}

	// update the used count
	arr_matrix->used--;
}
