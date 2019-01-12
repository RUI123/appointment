#ifndef USERS_H
#define USERS_H

#include "DateTime.h"
#include <time.h>
#include <cstring>
#include <fstream>

//forward declaration
class Users;

// prototype of ostream for user
ostream &operator << (ostream &, const Users&);

//constant size for name
const int NAME_CHAR_LIMIT=50;
//size for event
const int EVENT_CHAR_LIMIT=100;
//size for id 
const int ID_CHAR_LIMIT=8;
//set the number of officers
const int NUM_MEMBERS=3;

//Making a structure for Name
struct Name{
	string firstName;
	string lastName;
};

//set the default officers
const Name OFFICER_MEMBERS[NUM_MEMBERS]={
	{"Jhon","Smith"},{"Henry","Jhon"},{"Jack","Ken"}};

//set a structure for records to write and read from file
struct UsersRecord{
	char firstName[NAME_CHAR_LIMIT];
	char lastName[NAME_CHAR_LIMIT];
	char idNumber[ID_CHAR_LIMIT];
	
	char eventOnTheDate[EVENT_CHAR_LIMIT];

	int phoneNumber;
	int officer;
	int month;
	int day;
	int year;
	int hour;
	int minute;
};

//create a class for user
class Users{

	//member variables
private:
	Name userName;
	int officer;
	string phoneNumber;
	string eventOfAppoinment;
	string idNumber;
	DateTime timeForAppointment;

	//get the name of officer
	Name getOfficerName()	const	{return OFFICER_MEMBERS[officer];}
	//function to create a 6 digit random id
	void setIdNumber();
	//function to convert class to structrue for saving to file
	UsersRecord convertToStruct(UsersRecord &right);
	//function to convert structure to class for reading from file
	void convertToObject(UsersRecord& userStruct);
	//function to convert a char pointer to array
	void convertToCharArray(char info[], const char* ptr);
	//function to convert char array to string
	string convertToString(char[],int);
public :

	//using a template class for exceptions
	template<class T>
	class InvalidEntry{
	private:
		T value;
	public:
		InvalidEntry(T v){
			value=v;
		}
		T getValue()const{return value;}
	};
	
	//default constructors
	Users(){
		userName.firstName="";
		userName.lastName="";
		officer=0;
		phoneNumber="";
		eventOfAppoinment=="";
		idNumber="";
	}

	//constructors for creating new users
	Users(string f,string l,string p,DateTime tfApp,int o,string e){
		setUserName(f,l);
		setPhoneNumber(p);
		setTime(tfApp);
		setIdNumber();
		setOfficer(o);
		setEvent(e);
	}

	//constructors for creating information for old users
	Users(string f, string l, string p, DateTime tfApp, int o, string e, string id){
		setUserName(f, l);
		setPhoneNumber(p);
		setTime(tfApp);
		setIdNumber(id);
		setOfficer(o);
		setEvent(e);
	}

	//deconstructor
	~Users(){
		userName.firstName="";
		userName.lastName="";
		officer=0;
		phoneNumber="";
		eventOfAppoinment=="";
		idNumber="";
	}


	//get functions for all member variables
	Name getUserName()	const	{return userName;}
	DateTime getTime()	const	{return timeForAppointment;}
	//get the sign of officer
	int getOfficer()	const	{return officer;}
	string getPhoneNumber() const{return phoneNumber;}
	string getEvent()const {return eventOfAppoinment;}
	string getIdNumber()const {return idNumber;}

	//set functions for all member variables
	void setUserName(string first,string last);
	void setOfficer(int);
	void setTime(DateTime app);
	void setEvent(string);
	void setPhoneNumber(string);
	void setIdNumber(string);
	

	//functions to overload operator <<,>> to read and write from file
	void operator>>(fstream &);
	void operator <<(fstream &);

	//functions to overload operator =,<,>,==
	void operator=(const Users &right);
	bool operator >(const Users &right);
	bool operator <(const Users &right);
	bool operator ==(const Users &right);

	//functions to overlaod operator == 
	//and > to help compare with date object
	bool operator==(const Date&right);
	bool operator>(const Date&right);

	//function to output the contents of this object
	friend ostream &operator << (ostream &out, const Users&);
};

#endif // !USERS_H
