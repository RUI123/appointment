#include"Users.h"

//function to set the name of user
void Users::setUserName(string first, string last){

	//to test if the length of first or last 
	//within maximum 49 chars and throw exception
	if (first.length() > NAME_CHAR_LIMIT ||
		last.length() > NAME_CHAR_LIMIT)
		throw 
			"\nInvalid Name ( - Only allow 49 characters for either part of Name) :\n"
			+first+" "+last;

	//to test if they are made by letters and throw exception
	else if ((!timeForAppointment.IsLetter(first))||
		(!timeForAppointment.IsLetter(last)))
		throw 
			"\nInvalid Name ( - Name should be letters) :\n"
			+first+" "+last;
	//assign the value of name
	else{
		userName.lastName = last;
		userName.firstName = first;
	}
}

//function to set the time for appointment
void Users::setTime(DateTime app){
	timeForAppointment=app;
}

//function to set the event 
void Users::setEvent(string e){

	//to test if the length of event within 
	//the maximum value of 99 chars
	if(e.length()<EVENT_CHAR_LIMIT)
		eventOfAppoinment=e;
	else{
		cout<<"\nOnly allow 99 characters to describe the Event.";
		throw InvalidEntry<string> (e);
	}
}

//function to set the id 
void Users::setIdNumber(string id){

	//to test if the id length is within range
	if(id.length()==ID_CHAR_LIMIT-1){
		//to test if the id is digital
		if(timeForAppointment.IsDigit(id))
			idNumber = id;
		//throw exception
		else{
			cout<<"\nId Number should be a digital value.";
			throw InvalidEntry<string>(id);
		}
	}
	//throw exception
	else{
		cout<<"\nId Number should be 7 digits.";
		throw InvalidEntry<string>(id);
	}
}

//Function to set random id Number
void Users::setIdNumber(){

	idNumber="";
	for(int x=0;x<ID_CHAR_LIMIT;x++)
		idNumber+=to_string(rand()%10);
}

//function to set the officer by number
void Users::setOfficer(int s){
	//to test if the officer number within range of 
	//default value-3
	if(s<NUM_MEMBERS&&s>=0)
		officer=s;
	else{
		cout<<"\nThere is not such person here.";
		throw InvalidEntry<int>(s);
	}
}

//function to set the phone number
void Users::setPhoneNumber(string p){
	//to test if the length of phone number is 10
	if(p.length()==10){

		//to test if it's digital
		if(timeForAppointment.IsDigit(p))
			phoneNumber=p;

		//throw exception
		else{
			cout<<"\nPhone Number should be digital.";
			throw InvalidEntry<string>(p);
		}
	}
	//throw exception
	else{
		cout<<"\nPhone Number should be 10 digit.";
		throw InvalidEntry<string>(p);
	}
}

//function to overload operator =
void Users::operator=(const Users &right){

	userName.firstName=right.getUserName().firstName;
	userName.lastName=right.getUserName().lastName;
	idNumber=right.getIdNumber();
	phoneNumber=right.getPhoneNumber();
	officer=right.getOfficer();
	eventOfAppoinment=right.getEvent();
	timeForAppointment=right.getTime();
}

//function to overload operator > 
//by comparing time and officer number
bool Users::operator >(const Users &right){

	//to test the time
	if(timeForAppointment> right.getTime())
		return true;
	else if(timeForAppointment==right.getTime())
	{
		//to test the number of officer
		if(officer>right.getOfficer())
			return true;
		else
			return false;
	}
	else
		return false;
}

//function to overload operator < 
//by comparing time and officer number
bool Users::operator <(const Users &right){

	//to test the time
	if(timeForAppointment< right.getTime())
		return true;
	else if(timeForAppointment==right.getTime())
	{
		//to test the officer number
		if(officer<right.getOfficer())
			return true;
		else
			return false;
	}
	else
		return false;

}

//function to overload operator ==
//by comparing name,phone and id number
bool Users::operator ==(const Users &right){

	//to test if the Name, phone number and id number are same
	if (userName.firstName == right.getUserName().firstName&&
		userName.lastName == right.getUserName().lastName&&
		phoneNumber == right.getPhoneNumber() &&
		idNumber == right.getIdNumber())
		return true;
	else
		return false;
}

