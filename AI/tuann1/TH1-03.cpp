#include <iostream>
#include <ctime>
using namespace std;
int main ()
{
    FILE *f=fopen ("array1.txt","wt");
    int n;
    cin>>n;
    fprintf (f,"%d\n",n);
    srand (time(NULL));
    int cnt=0;
    for (int i=0;i<n;i++)
    {
        fprintf (f,"%d ",rand ()%101);
        cnt++;
        if (cnt==10)
        {
            fprintf (f,"\n");
            cnt=0;
        }
    }


}