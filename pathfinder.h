#pragma once
#include "position.h"
class pathfinder
{
private:
	int* map;
	position currentPosition;
	void display();

public:
	void search();
	bool dfs(position p);
	void search2();
	pathfinder(int* pmap, int initialColumn, int initialRow); //constructor
	int checkCellType(int c);

};
