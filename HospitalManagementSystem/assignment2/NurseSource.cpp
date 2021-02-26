#include"Nurse.h"

Nurse::Nurse()
{
	EmployeeID = 0;
	FirstName = new char[25];
	LastName = new char[25];
	TelNo = 0;
	Address = new char[50];
	EMail = new char[50];
	AnnualSalary = 0;
	strcpy(FirstName, "Not Provided");
	strcpy(LastName, "Not Provided");
	strcpy(Address, "Not Provided");
	strcpy(EMail, "Not Provided");
	Nursetype = UnknownNurse;
	overtime = 0;
}

Nurse::Nurse(int id, char* first, char* last, int tel, char* addr, char* mail, int salary,NurseTypes ty,int time)
{
	EmployeeID = id;
	TelNo = tel;
	AnnualSalary = salary;
	FirstName = new char[25];
	LastName = new char[25];
	Address = new char[50];
	EMail = new char[50];
	strcpy(FirstName, first);
	strcpy(LastName, last);
	strcpy(Address, addr);
	strcpy(EMail, mail);
	Nursetype = ty;
	overtime = time;
}

void Nurse::SetNurseType()
{
	int choose=0;
	cout << "Nurse type:\n1)General\n2)Midwife" << endl;
	cin >> choose;
	while ((choose != 1) && (choose != 2))
	{
		cout << "You entered invalid number please try again!\nNurse type:\n1)General\n2)Midwife" << endl;
		cin >> choose;
	}
	switch (choose)
	{
	case 1:
		Nursetype = General; break;
	case 2:
		Nursetype = Midwife; break;

	}
}
void Nurse::SetNurseOvertime()
{
	cout << "Enter the hours of overtime per week:" << endl;
	cin >> overtime;
	CalculateNurseAnnualSalary();
}

void Nurse::CalculateNurseAnnualSalary()
{
	if (Nursetype == General)
	{
		AnnualSalary = AnnualSalary + 20 * 52 * overtime;
	}
	else
	{
		AnnualSalary = AnnualSalary + 30 * 52 * overtime;
	}

}