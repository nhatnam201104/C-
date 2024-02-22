#include "LinkedList.h"
#include <iostream>
using namespace std;
// #include "Node.h"
LinkedList ::LinkedList() : head(nullptr), m_count(0){};

Node *LinkedList ::get(int index)
{
    if (m_count == 0)
        return NULL;
    if (index < 0 || index >= m_count)
        return NULL;
    Node *p;
    p = head;
    for (int i = 0; i < index; i++)
    {
        p = p->next;
    }
    return p;
}

void LinkedList ::InsertHead(int val)
{
    Node *node = new Node(val);
    if (m_count == 0)
    {
        head = node;
        tail = node;
    }
    else
    {
        node->next = head;
        head = node;
    }
    m_count++;
}
void LinkedList ::PrintList()
{
    Node *node;
    node = head;
    for (int i = 0; i < m_count; i++)
    {
        cout << node->data << " ";
        node = node->next;
    }
}
void LinkedList ::InsertTail(int val)
{
    Node *node = new Node(val);
    if (m_count == 0)
        head = tail = node;
    else
    {
        tail->next = node;
        tail = node;
    }
    m_count++;
}
// 12 23 33 12 39 19 5
void LinkedList ::Insert(int index, int val)
{
    if (index < 0 && index > m_count)
        return;
    if (index == 0)
    {
        InsertHead(val);
        return;
    }
    if (index == m_count)
    {
        InsertTail(val);
        return;
    }
    Node *nodeprev, *node, *newnode;
    node = head;
    newnode = new Node(val);
    for (int i = 0; i < index; i++)
    {
        nodeprev = node;
        node = node->next;
    }
    nodeprev->next = newnode;
    newnode->next = node;
    m_count++;
}
void LinkedList ::RemoveHead()
{
    head = head->next;
    m_count--;
}
void LinkedList ::RemoveTail()
{
    Node *pprev, *p = head;
    for (int i = 0; i < m_count; i++)
    {
        pprev = p;
        p = p->next;
    }
    pprev->next = NULL;
    delete p;
    tail = pprev;
    m_count--;
}
void LinkedList::Removeindex(int index)
{
    if (index < 0 || index >= m_count || m_count == 0)
        return;
    if (index == 0)
    {
        RemoveHead();
        return;
    }
    else if (index == m_count - 1)
    {
        RemoveTail();
    }
    else
    {
        int i = 1;
        Node *node = head->next, *nodeprev;
        while (i != index)
        {
            nodeprev = node;
            node = node->next;
            i++;
        }
        nodeprev->next = node->next;
        delete node;
        m_count--;
    }
}
void LinkedList ::Remove(int val)
{
    while (head->data == val)
        RemoveHead();
    while (tail->data == val)
        RemoveTail();
    // i bat dau tu vi tri head+1 toi tail-1
    int i = 1;
    Node *node = head->next, *nodeprev = head;
    while (i < m_count - 2)
    {
        if (node->data == val)
        {
            nodeprev->next = node->next;
            m_count--;
            i--;
        }
        else
        {
            nodeprev = node;
            node = node->next;
        }
        i++;
    }
}
int LinkedList::Count()
{
    return m_count;
}
int LinkedList::search(int val)
{
    Node *node = head;
    int index = 0;
    while (node->data != val)
    {
        node = node->next;
        if (node == NULL)
            return -1;
        index++;
    }
    return index;
}