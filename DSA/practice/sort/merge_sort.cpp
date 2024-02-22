    #include <iostream >
    using namespace std;
    void merge(int a[], int l, int m, int r)
    {
        int n1, n2;
        n1 = m - l + 1;
        n2 = r - m;
        int *tmp1 = new int[n1], *tmp2 = new int[n2];
        for (int i = 0; i < n1; i++)
        {
            tmp1[i] = a[l+i];
        }
        for (int j = 0; j < n2; j++)
        {
            tmp2[j] = a[ m + 1+j];
        }
        cout<<"mang tam 2\n";
        for (int i=0;i<n2;i++)
        {
            cout<<tmp2[i]<<" ";
        }
        cout<<"\n";
        int indexArr1 = 0, indexArr2 = 0, arr_index = l;
        while (indexArr1 < n1 && indexArr2 < n2)
        {
            if (tmp1[indexArr1] < tmp2[indexArr2])
            {
                a[arr_index] = tmp1[indexArr1];
                indexArr1++;
            }

            else
            {
                a[arr_index] = tmp2[indexArr2];
                indexArr2++;
            }
            arr_index++;
        }
        while (indexArr1 < n1)
        {
            a[arr_index++] = tmp1[indexArr1++];
        }
        while (indexArr2 < n2)
        {
            a[arr_index++] = tmp2[indexArr2++];
        }
        delete [] tmp1, tmp2;
    }
    void merge_sort(int a[], int l, int r)
    {
        int mid = l + (r - l) / 2;
        if (l < r)
        {
            merge_sort(a, l, mid);
            merge_sort(a, mid + 1, r);
            merge(a, l, mid, r);
        }
        else return;
    }
    int main()
    {
        
        int a[] = {-35, -18, -25, 0,16, -37, -26, -19, -40, -38};
        merge_sort(a, 0, (sizeof(a) / sizeof(int)));
        for (int i = 0; i <(sizeof(a) / sizeof(a[0])); i++)
        {
            cout << a[i] << " ";
        }

        return 0;
    }