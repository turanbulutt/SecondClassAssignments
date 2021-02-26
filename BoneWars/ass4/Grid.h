#include<iostream>

using namespace std;

class Grid
{
protected:
	int size;
	int** board;
	/*int* bones;
	int* traps;
	int* foods;
	int* medic;
	int* water;*/
	//that was the implementation of arrays about resources
public:
	Grid(int);
	void DeployResources(int**);
	void PrintBoard();
	int CalculateBones();
	int ChangeCoordinates(int,int,int);
	void AppearResources(int);
};

//full bone==1
//skull bone==2
//ordinary bone==3
//traps==4
//water==5
//burger==6
//nuggets==7
//chips=8
//medic==9

//-n +n -- -+ n+ n- +- ++