#include "list_adt.h"
using namespace std;
List_ADT ::List_ADT()
{
    m_count = 0;
    m_item = nullptr;
}
List_ADT ::~List_ADT()
{
    delete m_item;
}
int List_ADT ::Get(int index)
{
    if (index < m_count || index >= 0)
        return m_item[index];
    return -1;
}
void List_ADT ::Insert(int index, int val)
{
    if (index > m_count || index < 0)
        return;
    int *old_list = new int[m_count];
    for (int i = 0; i < m_count; i++)
    {
        old_list[i] = m_item[i];
    }
    // increase emlement
    m_count++;
    m_item = new int[m_count];
    for (int i = 0, j = 0; i < m_count; i++)
    {
        if (i == index)
            m_item[i] = val;
        else
        {
            m_item[i] = old_list[j];
            j++;
        }
    }
    delete[] old_list;
}
int List_ADT ::Count()
{
    return m_count;
}
int List_ADT ::Search(int val)
{
    int i = 0;
    while (i < m_count && m_item[i] != val)
        i++;
    if (i == m_count)
        return -1;
    return i;
}
void List_ADT ::Remove_Val(int val)
{
    int x = List_ADT ::Search(val);
    while (x != -1)
    {
        for (int i = x; i < m_count; i++)
        {
            m_item[i] = m_item[i + 1];
        }
        m_count--;
        x = List_ADT ::Search(val);
    }
}
void List_ADT ::Remove(int index)
{
    if (index < 0 || index > m_count)
        return;
    int *old_list = new int[m_count];
    for (int i = 0; i < m_count; i++)
        old_list[i] = m_item[i];
    m_count--;
    m_item = new int[m_count];
    for (int i = 0, j = 0; i < m_count; i++,j++)
    {
        if (j == index)
            j++;
            m_item[i] = old_list[j];
    }
    delete old_list;
}
