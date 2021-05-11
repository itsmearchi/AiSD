#include <iostream>

using namespace std;
#pragma once
struct Single_List {
	int DATA;
	Single_List* NEXT;
};
Single_List* HEAD; //указатель на первый элемент списка

struct Double_List {
	char* DATA;
	Double_List* NEXT, * PREV;
};
Double_List* DOUBLE_HEAD = new Double_List;
struct Single_List2 {

	char* DATA;
	int INDEX;
	Single_List2* NEXT;
};
Single_List2* HEAD2;







#pragma region 8.1
int make_single_list(float n, Single_List** head) {


	if (n > 0) {
		(*head) = new Single_List;
		cout << "Введите значение: ";
		cin >> (*head)->DATA;
		(*head)->NEXT = NULL;
		make_single_list(n - 1, &(*head)->NEXT);
	}
	return 0;
}
int print_single_list(Single_List* head) {
	if (head != NULL) {
		cout << head->DATA << " ";
		print_single_list(head->NEXT);
	}
	else cout << endl;
	return 0;
}
float search_ind(float data)
{
	float ind = 0;
	for (Single_List* Current = HEAD; Current != nullptr; Current = Current->NEXT)
	{
		if (Current->DATA == data) { return ind++; }
		ind++;
	}


}void insert(float data)
{
	Single_List* NewItem = new Single_List;
	NewItem->DATA = data;
	NewItem->NEXT = NULL;
	for (Single_List* Current = HEAD; Current != nullptr; Current = Current->NEXT)
	{
		if (Current->DATA == data) {
			NewItem->NEXT = Current->NEXT;
			Current->NEXT = NewItem;
		}
	}
}

int sum_list(Single_List* List)
{
	Single_List* p;
	p = List;
	float s = 0; int i = 1;
	while (p != NULL)
	{
		s += p->DATA;
		p = p->NEXT;
	}
	return s;
}
Single_List* insert_item_single_list(Single_List* Head, float Number, float DataItem) {
	Number--;
	Single_List* NewItem = new Single_List;
	NewItem->DATA = DataItem;
	NewItem->NEXT = NULL;
	if (Head == NULL) {//список пуст
		Head = NewItem;//создаем первый элемент списка
	}
	else {//список не пуст
		Single_List* Current = Head;
		for (int i = 1; i < Number && Current->NEXT != NULL; i++)
			Current = Current->NEXT;
		if (Number == 0) {
			//вставляем новый элемент на первое место
			NewItem->NEXT = Head;
			Head = NewItem;
		}
		else {//вставляем новый элемент на непервое место
			if (Current->NEXT != NULL)
				NewItem->NEXT = Current->NEXT;
			Current->NEXT = NewItem;
		}
	}
	return Head;
}
#pragma endregion





#pragma region 8.2


int make_single_list2(float n, Single_List2** head) {

	if (n > 0) {
		char* str;
		str = new char[10];
		cout << "Enter element: ";
		cin >> str;

		*head = new Single_List2();
		(*head)->DATA = str;
		(*head)->NEXT = NULL;
		make_single_list2(n - 1, &(*head)->NEXT);
	}
	return 0;
}

int print_single_list2(Single_List2* head) {
	if (head != nullptr) {
		cout << head->DATA << "\t";
		print_single_list2(head->NEXT);
	}
	else cout << endl;
	return 0;
}
int _print_single_list2(Single_List2* head) {
	if (head != nullptr) {
		cout << head->DATA << "\t";
		_print_single_list2(head->NEXT);
	}
	else cout << "";
	return 0;
}
int single_list2even(Single_List2* head, int counter) {
	for (Single_List2* Current = HEAD2; Current != NULL; Current = Current->NEXT) {
		if (counter % 2 != 0)cout << Current->DATA << "\t";
		counter++;
	}
	return 0;
}
void delete_single_list(Single_List2* Head) {
	if (Head != nullptr) {
		delete_single_list(Head->NEXT);
		delete Head;
	}
}


#pragma endregion








#pragma region 8.3
int make_double_list(int n, Double_List** Head, Double_List* Prev) {
	if (n > 0) {
		char* str;
		str = new char[10];
		cout << "Enter element: ";
		cin >> str;
		*Head = new Double_List;
		//выделяем память под новый элемент
		(*Head)->DATA = str;
		//вводим значение информационного поля
		(*Head)->PREV = Prev;
		(*Head)->NEXT = NULL;//обнуление адресного поля
		make_double_list(n - 1, &((*Head)->NEXT), (*Head));
	}
	else (*Head) = NULL;
	return 0;
}
int print_double_list(Double_List* Head) {
	if (Head != NULL) {
		cout << Head->DATA << "\t";
		print_double_list(Head->NEXT);
		//переход к следующему элементу
	}
	else cout << "\n";
	return 0;
}
int search_ind_d(char* data)
{
	int ind = 0;
	for (Double_List* cur = DOUBLE_HEAD; cur != NULL; cur = cur->NEXT) {
		if (strcmp(cur->DATA, data) == 0)return ind;
		ind++;
	}
}
Double_List* delete_item_double_list(Double_List* Head, int Number) {
	Double_List* ptr;//вспомогательный указатель
	Double_List* Current = Head;
	for (int i = 0; i < Number && Current != NULL; i++)
		Current = Current->NEXT;
	if (Current != NULL) {//проверка на корректность
		if (Current->PREV == NULL) {//удаляем первый элемент
			Head = Head->NEXT;
			delete(Current);
			Head->PREV = NULL;
			Current = Head;
		}
		else {//удаляем непервый элемент
			if (Current->NEXT == NULL) {
				//удаляем последний элемент
				Current->PREV->NEXT = NULL;
				delete(Current);
				Current = Head;
			}
			else {//удаляем непервый и непоследний элемент
				ptr = Current->NEXT;
				Current->PREV->NEXT = Current->NEXT;
				Current->NEXT->PREV = Current->PREV;
				delete(Current);
				Current = ptr;
			}
		}
	}
	return Head;
}
#pragma endregion






