#include <iostream>
#include <string>
using namespace std;
class Sinhvien
{
protected:
    int mssv;
    string hoten;
    int diemtrungbinh;

public:
    friend istream &operator>>(istream &in, Sinhvien &a)
    {
        in.ignore();
        cout << "Nhap ten hoc sinh:";
        getline (in,a.hoten);
        cout << "nhap ma so sinh vien:";
        in >> a.mssv;
        cout << "nhap diem trung binh:";
        in >> a.diemtrungbinh;
        return in;
    }
    void sapxepdiemtb(Sinhvien a[], int n)
    {
        //  3 44 38 5 47
        int min_index;
        for (int i = 0; i < n - 1; i++)
        {
            min_index = i;
            for (int j = i + 1; j < n; j++)
            {
                if (a[j].diemtrungbinh < a[min_index].diemtrungbinh)
                {
                    min_index = j;
                }
            }
            swap(a[i], a[min_index]);
        }
    }
    void sapxepmssv(Sinhvien a[], int n)
    {
        bool swaped;
        do
        {
            swaped = false;
            for (int i = 0; i < n - 1; i++)
            {
                if (a[i].mssv >= a[i + 1].mssv)
                {
                    swap(a[i], a[i + 1]);
                    swaped = true;
                }
            }
        } while (swaped);
    }
    void output(Sinhvien a[], int n)
    {
        for (int i = 0; i < n; i++)
            cout << a[i].hoten << " " << a[i].mssv << " " << a[i].diemtrungbinh << "\n";
    }
    void input(Sinhvien a[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }
    bool operator < (Sinhvien another)
    {
        int a=this->hoten.length();
        int b=another.hoten.length();
        if (a<b)
        return true;
        return false;
    }
    bool operator > (Sinhvien another)
    {
        if (this->hoten.length()<(another.hoten).length())
        return false;
        return true;
    }
void sort_ten(Sinhvien a[], int l, int r)
{
    int i = l;
    int j = r;
    int x= a[(l + r)/2].hoten.length();
    do
    {
        while (a[i].hoten.length() < x)
            i++;
        while (a[j].hoten.length() > x)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }

    } while (i < j);
    if (l < j)
        sort_ten(a, l, j);
    if (i < r)
        sort_ten(a, i, r);
}
};

Sinhvien sv[10000];
int main()
{
    int n;
    cout << "nhap n:";
    cin >> n;
    sv->input(sv, n);   
    // sv->sapxepdiemtb (sv,n);
    // cout<<"sap xep theo diem trung binh:\n";
    // sv->output(sv, n);
    // cout<<"sap xep theo mssv:\n";
    // sv->sapxepmssv(sv,n);
    // sv->output(sv, n);
    cout<<"sap xep theo ten:\n";
    sv->sort_ten (sv,0,n-1);
    sv->output (sv,n);
}
