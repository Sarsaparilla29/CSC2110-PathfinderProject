#include <iostream>
#include "cell.h"
//#include "position.h"
#include "pathfinder.h"

int main(){
    // from zoom meeting dec 3
    // create map
    cell fullmap[5][6];
    // fill the map with walls (1)
    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 7; j++)
            fullmap[i][j].setCellType(1);

    std::cout << "After setting all cells to wall(1)\n";
    for(int i = 0; i < 6; i++){
        std::cout << " ";
        for(int j = 0; j < 7; j++){
            std::cout << fullmap[i][j].getCellType() << " ";
        }
        std::cout << "\n";
    }

    // updating specific cells with empty(0) or goal(2) values
    fullmap[1][0].setCellType(0);
    fullmap[1][1].setCellType(0);
    fullmap[1][2].setCellType(0);
    fullmap[1][3].setCellType(0);
    fullmap[1][4].setCellType(0);
    fullmap[1][5].setCellType(0);
    fullmap[2][5].setCellType(0);
    fullmap[3][5].setCellType(0);
    fullmap[3][4].setCellType(0);
    fullmap[3][3].setCellType(0);
    fullmap[3][2].setCellType(0);
    fullmap[4][2].setCellType(0);
    fullmap[5][2].setCellType(2);
    //fullmap[0][6].setCellType(1); // set manually to a wall(1)

    //fullmap[0][6].setCellType(1); // for some reason this cell changes to 0 when [1][0] is set to 0
    // initial position will be 1,0
    
    std::cout << "Created Path\n";
    for(int i = 0; i < 6; i++){
        std::cout << " ";
        for(int j = 0; j < 7; j++){
            std::cout << fullmap[i][j].getCellType() << " ";
        }
        std::cout << "\n";
    }
    
    pathfinder pf(&fullmap[0][0],0,1);
    pf.search();
    std::cout << "END\n";



    //cellObj.setCellType(arr[0][0]);

    // pointer to array
    //int *Ptr = &arr[0][0];

    // search function
    //pathObj.search();

    // end of program
    //return 0;
}
