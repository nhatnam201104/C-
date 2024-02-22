#pragma once
#include "Node.h"
class DoublyLinkedList
{
    private:
    int m_count;
    Node *head,*tail;
    public:
    DoublyLinkedList() : m_count(0),head(nullptr),tail (nullptr){};
    void Insert_head(int data);
    void Insert_tail (int data);
    void Insert(int data,int index);
    Node*Getnode (int index);
    void Printlist();
    void Remove_head ();
    void Remove_tail ();
    void Remove (int index);
};