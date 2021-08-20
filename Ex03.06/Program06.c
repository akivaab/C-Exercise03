#include <stdio.h>
#include "Symmetry.h"

#define SIZE 4

int main(void)
{
    int matrix[SIZE][SIZE] = { { 1, 1, 1, 1},
                               { 1, 2, 7, 2},
                               { 1, 2, 3, 3},
                               { 5, 2, 3, 4} };
    int symmetryStatus = Transpose(SIZE, matrix);

    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            printf_s("%d\t", matrix[i][j]);
        }
        printf_s("\n");
    }

    printf_s("\nThe matrix was ");
    switch (symmetryStatus)
    {
    case 1:
        printf_s("symmetric.\n");
        break;

    case -1:
        printf_s("skew-symmetric.\n");
        break;

    case 0:
        printf_s("neither symmetric nor skew-symmetric.\n");
        break;

    default:
        printf_s("inconclusively part of any known category\n");
        break;
    }

    return 0;
}