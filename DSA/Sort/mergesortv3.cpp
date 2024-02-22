#include <iostream>
using namespace std;
void msort(int a[], int n, int l, int r, int b[])
{
	int m, i, j, k;

	// Lay vi tri giua cua a 
	m = (l + r) / 2;

	// Thuc hien merge sort tren a tu vi tri l den m 
	if (l < m)
		msort(a, n, l, m, b);

	// Thuc hien merge sort tren a tu vi tri m + 1 den r neu m < r 
	if (m + 1 < r)
		msort(a, n, m + 1, r, b);

	// Do cac phan tu cua a tu vi tri l den m co thu tu vao b 
	for (i = l; i <= m; i++)
		b[i] = a[i];

	// Do cac phan tu cua a tu vi tri m + 1 den r co thu tu vao b theo thu tu nguoc
	for (i = m + 1; i <= r; i++)
		b[i] = a[m + 1 + r - i];

	// Tron b tu vi tri l den m co thu tu va b tu vi tri r den m + 1 co thu tu vao a 
	for (i = l, j = l, k = r; i <= r; i++)
		if (b[j] < b[k])
			a[i] = b[j++];
		else
			a[i] = b[k--];
}
void output(int a[], int n)
{

    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
}
int a[100001];
int b[100001];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    msort(a, n, 0, n - 1, b);
    output(a, n);

    return 0;
}
