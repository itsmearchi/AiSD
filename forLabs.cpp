#include <iostream>
#include "forLabs.h"
char* name = (char*)"test.txt";

int main() {
	
	int x[] = { 21,-100,-4,6,8,12,11,1 };
	int k = 8;
	setlocale(LC_ALL, "ru");
	//shaker(x, k);		 3 4 1 5 7 8 2
	//selectionSort(x, k);
	//insertSort(x, k);
	//buildPyramidSort(x, k);
	
	Simple_Merging_Sort(name);
	/*for (int i = 0; i < k; i++)
	{
		std::cout << x[i] << " ";
	}*/
}