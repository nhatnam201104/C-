#include <iostream>
using namespace std;
class Time
{
    public :
    int hour;
    int minute;
    int second;
    private:
    Time (int hour,int minute,int second)
    {
        this->hour =hour;
        this->minute=minute;
        this->second=second;
    }
    void setTime (int hour,int minute,int second)
    {
        this->hour =hour;
        this->second=second;
        this->minute=hour;
    }
    void setHour (int hour)
    {
        this->hour=hour;
    }
    void setMinute (int minute)
    {
        this->minute=minute;
    }
    void setSecond (int second)
    {
        this->second=second;
    }
    int getHour ()
    {
        return this->hour;
    }
    int getSecond ()
    {
        return this->second;
    }
    int getMinute ()
    {
        return minute;
    }
    void nextSecond ()
    {
        second ++;
        if (second==60)
        {
            second=0;
            minute++;
            if (minute>59)
                {
                    hour++;
                    minute=0;
                }
                if (hour>23)
                    hour=0;
        }
    }
    void previousSecond ()
    {
        second--;
        if (second<0)
            {
                second=59;
                minute--;
                if (minute<0)
                    {
                        hour--;
                    }
                    if (hour <0)
                        {
                            hour=23;
                        }
            }
            
    }
   void display() {
		string hour = to_string(this->hour);
		string minute = to_string(this->minute);
		string second = to_string(this->second);
		if (hour.length() == 1)
			hour = "0" + hour;
		if (minute.length() == 1)
			minute = "0" + minute;
		if (second.length() == 1)
			second = "0" + second;
		cout << hour + ":" << minute + ":" + second << endl;
	}
	};