#include<iostream>
using namespace std;

class Employee
{
protected:
	int EmployeeID;
	char* FirstName;
	char* LastName;
	int TelNo;
	char* Address;
	char* EMail;
	int AnnualSalary;
public:
	Employee();
	Employee(int, char*, char*, int, char*, char*, int);
	void SetEmployeeID();
	void SetEmployeeFirstName();
	void SetEmployeeLastName();
	void SetEmployeeTelNo();
	void SetEmployeeAddress();
	void SetEmployeeEMail();
	void SetEmployeeAnnualSalary();
	void PrintEmployee();
	int GetSalary();
	int GetID();
};