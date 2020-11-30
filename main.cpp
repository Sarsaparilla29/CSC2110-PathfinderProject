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

    // array for map 5 rows 6 columns
    int arr[5][6] = {
        {cellObj0,cellObj0,cellObj0,cellObj0,cellObj0,cellObj1}
        {cellObj1,cellObj1,cellObj0,cellObj1,cellObj0,cellObj1}
        {cellObj0,cellObj0,cellObj0,cellObj1,cellObj0,cellObj1}
        {cellObj0,cellObj1,cellObj1,cellObj1,cellObj0,cellObj1}
        {cellObj1,cellObj1,cellObj1,cellObj2,cellObj0,cellObj1}
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
    &arrPtr = arr;

    // search function
    pathObj.search();






    // end of program
    return 0;
}
