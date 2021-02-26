#include"Employee.h"

Employee::Employee()
{
	EmployeeID = 0;
	FirstName = new char[25];
	LastName = new char[25];
	TelNo = 0;
	Address = new char[100];
	EMail = new char[50];
	AnnualSalary = 0;
	strcpy(FirstName, "Not Provided");
	strcpy(LastName, "Not Provided");
	strcpy(Address, "Not Provided");
	strcpy(EMail, "Not Provided");
}

Employee::Employee(int id, char* first, char* last, int tel, char* addr, char* mail, int salary)
{
	EmployeeID = id;
	TelNo = tel;
	AnnualSalary = salary;
	FirstName = new char[25];
	LastName = new char[25];
	Address = new char[100];
	EMail = new char[50];
	strcpy(FirstName, first);
	strcpy(LastName, last);
	strcpy(Address, addr);
	strcpy(EMail, mail);
}

void Employee::SetEmployeeID()
{
	cout << "Enter the ID number of employee: " << endl;
	cin >> EmployeeID;
}

void Employee::SetEmployeeFirstName()
{
	delete[] FirstName;
	FirstName = new char[25];
	cout << "Enter the first name of employee: " << endl;
	cin >> FirstName;
}

void Employee::SetEmployeeLastName()
{
	delete[] LastName;
	LastName = new char[25];
	cout << "Enter the last name of employee: " << endl;
	cin >> LastName;

}

void Employee::SetEmployeeTelNo()
{
	cout << "Enter the telephone number of employee: " << endl;
	cin >> TelNo;
}

void Employee::SetEmployeeAddress()
{
	delete[] Address;
	Address = new char[100];
	cout << "Enter the address of employee: " << endl;
	cin.ignore();
	cin.getline(Address, 100);
}

void Employee::SetEmployeeEMail()
{
	delete[] EMail;
	EMail = new char[50];
	cout << "Enter the e mail of employee: " << endl;
	cin >> EMail;

}

void Employee::SetEmployeeAnnualSalary()
{
	cout << "Enter the annual salary of employee: " << endl;
	cin >> AnnualSalary;
}

void Employee::PrintEmployee()
{
	if(this->FirstName!=NULL)
		cout << EmployeeID << "\t" << FirstName << "\t" << LastName << "\t" << TelNo << "\t" << EMail << endl;

}

int Employee::GetSalary()
{
	return AnnualSalary;
}

int Employee::GetID()
{
	return EmployeeID;
}