// Copyright Florin-Cristian Motrun 334CA 2023-2024

#include "headers/allocations.h"
#include "headers/load.h"
#include "headers/sort.h"
#include "headers/dimensions.h"
#include "headers/print.h"
#include "headers/frees.h"
#include "headers/delete.h"
#include "headers/resize.h"
#include "headers/transpose.h"
#include "headers/multiply.h"
#include "headers/pow.h"
#include "headers/strassen.h"

int main(void)
{
	char command;
	command = getchar();

	// initialize the array of matrices
	arr_matrix_t *arr_matrix;
	alloc_arr(&arr_matrix, INITIAL_SIZE);

	while (command != 'Q') {
		if (command == 'L')
			add_matrix(arr_matrix);

		else if (command == 'P')
			print_matrix(arr_matrix);

		else if (command == 'D')
			dim_matrix(arr_matrix);

		else if (command == 'M')
			multiply_matrices_command(arr_matrix);

		else if (command == 'T')
			matrix_transpose(arr_matrix);

		else if (command == 'O')
			sort_matrices(arr_matrix);

		else if (command == 'R')
			pow_matrix(arr_matrix);

		else if (command == 'C')
			resize_matrix(arr_matrix);

		else if (command == 'F')
			delete_matrix(arr_matrix);

		else if (command == 'S')
			strassen(arr_matrix);

		else
			printf("Unrecognized command\n");
		command = getchar();
		command = getchar();
	}

	// free memory allocated for the array of matrices
	free_arr(arr_matrix);

	return 0;
}
