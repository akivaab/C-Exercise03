#ifndef _OPTIMIZED_FIBONACCI_H_
#define _OPTIMIZED_FIBONACCI_H_
#include <stdlib.h>

/**
 *  @file Optimized Fibonacci
*/

/**
 * @brief shorthand for "unsigned long long int"
*/
typedef unsigned long long int ull_t;

/**
 * @brief Calculates the n'th number of the Fibonacci sequence.
 *
 * @param n the index of the number of the sequence being sought
 *
 * @return the n'th number of the Fibonacci sequence
 *
 * @note Fibonacci(0) = 0, Fibonacci(1) = 1, etc.
*/
ull_t Fibonacci(size_t n);

/**
 * @brief Initialize the Fibonacci database with the first two number of the sequence, 0 and 1. 
*/
void InitFibonacci(void);

/**
 * @brief Free the memory that was used for the Fibonacci database. 
*/
void FinalizeFibonacci(void);

#endif