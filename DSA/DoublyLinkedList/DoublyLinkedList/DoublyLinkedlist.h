#pragma once
#include "Node.h"
class DoublyLinkedlist {
private:
	int m_count;
public:
	Node* head, * tail;
	DoublyLinkedlist() : head(nullptr), tail(nullptr),m_count(0){};
	void Insert_Head(int val);
	void Insert_Tail(int val); 
	void Insert(int index, int val);
	void PrintList();
	void Remove_Head();
	void Remove_Tail();
	void Remove(int index);

};