#include <iostream>
using namespace std;
void insertion_sort(int a[], int n)
{
    int current, poison;
    for (int i = 1; i < n; i++)
    {
        current = a[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (current < a[j])
                a[j + 1] = a[j];
            else
                break;
        }
        a[j + 1] = current;
    }
}
void output(int a[], int n)
{

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
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
    insertion_sort(a, n);
    output(a, n);

    return 0;
}