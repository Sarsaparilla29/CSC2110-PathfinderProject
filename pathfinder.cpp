#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "pathfinder.h"

void pathfinder::display()
{
	cout << "(" << currentPosition.getColumn() << "," << currentPosition.getRow() << ") -> ";
}

void pathfinder::search(){
    // debugging statement
    //std::cout << "reached search function" << std::endl;
    // call the dfs algorithm
    std::vector<std::string> solution;

    if(dfs(currentPosition, solution)) {
        // print the solution
        //std::cout << solution.back() << "\n" << std::endl;
        // how we can add the inital position to the vector?

        std::cout << "Solution: ";
        // reverse vector output 
        for (auto rvout = solution.crbegin(); rvout != solution.crend(); ++rvout) {
            std::cout << "\n" << *rvout;
        }
    }
    else{
        std::cout << "No path to the solution was found.\n";
    }
    // use a for loop to print contents of vector
}
//            pos   x-structure  x-boundaries 
bool pathfinder::dfs(position p, std::vector<std::string>& v){
    // debugging statement
    //std::cout << "reached dfs function" << std::endl;
    const int rowSize = 5;
    const int columnSize = 6;
    
    cell* currentCell = map + (p.getRow()*columnSize + p.getColumn());

    //std::string fRow = (std::string)p.getRow();
    //std::string fColumn = (std::string)p.getColumn();
    std::stringstream buffer;
    buffer << "(" << p.getRow() << "," << p.getColumn() << ")" << " goal";
    // Check if this state is the goal (solution)
    if(currentCell->getCellType() == 2) { // is this the goal?
        v.push_back(buffer.str()); // position in the format (leftPosition.getRow(), leftPosition.getColumn())->
        return true;
    }
    // Mark this state as visited(3)
    currentCell->setCellType(3);
    // Perform actions "when possible" 
    // Order of actions: left (decrease column value), right (increase column value), 
    //                   up (decrease row value),      down (increase row value)
    
    // 1) is the next position within the array boundaries
    // 2) cells that the algorithm should not visit
    //    a) wall
    //    b) visited
    // 3) check whether next position contains the path to the solution 
    //    (call dfs again with next position)
    
    // cell pointers to positions around current position
    cell *leftCell = map + (p.getRow()*columnSize + (p.getColumn() - 1));
    cell *rightCell = map + (p.getRow()*columnSize + (p.getColumn() + 1));
    cell *upCell = map + ((p.getRow() - 1)*columnSize + p.getColumn());
    cell *downCell = map + ((p.getRow() + 1)*columnSize + p.getColumn());

    // position objects to the position around current position
    position leftPosition(p.getRow(), p.getColumn()-1);
    position rightPosition(p.getRow(), p.getColumn()+1);
    position upPosition(p.getRow()-1, p.getColumn());
    position downPosition(p.getRow()+1, p.getColumn());

    if(p.getColumn()-1 >=0 && leftCell->getCellType()!=1 && leftCell->getCellType()!=3 && dfs(leftPosition,v)){ // left
        // this is part of the path of the solution
        //std::cout << "leftPosition\n";
        std::stringstream leftBuffer;
        leftBuffer << "(" << p.getRow() << "," << p.getColumn() << ")" << " left";
        v.push_back(leftBuffer.str()); // position in the format (leftPosition.getRow(), leftPosition.getColumn())->
        return true;
    }
    else if(p.getColumn()+1 >=0 && rightCell->getCellType()!=1 && rightCell->getCellType()!=3 && dfs(rightPosition,v)) { // right
        //std::cout << "rightPosition\n";
        std::stringstream rightBuffer;
        rightBuffer << "(" << p.getRow() << "," << p.getColumn() << ")" << " right";
        v.push_back(rightBuffer.str()); // position in the format (leftPosition.getRow(), leftPosition.getColumn())->
        return true;
    }
    else if (p.getRow()-1 >=0 && upCell->getCellType()!=1 && upCell->getCellType()!=3 && dfs(upPosition,v)) { // up
        //std::cout << "upPosition\n";
        std::stringstream upBuffer;
        upBuffer << "(" << p.getRow() << "," << p.getColumn() << ")" << " up";
        v.push_back(upBuffer.str()); // position in the format (leftPosition.getRow(), leftPosition.getColumn())->
        return true;
    }
    else if (p.getRow()+1 >=0 && downCell->getCellType()!=1 && downCell->getCellType()!=3 && dfs(downPosition,v)) { // down
        //std::cout << "downPosition\n";
        std::stringstream downBuffer;
        downBuffer << "(" << p.getRow() << "," << p.getColumn() << ")" << " down";
        v.push_back(downBuffer.str()); // position in the format (leftPosition.getRow(), leftPosition.getColumn())->
        return true;
    }

    return false;
}

pathfinder::pathfinder(cell* pmap, int inR, int inC) //constructor
{
	map = pmap;
	currentPosition.setColumn(inC);
	currentPosition.setRow(inR);
}

