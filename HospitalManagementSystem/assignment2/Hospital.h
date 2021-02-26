#include"Team.h"

class Hospital: public Team
{
private:
	Team *HospitalTeams;
	int numberOfTeam;
public:
	Hospital();
	void AddnewTeam();
	void SearchEmployee(int);
	void PrintAllTeams();
	void PrintTeam(int);
	void PrintAnnualCostHospital();
	void PrintAnnualCostTeam(int);
	int GetNumberOfTeam();

};