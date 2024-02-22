#include <iostream>
#include <string.h>
using namespace std;
class Date 
{
    private :
    int day;
    int month;
    int year;
    public:
     Date (int day,int month,int year)
    {
        this->day=day;
        this->month=month;
        this->year=year;
    }
     void setDate(int day, int month, int year) {
		  this->day = day;
		  this->month = month;
		  this->year = year;
	  }
    void setDay (int day)
    {
        this->day=day;
    }
    void setMonth(int month)
    {
        this->month=month;
    }
    void setYear (int year)
    {
        this->year=year;
    }
    int getDay()
    {
        return this->day;
    }
    int getMonth()
    {
        return this->month;
    }
    int getYear ()
    {
        return this->year;
    }
    void display ()
    {
        cout<<(string (2-to_string(day).length(),'0')+to_string(day)+'/') + (string (2-to_string(month).length(),'0')+to_string(month)+'/') + to_string(year);
    }
    
};
int main ()
{
    Date d(1, 1, 1997);
	d.display();
	d.setDate(12, 12, 2004);
	d.display();
	d.setMonth(3);
	d.display();	
	return 0;
}