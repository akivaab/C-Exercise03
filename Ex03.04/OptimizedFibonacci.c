#include <malloc.h>
#include <stdlib.h>
#include <stdio.h>
#include "OptimizedFibonacci.h"

static ull_t *s_fibonacciArray = NULL;
static size_t s_fibonacciArraySize = 0;

ull_t Fibonacci(size_t n)
{
    if (!s_fibonacciArray)
    {
        InitFibonacci();
    }

    if (s_fibonacciArraySize <= n)
    {
        size_t oldSize = s_fibonacciArraySize;
        s_fibonacciArraySize = n + 1;
        ull_t *newArray = (ull_t *)realloc(s_fibonacciArray, s_fibonacciArraySize * sizeof(ull_t));

        if (newArray)
        {
            s_fibonacciArray = newArray;
        }
        else
        {
            return 0;
        }

        for (size_t index = oldSize; index < s_fibonacciArraySize; ++index)
        {
            s_fibonacciArray[index] = s_fibonacciArray[index - 1] + s_fibonacciArray[index - 2];

            /* Check overflow: If number is wrapped around, set it to zero.
             * If Previous value is already zero, it means we've already wrapped
             * and all values from now on should be zero.
             */
            if ((s_fibonacciArray[index] < s_fibonacciArray[index - 1])
                || (s_fibonacciArray[index - 1] == 0))
            {
                s_fibonacciArray[index] = 0;
            }
        }
    }

    if (s_fibonacciArray)
    {
        return s_fibonacciArray[n];
    }
    else
    {
        return 0;
    }
    
}

void InitFibonacci(void)
{
    if (!s_fibonacciArray)
    {
        const size_t INITIAL_ARRAY_SIZE = 2;
        s_fibonacciArray = malloc(INITIAL_ARRAY_SIZE * sizeof(ull_t));

        if (s_fibonacciArray)
        {
            s_fibonacciArraySize = INITIAL_ARRAY_SIZE;
            s_fibonacciArray[0] = 0;
            s_fibonacciArray[1] = 1;
        }
        else
        {
            printf_s("Fatal error: Out of memory. Please contact your administrator\n");
            exit(1);
        }
    }
}

void FinalizeFibonacci(void)
{
    if (s_fibonacciArray)
    {
        free(s_fibonacciArray);
        s_fibonacciArraySize = 0;
        s_fibonacciArray = NULL;
    }
}