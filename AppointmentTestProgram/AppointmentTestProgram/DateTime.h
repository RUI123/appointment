#ifndef DATETIME_H
#define DATETIME_H

#include"date.h"
#include"Time.h"
#include<iomanip>

//forward declaraction 
class DateTime;

// prototype of istream and ostream for date and time
istream &operator >> (istream &, DateTime&);
ostream &operator << (ostream &, const DateTime&);


//create class datetime to inherited 
//Date class and Abstract base class Time
class DateTime:public Date,public Time{

public:

	//default constructor
	DateTime();

	//constructor to assign the values of time
	DateTime(int,int,int,int,int);
	
	//deconstructor
	~DateTime(){}

	//functions to overload operator =,==,<,>
	const DateTime operator=(const DateTime &right);
	bool operator >(const DateTime &right);
	bool operator <(const DateTime &right);
	bool operator ==(const DateTime &right);

	// using friend function to overload the istream
	//and ostream operators for datetime
	friend istream &operator >> (istream &in, DateTime&);	
	friend ostream &operator << (ostream &out, const DateTime&);

	//declare the virtual function to print time
	virtual void printTime()const;
};


#endif // !TIME_H
