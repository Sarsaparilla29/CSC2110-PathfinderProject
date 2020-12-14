#include <iostream>
#include <iomanip>
#include "position.h"

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
