#pragma once
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Single_List {
	int DATA;
	Single_List* NEXT;
};
Single_List* HEAD; //????????? ?? ?????? ??????? ??????


struct Single_List2 {

	char* DATA;
	int INDEX;
	Single_List2* NEXT;
};
Single_List2* HEAD2;


struct Double_List {
	char* DATA;
	Double_List* NEXT, * PREV;
};
Double_List* DOUBLE_HEAD = new Double_List;

struct Double_List2 {
	int DATA;
	Double_List2* NEXT, * PREV;
};
Double_List2* DOUBLE_HEAD2 = new Double_List2;




#pragma region 8.1
int make_single_list(float n, Single_List** head) {


	if (n > 0) {
		(*head) = new Single_List;
		cout << "??????? ????????: ";
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
	if (Head == NULL) {//?????? ????
		Head = NewItem;//??????? ?????? ??????? ??????
	}
	else {//?????? ?? ????
		Single_List* Current = Head;
		for (int i = 1; i < Number && Current->NEXT != NULL; i++)
			Current = Current->NEXT;
		if (Number == 0) {
			//????????? ????? ??????? ?? ?????? ?????
			NewItem->NEXT = Head;
			Head = NewItem;
		}
		else {//????????? ????? ??????? ?? ???????? ?????
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
		//???????? ?????? ??? ????? ???????
		(*Head)->DATA = str;
		//?????? ???????? ??????????????? ????
		(*Head)->PREV = Prev;
		(*Head)->NEXT = NULL;//????????? ????????? ????
		make_double_list(n - 1, &((*Head)->NEXT), (*Head));
	}
	else (*Head) = NULL;
	return 0;
}
int print_double_list(Double_List* Head) {
	if (Head != NULL) {
		cout << Head->DATA << "\t";
		print_double_list(Head->NEXT);
		//??????? ? ?????????? ????????
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
	Double_List* ptr;//??????????????? ?????????
	Double_List* Current = Head;
	for (int i = 0; i < Number && Current != NULL; i++)
		Current = Current->NEXT;
	if (Current != NULL) {//???????? ?? ????????????
		if (Current->PREV == NULL) {//??????? ?????? ???????
			Head = Head->NEXT;
			delete(Current);
			Head->PREV = NULL;
			Current = Head;
		}
		else {//??????? ???????? ???????
			if (Current->NEXT == NULL) {
				//??????? ????????? ???????
				Current->PREV->NEXT = NULL;
				delete(Current);
				Current = Head;
			}
			else {//??????? ???????? ? ??????????? ???????
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






#pragma region 8.4
//???????? ???????????????? ?????? (?????????? ? ?????)
int Make_Double_List(int n, Double_List2** Head,
	Double_List2* Prev) {
	if (n > 0) {
		*Head = new Double_List2;
		//???????? ?????? ??? ????? ???????
		cout << "??????? ???????? ";
		cin >> (*Head)->DATA;
		//?????? ???????? ??????????????? ????
		(*Head)->PREV = Prev;
		(*Head)->NEXT = NULL;//????????? ????????? ????
		Make_Double_List(n - 1, &((*Head)->NEXT), (*Head));
	}
	else (*Head) = NULL;
	return 0;
}
int Print_Double_List(Double_List2* Head) {
	if (Head != NULL) {
		cout << Head->DATA << "\t";
		Print_Double_List(Head->NEXT);
		//??????? ? ?????????? ????????
	}
	else cout << "\n";
	return 0;
}

Double_List2* get_last_element_address(Double_List2* dHead) {

	Double_List2* cur = dHead;
	while (cur->NEXT != nullptr)
		cur = cur->NEXT;

	return cur;
}



vector<int> min_array;

int set_min_array() {
	Double_List2* address_last = get_last_element_address(DOUBLE_HEAD2);
	Double_List2* address_first = DOUBLE_HEAD2;

	while (address_first != nullptr && address_last != nullptr)
	{
		if (address_first->DATA < address_last->DATA)
			min_array.push_back(address_first->DATA);
		else min_array.push_back(address_last->DATA);

		address_first = address_first->NEXT;
		address_last = address_last->PREV;
	}
	return 0;
}
int get_max() {
	int max = min_array[0];
	for (int i = 1; i < min_array.size(); i++) {
		if (min_array[i] > max)
			max = min_array[i];
	}
	return max;
}
#pragma endregion
