#pragma once

void bubbleSort(int* x, int k) {
	for (int i = k - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (x[j] > x[j + 1])
			{
				int temp = x[j];
				x[j] = x[j + 1];
				x[j + 1] = temp;
			}
		}
	}
}

void shaker(int* x, int k) {
	bool e;
	do
	{
		e = false;
		for (int i = k - 1; i > 0; i--)
		{
			if (x[i - 1] > x[i])
			{
				int temp = x[i];
				x[i] = x[i - 1];
				x[i - 1] = temp;
				e = true;
			}
		}
		for (int i = 1; i < k; i++)
		{
			if (x[i - 1] > x[i])
			{
				int temp = x[i];
				x[i] = x[i - 1];
				x[i - 1] = temp;
				e = true;
			}

		}

	} while (e);
}
void selectionSort(int* x, int k) {
	int min;
	for (int i = 0; i < k - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < k; j++)
		{
			if (x[j] < x[min])
			{
				min = j;
			}
		}
		int t = x[i];
		x[i] = x[min];
		x[min] = t;
	}
}
void insertSort(int* x, int k) {

	for (int i = 0; i < k; i++)
	{
		int t = x[i], j;
		for (j = i - 1; j >= 0 && x[j] > t; j--)
			x[j + 1] = x[j];
		x[j + 1] = t;
	}
};
