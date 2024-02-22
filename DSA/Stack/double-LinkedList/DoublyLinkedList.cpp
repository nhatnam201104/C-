#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;
void DoublyLinkedList ::Insert_head(int value)
{
    Node *node = new Node(value);
    node->next = head;
    if (m_count == 0)
    {
        head = node;
        tail = node;
    }
    else
    {
        head->previous = node;
        head = node;
    }
    m_count++;
}
void DoublyLinkedList::Printlist()
{
    Node *node = head;
    for (int i = 0; i < m_count; i++)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
void DoublyLinkedList ::Insert_tail(int value)
{
    Node *node = new Node(value);
    if (m_count == 0)
    {
        head = tail = nullptr;
    }
    else
    {
        tail->next = node;
        node->previous=tail;
        tail=node;
    }
}
void DoublyLinkedList :: Insert (int data ,int index)
{
    
}

// 12 13 15