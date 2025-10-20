#include <iostream>
#include "InsertionSort.h"

void InsertionSort::Exec(int* array, int size)
{
    int i, j, k;

    for (i = 1; i < size; i++)
    {
        k = array[i];
        j = i - 1;

        while ((j >= 0) && (array[j] > k))
        {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = k;
    }
}

void InsertionSort::SubSort(int* array, int nFirst, int nLast)
{

}
