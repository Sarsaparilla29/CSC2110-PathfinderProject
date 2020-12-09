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
	pathfinder(int* pmap, int* initialColumn, int* initialRow); //constructor

};
