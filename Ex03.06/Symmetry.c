#include "Symmetry.h"

void Swap(numeric_t *a, numeric_t *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

enum SymmetryStatus Transpose(size_t size, numeric_t(*matrix)[])
{
    enum SymmetryStatus status = undetermined;
    for (size_t i = 0; i < size; ++i)
    {
        for (size_t j = i + 1; j < size; ++j)
        {
            status = CheckSymmetry(status, ((numeric_t *)matrix) + i * size + j,
                                           ((numeric_t *)matrix) + j * size + i);
            Swap(((numeric_t *)matrix) + i * size + j,
                 ((numeric_t *)matrix) + j * size + i);
        }
    }
    return status;
}

enum SymmetryStatus CheckSymmetry(enum SymmetryStatus status, numeric_t *element1, numeric_t *element2)
{
    if (status != neither && *element1 == *element2 && status != skewSymmetric)
    {
        return symmetric;
    }
    else if (status != neither && *element1 == -(*element2) && status != symmetric)
    {
        return skewSymmetric;
    }
    else
    {
        return neither;
    }
}