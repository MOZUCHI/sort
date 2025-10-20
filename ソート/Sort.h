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
	
	// �N�C�b�N�m�[�h�p�ċA�֐�
	virtual void SubSort(int* array, int nFirst, int nLast) = 0;
};