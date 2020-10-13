#pragma once

class cell {
private:
    int cellType; //0 means empty, 1 means wall, 2 means goal, 3 means visited cell
public:
    void setCellType(int acellType); //mutator for cellType
    int getCellType(); //accessor for cellType
    cell(); //initialize cellType to 0
};
