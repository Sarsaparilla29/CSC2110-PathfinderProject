#include <iostream>
#include "cell.h"

void cell::setCellType(int acellType){
    cellType = acellType;
}
int cell::getCellType(){
    return cellType;
}
cell::cell(){
    cellType = 0;
}
