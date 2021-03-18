#pragma once
using namespace std;

struct Single_List
{
	float DATA;
	Single_List* NEXT;
};
Single_List* HEAD; //указатель на первый элемент списка
Single_List* CURRENT; //указатель на текущий элемент списка


int make_single_list(int n, Single_List** head) {


	if (n > 0) {
		(*head) = new Single_List;
		cout << "¬ведите значение: ";
		cin >> (*head)->DATA;
		/*float s = (*head)->DATA;
		s += (*head)->DATA;*/
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

int search_ind(int data)
{
	int ind = 0;
	for (Single_List* Current = HEAD; Current != nullptr; Current = Current->NEXT)
	{
		if (Current->DATA == data) { return ind += 2; }
		ind++;
	}
}

Single_List* insert_item_single_list(Single_List* Head, int Number, int DataItem) {
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
			//вставл€ем новый элемент на первое место
			NewItem->NEXT = Head;
			Head = NewItem;
		}
		else {//вставл€ем новый элемент на непервое место
			if (Current->NEXT != NULL)
				NewItem->NEXT = Current->NEXT;
			Current->NEXT = NewItem;
		}
	}
	return Head;
}