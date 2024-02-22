#include "Queue.h"
#include "Node.h"
using namespace std;
template <typename T>
void Queue<T> ::push (T value)
{
	Node <T>* node = new Node <T> (value);
	if (m_count == 0)
	{
		head = tail = node;
	}
	else
	{
		tail->next = node;
		tail=node;

	}
	m_count++;
}
template <typename T>
T Queue <T> ::front()
{
	return head->value;
}
template <typename T>
T Queue <T> ::back()
{
	return tail->value;
}
template <typename T>
void Queue <T> ::pop()
{
	if (m_count == 0)
		return;
	else
	{
		head = head->next;
		m_count--;
	}
	
}
template <typename T>
int Queue <T> ::size()
{
	return m_count;
}
template <typename T>
int Queue <T> ::empty()
{
	if (m_count == 0)
		return 1;
	return 0;
}