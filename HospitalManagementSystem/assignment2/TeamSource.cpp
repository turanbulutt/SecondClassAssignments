#include"Team.h"

Team::Team()
{
	TeamID = 0;
	numMember = 0;
	TeamLeader = new Doctor;
	*TeamMembers = new Employee;

}

Team::Team(int id)
{
	TeamID = id;
	numMember = 0;
	TeamLeader = new Doctor;
	*TeamMembers = new Employee;
}

void Team::SetTeamID()
{
	cout << "Enter the team ID:" << endl;
	cin >> TeamID;
}

void Team::GetTeamLeader()
{
	cout << "Enter the details of the team leader:\n" << endl;
	TeamLeader->SetEmployeeID();
	TeamLeader->SetEmployeeFirstName();
	TeamLeader->SetEmployeeLastName();
	TeamLeader->SetEmployeeTelNo();
	TeamLeader->SetEmployeeAddress();
	TeamLeader->SetEmployeeEMail();
	TeamLeader->SetEmployeeAnnualSalary();
	TeamLeader->SetDoctorType2();
	numMember++;
	cout << "The team leader has been added to the team successfully!" << endl;
}

void Team::AddTeamMember(Doctor &newMember)
{
	if (newMember.GetType() != 4 && newMember.GetType() != 5 && newMember.GetType() != 6)
	{
		numMember++;
		TeamMembers[numMember] = &newMember;

	}
	else if (numMember == 0)
		cout << "Assign the team leader first!!" << endl;
	else if (numMember == 25)
		cout << "Your team is full!!" << endl;
	else
		cout << "Your doctors have invalid type!" << endl;
}

void Team::AddTeamMember(Nurse& newMember)
{
	if(numMember==0)
		cout << "Assign the team leader first!!" << endl;
	else if (numMember == 25)
		cout << "Your team is full!!" << endl;
	else
	{
		numMember++;
		TeamMembers[numMember] = &newMember;
	}
		

}

void Team::AddTeamMember(Admin& newMember)
{
	if (numMember == 0)
		cout << "Assign the team leader first!!" << endl;
	else if (numMember == 25)
		cout << "Your team is full!!" << endl;
	else
	{
		numMember++;
		TeamMembers[numMember] = &newMember;
	}

}

void Team::ListMembers()
{
	int member = 2;
	cout << "Team Leader:" << endl;
	TeamLeader->PrintEmployee();
	cout << "Team Members: " << endl;
	for (member; member <= numMember; member++)
	{
		TeamMembers[member]->PrintEmployee();
	}
}

int Team::CalculateSalary()
{
	int salary = 0;
	salary += TeamLeader->GetSalary();
	int member = 2;
	for (member; member <= numMember; member++)
	{
		salary=salary+TeamMembers[member]->GetSalary();
	}
	return salary;
}

int Team::SearchMember(int ID)
{
	int member = 2;
	if (ID==TeamLeader->GetID())
	{
		cout << "It is found in team " << TeamID << ". The details are listed below" << endl;
		TeamLeader->PrintEmployee();
		return 1;
	}
	else
	{
		for (member; member <= numMember; member++)
		{
			if (TeamMembers[member]->GetID() == ID)
			{
				cout << "It is found in team " << TeamID << ". The details are listed below" << endl;
				TeamMembers[member]->PrintEmployee();
				return 1;
			}
		}
	}
	return 0;
}

void Team::PrintLeader()
{
	TeamLeader->PrintEmployee();
}

int Team::GetTeamID()
{
	return TeamID;
}