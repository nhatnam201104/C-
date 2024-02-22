#include <iostream>
#include <string>
using namespace std;
class person 
{
    protected:
    string name;
    string gioitinh;
    int tuoi;
    public:
    person ()
    {
        this->name="";
        this->gioitinh="";
        this->tuoi=0;
    }
    ~person ()
    {
        this->name="";
        this->gioitinh="";
        this->tuoi=0;
    }
    void in ()
    {
        cin.ignore();;
        cout<<"nhap ho ten:";
        getline (cin,name);
        cout<<"nhap gioi tinh:";
        getline (cin,gioitinh);
        cout<<"nhap tuoi:";
        cin>>tuoi;
    }
    void out ()
    {
        cout<<"ho ten: "<<this->name;
        cout<<"\tgioi tinh: "<<this->gioitinh;
        cout<<"\ttuoi: "<<this->tuoi;
    }

};