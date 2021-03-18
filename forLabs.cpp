#include <iostream>
#include "forLabs.h"
char* name = (char*)"test.txt";

int main() {
	setlocale(LC_ALL, "ru");
	int N, num;


	cout << "Количество элементов в списке: ";
	cin >> N;
	cout << "Искомое число: ";
	cin >> num;


	make_single_list(N, &HEAD);
	cout << "Изнчальный список" << endl;
	print_single_list(HEAD);

	//cout << "Индекс искомого числа " << search_ind(num) << endl;

	insert_item_single_list(HEAD, search_ind(num), num);
	cout << "Изменённый список" << endl;
	print_single_list(HEAD);

	
	return 0;
}