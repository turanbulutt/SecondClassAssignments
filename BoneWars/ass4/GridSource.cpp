#include"Grid.h"
#include<time.h>

Grid::Grid(int sizee)
{
	size = sizee;
	if (size < 5)
	{
		cout << "Grid size set as 5 because you entered below 5." << endl;
		size = 5;
	}
	cout << "\n\n" << endl;
	board = new int*[size];
	for (int i = 0; i < size; i++)
	{
		board[i] = new int[size];
	}
	DeployResources(board);
}

void Grid::DeployResources(int **board)
{
	srand(time(NULL));
	//set board 0
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			board[i][j] = 0;
		}
	}
	board[0][0] = 23; //set player 1
	board[size - 1][size - 1] = 24; //set player 2
	int row, collumn, part, check = 0;
	for (int i = 0; i < 3 * size * size / 25; i++)//set bones and foods
	{
		while (check == 0)//for setting bones without intersection
		{
			part = rand() % 3 + 1;
			row = rand() % size;
			collumn = rand() % size;
			if (part == 1 && board[row][collumn] == 0) //if part equals to 1 we set bone as a ordinary bone=3
			{
				board[row][collumn] = 3;
				check = 1;
			}
			else if (part == 2 && board[row][collumn] == 0) // if part equals to 2 we set bone as a skull bone=2
			{
				board[row][collumn] = 2;
				check = 1;
			}
			else if (part == 3 && board[row][collumn] == 0) // if part equals to 3 we set bone as a full bone and we have to check all side because the size equal to 2,full bone=1
			{
				if (row != size - 1 && board[row + 1][collumn] == 0)
				{
					board[row + 1][collumn] = 1;
					board[row][collumn] = 1;
					check = 1;
				}
				else if (row != 0 && board[row - 1][collumn] == 0)
				{
					board[row - 1][collumn] = 1;
					board[row][collumn] = 1;
					check = 1;
				}
				else if (collumn != size - 1 && board[row][collumn + 1] == 0)
				{
					board[row][collumn + 1] = 1;
					board[row][collumn] = 1;
					check = 1;
				}
				else if (row != 0 && board[row][collumn - 1] == 0)
				{
					board[row][collumn - 1] = 1;
					board[row][collumn] = 1;
					check = 1;
				}
			}
		}
		check = 0;
		while (check == 0)//for setting foods without intersection
		{
			part = rand() % 3 + 1;
			row = rand() % size;
			collumn = rand() % size;
			if (part == 1 && board[row][collumn] == 0)// set food as a chips=8
			{
				board[row][collumn] = 8;
				check = 1;
			}
			else if (part == 2 && board[row][collumn] == 0)//set food as a burger=6
			{
				if (row != size - 1 && board[row + 1][collumn] == 0)
				{
					board[row + 1][collumn] = 6;
					board[row][collumn] = 6;
					check = 1;
				}
				else if (row != 0 && board[row - 1][collumn] == 0)
				{
					board[row - 1][collumn] = 6;
					board[row][collumn] = 6;
					check = 1;
				}
				else if (collumn != size - 1 && board[row][collumn + 1] == 0)
				{
					board[row][collumn + 1] = 6;
					board[row][collumn] = 6;
					check = 1;
				}
				else if (row != 0 && board[row][collumn - 1] == 0)
				{
					board[row][collumn - 1] = 6;
					board[row][collumn] = 6;
					check = 1;
				}
			}
			else if (part == 3 && board[row][collumn] == 0)//set food as a nuggets=7
			{
				if (row != size - 1 && board[row + 1][collumn] == 0)
				{
					board[row + 1][collumn] = 7;
					board[row][collumn] = 7;
					check = 1;
				}
				else if (row != 0 && board[row - 1][collumn] == 0)
				{
					board[row - 1][collumn] = 7;
					board[row][collumn] = 7;
					check = 1;
				}
				else if (collumn != size - 1 && board[row][collumn + 1] == 0)
				{
					board[row][collumn + 1] = 7;
					board[row][collumn] = 7;
					check = 1;
				}
				else if (row != 0 && board[row][collumn - 1] == 0)
				{
					board[row][collumn - 1] = 7;
					board[row][collumn] = 7;
					check = 1;
				}
			}
		}
		check = 0;
	}
	check = 0;
	for (int i = 0; i < 2 * size * size / 25; i++)// for set water and trap
	{
		while (check == 0)//for set traps=4  without intersection
		{
			row = rand() % size;
			collumn = rand() % size;
			if (board[row][collumn] == 0)
			{
				board[row][collumn] = 4;
				check = 1;
			}
		}
		check = 0;
		while (check == 0) //for set water=5  without intersection
		{
			row = rand() % size;
			collumn = rand() % size;
			if (board[row][collumn] == 0)
			{
				board[row][collumn] = 5;
				check = 1;
			}
		}
		check = 0;
	}
	check = 0;
	for (int i = 0; i < size * size / 25; i++)// for set medic
	{
		while (check == 0) //for set medic=9  without intersection
		{
			row = rand() % size;
			collumn = rand() % size;
			if (board[row][collumn] == 0)
			{
				board[row][collumn] = 9;
				check = 1;
			}
		}
		check = 0;
	}
}

void Grid::PrintBoard()
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == 23) //player 1
			{
				cout << "P1\t";
			}
			else if (board[i][j] == 24)//player 2
			{
				cout << "P2\t";
			}
			else if (board[i][j] == 11)//full bone
			{
				cout << "F\t";
			}
			else if (board[i][j] == 12)//skull bone
			{
				cout << "S\t";
			}
			else if (board[i][j] == 13)//ordinary bone
			{
				cout << "O\t";
			}
			else if (board[i][j] == 14)//traps
			{
				cout << "T\t";
			}
			else if (board[i][j] == 15)//water
			{
				cout << "W\t";
			}
			else if (board[i][j] == 16)//burger
			{
				cout << "B\t";
			}
			else if (board[i][j] == 17)//nugget
			{
				cout << "N\t";
			}
			else if (board[i][j] == 18)//chips
			{
				cout << "C\t";
			}
			else if (board[i][j] == 19)//medic
			{
				cout << "M\t";
			}
			else//empty
			{
				cout << "-\t";
			}
		}
		cout <<"\n"<< endl;
	}
}

int Grid::CalculateBones()
{
	int score = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == 1)
			{
				score += 100;
			}
			else if (board[i][j] == 2)
			{
				score += 50;
			}
			else if (board[i][j] == 3)
			{
				score += 20;
			}
		}
	}
	return score;
}

int Grid::ChangeCoordinates(int x,int y,int ID)
{
	int retri = board[x][y];
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == ID)
			{
				board[i][j] = 0;
			}
		}
	}
	board[x][y] = ID;
	if (retri == 1 || retri == 6 || retri == 7)
	{
		if (board[x - 1][y] == retri)
		{
			board[x - 1][y] = 0;
		}
		else if (board[x + 1][y] == retri)
		{
			board[x + 1][y] = 0;
		}
		else if (board[x][y - 1] == retri)
		{
			board[x][y - 1] = 0;
		}
		else if (board[x][y + 1] == retri)
		{
			board[x][y + 1] = 0;
		}
	}
	AppearResources(retri);
	return retri;
}

void Grid::AppearResources(int id)
{
	id = id % 10;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == id && id != 0)
			{
				board[i][j] += 10;
			}
		}
	}
}