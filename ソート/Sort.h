#pragma once

class Sort
{
protected:
	void Swap(int& a, int& b)
	{
		int temp = a;
		a = b;
		b = temp;
	}

public:
	virtual void Exec(int* array, int size) = 0;
	
	// クイックノード用再帰関数
	virtual void SubSort(int* array, int nFirst, int nLast) = 0;
};