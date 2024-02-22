#include <iostream>
using namespace std;
struct node
{
    node *next;
    int data;
};
struct list
{
    node *head = nullptr, *tail = nullptr;
};
list l;
node *newNode(int n);
void insertHead(list &l,int data);
void insertTail(list &l,int data);
void insertNodeq(list &l,int index,int value);
void deletenode(list &l);
void printList(list l);
int quantity (list l);
int main()
{
    insertHead (l,2);
    insertHead (l,3);
    insertHead (l,4);
    insertHead (l,5);
    insertTail (l,7);
    insertNodeq (l,4,100);
    // insertNodeq (l,4,9);

    printList(l);
    cout <<"\n"<<quantity (l);
}

void printList(list l)
{
    node *p = l.head;
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
node *newNode(int n)
{
    node *p=new node ;
    p->data =n;
    p->next =NULL;
    return p;
}
void insertHead (list &l, int data)
{
    node *p=new node;
    p=newNode (data);
    if (l.head==NULL)
    {
        l.head =p;
        l.tail =p;
    }
    else {
        p->next =l.head;
        l.head =p;
    }
}
void insertTail (list &l ,int data)
{
    node *p;
    p=newNode (data);
    if (l.head==NULL)
    {
        l.head=p;
        l.tail=p;
    }
    else 
    {
        l.tail->next =p;
        l.tail=p;
    }
}
int quantity (list l)
{
    int cnt=0;
    node *p =l.head;
    while (p!=NULL)
    {
        cnt++;
        p=p->next;
    }
    return cnt;
}
void insertNodeq (list &l,int index,int value){
    if (index<0||index>quantity (l)-1)
    return;
    if (index==0)
    insertHead (l,value);
    else if (index==(quantity(l)-1))
    insertTail (l,value);
    else 
    {
        node *q=l.head;
        for (int i=0;i<index-1;i++)
        {
           q=q->next;
        }
        node *p=newNode (value);
        p->next=q->next;
        q->next =p;

    }

}