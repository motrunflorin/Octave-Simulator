Matrix Manipulation Library
Description

This is a C library for matrix operations, including basic operations like addition, multiplication, transpose, resizing, sorting, and more. It also includes the Strassen algorithm for efficient matrix multiplication.
Structures

    matrix_t: Represents a matrix with rows, columns, and the values of the matrix as a 2D array.
    arr_matrix_t: Represents an array of matrices with size and occupied space.

Utils

    modulo: Calculates modulo 10007 of an integer.
    sum_matrix: Calculates the sum of elements of a matrix then its modulo.
    swap_matrix: Swaps two matrices by reference.

Allocations

    check_alloc: Verifies if allocation is successful.
    alloc_grid: Allocates memory for a matrix.
    alloc_arr: Allocates memory for the array of matrices.
    resize_arr: Reallocates memory for the array of matrices with 1, less, or more.

Frees

    free_matrix: Frees the memory of a matrix.
    free_arr: Frees the memory of the array.

Operations

    add_matrix: Adds a new matrix at the end of the array.
        Allocates memory for a matrix and populates it with values from input.
        If the occupied space is equal to the array size, then the size of the array grows with 1.

    print_matrix: Prints a chosen matrix from the array.

    dim_matrix: Prints dimensions of a given matrix.

    sort_matrices: Sorts matrices in ascending order based on their sum by swapping, only if there are at least 2.

    delete_matrix: Deletes a given matrix from the array.
        If the array has one element, frees the memory of the first matrix.
        If there are at least 2 matrices in the array, moves the given matrix to the end of the array and then frees its memory.
        The size of the array decreases by 1.

    matrix_transpose: Creates the transpose of a given matrix.
        The rows are swapped with columns.
        Transpose replaces the given matrix in the array.

Pow

    read_matrix_and_power: Reads from input the index and power of a matrix.
    pow_matrix: Raises a given matrix to a given power.
        At first, the result is the identity matrix.
        While the power is positive:
            If the power is even, it halves, and the matrix becomes the matrix raised to the second power.
            If the power is odd, it decrements by one, and the result becomes the product of the last result and the matrix; then the power is halved, and the matrix becomes the matrix raised to the second power.
        After the power becomes 0, the result replaces the given matrix in the array.

Multiply

    multiply_matrices: Returns the product of 2 matrices.
        Every element of the returned matrix is modulo 10007.

    multiply_matrices_command: Calculates the product of 2 given matrices and adds it to the end of the array.

Resize

    read_indices: Reads the indices from input, allocates memory for an array of indices, and populates it.
    resize_rows: Creates and returns a matrix formed with the specified rows indices.
    resize_columns: Creates and returns a matrix formed with the specified columns indices.
    resize_matrix_indices: Creates and returns a matrix formed with the combined specified columns and rows indices.
        It uses resize_rows and resize_columns functions.
    resize_matrix: Reads the matrix index and the indices of rows and columns, creates the resized matrix with resize_matrix_indices function, and replaces the given matrix in the array with the resized matrix.

Strassen

    Strassen is an algorithm much faster than the regular multiplication of matrices.
    It uses a divide-and-conquer approach.
    It breaks down the matrix multiplication into a series of subproblems and employs a set of formulas to compute the results more efficiently.
    It reduces the number of multiplications, involving more additions, making computations faster for large matrices.

Functions

    subtract_matrices: Subtracts 2 matrices and returns the result.
    add_matrices: Adds 2 matrices and returns the result.
    allocate_submatrices: Allocates memory for a 2*2 array of submatrices.
    populate_submatrices: Extracts submatrices from a given matrix using specified rows and columns indices.
    strassen_multiply: Performs the Strassen algorithm.
        Recursively divides matrices into submatrices, does multiplications, and then combines the results.
    strassen: Reads the given matrices, applies the Strassen algorithm on them, and adds the result to the end of the array of matrices. If the array is full, its size grows by 1.

Usage

    L: Add a matrix to the array.
    P: Print a matrix from the array.
    D: Print dimensions of a matrix.
    M: Multiply two matrices and add to the array.
    T: Transpose a matrix.
    O: Sort matrices in the array.
    R: Raise a matrix to a power.
    C: Resize a matrix.
    F: Delete a matrix from the array.
    S: Apply Strassen algorithm.
    Q: Quit the program.
