# Copyright Florin-Cristian Motrun 334CA 2023-2024

Structures:
    - matrix_t : used for matrices
        * it retains the number of rows, columns and the values of matrix as
        a 2D array

    - arr_matrix_t : used for array of matrices
        * it retains the array of matrices, the actual size and the occupied
                                                                        size
Utils:
    - modulo : calculates modulo 10007 of an integer

    - sum_matrix : calculates sum of elements of matrix then its modulo

    - swap_matrix : swaps 2 matrices by reference

Allocations:
    - check_alloc : verifies if allocation is successful

    - alloc_grid : allocates memory for a matrix

    - alloc_arr : allocates memory for the array of matrices

    - resize_arr : reallocates memory for the array of matrices with 1, less or
                                                                        more

Frees:
    - free_matrix : frees the memory of a matrix

    - free_arr : frees the memory of the array

Operations:

    - add_matrix : adds a new matrix at the end of array
        * allocates memory for matrix and the populates it with values from
                                                                       input
        * if the occupied space is equal with the size array,
                          then the size of array grows with 1

    - print_matrix : prints a chosen matrix from array

    - dim_matrix : prints dimensions of a given matrix

    - sort_matrices : sorts ascending the matrices of array based on their sum
                      by swapping, only if there are at least 2

    - delete_matrix : delete a given matrix from array
        * if the array has one element, free the memory of the first matrix

        * if there are at least 2 matrices in array, move the given matrix at
        the end of array and then free its memory

        * the size of array decrease with 1
    
    - matrix_transpose : create the transpose of a given matrix
        * the rows are swapped with columns
        * transpose replaces the given matrix in array
    
    Pow:
        - read_matrix_and_power : read from input the index and power of matrix

        - pow_matrix : raises a given matrix to a given power
            at first the result is the identity matrix

            while the power is positive

            * if power is even then it halves and the matrix becomes matrix
            raised to the second power

            * if power is odd then it decrements by one and the result becomes
            the product of last result and the matrix; then the power is halved
            and the matrix becomes the matrix risen to the second power

            * after the power becomes 0, the result replaces the given matrix
                                                                    in array

    Multiply : 
        - multiply_matrices : 
            * returns the product of 2 matrices
            * every element of the returned matrix is modulo 10007

        - multiply_matrices_command : calculate the product of 2 given
                                    matrices and add it at the end of the array

    Resize :
        - read_indices : reads the indices from input
            * allocates memory for an array of indices and populates it
            * returns a pointer to the array
        
        - resize_rows : creates and returns a matrix formed with the specified
                        rows indices

        - resize_columns : creates and returns a matrix formed with the
                           specified columns indices

        - resize_matrix_indices : creates and returns a matrix formed with the
                                  combined specified columns and rows indices
            * it uses resize_rows and resize_columns functions

        - resize_matrix : 
            * it reads the matrix index and the indices of rows and columns
            * creates the resized matrix with resize_matrix_indices function
            * replace in array the given matrix with the resized matrix
     
    Strassen :

    Strassen is an algorithm much faster than the regular multiplication
    of matrices.

    It uses a divide-and-conquer approach.

    It breaks down the matrix multiplication into a series of subproblems
    and employs a set of formulas to compute the results more efficiently.

    It is known that a multiplication takes more overhead than an addition:
    Strassen reduces the number of multiplications, but involves more
    additions, so for large matrices the computations are faster by using
    less multiplications.

        - subtract_matrices : subtracts 2 matrices and returns the result

        - add_matrices : adds 2 matrices and returns the result

        - allocate_submatrices : allocates memory for a 2*2 array of
                                 submatrices
        
        - populate_submatrices : extracts submatrices from a given matrix
                                 using specified rows and columns indices

        - strassen_multiply : performs Strassen algorithm
            * recursively divides matrices into submatrices, does 
            multiplications and then combines the results

        - strassen :
            * reads the given matrices
            * applies the Strassen algorithm on them
            * add the result at the end of the array of matrices
                if array full, its size grows with 1

- MAIN :

* allocate memory for the array of matrices

* if command is L : call add_matrix
                P : call print_matrix
                D : call dim_matrix
                M : call multiply_matrices_command
                T : call matrix_transpose
                O : call sort_matrices
                R : call pow_matrix
                C : call resize_matrix
                F : call delete_matrix
                S : call strassen
                Q : call free_arr and the program ends
          another : print "Unrecognized command"    