#include <iostream>
#include "forLabs.h"
char* name = (char*)"test.txt";

int main() {
	setlocale(LC_ALL, "ru");
	float N, num;

#pragma region Первое задание
	/*cout << "Количество элементов в списке: ";
	cin >> N;
	cout << "Искомое число: ";
	cin >> num;


	make_single_list(N, &HEAD);
	cout << "Изнчальный список" << endl;
	print_single_list(HEAD);
	cout << "Среднее арифметическое элементов списка = " << sum_list(HEAD) / N << endl << endl;

	insert_item_single_list(HEAD, search_ind(num), num);
	cout << "Изменённый список" << endl;
	print_single_list(HEAD);*/

#pragma endregion

	cout << "Количество элементов в списке: ";
	cin >> N;
	make_single_list2(N, &HEAD2);
	cout << "Изначальный список" << endl;
	print_single_list2(HEAD2);

	return 0;
}