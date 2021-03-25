#include "forLabs.h"


int main() {
	setlocale(LC_ALL, "ru");
	float N, num;
	char* data = (char*)"Ch";
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

	make_double_list(N, &DOUBLE_HEAD, DOUBLE_HEAD->PREV);
	cout << "Изнчальный список" << endl;
	print_double_list(DOUBLE_HEAD);
	delete_item_double_list(DOUBLE_HEAD, 3);
	cout << "Изменённый список" << endl;
	print_double_list(DOUBLE_HEAD);
	//cout << "Индекс спец символа " << search_ind_d(data) << endl;
	return 0;
}