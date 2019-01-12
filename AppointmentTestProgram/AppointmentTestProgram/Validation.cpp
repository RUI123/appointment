
#include "Validation.h"
#include <string>
#include <iostream>

using namespace std;


////function to test if it's a leap year
bool Validation::IsLeapYear(int year){

	if(year%100==0){
		if(year%400==0)
			return true;
		else
			return false;
	}
	else if(year%4==0)
		return true;
	else
		return false;
}

//function to test if it's a integer data type
bool Validation::IsDigit(string info){

	//convert to cstring, then convert to integer
	for(char c:info)
		if(!isdigit(c)){
			cout<<"\nInput should only be Digital Number.";
			return false;
		}
	return true;
}

bool Validation::IsLetter(string info){
	
		for(char c:info){
			
			if(!isalpha(c)){
				cout<<"\nInput should only be Letters.";
				return false;
			}
		}
		return true;
}
//function to convert the time to hours
double Validation::ConvertToHour(int h,int m){

	return h+m/60.0;
}


//function to test if the time interval between two appointment  is enough
bool Validation::IsValidInterval(int h1,int m1,int h2,int m2,int interval){

	if(abs(ConvertToHour(h1,m1)-ConvertToHour(h2,m2))>=interval)
		return true;
	else
		return false;
}

//function to test if first time is late than second time
bool Validation::IsGreaterTime(int h1,int m1,int h2,int m2){
	if(ConvertToHour(h1,m1)>ConvertToHour(h2,m2))
		return true;
	else
		return false;
}

//function to test if it's well formated (ex. 01 is not allowed)
bool Validation::IsFormated(string info){

	if(info==to_string(atoi(info.c_str())))
		return true;
	cout<<"\nEach input should be seperated by a space or an enter key.";
	return false;
}