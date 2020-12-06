#include <iostream>
#include "cell.h"
#include "position.h"
#include "pathfinder.h"

int main(){
    // cell objects
    /*cell cellObj0 = 0;
    cell cellObj1 = 1;
    cell cellObj2 = 2;
    cell cellObj3 = 3;*/

    // pathfinder object
    pathfinder pathObj;

    // array for map 5 rows 6 columns
    /*int arr[5][6] = {
        {cellObj0,cellObj0,cellObj0,cellObj0,cellObj0,cellObj1;}
        {cellObj1,cellObj1,cellObj0,cellObj1,cellObj0,cellObj1;}
        {cellObj0,cellObj0,cellObj0,cellObj1,cellObj0,cellObj1;}
        {cellObj0,cellObj1,cellObj1,cellObj1,cellObj0,cellObj1;}
        {cellObj1,cellObj1,cellObj1,cellObj2,cellObj0,cellObj1;}
    };*/

    cell arr[5][6] = {
        {cell(0,0),cell(0,1),cell(0,2),cell(0,3),cell(0,4),cell(0,5)}
        {cell(1,0),cell(1,1),cell(1,2),cell(1,3),cell(1,4),cell(1,5)}
        {cell(2,0),cell(2,1),cell(2,2),cell(2,3),cell(2,4),cell(2,5)}
        {cell(3,0),cell(3,1),cell(3,2),cell(3,3),cell(3,4),cell(3,5)}
        {cell(4,0),cell(4,1),cell(4,2),cell(4,3),cell(4,4),cell(4,5)}
    };

    // easier visualization of map
    /*int arr[5][6] = {
        {0,0,0,0,0,1}
        {1,1,0,1,0,1}
        {0,0,0,1,0,1}
        {0,1,1,1,0,1}
        {1,1,1,2,0,1}
    };*/

    // pointer to array
    int *arrPtr;
    arrPtr = &arr;

    // search function
    pathObj.search();

    // end of program
    return 0;
}
