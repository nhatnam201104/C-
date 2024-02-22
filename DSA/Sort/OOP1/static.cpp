// #include <iostream>
// #include <string.h>
#include <bits/stdc++.h>
using namespace std;
class sinhvien 
{
    private :
    string id,name,ns;
    int gpa;
    static int dem;
    public :
    void in();
    void getinfor ();
    string getid ();
};
string sinhvien:: getid()
{
    return this->id;
}
int sinhvien ::dem=0;
void sinhvien::getinfor ()
{
    dem++;
    this->id="SV" + string (3- to_string(dem).length(), '0')+to_string(dem);
    cout<<"nhap ten: "; getline (cin,this->name);
    cout<<"ngay sinh: "; cin>> this->ns;
    cout<<"diem: "; cin>>this->gpa;
    cin.ignore();
}
void sinhvien::in()
{
    cout<<id<<" "<<this->name<<" "<<this->ns<<" "<<this->gpa<<"\n";
}
int main()
{
    sinhvien a;
    a.getinfor();
    a.in();
    sinhvien b;
    b.getinfor ();
    b.in();
}