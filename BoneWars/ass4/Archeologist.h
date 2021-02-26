#include"Bones.h"
#include<vector>
#include"Grid.h"

class Archeologist 
{
private:
	int score;
	int x;
	int y;
	float energy;
	int IDNumber;
	int *Inventory;
	char letter;
	int injury;
public:
	Archeologist(char,float,int,int,int);
	int GetScore();
	float GetEnergy();
	void AddItem(int,int,int,int,Grid&);
	void ChangeEnergy();
	void PrintInventory();
	void CheckInjury();
};