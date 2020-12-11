#include "Pathfinder.h"

void pathfinder::display()
{
	cout << "(" << currentPosition.getColumn() << currentPosition.getRow() << ") -> ";
}

void pathfinder::search() //Function for the schmooving
{
	do //Still wrapping my head around this, hopefully we can discuss during the next meeting
	{
		if (currentPosition.getColumn() < *map)
		{
			if (checkCellType(currentPosition.getColumn() + 1) == 0)
			{
				currentPosition.setCellType(3); //Marks it as visited
			}

			else if (checkCellType(currentPosition.getColumn() + 1) == 2)
			{
				break; //Ends the function call to end at the goal
			}

			else if (checkCellType(currentPosition.getColumn() + 1) == 3)
			{
				cout << "We been here cuz."; //Something when the programs goes to an already visted cell
			}
		}
		
	} while(currentPosition.getRow() != 1 || currentPosition.getColumn() != 1); //Stops when met with a wall
}

pathfinder::pathfinder(int* pmap, int inC, int inR) //constructor
{
	map = pmap;
	currentPosition.setColumn(inC);
	currentPosition.setRow(inR);
}

int pathfinder::checkCellType(int c) //Function to check what type of cell we're at
{
	switch (c)
	{
	case 0:
		cout << "This cell is empty";
		return 0;
		break;
	case 1:
		cout << "This is a wall";
		return 1;
		break;
	case 2:
		cout << "This is the goal";
		return 2;
		break;
	case 3:
		cout << "I've been here before";
		return 3;
		break;
	}
}
