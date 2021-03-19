#pragma once
using namespace std;

struct Single_List {
	float DATA;
	Single_List* NEXT;
};
Single_List* HEAD; //указатель на первый элемент списка



struct Single_List2 {

	char* DATA;
	Single_List2* NEXT;
};
Single_List2* HEAD2; //указатель на первый элемент списка







#pragma region Первое задание
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