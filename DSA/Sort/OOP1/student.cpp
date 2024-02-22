#include <iostream>
using namespace std;
class student
{
    private :
    // string fristname;
    // string lastname;

    string fullname;
    public:
    // student ()
    // {
    //     getline (cin,fristname);
    //     getline (cin,lastname);
    // }
    string getfullname ()
    {
        // return fristname+" " + lastname;
        return fullname;
    }
    void in ()
    {
        cout<<"FULL NAME: "<<getfullname ();
    }
};
