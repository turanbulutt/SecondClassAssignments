#include"Hospital.h"

Hospital::Hospital()
{
	HospitalTeams = new Team[25];
	numberOfTeam = 0;
}

void Hospital::AddnewTeam()
{
	numberOfTeam++;
	HospitalTeams[numberOfTeam].SetTeamID();
	HospitalTeams[numberOfTeam].GetTeamLeader();
	char choose;
	int chooseType;
	cout << "Would you like to add a new member to your team (Y/N)" << endl;
	cin >> choose;
	while (choose == 'y' || choose == 'Y')
	{
		cout << "1. Doctor \n2. Nurse \n3. Admin \nSelect type: " << endl;
		cin >> chooseType;
		if (chooseType == 1)
		{
			Doctor* newDoc = new Doctor;
			newDoc->SetEmployeeID();
			newDoc->SetEmployeeFirstName();
			newDoc->SetEmployeeLastName();
			newDoc->SetEmployeeTelNo();
			newDoc->SetEmployeeAddress();
			newDoc->SetEmployeeEMail();
			newDoc->SetEmployeeAnnualSalary();
			newDoc->SetDoctorType3();
			HospitalTeams[numberOfTeam].AddTeamMember(*newDoc);
		}
		else if (chooseType == 2)
		{
			Nurse* newNurs = new Nurse;
			newNurs->SetEmployeeID();
			newNurs->SetEmployeeFirstName();
			newNurs->SetEmployeeLastName();
			newNurs->SetEmployeeTelNo();
			newNurs->SetEmployeeAddress();
			newNurs->SetEmployeeEMail();
			newNurs->SetNurseType();
			newNurs->SetNurseOvertime();
			HospitalTeams[numberOfTeam].AddTeamMember(*newNurs);
		}
		else if (chooseType == 3)
		{
			Admin* newAdmin = new Admin;
			newAdmin->SetEmployeeID();
			newAdmin->SetEmployeeFirstName();
			newAdmin->SetEmployeeLastName();
			newAdmin->SetEmployeeTelNo();
			newAdmin->SetEmployeeAddress();
			newAdmin->SetEmployeeEMail();
			newAdmin->SetAdminType();
			newAdmin->SetWorkedHour();
			HospitalTeams[numberOfTeam].AddTeamMember(*newAdmin);
		}
		else
		{
			cout << "You entered wrong selection please try again!!";
		}
		cout << "Would you like to add a new member to your team (Y/N)" << endl;
		cin >> choose;
	}
	cout << "The team has been added to the hospital successfully! " << endl;
}

void Hospital::SearchEmployee(int id)
{
	int number = 1,check=0;
	for (number; number <= numberOfTeam; number++)
	{
		check=HospitalTeams[number].SearchMember(id);
		if (check)
			break;
	}
	if (!check)
		cout << "Employee couldn't found!!" << endl;
}

void Hospital::PrintAllTeams()
{
	int number = 1;
	for (number; number <= numberOfTeam; number++)
	{
		cout << "Team " << HospitalTeams[number].GetTeamID() << endl;
		HospitalTeams[number].ListMembers();
	}
}

void Hospital::PrintTeam(int id)
{
	int number = 1,check=0;
	for (number; number <= numberOfTeam; number++)
	{
		if (HospitalTeams[number].GetTeamID() == id)
		{
			check = 1;
			HospitalTeams[number].ListMembers();
			break;
		}
	}
	if (!check)
	{
		cout << "There is no team that called " << id << " id!!" << endl;
	}
}

void Hospital::PrintAnnualCostHospital()
{
	int number = 1,salary=0;
	for (number; number <= numberOfTeam; number++)
	{
		salary=salary+HospitalTeams[number].CalculateSalary();
	}
	cout << "Total annual salary of hospital is " << salary << endl;
}

void Hospital::PrintAnnualCostTeam(int id)
{
	int number = 1, check = 0,salary=0;
	for (number; number <= numberOfTeam; number++)
	{
		if (HospitalTeams[number].GetTeamID() == id)
		{
			check = 1;
			salary=HospitalTeams[number].CalculateSalary();
			cout << "Annual salary of team " << id << " " << salary;
			break;
		}
	}
	if (!check)
	{
		cout << "There is no team that called " << id << " id!!" << endl;
	}
}

int Hospital::GetNumberOfTeam()
{
	return numberOfTeam;

}