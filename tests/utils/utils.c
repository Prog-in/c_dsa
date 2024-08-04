#include <time.h>
#include <stdlib.h>

int genRandNum()
{
    return rand() % 100;
}

int *genRandArr(unsigned n)
{
    int *arr = malloc(n * sizeof(int));

    for (unsigned i = 0; i < n; i++)
    {
        arr[i] = genRandNum();
    }
    
    return arr;
}