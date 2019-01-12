#include"BinaryTree.h"

#include<conio.h>
#include<cstdlib>

//function to  load the data from file
void loadFile(fstream&);

//function to create the functioning of main menu
void mainMenuChoices(fstream&);
//function to print the menu
void printMainMenu();

//function to create functioning of making appointment menu
void appointmentChoices(fstream&);
//function to print making appointment menu
void printAppointmentMenu();
//function to make an appointment
void makeAppointment(fstream &);
//function to get the inputs of appointment and return the value
Users getInputsOfAppointment();
//function for user to choose the officer
int getOfficerChoices();

//function to show the schedual of a date
void showSchedual();
//function to get inputs of a date
Date getDateInput();

//function to delete a appointment
void cancelAppointment();
//function to get the information to cancel appointment
Users getCancelAppInfo();

//function to save tree into binary file
void saveToFile(fstream &);

//declare a variable for current date
Date currentDate;
//create an empty tree
BinaryTree <Users> records;
//count the number of records
int recordsOfFile = 0;

int main(){

	//declare a variable to read and write from file
	fstream file;
	//open read and write mode
	file.open("appointmentRecord.dat", ios::in | ios::out | ios::binary);
	//test if the file exists
	if(!file){
		file.close();
		//open write mode
		file.open("appointmentRecord.dat", ios::out | ios::binary);
	}
	//to load the file to tree
	else{
		try{
			loadFile(file);}catch(string e){cout<<e;}catch(bad_alloc){cout<<"ads";};
	}

	cout<<"\t\tWelcome to the program\n";
	cout<<"\n\nPlease enter Current Date to start the program...\n";
	while(true){
		try{
			cout<<"\nMonth Day Year (Inputs should be "
				<<"seperated by a space or an enter key):\n";
			cin>>currentDate;
			mainMenuChoices(file);
		}catch(string e){
			cout<<e;
		}
	}
	

	system("pause");
	return 0;
}

//function to load data from the file 
void loadFile(fstream &read){
	Users inst;
	while (read){
		inst << read;
		//records.insertNode(inst);
		recordsOfFile++;
		cout<<"load";
	}
}

//function to create the functioning of main menu
void mainMenuChoices(fstream &file){
	//clear scream
	system("cls");
	//print the main menu
	printMainMenu();

	//all functions choices for the main menu
	while(true){
		switch(_getch()){

			//to change to  making appointment menu
			case '1':	
				appointmentChoices(file);
				break;

			case '2':
				showSchedual();
				break;

			case '3':
				cancelAppointment();
				break;
			case '4':
				saveToFile(file);
				break;

				//to end the program
			case '5':
				file.close();
				cout<<"\nProgram is Ending...\n";
				system("pause");
				exit(0);

				//avoid bad entry
			default:	
				cout<<"\n\nInvalid choice, Please reenter:\t";
				break;
		}
		printMainMenu();
	}
}

//function to print the main menu
void printMainMenu(){
	cout << "Date:\t";
	//print current date
	currentDate.printDate();
	cout << "\n\n\n****************   MAIN MENU   *****************\n\n";
	cout << "\t1.\tSchedual Appointment\n"
		<< "\t2.\tShow Schedual of a Date\n"
		<< "\t3.\tCancel Appointment\n"
		<< "\t4.\tSave\n"
		<< "\t5.\tExit";
}

//function to create functioning of making appointment menu
void appointmentChoices(fstream &file){

	system("cls");
	printAppointmentMenu();
	while (true){
		switch (_getch()){
		
			//choice to make appointment
			case '1':
				system("cls");
				makeAppointment(file);
				break;
				//choice to back to main
			case '2':
				mainMenuChoices(file);
				break;

				//invalid entry
			default:
				cout << "\n\nInvalid choice, Please reenter:\t";
				break;
		}
	}
	
}

//function to show the appointment menu
void printAppointmentMenu(){
	cout<<"Date:\t";
	currentDate.printDate();
	cout << "\n\n\n****************   Schedual An Appointment   *****************\n\n"
		<<"1.\tMake Appointment Now\n"
		<<"2.\tCancel Choice\n";
}

//function to make an appointment
void makeAppointment(fstream & file){
	Users inst=getInputsOfAppointment();
	//insert a node to the tree
	try{
		records.insertNode(inst);
		cout<<"Thank you for making an appointment"
			<<", here is your all information:\n"
			<<inst;
	}
	//catch exception for unavailable time
	catch (string e){
		cout << e;
		cout<<"\nPlease be sure check the schedual first.";
	}
	//back for appointment choices
	cout<<"\nPlease press a key to go back to Appointment Menu.";
	_getch();
	appointmentChoices(file);
}

