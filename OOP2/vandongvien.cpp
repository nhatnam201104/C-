#include <iostream>
#include <string>
using namespace std;
class vdv 
{
    protected :
    string hoten,monthidau;
    float tuoi,cannang,chieucao;
    public :
    vdv ();
    vdv (string hoten,string monthidau,float tuoi,float cannang,float chieucao);
    ~vdv ();
    friend istream &operator >> (istream &in,vdv &a);
    friend ostream &operator << (ostream &out,vdv a);
    bool operator > (vdv another);
    void merge (vdv a[],int l,int m,int r);
    void mergesort (vdv a[],int l,int r);
};
vdv :: vdv()
{
    hoten="";
    monthidau="";
    tuoi=cannang=chieucao=0;
}
vdv :: vdv (string hoten,string monthidau,float tuoi,float cannang,float chieucao)
{
    this->hoten=hoten;
    this->monthidau=monthidau;
    this->tuoi=tuoi;
    this->cannang=cannang;
    this->chieucao=chieucao;
}
vdv :: ~vdv()
{
    this->hoten = this->monthidau = "";
    this->tuoi = 0;
    this->cannang = this->chieucao = 0;
}
istream &operator >> (istream &in,vdv &a)
{
    in.ignore();
    cout<<"nhap ten van dong vien:";
    getline (in,a.hoten);
    cout <<"nhap mon thi dau:";
    getline (in,a.monthidau);
    cout<<"nhap tuoi:";
    in>>a.tuoi;
    cout<<"nhap can nang:";
    in>>a.cannang;
    cout<<"nhap chieu cao:";
    in>>a.chieucao;
    return in;

}

ostream &operator << (ostream &out,vdv a)
{
    out <<a.hoten<<" "<<a.tuoi<<" "<<a.cannang<<" "<<a.chieucao<<" "<<a.monthidau;
    return out;
}
bool vdv :: operator > (vdv another)
{   
    if (this->chieucao==another.chieucao)
    return this->cannang > another.cannang; 
    else
    return this->chieucao > another.chieucao;
}
void merge (vdv *a,int l,int m,int r)
{
    int n1=m-l+1;
    int n2=r-m;
    vdv *arr1=new vdv[n1];
    vdv *arr2=new vdv[n2];
    for (int i=0;i<n1;i++)
    {
        arr1[i]=a[i+l];
    }
    for (int j=0;j<n2;j++)
    {
        arr2[j]=a[j+m+1];
    }   
    int i=0,j=0,a_index=l;
    while (i<n1&&j<n2)
    {
        if (arr2[j]>arr1[i])
        {
            a[a_index]=arr1[i];
            i++;
        }
        else
        {
            a[a_index]=arr2[j];
            j++;
        }
        a_index++;
       
    }
    while (i<n1)
    {
        a[a_index]=arr1[i];
        i++;
        a_index++;
    }
    while (j<n2)
    {
        a[a_index]=arr2[j];
        j++;
        a_index++;
    }
    
}
void mergesort (vdv *a,int l,int r)
{
    int m=(l+r)/2;
    if (l<r)
    {
        mergesort(a,l,m);
        mergesort(a,m+1,r);
    }
    merge(a,l,m,r);
}
int main()
{
    cout << "Nhap So Luong: "; int n; cin >> n;
    vdv *arr = new vdv[n];

    for (int i = 0; i < n; ++i) cin >> arr[i];

    cout << endl << endl;
    for (int i = 0; i < n; ++i) cout << arr[i] << endl;
    
    cout << "Sort" << endl;
    mergesort(arr,0,n-1);
    for (int i = 0; i < n; ++i) cout << arr[i] << endl;
    return 0;
}


 