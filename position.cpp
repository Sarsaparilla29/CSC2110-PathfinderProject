#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
using namespace std;
#include "Position.h"
#include "Cell.h"
#include "Pathfinder.h"


void position::setColumn(int acolumn) 
{
	column = acolumn;
}

int position::getColumn()
{
	return column;
}

void position::setRow(int arow) 
{
	row = arow;
}

int position::getRow() 
{
	return row;
}

position::position() 
{
	row = 0;
	column = 0;
}

position::position(int arow, int acolumn) 
{
	row = arow;
	column = acolumn;
}
