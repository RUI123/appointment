#include"DateTime.h"

//default constructor to inherited 
//two constructors from date and time
DateTime::DateTime():Date(),Time()	{}

//constructor to inherited 
//two constructors from date and time
DateTime::DateTime(int month,int day,int year,int hour,int minute)
	:Date(month,day,year),Time(hour,minute)	{}


//function to overload istream operator for datetime
istream &operator>> (istream & input, DateTime& datetime){

	Date dateEntry;
	//initialize variables to store data
	string hourEntry,minuteEntry;
	
	cin>>dateEntry>>hourEntry>>minuteEntry;
	
	// test if they are valid data
	if(!(datetime.IsDigit( hourEntry)&&
		datetime.IsDigit( minuteEntry)))
			// throw string exception
		throw "\nInvalid Values ( - Non-Digital or invalid format (ex. 01)Entrys (hour minute)):\n"
			+hourEntry+" "+minuteEntry;

	// set the date and avoid bad data
	else{
		datetime.setMonth(dateEntry.getMonth());
		datetime.setDay(dateEntry.getMonth(),
			dateEntry.getDay(),dateEntry.getYear());
		datetime.setYear(dateEntry.getYear());

		datetime.setHour(atoi(hourEntry.c_str()));
		datetime.setMinute(atoi(hourEntry.c_str()),
			atoi(minuteEntry.c_str()));
		//return inputs
		return input;
	}
}

// overloading operator function to get output 
ostream &operator<<(ostream & output, const DateTime& date){

	output<<"\nDate: "<<date.getLetterMonth()<<" "
		<<date.getDay()<<", "<<date.getYear()<<"\t"
		<<"Time: "<<date.getHour()<<":"<<date.getMinute()<<endl;
	return output;
}

//function to overload operator = and copy 
//the content of same object type
const DateTime DateTime::operator=(const DateTime &right){

	setMonth(right.getMonth());
	setDay(right.getMonth(),right.getDay(),right.getYear());
	setYear(right.getYear());
	setHour(right.getHour());
	setMinute(right.getHour(),right.getMinute());
	
	return *this;
}

//function to overload operator > and test them by comparing 
//they have enough time interval value between two time
//which means one should be an hour later than the other
bool DateTime::operator >(const DateTime &right){

	//test the year
	if (getYear() > right.getYear())
		return true;
	else if (getYear() == right.getYear()){

		//test the month
		if (getMonth() > right.getMonth())
			return true;
		else if (getMonth() == right.getMonth()){

			//test the day
			if (getDay() > right.getDay())
				return true;
			else if(getDay()==right.getDay()){

				//test if they have enough time between 
				//and first one is greater
				if(IsValidInterval(getHour(),getMinute()
					,right.getHour(),right.getMinute(),TIME_INTERVAL)&&
					IsGreaterTime(getHour(),getMinute()
					,right.getHour(),right.getMinute()))
					return true;
				else
					return false;
			}
			else 
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

//function to overload operator > and test them by comparing 
//they have enough time interval value between two time
//which means one should be an hour earlier than the other
bool DateTime::operator <(const DateTime &right){

	//test the year
	if (getYear() < right.getYear())
		return true;
	else if (getYear() == right.getYear()){

		//to test the month
		if (getMonth() < right.getMonth())
			return true;
		else if (getMonth() == right.getMonth()){

			//to test the day
			if (getDay() < right.getDay())
				return true;
			else if(getDay()==right.getDay()){

				//to test having enough time between and 
				//first one is smaller than second one
				if(IsValidInterval(right.getHour(),
					right.getMinute(),getHour(),getMinute(),TIME_INTERVAL)&&
					(!(IsGreaterTime(getHour(),getMinute()
					,right.getHour(),right.getMinute()))))
					return true;
				else
					return false;
			}
			else 
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

//function to overload operator == 
//to test if they have same time and date
bool DateTime::operator ==(const DateTime &right){

	if (getMonth() == right.getMonth()&&
		getDay() == right.getDay()&&
		getYear() == right.getYear()&&
		getHour()==right.getHour()&&
		getMinute()==right.getMinute())
		return true;
	else
		return false;
}

//virtual function to print the time
void DateTime::printTime() const{

	printf("Time: %02d:%02d",getHour(),getMinute());
}