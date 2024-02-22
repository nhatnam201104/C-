#include <iostream>
using namespace std;
void interchange_sort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
                swap(a[i], a[j]);
        }
    }
}
int main()
{
    int a[] = {35, 18, 25, 15, 16, 37, 26, 19, 40, 38};
    interchange_sort(a, (sizeof(a) / sizeof(int)));
    for (int i = 0; i < (sizeof(a) / sizeof(int)); i++)
    {
        cout << a[i] << " ";
    }
}