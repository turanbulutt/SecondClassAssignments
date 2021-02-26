#include"Nurse.h"

enum Admintypes{UnknownAdmin,Manager,Secretary};

class Admin: public Employee
{
private:
	Admintypes Admintype;
	int workedPerWeek;
public:
	Admin();
	Admin(int, char*, char*, int, char*, char*, Admintypes, int);
	void SetAdminType();
	void SetWorkedHour();
	void CalculateAdminSalary();
};