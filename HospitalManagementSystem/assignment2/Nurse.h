#include"Doctor.h"

enum NurseTypes{UnknownNurse,General,Midwife};



class Nurse :public Employee
{
private:
	NurseTypes Nursetype;
	int overtime;
public:
	Nurse();
	Nurse(int, char*, char*, int, char*, char*, int,NurseTypes,int);
	void SetNurseType();
	void SetNurseOvertime();
	void CalculateNurseAnnualSalary();
};