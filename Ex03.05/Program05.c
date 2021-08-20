#include <stdio.h>
#include "Transpose.h"

#define SIZE 4

int main(void)
{
    int matrix[SIZE][SIZE] = { { 1, 1, 1, 1}, 
                               { 2, 2, 2, 2},
                               { 3, 3, 3, 3},
                               { 4, 4, 4, 4} };
    Transpose(SIZE, matrix);
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            printf_s("%d\t", matrix[i][j]);
        }
        printf_s("\n");
    }

    return 0;
}