//function to print the information of a user
ostream &operator<<(ostream & output, const Users& user){

	output<<user.getTime()<<"First Name: "
		<<user.getUserName().firstName<<"\t"
		<<"Last Name: "<<user.getUserName().lastName<<"\n"
		<<"Phone Number:\t"<<user.getPhoneNumber()<<"\t"
		<<"Checking ID:\t"<<user.getIdNumber()<<"\n"
		<<"Officer:\t"<<OFFICER_MEMBERS[user.getOfficer()].firstName<<" "
		<<OFFICER_MEMBERS[user.getOfficer()].lastName<<"\nEvent:\t"
		<<user.getEvent();
	return output;
}

//function to convert char pointer to char array
void Users::convertToCharArray(char info[], const char* ptr){

	for (int x = 0; *(ptr + x) != '\0'; x++)
		info[x] = *(ptr + x);
}

//function to convert class object to structure
UsersRecord Users::convertToStruct(UsersRecord &right){

	convertToCharArray(right.firstName,getUserName().firstName.c_str());
	convertToCharArray(right.lastName, getUserName().lastName.c_str());
	convertToCharArray(right.eventOnTheDate, getEvent().c_str());
	convertToCharArray(right.idNumber, getIdNumber().c_str());

	right.phoneNumber=atoi(getPhoneNumber().c_str());
	right.officer = getOfficer();
	right.month = getTime().getMonth();
	right.day = getTime().getDay();
	right.year = getTime().getYear();
	right.hour = getTime().getHour();
	right.minute =getTime().getMinute();

	return right;
}

//function to convert char array to string 
//(only alphabet,letter and punctuation)
string Users::convertToString(char info[],int limit){
	string data="";
	for (int x = 0; info[x]<127&&info[x]>31&&x<limit; x++)
		data+=info[x] ;
	return data;
}

//function to convert structure to object
void Users::convertToObject(UsersRecord& userStruct){

	userName.firstName=convertToString
		(userStruct.firstName,NAME_CHAR_LIMIT);
	userName.lastName=convertToString
		(userStruct.lastName,NAME_CHAR_LIMIT);

	phoneNumber=to_string(userStruct.phoneNumber);

	timeForAppointment.setMonth(userStruct.month);
	timeForAppointment.setDay(userStruct.month,
		userStruct.day,userStruct.year);
	timeForAppointment.setYear(userStruct.year);
	timeForAppointment.setHour(userStruct.hour);
	timeForAppointment.setMinute(userStruct.hour,userStruct.minute);

	officer=userStruct.officer;
	eventOfAppoinment=convertToString
		(userStruct.eventOnTheDate,EVENT_CHAR_LIMIT);
	idNumber=convertToString
		(userStruct.idNumber,ID_CHAR_LIMIT);
}

//function to write the contents to binary file
void Users::operator>>(fstream & write){

	//create a struct t store value
	UsersRecord record;
	//write to file
	write.write(reinterpret_cast<char*>
		(&convertToStruct(record)),sizeof(convertToStruct(record)));
}

//function to read contents from binary file
void Users::operator <<(fstream & read){
	UsersRecord record;
	//read from file
	read.read(reinterpret_cast<char*>(&record),sizeof(record));

	//assign values to class
	convertToObject(record);
	
}

//function to overload operator =with Date type object
//to test if they are same date
bool Users::operator==(const Date&right){

	if (getTime().getDay() == right.getDay() &&
		getTime().getMonth() == right.getMonth() &&
		getTime().getYear() == right.getYear())
		return true;
	else
		return false;
}

//function to overload operator > with Date type object
//to test if date is earlier than appointment date of user
bool Users::operator>(const Date&right){

	//test the year
	if (getTime().getYear() > right.getYear())
		return true;
	else if (getTime().getYear() == right.getYear()){

		//test the month
		if (getTime().getMonth() > right.getMonth())
			return true;
		else if (getTime().getMonth() == right.getMonth()){

			//test the day
			if (getTime().getDay() > right.getDay())
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