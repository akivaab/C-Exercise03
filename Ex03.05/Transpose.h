#ifndef _TRANSPOSE_H_
#define _TRANSPOSE_H_
#include <stdlib.h>

/**
 * @file Matrix Transposition
*/

/**
 * @brief "numeric_t" enables us to easily change the data type the matrix holds. 
*/
typedef int numeric_t;

/**
 * @brief Swaps the values of two numbers.
 * 
 * @param a the first number
 * @param b the second number
*/
void Swap(numeric_t *a, numeric_t *b);

/**
 * @brief Transposes a square matrix
 * 
 * @param size the size of the matrix
 * @param matrix the matrix being transposed
*/
void Transpose(size_t size, numeric_t(*matrix)[]);

#endif

