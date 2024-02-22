#include <iostream>
// #include "bits/stdc++.h"
#include <ctime>
using namespace std;
int main()
{
    srand (time(NULL));
    FILE *f;

    f=fopen ("array2.txt","wt");
    int m,n;
    cout<<"Nhap so dong ";
    cin>>m;
    fprintf (f,"%d ",m);
    cout<<"cot";
    cin>>n;
    fprintf (f,"%d",n);
    fprintf (f,"\n");
    for (int i=0 ;i<m;i++)
    {
        for (int j=0;j<n;j++)
        {
            fprintf (f,"%d ",rand ()%101);
        }
        fprintf (f,"\n");
    }
    fclose (f);


}