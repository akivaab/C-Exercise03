#include <stdio.h>
#include "Fibonacci.h"

int main(void)
{
    int fibonacciIndex;
    printf_s("enter a non-negative integer: ");
    scanf_s(" %d", &fibonacciIndex);
    printf_s("The %d'th number of the fibonacci sequence is %llu", fibonacciIndex, Fibonacci(fibonacciIndex));

    return 0;
}