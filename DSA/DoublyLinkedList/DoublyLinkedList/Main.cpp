#include "DoublyLinkedlist.h"
#include <iostream>
using namespace std;
int main()
{
	DoublyLinkedlist list;
	list.Insert_Head(1);
	list.Insert_Head(3);
	list.Insert_Head(13);
	list.Insert_Head(9);
	list.PrintList();
	list.Insert_Tail(12);
	cout << "\n";
	list.PrintList();
	list.Insert(3, 13);
	cout << "\n";
	list.PrintList();
}