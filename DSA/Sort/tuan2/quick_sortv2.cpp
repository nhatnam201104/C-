#include <iostream>
using namespace std;

void quick_sort (int a[],int l,int r)
{

    int i=l,j=r;
    int m=(l+r)/2;
    do
    {
        
        while (a[i]>a[m]) i++;
        while (a[j]<a[m]) j--;
        if (i<=j)
        swap (a[i++],a[j--]);
    }
    while (i<j);
    if (l<j)
    quick_sort (a,l,j);
    if (i<r)
    quick_sort (a,i,r);

}
void output (int a[],int n)
{
    
    for (int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int a[100001];
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
    // insertion_sort(a,n);
    quick_sort (a,0,n-1);
    output(a,n);
    
    return 0;
}


