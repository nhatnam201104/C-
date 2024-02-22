#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int Data) : data(Data), next(nullptr){};
};
class linkedList
{
public:
    int m_count;
    node *head, *tail;
    linkedList() : head(nullptr), tail(nullptr), m_count(0){};
    void insertHead(int val);
    void insertTail(int val);
    void insertNodepafterq(int val, int k);
    void deleteNode(int k);
};
void linkedList::insertHead(int val)
{
    node *p = new node(val);
    if (m_count == 0)
    {
        head = p;
        tail = p;
    }
    else
    {
        p->next = head;
        head = p;
    }
    m_count++;
}
void linkedList::insertTail(int val)
{
    node *p = new node(val);
    if (m_count == 0)
    {
        head = p;
        tail = p;
    }
    else
    {
        tail->next = p;
        tail = p;
    }
    m_count++;
}
void linkedList::insertNodepafterq(int val, int k)
{
    if (k < 0 && k > m_count)
        return;
    if (k == 0)
        insertHead(val);
    else if (k == m_count)
        insertTail(val);
    else
    {
        node *p = head;
        for (int i=0;i<k-1;i++)
        {
            p=p->next;
        }


    }
}
int main()
{
}