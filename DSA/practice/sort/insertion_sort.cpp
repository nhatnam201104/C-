#include <iostream>
using namespace std;
void insertion_sort(int a[], int n)
{
    int current, poison = 0;
    for (int i = 1; i < n; i++)
    {
        current = a[i];
        poison = i - 1;
        while (poison >= 0 && a[poison] > current)
        {
            /* code */
            a[poison+1]=a[poison];
            poison--;
        }
        a[poison + 1] = current;
    }
}
int main()
{
    int a[] = {35, 18, 25, 15, 16, 37, 26, 19, 40, 38};
    insertion_sort(a, (sizeof(a) / sizeof(int)));
    for (int i = 0; i < (sizeof(a) / sizeof(int)); i++)
    {
        cout << a[i] << " ";
    }
}
// 35 18 25 15 16 37 26 19 40 38
// 18 35 25 15 16 37 26 19 40 38
// 18 25 35 15 16 37 26 19 40 38
// 18 25 35