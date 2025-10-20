#include <stdio.h>
#include "RadixSort.h"

int RadixSort::MaxBit(int* array, int size)
{
	int maxArray = array[0];  // �ő吔
	for (int i = 1; i < size; i++)
	{
		if (maxArray < array[i])
			maxArray = array[i];
	}
	int d = 1;
	int p = 10;
	while (maxArray >= p)
	{
		maxArray /= p;
		d++;
	}
	return d;
}

	
void RadixSort::Exec(int* array, int size)
{
	int d = MaxBit(array, size);
	int* tmp = new int[size];
	int* count = new int[10];	// �J�E���^�[
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++)
	{
		for (j = 0; j < 10; j++)
		{
			// �e���蓖�Ă̑O�ɃJ�E���^�[���N���A����
			count[j] = 0;
		}
		for (j = 0; j < size; j++)
		{
			// �e�����̃��R�[�h�̐��𐔂���
			k = (array[j] / radix) % 10;
			count[k]++;
		}
		for (j = 1; j < 10; j++)
		{
			// tmp���̈ʒu���e�o�P�b�g�ɏ��ԂɊ��蓖�Ă�
			count[j] = count[j - 1] + count[j];
		}
		// �����̑S�Ẵ��R�[�h�����Ԃ�tmp�Ɏ��W����
		for (j = size - 1; j >= 0; j--)
		{
			k = (array[j] / radix) % 10;
			tmp[count[k] - 1] = array[j];
			count[k]--;
		}
		// �ꎞ�z��̓��e���f�[�^�ɃR�s�[
		for (j = 0; j < size; j++)
		{
			array[j] = tmp[j];
		}
		radix *= 10;
	}
	delete[]tmp;
	delete[]count;
}

void RadixSort::SubSort(int* array, int nFirst, int nLast)
{
}