#include <iostream>
#include "cell.h"
#include "position.h"
#include "pathfinder.h"

int main(){
    // cell objects
    cell cellObj0 = 0;
    cell cellObj1 = 1;
    cell cellObj2 = 2;
    cell cellObj3 = 3;

    // pathfinder object
    pathfinder pathObj;

    // array for map
    int arr[5][6] = {
        {cellObj1,cellObj1,cellObj1,cellObj1,cellObj1,cellObj1}
        {cellObj0,cellObj0,cellObj0,cellObj0,cellObj0,cellObj1}
        {cellObj1,cellObj1,cellObj1,cellObj1,cellObj0,cellObj1}
        {cellObj1,cellObj0,cellObj0,cellObj0,cellObj0,cellObj1}
        {cellObj1,cellObj2,cellObj1,cellObj1,cellObj1,cellObj1}
    };

    // pointer to array
    int *arrPtr;
    &arrPtr = arr;

    // search function
    pathObj.search();


    /*int arr[5][6] = {
        {1,1,1,1,1,1}
        {0,0,0,0,0,1}
        {1,1,1,1,0,1}
        {1,0,0,0,0,1}
        {1,2,1,1,1,1}
    };*/




    // end of program
    return 0;
}
