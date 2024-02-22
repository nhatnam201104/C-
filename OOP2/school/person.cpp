#include <iostream>
using namespace std;
class Person 
{
    protected :
    int age;
    string name;
    public :
    void in ()
    {
        cout<<"nhap ten:";
        getline (cin,name);
        cout<<"nhap tuoi:";
        cin>>age;
    }
}