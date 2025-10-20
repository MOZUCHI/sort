#pragma once
#include "Sort.h"

// Šî”ƒ\[ƒg
class RadixSort : public Sort
{
public:
	virtual void Exec(int* array, int size) override;
	virtual void SubSort(int* array, int nFirst, int nLast)override;
	static int MaxBit(int* array, int size);
};