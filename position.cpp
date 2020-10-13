#include <iostream>
#include "position.h"

void posiiton::setColumn(int acolumn){
    column = acolumn;
}
void position::setRow(int arow){
    row = arow;
}
int position::getColumn(){
    return column;
}
int position::getRow(){
    return row;
}
position::position(){
    column = 0;
    row = 0;
}
position::position(int arow, int acolumn){
    column = acolumn;
    row = arow;
}
