#include"Admin.h"


Admin::Admin()
{
	EmployeeID = 0;
	FirstName = new char[25];
	LastName = new char[25];
	TelNo = 0;
	Address = new char[50];
	EMail = new char[50];
	strcpy(FirstName, "Not Provided");
	strcpy(LastName, "Not Provided");
	strcpy(Address, "Not Provided");
	strcpy(EMail, "Not Provided");
	Admintype = UnknownAdmin;
	workedPerWeek = 0;
}

Admin::Admin(int id, char* first, char* last, int tel, char* addr, char* mail, Admintypes ty,int hour)
{
	EmployeeID = id;
	TelNo = tel;
	FirstName = new char[25];
	LastName = new char[25];
	Address = new char[50];
	EMail = new char[50];
	strcpy(FirstName, first);
	strcpy(LastName, last);
	strcpy(Address, addr);
	strcpy(EMail, mail);
	Admintype = ty;
	workedPerWeek = hour;

}

void Admin::SetAdminType()
{
	int choose=0;
	while ((choose != 1) && (choose != 2))
	{
		cout << "Admin type:\n1)Manager\n2)Secretary" << endl;
		cin >> choose;
	}
	
	switch (choose)
	{
	case 1:
		Admintype = Manager; break;
	case 2:
		Admintype = Secretary; break;
	}
}

void Admin::SetWorkedHour()
{
	cout << "Enter worked per week:" << endl;
	cin >> workedPerWeek;
	CalculateAdminSalary();
}

void Admin::CalculateAdminSalary()
{
	if (Admintype == Manager)
		AnnualSalary = 50 * 52 * workedPerWeek;
	else
		AnnualSalary = 20 * 52 * workedPerWeek;

}
