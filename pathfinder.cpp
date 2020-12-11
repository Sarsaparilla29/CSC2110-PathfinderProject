#include "Pathfinder.h"

void pathfinder::search()
{
	do //Still wrapping my head around this, hopefully we can discuss during the next meeting
	{
		switch (currentPosition.getCellType())
		{
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
