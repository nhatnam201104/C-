    #include <iostream>
    #include <math.h>
    using namespace std;
    void counting_sort (int a[],int n)
    {
        int max=-1;
        int b[1000]={0};
        for (int i=0;i<n;i++)
        {
            b[a[i]]++;
            if (a[i]>max)
            max=a[i];
        }
        int j=0;
        for (int i=0;i<=max;i++)
        {
            while (b[i]>0)
            {
                a[j++]=i;
                b[i]--;
            }
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
        counting_sort(a,n);
        output(a,n);
        
        return 0;
    }