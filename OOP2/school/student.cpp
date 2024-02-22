#include <iostream>
#include "person.cpp"
using namespace std;
class Student : public Person
{
    protected :
    int age;
    string name;
    public :
    void in ()
    {
        cout<<"con cho tran nam";
    }
}