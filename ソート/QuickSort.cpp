#include "QuickSort.h"

void QuickSort::Exec(int* array, int size)
{
	SubSort(array, 0, size - 1);
}

void QuickSort::SubSort(int* array, int nFirst, int nLast)
{
	int iLess = nFirst;		// 前半のインデックス
	int iGreater = nLast;	// 後半のインデックス
	int x;					// 値

	// ｘは両端の要素の平均値にする
	x = (array[nFirst] + array[nLast]) / 2;

	// 交換ループ
	// 位置が逆になると終了
	while (iLess < iGreater)
	{
		// ｘより小さい要素は無視
		while (array[iLess] < x) iLess++;

		// ｘより大きい要素は無視
		while (array[iGreater] > x) iGreater--;

		// 位置がちゃんとしているときは交換し、iLessとiGreaterを1つずつ進める
		if (iLess < iGreater)
		{
			Swap(array[iLess++], array[iGreater--]);
		}
	}

	// iLess == iGreaterで終わった時、iGreater < iLessになるようにする
	if (iLess == iGreater)
	{
		if (array[iLess] < x)iLess++;
		else if (array[iLess] > x)iGreater--;
	}

	// 次のブロックのサイズが2以上の時は再帰
	if (iLess >= nFirst + 2)
	{
		SubSort(array, nFirst, iLess - 1);
	}
	if (iGreater <= nLast - 2)
	{
		SubSort(array, iGreater + 1, nLast);
	}
}