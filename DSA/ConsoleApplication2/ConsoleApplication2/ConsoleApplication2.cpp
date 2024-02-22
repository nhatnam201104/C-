#include <iostream >
using namespace std;
void merge(int a[], int l, int m, int r)
{
    int n1, n2;
    n1 = m - l + 1;
    n2 = r - m;
    int* tmp1 = new int[n1], * tmp2 = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        tmp1[i] = a[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        tmp2[j] = a[ m + 1+j];
    }
    int i = 0, j = 0, arr_index = l;
    cout << "mang tam 2\n";
    for (int i = 0; i < n2; i++)
    {
        cout << tmp2[i] << " ";
    }
    cout << "\n";
    while (i < n1 && j < n2)
    {
        if (tmp1[i] < tmp2[j])
        {
            a[arr_index] = tmp1[i];
            i++;
        }

        else
        {
            a[arr_index] = tmp2[j];
            j++;
        }
        arr_index++;
    }
    while (i < n1)
    {
        a[arr_index++] = tmp1[i++];
    }
    while (j < n2)
    {
        a[arr_index++] = tmp2[j++];
    }
    delete []tmp1, tmp2;
}
void merge_sort(int a[], int l, int r)
{
    int mid = (r + l) / 2;
    if (l < r)
    {
        merge_sort(a, l, mid);
        merge_sort(a, mid + 1, r);
        merge(a, l, mid, r);
    }
}
int main()
{
    int a[] = { 35, 18, 25, 15, 16, 37, 26, 19, 40, 38 };
    merge_sort(a, 0,9);
    for (int i = 0; i <9; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}