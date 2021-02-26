#include"Bones.h"

Bones::Bones(int idnum)
{
	IDNumber = idnum;
	if (IDNumber == 1)
	{
		typee = BonesType::Full;
		effect = 100;
		letter = 'F';
	}
	else if (IDNumber == 2)
	{
		typee = BonesType::Skull;
		effect = 50;
		letter = 'S';
	}
	else if (IDNumber == 3)
	{
		typee = BonesType::Ordinary;
		effect = 20;
		letter = 'O';
	}
	else
	{
		typee = BonesType::Undefined;
		effect = 0;
		letter = 'X';
	}
}