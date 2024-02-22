#pragma once
#include "Node.h"
template <typename T>
class Queue {
private:
	int m_count;
public:
	Node <T>* tail;
	Node <T>* head;
	Queue() : head(nullptr), tail(nullptr), m_count(0) {};
	int size();
	int empty();
	T front();
	T back();
	void push(T value);
	void pop();
	
};