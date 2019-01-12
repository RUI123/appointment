#include"Time.h"

//function to set the hour in working time
void Time::setHour(int h){
	//create error message for exception
	string error="\nIt's Closing Time...\nInvalid Value:\t"+to_string(h);
	if(h>=START_HOUR&&h<=END_HOUR)
		hour=h;
	else
		//throw exception
		throw error;
}

//function to set the minute 
void Time::setMinute(int h,int m){
	string error;
	//test if the minute in the range
	if(m>=0&&m<=60){
		//test if it's closing time
		if(h==END_HOUR){
			if(m<=CLOSING_MINUTE)
				minute=m;
			//throw exception for out of minute range for closing
			else{
				error="\nIt's Closing Time...\nInvalid Value:\t"+to_string(m);
				throw error;
			}
		}
		//test if it's opening time
		else if(h==START_HOUR){
			if(m>=OPENING_MINUTE)
				minute=m;
			//throw exception for out of minute range for opening
			else{
				error="\nIt's Closing Time...\nInvalid Value:\t"+to_string(m);
				throw error;
			}
		}
		else
			minute=m;
	}
	//throw exception for having out range of minutes
	else {
		error="\nInvalid Value ( - Out of Range of Minutes):\t"+to_string(m);
		throw error;
	}
}
