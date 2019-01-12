#include "Date.h"

//function to return the month as letters
string Date::getLetterMonth()const{
	
	//to convert integer to enum to compare 
	//with the enum values of month
	if(static_cast<Months>(month)==JANUARY)
		return "January";
	else if(static_cast<Months>(month)==FEBRUARY)
		return "February";
	else if(static_cast<Months>(month)==MARCH)
		return "March";
	else if(static_cast<Months>(month)==APRIL)
		return "April";
	else if(static_cast<Months>(month)==MAY)
		return "May";
	else if(static_cast<Months>(month)==JUNE)
		return "June";
	else if(static_cast<Months>(month)==JULY)
		return "July";
	else if(static_cast<Months>(month)==AUGUST)
		return "August";
	else if(static_cast<Months>(month)==SEPTEMBER)
		return  "September";
	else if(static_cast<Months>(month)==OCTOBER)
		return "October";
	else if(static_cast<Months>(month)==NOVEMBER)
		return "November";
	else
		return "December";

}

//function to return the total days in a month as enum values
Days Date::getEndDay(int m,int y){

	//test if it's a leap year
	if(IsLeapYear(y)&&m==2)
		return LEAPMONTH2;
	else{
		if(m==1)
			return MONTH1;
		else if(m==2)
			return MONTH2;
		else if(m==3)
			return MONTH3;
		else if(m==4)
			return MONTH4;
		else if(m==5)
			return MONTH5;
		else if(m==6)
			return MONTH6;
		else if(m==7)
			return MONTH7;
		else if(m==8)
			return MONTH8;
		else if(m==9)
			return MONTH9;
		else if(m==10)
			return MONTH10;
		else if(m==11)
			return MONTH11;
		else
			return MONTH12;
	}
}

// function to set the month between 1 and 12
void Date::setMonth(int m){
	cout<<"mmmkkk"<<endl;
	cout<<m;
	string error="\nInvalid Value ( - Over Month Range(1-12) ):\t"
		+to_string(m);
	if(m>0&&m<13){
		month=m;
		cout<<m;
	}
	//throw a string exception for bad data
	else{
		cout<<m;
		throw error;
	}
	
}

//function to set the year from 2016 to 2018,include 2018
void Date::setYear(int y){
	string error="\nInvalid Value ( - Only Allow year "
		+to_string(CURRENT_YEAR_LIMIT)+" to year "
		+to_string(CURRENT_YEAR_LIMIT+YEAR_SCALE_LIMIT-1)
		+" ):\t"+to_string(y);

	if(y<CURRENT_YEAR_LIMIT+YEAR_SCALE_LIMIT&&y>CURRENT_YEAR_LIMIT-1)
		year=y;
	else
		throw error;
}

// function to set day within range of a month
void Date::setDay(int m,int d,int y){

	string error="Invalid Value ( - Over Days Range of a Month):\t"
		+to_string(d);
	//test if it's the day within the range of current month
	if(d>0&&d<(static_cast<Days>(getEndDay(m,y))+1))
		day=d;
	//throw exception
	else
		throw error;
	
}

//function to print the date
void Date::printDate(){

	cout<<getLetterMonth()<<" "
		<<getDay()<<", "<<getYear();
}

//function to overloading the istream operator
istream &operator>> (istream & input, Date& date){


	//initialize variables to for the date
	string dayEntry, monthEntry, yearEntry;
	
	// get inputs
	cin>>monthEntry>> dayEntry>> yearEntry;
	
	// test if they are valid datatype and formate
	if(!(date.IsDigit(monthEntry)&&
		date.IsDigit(dayEntry)&&
		date.IsDigit(yearEntry)&&
		date.IsFormated(monthEntry)&&
		date.IsFormated(dayEntry)&&
		date.IsFormated(yearEntry)))

			throw "\nInvalid dataType or format (ex.01 is not allowed) (Month Day Year):\n"
				+monthEntry+" "+dayEntry+" "+yearEntry;
	//set the valid data
	else{
		date.setMonth(atoi(monthEntry.c_str()));
		date.setDay(atoi(monthEntry.c_str()),
			atoi(dayEntry.c_str()),
			atoi(yearEntry.c_str()));
		
		date.setYear(atoi(yearEntry.c_str()));
		
		//return inputs
		return input;
	}
}