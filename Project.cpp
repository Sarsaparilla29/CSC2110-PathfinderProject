// Project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class cell
{
private:
    int cellType;
public:
    void setCellType(int acellType)
    {
        cellType = acellType;
    }

    int getCellType()
    {
        return cellType;
    }

    cell()
    {
        cellType = 0;
    }
};

int main()
{

}

