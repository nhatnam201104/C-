#pragma once
#include <iostream>
class List_ADT
{
    private :
    int m_count;
    int * m_item;
    public :
    List_ADT ();
    ~List_ADT ();
    int Get (int index);
    void Insert (int index,int val);
    int Search (int val);
    void Remove (int index);
    int Count ();
    void Remove_Val (int val);
    
};