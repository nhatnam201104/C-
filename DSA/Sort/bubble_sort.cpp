#include <iostream>
#include <math.h>
using namespace std;
void bubble_sort (int a[],int n)
{
    bool swaped;   
    do 
    {
        swaped=false;
        for (int i=0;i<n-1;i++)
        {
            if (a[i]>=a[i+1])
            {
                swap (a[i],a[i+1]);
                swaped=true;
            }
        }
    }
    while (swaped);
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
    bubble_sort(a,n);
    output(a,n);
    
    return 0;
}
