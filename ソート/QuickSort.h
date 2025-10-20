#pragma once
#include "Sort.h"

// クイックソート
class QuickSort : public Sort
{
public:
	virtual void Exec(int* array, int size) override;
	virtual void SubSort(int* array, int nFirst, int nLast)override;

};