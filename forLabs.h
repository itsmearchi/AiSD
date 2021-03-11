#pragma once
#pragma warning(disable : 4996)
#pragma region Simple Massive Sort
void bubbleSort(int* x, int k) {
	for (int i = k - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (x[j] > x[j + 1])
			{
				int t = x[j];
				x[j] = x[j + 1];
				x[j + 1] = t;
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
	for (int i = 0; i < k - 1; i++)
	{
		int min = i;
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
#pragma endregion
#pragma region Pyramid Sort
void buildPyramid(int* x, int r, int k);
void sortPyramid(int* x, int k);

void buildPyramidSort(int* x, int k) {
	buildPyramid(x, k / 2 + 1, k - 1);
	sortPyramid(x, k - 1);
}

void exch(int* x, int i, int j) {
	int t = x[i];
	x[i] = x[j];
	x[j] = t;
}
void sifting(int* x, int left, int right) {
	int q = 2 * left + 1, p = q + 1;
	if (q <= right) {
		if (p <= right && x[q] < x[p])
			q = p;
		if (x[left] < x[q]) {
			exch(x, left, q);
			sifting(x, q, right);
		}
	}
}
void buildPyramid(int* x, int r, int k) {
	sifting(x, k, r);
	if (k > 0)
		buildPyramid(x, r, k - 1);
}
void sortPyramid(int* x, int k) {
	exch(x, 0, k);
	sifting(x, 0, k - 1);
	if (k > 1)
		sortPyramid(x, k - 1);
}

#pragma endregion
#pragma region Описание функции сортировки простым слиянием
int Simple_Merging_Sort(char* name) {
	int a1, a2, k, i, j, kol;
	FILE* f, * f1, * f2;
	kol = 0;
	if ((f = fopen(name, "r")) == NULL)
		printf("\nИсходный файл не может быть прочитан...");
	else {
		while (!feof(f)) {
			fscanf(f, "%d", &a1);
			kol++;
		}
		fclose(f);
	}
	k = 1;
	while (k < kol) {
		f = fopen(name, "r");
		f1 = fopen("smsort_1", "w");
		f2 = fopen("smsort_2", "w");
		if (!feof(f)) fscanf(f, "%d", &a1);
		while (!feof(f)) {
			for (i = 0; i < k && !feof(f); i++) {
				fprintf(f1, "%d ", a1);
				fscanf(f, "%d", &a1);
			}
			for (j = 0; j < k && !feof(f); j++) {
				fprintf(f2, "%d ", a1);
				fscanf(f, "%d", &a1);
			}
		}
		fclose(f2);
		fclose(f1);
		fclose(f);

		f = fopen(name, "w");
		f1 = fopen("smsort_1", "r");
		f2 = fopen("smsort_2", "r");
		if (!feof(f1)) fscanf(f1, "%d", &a1);
		if (!feof(f2)) fscanf(f2, "%d", &a2);
		while (!feof(f1) && !feof(f2)) {
			i = 0;
			j = 0;
			while (i < k && j < k && !feof(f1) && !feof(f2)) {
				if (a1 < a2) {
					fprintf(f, "%d ", a1);
					fscanf(f1, "%d", &a1);
					i++;
				}
				else {
					fprintf(f, "%d ", a2);
					fscanf(f2, "%d", &a2);
					j++;
				}
			}
			while (i < k && !feof(f1)) {
				fprintf(f, "%d ", a1);
				fscanf(f1, "%d", &a1);
				i++;
			}
			while (j < k && !feof(f2)) {
				fprintf(f, "%d ", a2);
				fscanf(f2, "%d", &a2);
				j++;
			}
		}
		while (!feof(f1)) {
			fprintf(f, "%d ", a1);
			fscanf(f1, "%d", &a1);
		}
		while (!feof(f2)) {
			fprintf(f, "%d ", a2);
			fscanf(f2, "%d", &a2);
		}
		fclose(f2);
		fclose(f1);
		fclose(f);
		k *= 2;
	}
	remove("smsort_1");
	remove("smsort_2");
	return 0;
}
#pragma endregion