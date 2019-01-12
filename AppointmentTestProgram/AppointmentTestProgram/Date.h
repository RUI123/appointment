#ifndef DATE_H
#define DATE_H

#include <iostream>
#include "Validation.h"

using namespace std;

//forward declaration
class Date;
// prototype of overloading istream operator
istream &operator >> (istream &, Date&);

// Using Enumeration to declare the month value
enum Months{JANUARY=1,FEBRUARY,MARCH,APRIL,MAY,
	JUNE,JULY,AUGUST,SEPTEMBER,OCTOBER,NOVEMBER,DECEMBER};

//Using Enumeration to declare the number of days in the month
enum Days{MONTH1=31, MONTH2=28,LEAPMONTH2=29, MONTH3=31,
	MONTH4=30, MONTH5=31,MONTH6=30, MONTH7=31,
	MONTH8=31, MONTH9=30, MONTH10=31, MONTH11=30, MONTH12=31};

//Using a constant value to indicate the current year
const int CURRENT_YEAR_LIMIT=2016;
const int YEAR_SCALE_LIMIT=3;

// create a class Date and inherited all boolean functions from Validation class
class Date:public Validation{

	// member values 
private:
	int month;
	int day;
	int year;

	//return the enum of number of days of a month
	Days getEndDay(int,int);
	
	

public:
	// default constructor to indicate a default date 1 1 2016(current year)
	Date(){
		month=1;
		day=1;
		year=CURRENT_YEAR_LIMIT;
	}

	//create a constructor to set the values of a date
	Date(int m,int d, int y){
		setMonth(m);
		setDay(m,d,y);
		setYear(y);
	}

	//deconstructor 
	virtual ~Date(){
		month=0;
		day=0;
		year=0;
	}

	//function set functions for a date
	void setMonth(int);
	void setDay(int,int,int);
	void setYear(int y);

	//function to get the values of a date
	int getMonth()const{return month;}
	int getYear()const{return year;}
	int getDay()const{return day;}

	//function to return the month value as letter
	string getLetterMonth() const;
	//function to print the date as one formate
	void printDate();
	//function to overload the istream operator
	friend istream &operator >> (istream &in, Date&);	
	
};

#endif

