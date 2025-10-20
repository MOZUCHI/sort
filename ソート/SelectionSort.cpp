#include "SelectionSort.h"

void SelectionSort::Exec(int* array, int size)
{
	int i, j, m, min;

	for (i = 0; i < size - 1; i++)
	{
		m = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[m])
			{
				m = j;
			}
		}

		min = array[m];
		array[m] = array[i];
		array[i] = min;
	}
}

void SelectionSort::SubSort(int* array, int nFirst, int nLast)
{

}