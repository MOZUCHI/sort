#include "QuickSort.h"

void QuickSort::Exec(int* array, int size)
{
	SubSort(array, 0, size - 1);
}

void QuickSort::SubSort(int* array, int nFirst, int nLast)
{
	int iLess = nFirst;		// �O���̃C���f�b�N�X
	int iGreater = nLast;	// �㔼�̃C���f�b�N�X
	int x;					// �l

	// ���͗��[�̗v�f�̕��ϒl�ɂ���
	x = (array[nFirst] + array[nLast]) / 2;

	// �������[�v
	// �ʒu���t�ɂȂ�ƏI��
	while (iLess < iGreater)
	{
		// ����菬�����v�f�͖���
		while (array[iLess] < x) iLess++;

		// �����傫���v�f�͖���
		while (array[iGreater] > x) iGreater--;

		// �ʒu�������Ƃ��Ă���Ƃ��͌������AiLess��iGreater��1���i�߂�
		if (iLess < iGreater)
		{
			Swap(array[iLess++], array[iGreater--]);
		}
	}

	// iLess == iGreater�ŏI��������AiGreater < iLess�ɂȂ�悤�ɂ���
	if (iLess == iGreater)
	{
		if (array[iLess] < x)iLess++;
		else if (array[iLess] > x)iGreater--;
	}

	// ���̃u���b�N�̃T�C�Y��2�ȏ�̎��͍ċA
	if (iLess >= nFirst + 2)
	{
		SubSort(array, nFirst, iLess - 1);
	}
	if (iGreater <= nLast - 2)
	{
		SubSort(array, iGreater + 1, nLast);
	}
}