//function to get the all inputs of the appointment
Users getInputsOfAppointment(){

	//declare a variable to assign all data
	Users visitor;
	//delcare variables for getting the inputs
	string firstName, lastName, eventTodo, phone;
	DateTime appointmentTime;
	int officer=1;

	//get the inputs
	while(true){
		try{
			cout<<"Month Day Year Hour Minute \n(Inputs should be "
				<<"seperated by a space or an enter key):\n";
			cin>>appointmentTime;
			cin.ignore();

			cout << "\nPlease enter First Name:\t";
			getline(cin,firstName);
			cout << "\nPlease enter Last Name:\t";
			getline(cin, lastName);
			cout << "\nPlease enter Phone Number:\t";
			getline(cin, phone);
			cout << "\nPlease enter Event:\t";
			getline(cin, eventTodo);

			//declare a variable to assign all data and test
			Users copy(firstName,lastName,phone,
				appointmentTime,officer,eventTodo);
			visitor=copy;
			//test if user make an appointment after today
			if (!(visitor > currentDate))
				throw "\nMaking Appointment today or Before is not Allowed.";
			
			//value that allows user to choose officer
			officer=0;
			//catch the exceptions
		}catch (Users::InvalidEntry<string> e){
			cout << e.getValue();
		}catch (Users::InvalidEntry<int> e){
			cout << e.getValue();
		}catch (string e){
			cout << e;
		}

		//set the officer
		while(!officer){
			officer = getOfficerChoices();
			visitor.setOfficer(officer-1);
		}
		//to break the while loop
		if(officer)
			break;
	}

	//return the value
	return visitor;
}

//function to let user choose an officer 
int getOfficerChoices(){

	//variable to allow keep enter the officer menu or not
	int num = 1;
	//print the name of officers
	cout << "\n\n\n****************   Officers   *****************\n\n";
	for (Name m : OFFICER_MEMBERS)
		cout << num ++ << ".\t" << m.firstName << " " << m.lastName << "\n";

	//make choices for user
	switch (_getch())
	{
	case '1':
		num = 1;
		break;
	case '2':
		num = 2;
		break;
	case '3':
		num = 3;
		break;
	default:
		cout << "Invalid choice, Please reenter:\t";
		num = 0;
		break;
	}
	return num;
}

//function to show the schedual of the date
void showSchedual(){

	cout << "\n\n\n****************   Schedual   *****************\n\n"
		<<"Opening Time:\t"<<START_HOUR<<":"<<OPENING_MINUTE
		<<"Closing Time:\t"<<END_HOUR<<":"<<CLOSING_MINUTE
		<<endl;
	records.displayByDate(getDateInput());
	cout<<"End of the Schedual.\n";
	//back for main menu
	cout<<"\nPlease press a key to go back to Main Menu.";
	_getch();
}

//function to get the input of the date for showing schedual
Date getDateInput(){
	Date dateOfSchedual;
	cout<<"\n\nPlease enter A Date to show the Schedual of the date,\n";
	//get the input and print out
	while(true){
		try{
			cout<<"Month Day Year (Inputs should be "
				<<"seperated by a space or an enter key):\n";
			cin>>dateOfSchedual;

			//print the date
			dateOfSchedual.printDate();
			return dateOfSchedual;

		}catch(string e){
			cout<<e;
		}
	}
}

//function to delete one appointment 
//that apply to the information
void cancelAppointment(){
	Users visitor;
	try{
		visitor=records.searchNode(getCancelAppInfo());
		
		//test if the date for appointment is after current date
		if (!(visitor > currentDate))
			throw "\nAppointment today or Before is not Allowed to Cancel.";

		//delete the node
		records.remove(visitor);
		cout<<"\nAppointment has been deleted.\n";
	}catch(string e){
		cout<<e;
	}
	//back for main menu
	cout<<"\nPlease press a key to go back to Main Menu.";
	_getch();
}

//function to get basic information from user
//name,phone,id number
Users getCancelAppInfo(){

	//variable to store information
	Users visitor;
	string firstName, lastName, phone,idNumber;

	//get the inputs
	while(true){
		try{
			cout << "\nPlease enter First Name:\t";
			getline(cin,firstName);
			cout << "\nPlease enter Last Name:\t";
			getline(cin, lastName);
			cout << "\nPlease enter Phone Number:\t";
			getline(cin, phone);
			cout << "\nPlease enter idNumber for the Appointment:\t";
			getline(cin, idNumber);
			
			//to set the value
			visitor.setUserName(firstName,lastName);
			visitor.setPhoneNumber(phone);
			visitor.setIdNumber(idNumber);
			break;
		}catch (Users::InvalidEntry<string> e){
			cout << e.getValue();
		}catch (Users::InvalidEntry<int> e){
			cout << e.getValue();
		}catch (string e){
			cout << e;
		}
	}
	return visitor;
}


//funtion to save the data
void saveToFile(fstream &write){

	write.clear();
	//move to the begining of the ifle
	write.seekg(0L,ios::beg);
	//if the file has some data and has more data than tree
	//close file and open it in write mode
	if (records.getNumberOfNodes() < recordsOfFile&&recordsOfFile!=0){
		write.close();
		write.open("appointmentRecord.dat",ios::out|ios::binary);
	}
	//save the tree into binay file
	if(records.getNumberOfNodes()!=0){
		records.save(write);
		cout<<"\nData has been saved to file...";
	}
	else
		cout<<"\nThere is not any information need to be saved.";

	//back for main menu
	cout<<"\nPlease press a key to go back to Main Menu.";
	_getch();
}