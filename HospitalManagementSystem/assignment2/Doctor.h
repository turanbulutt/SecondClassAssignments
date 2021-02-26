#include"Employee.h"

enum DoctorTypes { UnknownDoctor,Intern, Practitioner, Assistant, Specialist, Docent, Professor };



class Doctor : public Employee
{
private:
	DoctorTypes Doctortype;
public:
	Doctor();
	Doctor(int, char*, char*, int, char*, char*, int, DoctorTypes);
	void SetDoctorType();
	void SetDoctorType2();
	void SetDoctorType3();
	int GetType();

};