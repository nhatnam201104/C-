#include <iostream>
using namespace std;
void merge(int a[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    int *arr1 = new int[n1];
    int *arr2 = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        arr1[i] = a[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        arr2[j] = a[m + 1 + j];
    }
    int i = 0, j = 0, a_index = l;
    while (i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            a[a_index] = arr1[i];
            i++;
        }
        else
        {
            a[a_index] = arr2[j];
            j++;
        }

        a_index++;
    }
    while (i < n1)
    {
        if (arr1[i] < arr2[j])
        {
            a[a_index] = arr1[i];
            i++;
            a_index++;
        }
    }
    while (j < n2)
    {
        a[a_index] = arr2[j];
        j++;
        a_index++;
    }
    delete[] arr1;
    delete[] arr2;
}
void merge_sort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = (r + l) / 2;
        merge_sort(a, l, m);
        merge_sort(a, m + 1, r);
        merge(a, l, m, r);
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
    merge_sort(a, 0, n - 1);
    output(a, n);

    return 0;
}