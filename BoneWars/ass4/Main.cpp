#include"Archeologist.h"
#include<time.h>

int main()
{
	int size;
	cout << "Enter the size of grid";
	cin >> size;
	Grid mygrid(size);
	if (size < 5)
	{
		size = 5;
	}
	srand(time(NULL));
	float energy=rand()%size+size;
	Archeologist p1('A', energy, 0, 0, 23);
	Archeologist p2('B', energy, size - 1, size - 1, 24);
	int MaxScore = mygrid.CalculateBones(), turn = 1,x,y,dice,check;
	cout << "Welcome to the BONE WARS!!!\n\nEach player started with "<<energy<<" energy.\n\n"<<endl << endl;
	while ((p1.GetEnergy() != 0 || p2.GetEnergy() != 0) && p1.GetScore() < MaxScore / 2 + 1 && p2.GetScore() < MaxScore / 2 + 1) 
	{
		cout << "Turn: " << turn << endl;
		mygrid.PrintBoard();
		if (p1.GetEnergy() >= 1) 
		{
			cout << "Player 1\nEnter the coordinates(0-" << size - 1 << "): ";
			cin >> x;
			cin >> y;
			while (x >= size || y >= size)
			{
				cout << "You entered invalid coordinates please try again: ";
				cin >> x;
				cin >> y;
			}
			dice = rand() % 6 + 1;
			cout << "\nYour dice is: " << dice << endl;
			check = mygrid.ChangeCoordinates(x, y, 23);
			p1.AddItem(check, dice, x, y, mygrid);
			cout << "Remaining energy for p1 is " << p1.GetEnergy() << endl;
			p1.PrintInventory();
		}
		mygrid.PrintBoard();
		if (p2.GetEnergy() >= 1)
		{
			cout << "Player 2\nEnter the coordinates(0-" << size - 1 << "): ";
			cin >> x;
			cin >> y;
			while (x >= size || y >= size)
			{
				cout << "You entered invalid coordinates please try again: ";
				cin >> x;
				cin >> y;
			}
			dice = rand() % 6 + 1;
			cout << "\nYour dice is: " << dice << endl;
			check = mygrid.ChangeCoordinates(x, y, 24);
			p2.AddItem(check, dice, x, y, mygrid);
			cout << "Remaining energy for p2 is " << p2.GetEnergy() << endl;
			p2.PrintInventory();
		}
		cout << "Scores:\nPlayer1: " << p1.GetScore() << "\nPlayer2: " << p2.GetScore() << endl;
		turn++;
	}
	if (p1.GetScore() > p2.GetScore())
	{
		cout << "Player 1 has won the war CONGRATULATIONS!!!\n\nTotal Scores:Player1: " << p1.GetScore() << "\nPlayer2: " << p2.GetScore() << endl;
	}
	else if (p2.GetScore() > p1.GetScore())
	{
		cout << "Player 2 has won the war CONGRATULATIONS!!!\n\nTotal Scores:Player1: " << p1.GetScore() << "\nPlayer2: " << p2.GetScore() << endl;
	}
	else
	{
		cout << "Draw!!!" << endl;
	}

	return 0;
}