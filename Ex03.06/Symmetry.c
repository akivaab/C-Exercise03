#include "Symmetry.h"

void Swap(numeric_t *a, numeric_t *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Transpose(size_t size, numeric_t(*matrix)[])
{
    int symmetryStatus = 2;     /* Not 1, 0, or -1 */
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = i + 1; j < size; ++j)
        {
            symmetryStatus = CheckSymmetry(symmetryStatus, ((numeric_t *)matrix) + i * size + j,
                                                           ((numeric_t *)matrix) + j * size + i);
            Swap(((numeric_t *)matrix) + i * size + j,
                 ((numeric_t *)matrix) + j * size + i);
        }
    }
    return symmetryStatus;
}

int CheckSymmetry(int symmetryStatus, numeric_t *element1, numeric_t *element2)
{
    if (*element1 == *element2 && symmetryStatus != 0 && symmetryStatus != -1)
    {
        return 1;
    }
    else if (*element1 == -(*element2) && symmetryStatus != 0 && symmetryStatus != 1)
    {
        return -1;
    }
    else
    {
        return 0;
    }
}