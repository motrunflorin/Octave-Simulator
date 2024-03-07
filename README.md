Matrix Manipulation Library
Description

This is a C library for matrix operations, including basic operations like addition, multiplication, transpose, resizing, sorting, and more. It also includes the Strassen algorithm for efficient matrix multiplication.
Structures

    matrix_t: Represents a matrix with rows, columns, and values as a 2D array.
    arr_matrix_t: Represents an array of matrices with size and occupied space.

Utils

    modulo: Calculates the modulo 10007 of an integer.
    sum_matrix: Calculates the sum of matrix elements with modulo.
    swap_matrix: Swaps two matrices by reference.

Allocations

    check_alloc: Verifies successful allocation.
    alloc_grid: Allocates memory for a matrix.
    alloc_arr: Allocates memory for an array of matrices.
    resize_arr: Reallocates memory for the array of matrices.

Frees

    free_matrix: Frees memory for a matrix.
    free_arr: Frees memory for the array.

Operations

    add_matrix: Adds a new matrix to the array.
    print_matrix: Prints a matrix from the array.
    dim_matrix: Prints dimensions of a matrix.
    sort_matrices: Sorts matrices in the array by their sums.
    delete_matrix: Deletes a matrix from the array.
    matrix_transpose: Creates the transpose of a matrix.
    pow_matrix: Raises a matrix to a given power.
    multiply_matrices: Multiplies two matrices.
    multiply_matrices_command: Multiplies two matrices and adds the result to the array.
    resize_rows: Creates a matrix with specified rows indices.
    resize_columns: Creates a matrix with specified columns indices.
    resize_matrix_indices: Creates a matrix with combined rows and columns indices.
    resize_matrix: Resizes a matrix with given indices.
    strassen_multiply: Performs Strassen algorithm for matrix multiplication.
    strassen: Applies Strassen algorithm on given matrices.

Strassen Algorithm

The Strassen algorithm is an efficient method for matrix multiplication. It uses a divide-and-conquer approach to reduce the number of multiplications, making computations faster for large matrices.
Functions

    subtract_matrices: Subtracts two matrices.
    add_matrices: Adds two matrices.
    allocate_submatrices: Allocates memory for a 2x2 array of submatrices.
    populate_submatrices: Extracts submatrices from a given matrix.
    strassen_multiply: Performs Strassen algorithm.
    strassen: Applies Strassen algorithm on given matrices.

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

How to Use

    Allocate memory for the array of matrices.
    Use commands:
        L to add a matrix.
        P to print a matrix.
        D to print matrix dimensions.
        M to multiply and add matrices.
        T to transpose a matrix.
        O to sort matrices.
        R to raise a matrix to a power.
        C to resize a matrix.
        F to delete a matrix.
        S to apply Strassen algorithm.
        Q to quit.
