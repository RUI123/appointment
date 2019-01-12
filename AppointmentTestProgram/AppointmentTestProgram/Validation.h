
#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

using namespace std;

//create a class of validation to help test data
class Validation{

private:
	//function to convert hour:minute to hours
	double ConvertToHour(int h,int m);

protected:
	//test if it's a leap year
	bool IsLeapYear(int);
public:
	//function to test if it's a digital value
	bool IsDigit(string);
	//function to test if it's letter
	bool IsLetter(string);

	//function to avoid entry 01
	bool IsFormated(string);

	//function to test if two appoinment 
	//have specific time remain between
	bool IsValidInterval(int ,int ,int,int,int);

	//function to test if the second time is earlier
	bool IsGreaterTime(int,int,int,int);
};

#endif // !VALIDATION_H
