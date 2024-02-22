#include <iostream>
#pragma once
using namespace std;
class Point 
{
    private :
    int x;
    int y;
    public :
    Point ()
    {
        x=0;
        y=0;
    }
    Point (int x,int y)
    {
        this->x=x;
        this->y=y;
    }
    int getX ()
    {
        return this->x;
    }
    int getY ()
    {
        return this->y;
    }
    void setX (int x)
    {
        this->x=x;
    }
    void setY (int y)
    {
        this->y=y;
    }

};