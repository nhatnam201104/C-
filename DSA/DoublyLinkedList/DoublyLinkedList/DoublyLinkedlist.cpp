#include <iostream>
#include "DoublyLinkedlist.h"
using namespace std;
void DoublyLinkedlist::Insert_Head(int val)
{
	Node* node = new Node(val);
	node->next = head;
	if (m_count == 0)
		head = tail = node;
	else
	{
		head->prev = node;
		head = node;
	}
	m_count++;
}
void DoublyLinkedlist::Insert_Tail(int val)
{
	Node* node = new Node(val);
	node->next = tail;
	if (m_count == 0)
		head = tail = node;
	else
	{
		tail->next = node;
		tail = node;
	}
	m_count++;
}


void DoublyLinkedlist::Insert(int index, int val)
{

	if (index == 0)
		Insert_Head(val);
	else if (index == m_count - 1)
		Insert_Tail(val);
	else
	{
		Node* temp = new Node(val);
		Node* node = head;
		for (int i = 0; i < index-1; i++)
		{
			node = node->next;
		
		}
		// 1 2 3 4 5 6 
		temp->next = node->next;
		temp->prev = node;
		node->next->prev = temp;
		node->next = temp;
		m_count++;

	}
	
}
void DoublyLinkedlist::PrintList()
{
	Node* node = head;
	for (int i = 0; i < m_count; i++)
	{
		cout << node->data << " ";
		node = node->next;
	}
}
// 1 2 3 4 5