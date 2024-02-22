#include <iostream>
using namespace std;
int main()
{
    int a[1000],b[1000],c[1000];
    int n,m;
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    cin>>m;
    for (int j=0;j<m;j++)
    {
        cin >> b[j];
    }
    int index_a=0,index_b=0,index_c=0;
    while ( index_a < n && index_b < m)
    {
        if (a[index_a]<b[index_b])
        {
            c[index_c]=a[index_a];
            index_a++;
            index_c++;
        }
        else 
        {
            c[index_c]=b[index_b];
            index_b++;
            index_c++;
        }
    }
    while (index_a<n)
    {
        c[index_c]=a[index_a];
        index_a++;
        index_c++;
    }
    while (index_b<m)
    {
        c[index_c]=b[index_b];
        index_b++;
        index_c++;    
    }
    
    for (int i=0;i<index_c;i++)
    {

        cout<< c[i]<<" ";
    }
    
}