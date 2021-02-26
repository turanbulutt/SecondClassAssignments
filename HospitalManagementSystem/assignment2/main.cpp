#include<iostream>
#include"hospital.h"

int main()
{
	Hospital* myHospital = new Hospital;
	cout << "Welcome to Hospital Management System! " << endl;
	int choose = 0,id;
	while (choose != 7)
	{
		cout << "1. Create a team \n2. Search a member by ID \n3. List all members \n4. List total annual salary \n5. List all members of a given team \n6. List total annual salary of a given team \n7. Exit Enter your selection:" << endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			myHospital->AddnewTeam();
			break;
		case 2:
			cout << "Enter member ID:" << endl;
			cin >> id;
			myHospital->SearchEmployee(id);
			break;
		case 3:
			myHospital->PrintAllTeams();
			break;
		case 4:
			myHospital->PrintAnnualCostHospital();
			break;
		case 5:
			cout << "Enter team ID:" << endl;
			cin >> id;
			myHospital->PrintTeam(id);
			break;
		case 6:
			cout << "Enter team ID:" << endl;
			cin >> id;
			myHospital->PrintAnnualCostTeam(id);
			break;
		case 7:
			break;
		default:
			cout << "You entered wrong selection please try again" << endl;

		}
	}
	return 0;

}