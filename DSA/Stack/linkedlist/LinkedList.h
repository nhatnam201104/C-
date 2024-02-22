#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
class LinkedList 
{
    private: 
    int m_count;
    public :
    Node *head;
    Node *tail;
    LinkedList ();
    Node *get(int index);
    void InsertHead(int val);
    void InsertTail(int val);
    void Insert(int index,int val);
    void RemoveHead();
    void RemoveTail();
    void Remove(int val);
    void Removeindex (int index);
    void PrintList();
    int Count();
    int search(int val);
    
};
#endif 
