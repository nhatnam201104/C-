#include <iostream>
#pragma once
using namespace std;
class Shape
{
    public :
    virtual double getArea () =0;
    virtual double getPerimeter ()=0;
};