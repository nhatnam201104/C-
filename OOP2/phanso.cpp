#include <iostream>
using namespace std;
class phanso 
{
    private :
    int tu,mau;
    public :
    phanso ();
    friend istream &operator  >> (istream &in,phanso &a);
    friend ostream &operator << (ostream &out,phanso a);
    phanso operator + (const phanso &psanother);
    phanso operator - ( phanso psanother);
    friend phanso operator * (phanso &ps1,phanso &ps2);
    friend phanso operator / (phanso ps1,phanso ps2);
    operator float ();
    int ucln (int , int);
    void rutgon(int &tu,int &mau);
};
phanso :: phanso ()
{
    this->mau=1;
    this->tu=1;
}
istream &operator >> (istream &in,phanso &a)
{
    cout <<"nhap tu:";
    cin>>a.tu;
    cout<<"nhap mau:";
    cin>>a.mau;
    return in;
}
ostream &operator << (ostream &out,phanso a)
{
    a.rutgon (a.tu,a.mau);
    cout<<a.tu<<"/"<<a.mau;
    return out;
}
phanso phanso::operator + (const phanso &psanother)
{
    phanso s;
    s.tu= this->tu * psanother.mau + psanother.tu * this->mau;
    s.mau = this->mau * psanother.mau;
    return s;
}
phanso phanso:: operator - (phanso psanother)
{
    phanso s;
    s.tu= this->tu * psanother.mau - psanother.tu * this->mau;
    s.mau = this->mau * psanother.mau;
    return s;
}
phanso operator * (phanso &ps1,phanso &ps2)
{
    phanso t;
    t.tu = ps1.tu * ps2.tu;
    t.mau = ps1.mau * ps2.mau;
    return t;
}
phanso operator / (phanso ps1,phanso ps2)
{
    phanso s;
    s.tu=ps1.tu*ps2.mau;
    s.mau = ps1.mau * ps2.tu;
    return s;
}
int phanso:: ucln (int a,int b)
{
    if (b==0)
    return a;
    if (a%b==0)
    return b;
    return ucln(b,a%b);
}
void phanso :: rutgon (int &tu,int &mau)
{
    int k=ucln (tu,mau);
    if (k<0)
    k=-k;
    tu=tu/k;
    mau=mau/k;
}
phanso ::operator float ()
{
    return (float)this->tu/this->mau;
}
int main ()
{
    phanso ps1,ps2;
    phanso s;
    cin>>ps1;
    cin>>ps2;
    s=ps1+ps2;
    cout<<s;

    s=ps1-ps2;
    cout<<"\n"<<s;
    
    s=ps1*ps2;
    cout<<"\n"<<s;

    s=ps1/ps2;
    cout<<"\n"<<s;
}