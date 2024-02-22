#include <iostream>
using namespace std;
int binarysearch(int a[], int n, int x, int l, int r)
{
    if (l > r)
        return -1;
    int m = (r - l) / 2;
    if (a[m] == x)
        return 1;
    if (x < a[m])
        return (a, n, x, l, m);
    return (a, n, x, m + 1, r);
}