#include <iostream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;
int main()
{
    LinkedList linkedList;
    linkedList.InsertHead(43);
    linkedList.InsertHead(76);
    linkedList.InsertTail(15);
    linkedList.InsertTail(44);
    cout << "First Printed:" << endl;
    linkedList.PrintList();
    cout << endl;

    linkedList.Insert(4, 100);
    linkedList.Insert(3, 48);
    linkedList.Insert(0, 22);
    cout << "Second Printed:" << endl;
    linkedList.PrintList();
    cout << endl;
    
    cout << "Get value of the second index:" << endl;
    Node *get = linkedList.get(2);
    if (get != NULL)
        cout << get->data;
    else
        cout << "not found";
    cout << endl
         << endl;
    
    cout << "The position of value 15:" << endl;
    int srch = linkedList.search(15);
    cout << srch << endl
         << endl;
    
    cout << "Remove the first element:" << endl;
    linkedList.Removeindex(0);
    linkedList.PrintList();
    cout << endl;
    cout << "Remove the fifth element:" << endl;
    linkedList.Removeindex(4);
    linkedList.PrintList();
    cout << endl;
    
    cout << "Remove the tenth element:" << endl;
    linkedList.Removeindex(9);
    linkedList.PrintList();
    cout << endl;
    return 0;
}
