#ifndef _FIBONACCI_H_
#define _FIBONACCI_H_

/**
 * @file Fibonacci
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
ull_t Fibonacci(unsigned int n);

#endif
