#include "Transpose.h"

void Swap(numeric_t *a, numeric_t *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void Transpose(size_t size, numeric_t(*matrix)[])
{
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = i + 1; j < size; ++j)
        {
            Swap(((numeric_t *)matrix) + i * size + j,
                ((numeric_t *)matrix) + j * size + i);
        }
    }
}