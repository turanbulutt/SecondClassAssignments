#include"Admin.h"

class Team :public Doctor
{
private:
	int TeamID;
	int numMember;
	Doctor *TeamLeader;
	Employee *TeamMembers[25];
public:
	Team();
	Team(int);
	void SetTeamID();
	int GetTeamID();
	void GetTeamLeader();
	void AddTeamMember(Doctor&);
	void AddTeamMember(Nurse &);
	void AddTeamMember(Admin &);
	void ListMembers();
	int CalculateSalary();
	int SearchMember(int);
	void PrintLeader();
};
