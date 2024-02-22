#include <iostream>
#include <algorithm>
using namespace std;
void output(int a[], int n)
{

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
void quick_sort(int a[], int l, int r)
{
    int i = l;
    int j = r;
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
        // output (a,8); cout<<"\n";

    } while (i < j);
    if (l < j)
        quick_sort(a, l, j);
    if (i < r)
        quick_sort(a, i, r);
}


int a[100001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    quick_sort(a, 0, n - 1);
    cout << "\n";
    output(a, n);

    return 0;
}

//12 5 5 8 3 8 15 20
// 12 5 5 8 3 8
// 15 20

