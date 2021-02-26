#include"Doctor.h"

Doctor::Doctor()
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
	Doctortype = UnknownDoctor;
}
Doctor::Doctor(int id, char* first, char* last, int tel, char* addr, char* mail, int salary, DoctorTypes tit)
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
	Doctortype = tit;
}

void Doctor::SetDoctorType()
{
	int choose=0;
	while ((choose != 4) && (choose != 5) && (choose != 6) && (choose != 1) && (choose != 2) && (choose != 3))
	{
		cout << "Doctor Type:\n 1) Intern\n2) Practitioner\n3) Assistant\n4) Specialist\n5) Docent\n6) Professor" << endl;
		cin >> choose;
	}
	
	switch (choose)
	{
	case 1:
		Doctortype = Intern; break;
	case 2:
		Doctortype = Practitioner; break;
	case 3:
		Doctortype = Assistant; break;
	case 4:
		Doctortype = Specialist; break;
	case 5:
		Doctortype = Docent; break;
	case 6:
		Doctortype = Professor; break;

	}

}

void Doctor::SetDoctorType2()
{
	int choose=0;
	while ((choose != 4) && (choose != 5) && (choose != 6))
	{
		cout << "Doctor Type:\n4) Specialist\n5) Docent\n6) Professor" << endl;
		cin >> choose;
		switch (choose)
		{
		case 4:
			Doctortype = Specialist; break;
		case 5:
			Doctortype = Docent; break;
		case 6:
			Doctortype = Professor; break;
		default:
			cout << "Please enter valid number!" << endl; break;
		}
	}
}

void Doctor::SetDoctorType3()
{
	int choose=0;
	while ((choose != 1) && (choose != 2) && (choose != 3))
	{
		cout << "Doctor Type:\n1) Intern\n2) Practitioner\n3) Assistant" << endl;
		cin >> choose;
	}
	switch (choose)
	{
	case 1:
		Doctortype = Intern; break;
	case 2:
		Doctortype = Practitioner; break;
	case 3:
		Doctortype = Assistant; break;
	
	}

}

int Doctor::GetType()
{
	return Doctortype;
}