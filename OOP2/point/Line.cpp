#include <iostream>
#include <math.h>
#include "Point.cpp"
using namespace std;
class Line : public Point
{
    private :
    Point begin;
    Point end;
    public :
    Line (Point begin,Point end)
    {
        this->begin=begin;
        this->end=end;
    }
    Line (int x1,int y1,int x2,int y2)
    {
        this->begin=Point (x1,y1);
        this->end =Point (x2,y2);
    }
    void setBegin (Point begin)
    {
        this->begin=begin;
    }
    void setEnd (Point end)
    {
        this->end=end;
    }
    Point getBegin ()
    {
        return this->begin;
    }
    Point getEnd ()
    {
        return this->end;
    }
    double getLength ()
    {
        return sqrt( pow (begin.getX()-end.getX(), 2) + pow (end.getY()-begin.getY(), 2) );
    }
};