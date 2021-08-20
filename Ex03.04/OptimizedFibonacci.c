#include <malloc.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include "OptimizedFibonacci.h"

static ull_t *s_fibonacciDb = NULL;
static size_t s_fibonacciDbSize = 0;

ull_t Fibonacci(size_t n)
{
    if (!s_fibonacciDb)
    {
        InitFibonacci();
    }

    if (s_fibonacciDbSize <= n) /* s_fibonacciDbSize == n means it's up to n-1 */
    {
        size_t oldSize = s_fibonacciDbSize;

        s_fibonacciDbSize = n + 1;

        ull_t *newDb = (ull_t *)realloc(s_fibonacciDb, s_fibonacciDbSize * sizeof(ull_t));

        if (newDb)
        {
            s_fibonacciDb = newDb;
        }
        else
        {
            return 0;
        }

        /* Fill the cache from the last existing value to n (which is in index [n+1]): */
        for (size_t index = oldSize; index < s_fibonacciDbSize; ++index)
        {
            s_fibonacciDb[index] = s_fibonacciDb[index - 1] + s_fibonacciDb[index - 2];

            /* Check overflow: If number is wrapped around, set it to zero.
             * If Previous value is already zero, it means we've already wrapped
             * and all values from now on should be zero.
             */
            if ((s_fibonacciDb[index] < s_fibonacciDb[index - 1])
                || (s_fibonacciDb[index - 1] == 0))
            {
                s_fibonacciDb[index] = 0;
            }
        }
    }

    return s_fibonacciDb[n];
}

void InitFibonacci(void)
{
    if (!s_fibonacciDb)
    {
        const size_t INITIAL_DB_SIZE = 2;

        s_fibonacciDb = malloc(INITIAL_DB_SIZE * sizeof(ull_t));

        if (s_fibonacciDb)
        {
            s_fibonacciDbSize = INITIAL_DB_SIZE;
            s_fibonacciDb[0] = 0;
            s_fibonacciDb[1] = 1;
        }
        else
        {
            printf("Fatal error: Out of memory. Please contact your administrator\n");
            exit(1);
        }
    }
}

void FinalizeFibonacci(void)
{
    if (s_fibonacciDb)
    {
        free(s_fibonacciDb);
        s_fibonacciDbSize = 0;
        s_fibonacciDb = NULL;
    }
}