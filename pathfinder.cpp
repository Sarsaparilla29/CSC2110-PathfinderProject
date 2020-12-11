#include "Pathfinder.h"

void pathfinder::display()
{
	cout << "(" << currentPosition.getColumn() << currentPosition.getRow() << "), ";
}

void pathfinder::search()
{
	do //Still wrapping my head around this, hopefully we can discuss during the next meeting
	{
		switch (currentPosition.getCellType())
		{
		case 0:
			cout << "This cell is empty";
			break;
		case 1:
			cout << "This is a wall";
			break;
		case 2:
			cout << "This is the goal";
			break;
		case 3:
			cout << "I've been here before";
			break;
		}

	} while (0);
}

pathfinder::pathfinder(int* pmap, int inC, int inR)
{
	map = pmap;
	currentPosition.setColumn(inC);
	currentPosition.setRow(inR);
}
