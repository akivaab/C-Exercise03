#ifndef _SYMMETRY_H_
#define _SYMMETRY_H_
#include <stdlib.h>

/**
 * @file Matrix Transposition Symmetry
*/

/**
 * @brief "numeric_t" enables us to easily change the data type the matrix holds.
*/
typedef int numeric_t;

/**
 * @brief Values that reflect whether a matrix is symmetric or otherwise. 
*/
typedef enum SymmetryStatus_t
{
    symmetric = 1,
    skewSymmetric = -1,
    neither = 0,
    undetermined = 2
} SymmetryStatus;

/**
 * @brief Swaps the values of two numbers.
 *
 * @param a the first number
 * @param b the second number
*/
void Swap(numeric_t *a, numeric_t *b);

/**
 * @brief Transposes a square matrix and indicates if its symmetric, skew-symmetric, or neither. 
 *
 * @param size the size of the matrix
 * @param matrix the matrix being transposed
 * 
 * @return a value indicating the symmetric status of the matrix
*/
SymmetryStatus Transpose(size_t size, numeric_t(*matrix)[]);

/**
 * @brief Checks if two elements of a matrix being transposed make it symmetrical, skew-symmetrical, or neither. 
 * 
 * @param status indicates what examining past elements has determined regarding the matrix's symmetry so far
 * @param element1 points to the first element of the pair being transposed
 * @param element2 points to the second element of the pair being transposed
 * 
 * @return a value indicating the status of the matrix as determined so far
*/
SymmetryStatus CheckSymmetry(SymmetryStatus status, numeric_t *element1, numeric_t *element2);
#endif
