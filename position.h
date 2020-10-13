#pragma once

class position {
private:
    int column;
    int row;
public:
    void setColumn(int acolumn); //mutator for column
    void setRow(int arow); // mutator for row
    int getColumn(); // accessor for column
    int getRow(); //accessor for row
    position(); //initialize row and column to 0
    position(int arow, int acolumn); //initializes row and column using arguments
};
