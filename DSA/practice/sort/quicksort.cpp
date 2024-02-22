#include <iostream>
using namespace std;
void quick_sort(int a[], int l, int r)
{
    int i = l, j = r;
    int x = a[(l + r) / 2];
    do
    {
        while (a[i] < x)
            i++;
        while (a[j] > x)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    } while (i < j);
    if (l < j)
        quick_sort(a, l, j);
    if (i < r)
        quick_sort(a, i, r);
}
int main()
{
    int a[] = {12, 5, 5, 15, 3, 8, 8, 20};
    quick_sort(a, 0, (sizeof(a) / sizeof(int)));
    for (int i = 0; i < (sizeof(a) / sizeof(int)); i++)
    {
        cout << a[i] << " ";
    }
}