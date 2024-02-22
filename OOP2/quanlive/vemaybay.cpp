#include <iostream>
#include <string>
using namespace std;
class date 
{
    protected :
    int d,m,y;
    public :
    date ()
    {
        d=0;
        m=0;
        y=0;
    }

    date (int d,int m,int y)
    {
        this->d=d;
        this->m=m;
        this->y=y;
    }
    void getdate ()
    {
        cout<<this->d<<"/"<<this->m<<"/"<<this->y;
    }
    void setdate ()
    {
        cout<<"d/m/y?";
        cin>>d>>m>>y;
    }

};
class vemaybay
{
    protected:
    string tenchuyen;
    long long giave;
    date ngaybay;
    public:
    vemaybay ()
    {
        this->tenchuyen="";
        this->giave=0;
    }
    ~vemaybay ()
    {
        this->tenchuyen="";
        this->giave=0;
    }
    void in ()
    {
        cin.ignore();
        cout << "nhap ten chuyen:";
        getline (cin,this->tenchuyen);
        ngaybay.setdate();
        cout<< "nhap gia tien:";
        cin>>this->giave;
    }
    void out ()
    {

        cout << "Ten Chuyen: " << this->tenchuyen << endl;
        cout << "Ngay Bay: " << endl << "\t";
        this->ngaybay.getdate();
        cout << "Gia Ve: " << this->giave << endl;
    }
    long long getgiave ()
    {
        return this->giave;
    }
};