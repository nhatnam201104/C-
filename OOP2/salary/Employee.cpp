#include <iostream>
#pragma once
using namespace std;
class Employee 
{
    private :
    string name;
    int paymentPerHour  ;
    public :
    Employee (string name,int paymentPerHour)
    {
        this->name=name;
        this->paymentPerHour=paymentPerHour;
    }
    void setName ()
    {
        this->name=name;
    }
    void setPaymentPerHour ()
    {
        this->paymentPerHour=paymentPerHour;
    }
    int getPaymentPerHour ()
    {
        return this->paymentPerHour;
    }
    string getName ()
    {
        return this->name;
    }
    virtual int calculateSalary () = 0;
};