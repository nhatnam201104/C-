#include <iostream>
#include "person.cpp"
#include "vemaybay.cpp"
using namespace std;
class hanhkhach  : public person
{
    protected :
    vemaybay *ve;
    int soluong;
    int tongtien;   
    public:
    hanhkhach()
    {
        this->soluong=0;
        this->ve=new vemaybay[this->soluong];
    
    }
    ~hanhkhach()
    {
        this->soluong=0;
        // this->ve=delete vemaybay[this->soluong];
        delete ve;
    
    }
    void in ()
    {
        person ::in();
        cout<<"so luong ve hanh khach da mua:";
        cin>>soluong;
        ve=new vemaybay [soluong];
        for (int i=0;i<this->soluong;i++)
        {
            ve[i].in();
            tongtien+=ve[i].getgiave();
        }
    }
    void out()
    {
        cout << "- Thong Tin Khach Hang: " << endl;
        person :: out();
        cout << "- Thong Tin Chuyen Bay: " << endl;
        for (int i = 0; i < this->soluong; ++i)
        {
            ve[i].out();
            cout << endl;
        }
        cout << "==> Tong Tien = " << this->tongtien;
        cout << endl;
    }
};