#include <iostream>
#include "forLabs.h"




int main() {
	int x[] = { 21,-100,-4,6,8,12,11,1 };
	int k = 8;
	//bubbleSort(x, k);
	//shaker(x, k);
	//selectionSort(x, k);

	insertSort(x, k);
	
	for (int i = 0; i < k; i++)
	{
		std::cout << x[i] << " ";
	}
}