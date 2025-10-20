#include <stdio.h>
#include "RadixSort.h"

int RadixSort::MaxBit(int* array, int size)
{
	int maxArray = array[0];  // 最大数
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
	int* count = new int[10];	// カウンター
	int i, j, k;
	int radix = 1;
	for (i = 1; i <= d; i++)
	{
		for (j = 0; j < 10; j++)
		{
			// 各割り当ての前にカウンターをクリアする
			count[j] = 0;
		}
		for (j = 0; j < size; j++)
		{
			// 各箱内のレコードの数を数える
			k = (array[j] / radix) % 10;
			count[k]++;
		}
		for (j = 1; j < 10; j++)
		{
			// tmp内の位置を各バケットに順番に割り当てる
			count[j] = count[j - 1] + count[j];
		}
		// 箱内の全てのレコードを順番にtmpに収集する
		for (j = size - 1; j >= 0; j--)
		{
			k = (array[j] / radix) % 10;
			tmp[count[k] - 1] = array[j];
			count[k]--;
		}
		// 一時配列の内容をデータにコピー
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