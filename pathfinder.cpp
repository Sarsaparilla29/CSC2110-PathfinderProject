#include "Pathfinder.h"

void pathfinder::display()
{
	cout << "(" << currentPosition.getColumn() << currentPosition.getRow() << ") -> ";
}

void pathfinder::search() //FUnction for schmovement
{
	display(); //For initial position
	if(dfs(currentPosition) == true)
	{
		display();
	}
	else
	{
		cout << "I'm sorry friend, no path was found :(" << endl;
	}
}

bool pathfinder::dfs(position p)
{
	const int rowSize = 5;
	const int columnSize = 6;

	//Order of action: up(decrease row), right(increase column), down(increase row value), left(decrease column)


	//position objects to the positions around the current position
	position upPosition(p.getRow() - 1, p.getColumn());
	position rightPosition(p.getRow(), p.getColumn() + 1);
	position downPosition(p.getRow() + 1, p.getColumn());
	position leftPosition(p.getRow(), p.getColumn() - 1);

	//check for goal
	if (p.getCellType() == 2)
	{
		display();
		return true;
	}

	//up
	if (p.getRow() - 1 >= 0 && checkCellType(p.getRow() - 1) != 1 && checkCellType(p.getRow() - 1) != 3 && dfs(upPosition))
	{
		//display();
		return true;
	}
	//right
	else if (p.getColumn() + 1 >= 0 && checkCellType(p.getColumn() + 1) != 1 && checkCellType(p.getColumn() + 1) != 3 && dfs(rightPosition))
	{
		return true;
	}
	//down
	else if (p.getRow() + 1 >= 0 && checkCellType(p.getRow() + 1) != 1 && checkCellType(p.getRow() + 1) != 3 && dfs(downPosition))
	{
		return true;
	}
	//left
	else if (p.getColumn() - 1 >= 0 && checkCellType(p.getColumn() - 1) != 1 && checkCellType(p.getColumn() - 1) != 3 && dfs(leftPosition))
	{
		return true;
	}

	return false;
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
