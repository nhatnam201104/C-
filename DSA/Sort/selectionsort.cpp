    #include <iostream>
    #include <math.h>
    using namespace std;
    void selection_sort (int arr[],int n)
    {
        //  3 44 38 5 47 
        int min_index;
        for (int i=0;i<n-1;i++)
        {
            // 39 9 20 2 18 14 1 11
            // 1 9 20 2 18 14 39 11
            // 1 2 20 9 18 14 39 11
            // 1 2 9 20 18 14 39 11
            // 1 2 9 11 18 14 39 20
            // 1 2 9 11 14 18 39 20
            // 1 2 9 11 14 18 20 39
            min_index=i;    
            for (int j=i+1;j<n;j++)
            {
                if (arr[j]<arr[min_index])
                {
                    min_index=j;
                }
            }
            swap (arr[i],arr[min_index]);
        }
    }
    void output (int arr[],int n)
    {
        for (int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    }

    int arr[100001];
    int main(){
        int n;
        cin >> n;
        for (int i = 0; i < n; i++){
            cin >> arr[i];
        }
        selection_sort(arr,n);
        output(arr,n);
        
        return 0;
    }