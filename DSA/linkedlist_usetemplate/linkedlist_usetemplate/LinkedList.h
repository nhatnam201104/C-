
#pragma once
#pragma once
#include "Node.h"
template <typename T>
class LinkedList
{
private:
    int m_count;

public:
    Node<T>* Head;
    Node<T>* Tail;
    LinkedList() : Head(nullptr), m_count(0) {};
    Node<T>* Get(int index);
    void InsertHead(T val);
    void InsertTail(T val);
    void Insert(T val, int index);
    void RemoveHead();
    void RemoveTail();
    void RemoveIndex(int index);
    int Search(int val);
    void PrintList();
};