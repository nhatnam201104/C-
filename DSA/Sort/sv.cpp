#include <iostream>
#include <string.h>
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
        
        cout << "Nhap ten hoc sinh:";
        getline (in,a.hoten) ;
        // in.ignore();
        cout << "nhap ma so sinh vien:";
        in >> a.mssv;
        cout << "nhap diem trung binh:";
        in >> a.diemtrungbinh;
        return in;
    }
    void out ()
    {
        cout <<this->hoten.length();
    }
};
int main ()
{
    Sinhvien sv;
    cin>>sv;
    sv.out();
}