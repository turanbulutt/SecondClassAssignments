#include"Archeologist.h"

Archeologist::Archeologist(char letteer, float eneergy, int xx, int yy,int id)
{
	letter = letteer;
	x = xx;
	y = yy;
	energy = eneergy;
	IDNumber = id;
	score = 0;
	injury = 0;
	Inventory = new int[10];
	for (int i = 0; i < 10; i++)
	{
		Inventory[i] = 0;
	}
}

int Archeologist::GetScore()
{
	return score;
}

float Archeologist::GetEnergy()
{
	return energy;
}

void Archeologist::AddItem(int id,int dice,int x,int y,Grid &mygrid)
{
	if (id == 4 && dice>1 && dice<6) //if situations are true trap will effect the player
	{
		injury = 1;
		cout << "\nBAD NEWS!!! You step a trap.." << endl;
	}
	else if (id == 1 || id==2 || id==3)//checking for bones
	{
		Inventory[id]++;
		if (id == 1)
		{
			cout << "\nYou found full body bones. What a treasure!!!" << endl;
			score += 100;
		}
		else if (id == 2)
		{
			cout << "\nYou found skull bone. Nice one!!!" << endl;
			score += 50;
		}
		else
		{
			cout << "\nYou found ordinary bone. Not bad!!!" << endl;
			score += 20;
		}
	}
	else if (id == 5)//checking for water
	{
		cout << "\nYou found water!!!" << endl;
		Inventory[5]++;
		energy += 1;
	}
	else if (id == 6 || id == 7 || id == 8)//checking for foods
	{
		Inventory[id]++;
		if (id == 6)
		{
			cout << "\nYou found a burger. This night will be good!!!" << endl;
			energy += 4;
		}
		else if (id == 7)
		{
			cout << "\nYou found a nugget. At least you will eat something!!!" << endl;
			energy += 3;
		}
		else 
		{
			cout << "\nYou found a chips. Better than nothing!!!" << endl;
			energy += 2;
		}
	}
	else if (id == 9)//checking for medic
	{
		cout << "\nYou found medical supply. This should protect you from traps!!!" << endl;
		Inventory[9]++;
	}
	int check;
	if (dice == 6)//if player throw to the dice as a 6, it will check all squares
	{
		check=mygrid.ChangeCoordinates(x - 1, y, 0);//same checkings for this coordinates
		if (check == 1 || check == 2 || check == 3)
		{
			Inventory[check]++;
			if (check == 1)
			{
				cout << "\nYou found full body bones. What a treasure!!!" << endl;
				score += 100;
			}
			else if (check == 2)
			{
				cout << "\nYou found skull bone. Nice one!!!" << endl;
				score += 50;
			}
			else
			{
				cout << "\nYou found ordinary bone. Not bad!!!" << endl;
				score += 20;
			}
		}
		else if (check == 5)
		{
			cout << "\nYou found water!!!" << endl;
			Inventory[5]++;
			energy += 1;
		}
		else if (check == 6 || check == 7 || check == 8)
		{
			Inventory[check]++;
			if (check == 6)
			{
				cout << "\nYou found a burger. This night will be good!!!" << endl;
				energy += 4;
			}
			else if (check == 7)
			{
				cout << "\nYou found a nugget. At least you will eat something!!!" << endl;
				energy += 3;
			}
			else
			{
				cout << "\nYou found a chips. Better than nothing!!!" << endl;
				energy += 2;
			}
		}
		else if (check == 9)
		{
			cout << "\nYou found medical supply. This should protect you from traps!!!" << endl;
			Inventory[9]++;
		}

		check = mygrid.ChangeCoordinates(x + 1, y, 0);//same checkings for this coordinates
		if (check == 1 || check == 2 || check == 3)
		{
			Inventory[check]++;
			if (check == 1)
			{
				cout << "\nYou found full body bones. What a treasure!!!" << endl;
				score += 100;
			}
			else if (check == 2)
			{
				cout << "\nYou found skull bone. Nice one!!!" << endl;
				score += 50;
			}
			else
			{
				cout << "\nYou found ordinary bone. Not bad!!!" << endl;
				score += 20;
			}
		}
		else if (check == 5)
		{
			cout << "\nYou found water!!!" << endl;
			Inventory[5]++;
			energy += 1;
		}
		else if (check == 6 || check == 7 || check == 8)
		{
			Inventory[check]++;
			if (check == 6)
			{
				cout << "\nYou found a burger. This night will be good!!!" << endl;
				energy += 4;
			}
			else if (check == 7)
			{
				cout << "\nYou found a nugget. At least you will eat something!!!" << endl;
				energy += 3;
			}
			else
			{
				cout << "\nYou found a chips. Better than nothing!!!" << endl;
				energy += 2;
			}
		}
		else if (check == 9)
		{
			cout << "\nYou found medical supply. This should protect you from traps!!!" << endl;
			Inventory[9]++;
		}

		check = mygrid.ChangeCoordinates(x - 1, y - 1, 0);//same checkings for this coordinates
		if (check == 1 || check == 2 || check == 3)
		{
			Inventory[check]++;
			if (check == 1)
			{
				cout << "\nYou found full body bones. What a treasure!!!" << endl;
				score += 100;
			}
			else if (check == 2)
			{
				cout << "\nYou found skull bone. Nice one!!!" << endl;
				score += 50;
			}
			else
			{
				cout << "\nYou found ordinary bone. Not bad!!!" << endl;
				score += 20;
			}
		}
		else if (check == 5)
		{
			cout << "\nYou found water!!!" << endl;
			Inventory[5]++;
			energy += 1;
		}
		else if (check == 6 || check == 7 || check == 8)
		{
			Inventory[check]++;
			if (check == 6)
			{
				cout << "\nYou found a burger. This night will be good!!!" << endl;
				energy += 4;
			}
			else if (check == 7)
			{
				cout << "\nYou found a nugget. At least you will eat something!!!" << endl;
				energy += 3;
			}
			else
			{
				cout << "\nYou found a chips. Better than nothing!!!" << endl;
				energy += 2;
			}
		}
		else if (check == 9)
		{
			cout << "\nYou found medical supply. This should protect you from traps!!!" << endl;
			Inventory[9]++;
		}

		check = mygrid.ChangeCoordinates(x - 1, y + 1, 0);//same checkings for this coordinates
		if (check == 1 || check == 2 || check == 3)
		{
			Inventory[check]++;
			if (check == 1)
			{
				cout << "\nYou found full body bones. What a treasure!!!" << endl;
				score += 100;
			}
			else if (check == 2)
			{
				cout << "\nYou found skull bone. Nice one!!!" << endl;
				score += 50;
			}
			else
			{
				cout << "\nYou found ordinary bone. Not bad!!!" << endl;
				score += 20;
			}
		}
		else if (check == 5)
		{
			cout << "\nYou found water!!!" << endl;
			Inventory[5]++;
			energy += 1;
		}
		else if (check == 6 || check == 7 || check == 8)
		{
			Inventory[check]++;
			if (check == 6)
			{
				cout << "\nYou found a burger. This night will be good!!!" << endl;
				energy += 4;
			}
			else if (check == 7)
			{
				cout << "\nYou found a nugget. At least you will eat something!!!" << endl;
				energy += 3;
			}
			else
			{
				cout << "\nYou found a chips. Better than nothing!!!" << endl;
				energy += 2;
			}
		}
		else if (check == 9)
		{
			cout << "\nYou found medical supply. This should protect you from traps!!!" << endl;
			Inventory[9]++;
		}

		check = mygrid.ChangeCoordinates(x + 1, y - 1, 0);
		if (check == 1 || check == 2 || check == 3)
		{
			Inventory[check]++;
			if (check == 1)
			{
				cout << "\nYou found full body bones. What a treasure!!!" << endl;
				score += 100;
			}
			else if (check == 2)
			{
				cout << "\nYou found skull bone. Nice one!!!" << endl;
				score += 50;
			}
			else
			{
				cout << "\nYou found ordinary bone. Not bad!!!" << endl;
				score += 20;
			}
		}
		else if (check == 5)
		{
			cout << "\nYou found water!!!" << endl;
			Inventory[5]++;
			energy += 1;
		}
		else if (check == 6 || check == 7 || check == 8)
		{
			Inventory[check]++;
			if (check == 6)
			{
				cout << "\nYou found a burger. This night will be good!!!" << endl;
				energy += 4;
			}
			else if (check == 7)
			{
				cout << "\nYou found a nugget. At least you will eat something!!!" << endl;
				energy += 3;
			}
			else
			{
				cout << "\nYou found a chips. Better than nothing!!!" << endl;
				energy += 2;
			}
		}
		else if (check == 9)
		{
			cout << "\nYou found medical supply. This should protect you from traps!!!" << endl;
			Inventory[9]++;
		}

		check = mygrid.ChangeCoordinates(x + 1, y + 1, 0);//same checkings for this coordinates
		if (check == 1 || check == 2 || check == 3)
		{
			Inventory[check]++;
			if (check == 1)
			{
				cout << "\nYou found full body bones. What a treasure!!!" << endl;
				score += 100;
			}
			else if (check == 2)
			{
				cout << "\nYou found skull bone. Nice one!!!" << endl;
				score += 50;
			}
			else
			{
				cout << "\nYou found ordinary bone. Not bad!!!" << endl;
				score += 20;
			}
		}
		else if (check == 5)
		{
			cout << "\nYou found water!!!" << endl;
			Inventory[5]++;
			energy += 1;
		}
		else if (check == 6 || check == 7 || check == 8)
		{
			Inventory[check]++;
			if (check == 6)
			{
				cout << "\nYou found a burger. This night will be good!!!" << endl;
				energy += 4;
			}
			else if (check == 7)
			{
				cout << "\nYou found a nugget. At least you will eat something!!!" << endl;
				energy += 3;
			}
			else
			{
				cout << "\nYou found a chips. Better than nothing!!!" << endl;
				energy += 2;
			}
		}
		else if (check == 9)
		{
			cout << "\nYou found medical supply. This should protect you from traps!!!" << endl;
			Inventory[9]++;
		}

		check = mygrid.ChangeCoordinates(x, y + 1, 0);//same checkings for this coordinates
		if (check == 1 || check == 2 || check == 3)
		{
			Inventory[check]++;
			if (check == 1)
			{
				cout << "\nYou found full body bones. What a treasure!!!" << endl;
				score += 100;
			}
			else if (check == 2)
			{
				cout << "\nYou found skull bone. Nice one!!!" << endl;
				score += 50;
			}
			else
			{
				cout << "\nYou found ordinary bone. Not bad!!!" << endl;
				score += 20;
			}
		}
		else if (check == 5)
		{
			cout << "\nYou found water!!!" << endl;
			Inventory[5]++;
			energy += 1;
		}
		else if (check == 6 || check == 7 || check == 8)
		{
			Inventory[check]++;
			if (check == 6)
			{
				cout << "\nYou found a burger. This night will be good!!!" << endl;
				energy += 4;
			}
			else if (check == 7)
			{
				cout << "\nYou found a nugget. At least you will eat something!!!" << endl;
				energy += 3;
			}
			else
			{
				cout << "\nYou found a chips. Better than nothing!!!" << endl;
				energy += 2;
			}
		}
		else if (check == 9)
		{
			cout << "\nYou found medical supply. This should protect you from traps!!!" << endl;
			Inventory[9]++;
		}

		check = mygrid.ChangeCoordinates(x, y - 1, 0);//same checkings for this coordinates
		if (check == 1 || check == 2 || check == 3)
		{
			Inventory[check]++;
			if (check == 1)
			{
				cout << "\nYou found full body bones. What a treasure!!!" << endl;
				score += 100;
			}
			else if (check == 2)
			{
				cout << "\nYou found skull bone. Nice one!!!" << endl;
				score += 50;
			}
			else
			{
				cout << "\nYou found ordinary bone. Not bad!!!" << endl;
				score += 20;
			}
		}
		else if (check == 5)
		{
			cout << "\nYou found water!!!" << endl;
			Inventory[5]++;
			energy += 1;
		}
		else if (check == 6 || check == 7 || check == 8)
		{
			Inventory[check]++;
			if (check == 6)
			{
				cout << "\nYou found a burger. This night will be good!!!" << endl;
				energy += 4;
			}
			else if (check == 7)
			{
				cout << "\nYou found a nugget. At least you will eat something!!!" << endl;
				energy += 3;
			}
			else
			{
				cout << "\nYou found a chips. Better than nothing!!!" << endl;
				energy += 2;
			}
		}
		else if (check == 9)
		{
			cout << "\nYou found medical supply. This should protect you from traps!!!" << endl;
			Inventory[9]++;
		}
	}

}

void Archeologist::ChangeEnergy()//adjusting energy at the end of the turn
{
	float energyChange = -1;
	CheckInjury();
	if (Inventory[6] > 0 && Inventory[7] > 0 && Inventory[8] > 0)
	{
		energyChange++;
	}
	if (injury)
	{
		energyChange = energyChange - 0.25;
	}
	energy += energyChange;

}

void Archeologist::PrintInventory()
{
	cout << "Inventory:\nWater: " << Inventory[5] << "\nBurger: " << Inventory[6] << "\nNuggets: " << Inventory[7] << "\nChips: " << Inventory[8];
	cout << "\nMedical Supplies: " << Inventory[9] << endl;
	if (injury == 1)
	{
		cout << "You are injury!!! Need to find Medical Supplies" << endl;
	}
}

void Archeologist::CheckInjury()
{
	if (injury == 1 && Inventory[9] > 0)
	{
		injury = 0;
	}
}