
#include <stdio.h>
#include <limits.h>
#include <iostream>
class Node
{
public:
	int Value;
	Node *Next;

	Node(int value) : Value(value), Next(NULL) {}
};

class LinkedList
{
private:
	int m_count;

public:
	Node *Head;
	Node *Tail;
	~LinkedList()
	{
		Head = nullptr;
		Tail = nullptr;
		m_count = 0;
	};
	LinkedList() : Head(nullptr), Tail(nullptr), m_count(0){};
	Node *Get(int index);

	void InsertHead(int val);
	void InsertTail(int val);
	void Insert(int index, int val);

	int Search(int val);
	void RemoveHead();
	void RemoveTail();
	void Remove(int index);

	int Count();
	void PrintList()
	{
		Node *p = Head;
		while (p != NULL)
		{
			std::cout<<p->Value <<" ";
			p = p->Next;
		}
	};

	// 1. �em so lan xuat hien cua gia tri val trong Linked List
	int CountOccurrence(int val);
	// 2. T�m gia tri min trong Linked List
	int FindMin();
	// 3. Tinh gia tri trung binh cac phan tu co trong Linked List
	double FindAverage();
	// 4. Sap xep cac phan tu trong Linked List theo thu tu tang dan
	void SortAsc();
};

Node *LinkedList::Get(int index)
{
	if (index < 0 || index > m_count)
		return NULL;
	Node *node = Head;
	for (int i = 0; i < index; ++i)
	{
		node = node->Next;
	}

	return node;
}

void LinkedList::InsertHead(int val)
{
	Node *node = new Node(val);
	node->Next = Head;
	Head = node;
	if (m_count == 0)
		Tail = Head;
	m_count++;
}

/////////////////////////////////////////
int LinkedList::CountOccurrence(int val)
{
	Node *p = Head;
	int cnt = 0;
	while (p != NULL)
	{
		if (p->Value == val)
			cnt++;
		p = p->Next;
	}
	return cnt;
}
void TestCountOccurrence()
{
	LinkedList list;
	list.InsertHead(9);
	list.InsertHead(12);
	list.InsertHead(4);
	list.InsertHead(6);
	list.InsertHead(7);
	list.InsertHead(12);
	list.InsertHead(12);
	std::cout << list.CountOccurrence(12) << "\n";
}
/////////////////////////////////////////
int LinkedList::FindMin()
{
	int min = INT_MAX;
	Node *p = Head;
	while (p != NULL)
	{
		if (p->Value < min)
			min = p->Value;
		p = p->Next;
	}
	return min;
}

void TestFindMin()
{
	LinkedList list;
	list.InsertHead(9);
	list.InsertHead(12);
	list.InsertHead(4);
	list.InsertHead(6);
	list.InsertHead(7);
	list.InsertHead(12);
	list.InsertHead(12);
	std::cout << list.FindMin() << "\n";
}
/////////////////////////////////////////

double LinkedList::FindAverage()
{
	if (m_count==0)
	return 0;
	Node *p = Head;
	int sum = 0;
	while (p != NULL)
	{
		sum += p->Value;
		p = p->Next;
	}
	return sum * 1.0 / m_count;
}
void TestFindAverage()
{
	LinkedList list;
	list.InsertHead(1);
	list.InsertHead(2);
	list.InsertHead(3);
	list.InsertHead(4);
	list.InsertHead(5);
	list.InsertHead(6);
	// list.InsertHead(12);
	std::cout << list.FindAverage() << "\n";
}

/////////////////////////////////////////
void LinkedList::SortAsc()
{
	Node *p = Head;
	int tmp;
	while (p != NULL)
	{
		if (p->Value > p->Next->Value)
		{
			tmp = p->Value;
			p->Value = p->Next->Value;
			p->Next->Value = tmp;
		}
		p = p->Next;
	}
}
void TestSortAsc()
{
	LinkedList list;
	list.InsertHead(9);
	list.InsertHead(12);
	list.InsertHead(4);
	list.InsertHead(6);
	list.InsertHead(7);
	list.InsertHead(12);
	list.InsertHead(12);
	list.SortAsc();
	list.PrintList ();
}
/////////////////////////////////////////
int main(void)
{
	TestCountOccurrence();
	TestFindMin();
	TestFindAverage();
	TestSortAsc();
	return 0;
}
