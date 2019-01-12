#ifndef TIME_H
#define TIME_H

#include<string>
#include<iostream>
using namespace std;

//set the hours for making appointment
const int START_HOUR=8;
const int END_HOUR=16;

//set the minutes for  making appointment
const int OPENING_MINUTE=0;
const int CLOSING_MINUTE=0;

//set the default hours for time needed between two appointment
const int TIME_INTERVAL=1;

//create a abstract base class 
class Time{
	//member variables
private:
	int hour;
	int minute;

public:

	//default constructor to set the opening time
	Time(){
		hour=START_HOUR;
		minute=OPENING_MINUTE;
	}

	//constructor to set the time
	Time(int h,int m){
	
		setHour(h);
		setMinute(h,m);
	}

	//deconstructor
	virtual ~Time(){
		hour=0;
		minute=0;
	}

	//functions to set the time
	void setHour(int);
	void setMinute(int,int);

	//functions to get the time
	int getHour()const{return hour;}
	int getMinute()const{return minute;}

	//using virtual funtion to declare
	//time class as abstract base class
	virtual void printTime()const =0;
};



#endif // !TIME_H
