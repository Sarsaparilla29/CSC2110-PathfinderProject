#include <iostream>
#include "cell.h"
#include "pathfinder.h"

int main(){
    // create map
    cell fullmap[5][6];
    // fill the map with walls (1)
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            fullmap[i][j].setCellType(1);
        }
    }

    std::cout << "After setting all cells to wall(1)\n";
    for(int i = 0; i < 5; i++){
        std::cout << " ";
        for(int j = 0; j < 6; j++){
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
    fullmap[4][1].setCellType(2);
    // need to rebuild solution in VS every time a change is made to the map

    // initial position will be (1,0)
    
    std::cout << "Created Path\n";
    for(int i = 0; i < 5; i++){
        std::cout << " ";
        for(int j = 0; j < 6; j++){
            std::cout << fullmap[i][j].getCellType() << " ";
        }
        std::cout << "\n";
    }
    
    pathfinder pf(&fullmap[0][0],1,0);
    pf.search();
    std::cout << "\nEND\n";

    std::cout << "After Search\n";
    for (int i = 0; i < 5; i++) {
        std::cout << " ";
        for (int j = 0; j < 6; j++) {
            std::cout << fullmap[i][j].getCellType() << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
