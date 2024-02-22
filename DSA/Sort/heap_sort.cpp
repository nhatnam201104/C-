#include <iostream>
#include <math.h>
using namespace std;
void heapify (int a[],int n,int i)
{
    int l=i*2+1;
    int r=i*2+2;
    int max=i;
    if (l<n && a[l]>a[max])
    max=l;
    if (r<n && a[r]>a[max])
    max=r;
    if (max!=i)
    {
        swap (a[i],a[max]);
        return heapify (a,n,max);

    }
}
void heapsort (int a[],int n)
{
    for (int i=n/2-1;i>=0;i--)
    heapify (a,n,i);
    
    for (int i=n-1;i>=0;i--)
    {
        swap (a[0],a[i]);
        heapify (a,i,0);
    
    }
}
void output (int a[],int n)
{
    for (int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int a[100001];
int main(){
	int n;
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
    heapsort(a,n);
    output(a,n);
    
    return 0;
}
