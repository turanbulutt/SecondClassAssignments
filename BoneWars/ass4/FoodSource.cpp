#include"Food.h"

Food::Food(int idnum)
{
	IDNumber = idnum;
	if (IDNumber == 6)
	{
		typee=FoodType::Burger;
		effect = 4;
		letter = 'B';
	}
	else if (IDNumber == 7)
	{
		typee=FoodType::Nuggets;
		effect = 3;
		letter = 'N';
	}
	else if (IDNumber == 8)
	{
		typee = FoodType::Chips;
		effect = 2;
		letter = 'C';
	}
	else
	{
		typee = FoodType::Undefined;
		effect = 0;
		letter = 'X';
	}
}