#include "Queue.h"
using namespace std;
template <typename T>
void Queue<T>:: push(T value)
{
	Node <T>* node = new Node<T> (value);
	if (m_count == 0)
	{
		head = tail = node;
	}
	else
	{
		tail->next = node;
		node = tail;

	}
	m_count++;
}
template <typename T> 
T Queue <T> ::front()
{
	return head
}