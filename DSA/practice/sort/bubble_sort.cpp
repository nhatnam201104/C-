#include <iostream>
using namespace std;
void bubble_sort(int a[], int n)
{
    bool flag;
    do
    {
        flag = false;
        for (int i = 0; i < n - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                flag = true;
            }
        }
    }   
    while (flag);
}
int main()
{
    int a[] = {35, 18, 25, 15, 16, 37, 26, 19, 40, 38};
    bubble_sort(a, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << a[i] << " ";
    }
}