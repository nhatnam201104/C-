#include "LinkedList.h"
#include <iostream>
using namespace std;
template <typename T>
Node<T>* LinkedList<T>::Get(int index)
{
    int poison;
    Node<T>* node = Head;
    if (m_count == 0 || index < 0 || index >= m_count)
        return nullptr;
    while (poison != index)
    {
        node = node->Next;
    }
    return node;
}
template <typename T>
void LinkedList<T>::InsertHead(T val)
{
    Node<T>* node = new Node<T>(val);
    if (m_count == 0)
    {
        Head = node;
        Tail = node;
    }
    else
    {
        Head->Next = node;
        Head = node;
    }
    m_count++;
}
template <typename T>
void LinkedList<T>::InsertTail(T val)
{
    Node<T>* node = new Node<T>(val);
    if (m_count == 0)
        Head = Tail = node;
    else
    {
        Tail->Next = node;
        Tail = node;
    }
    m_count++;
}
template <typename T>
void LinkedList<T>::Insert(T val, int index)
{
    if (index < 0 || index >= m_count)
        return;
    if (index == 0)
        InsertHead(val);
    else if (index = m_count - 1)
        InsertTail(val);
    else
    {
        Node<T>* node = new Node<T>(val);
        Node<T>* pprev = nullptr, * p = Head;
        int i = 0;
        while (i != index)
        {
            pprev = p;
            p = p->Next;
        }
        pprev->Next = node;
        node->Next = p;
    }
    m_count++;
}
template <typename T>
void LinkedList<T>::RemoveHead()
{
    if (m_count == 0)
        return;
    Head = Head->Next;
    m_count--;
}
template <typename T>
void LinkedList<T>::RemoveTail()
{
    if (m_count == 0)
        return;
    if (m_count == 1)
        RemoveHead();
    else
    {
        Node<T>* node = Head, * nodeprev = nullptr;
        while (node->Next == nullptr)
        {
            nodeprev = node;
            node = node->Next;
        }
        nodeprev->Next == nullptr;
        Tail = nodeprev;
        delete node;
    }
    m_count--;
}
template <typename T>
void LinkedList<T>::RemoveIndex(int index)
{
    if (m_count == 0 || index < 0 || index >= m_count)
        return;
    if (index == 0)
    {
        RemoveHead();
        return;
    }
    if (index = m_count - 1)
    {
        RemoveTail();
        return;
    }
    Node<T>* node = Head, * nodeprev;
    int i = 0;
    while (i != index)
    {
        nodeprev = node;
        node = node->Next;
    }
    nodeprev.Next = node->Next;
    delete node;
    m_count--;
}
template <typename T>
int LinkedList<T>::Search(int val)
{
    if (m_count == 0)
        return -1;
    Node<T>* node = Head;
    int poison = 0;
    while (node->Value != val)
    {
        node = node->Next;
        poison++;
        if (node == nullptr)
            return -1;
    }
    return node;
}
template <typename T>
void LinkedList<T>::PrintList()
{
    if (m_count == 0)
        return;
    Node<T>* node = Head;
    while (node->Next != nullptr)
    {
        cout << node->Value << " ";
    }
}
