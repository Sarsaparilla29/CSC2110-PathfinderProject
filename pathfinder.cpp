#include <iostream>
#include "pathfinder.h"
#include <vector>
#include <string>

void pathfinder::display()
{
	cout << "(" << currentPosition.getColumn() << currentPosition.getRow() << ") -> ";
}

void pathfinder::search(){
    // debugging statement
    std::cout << "reached search function" << std::endl;
    // call the dfs algorithm
    std::vector<std::string> solution;

    if(dfs(currentPosition, solution)) {
        // print the solution
        std::cout << solution.back() << "\n" << std::endl;
        // how we can add the inital position to the vector?

        std::cout << "Solution: ";
        for(int i = solution.size(); i >= 0; i--){
            std::cout << solution[i] << std::endl;
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
    std::cout << "reached dfs function" << std::endl;
    const int rowSize = 5;
    const int columnSize = 6;
    
    cell* currentCell = map + (p.getRow()*columnSize + p.getColumn());
    // Check if this state is the goal (solution)
    if(currentCell->getCellType() == 2) { // is this the goal?
        v.push_back("currentPosition"); // position in the format (leftPosition.getRow(), leftPosition.getColumn())->
        return true;
    }
    // Mark this state as visited(3)
    currentCell->setCellType(3);
    // Perform actions "when possible" 
    // Order of actions: left (decrease column value), right (increase column value), 
    //                   up (decrease row value),      down (increase row value)
    
    // 1) is the next position within the array boundaries
    // 2) cells that the alogorithm should not visit
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
        std::cout << "leftPosition\n";
        v.push_back("leftPosition"); // position in the format (leftPosition.getRow(), leftPosition.getColumn())->
        return true;
    }
    else if(p.getColumn()+1 >=0 && rightCell->getCellType()!=1 && rightCell->getCellType()!=3 && dfs(rightPosition,v)) { // right
        std::cout << "rightPosition\n";
        v.push_back("rightPosition"); // position in the format (leftPosition.getRow(), leftPosition.getColumn())->
        return true;
    }
    else if (p.getRow()-1 >=0 && upCell->getCellType()!=1 && upCell->getCellType()!=3 && dfs(upPosition,v)) { // up
        std::cout << "upPosition\n";
        v.push_back("upPosition"); // position in the format (leftPosition.getRow(), leftPosition.getColumn())->
        return true;
    }
    else if (p.getRow()+1 >=0 && downCell->getCellType()!=1 && downCell->getCellType()!=3 && dfs(downPosition,v)) { // down
        std::cout << "downPosition\n";
        v.push_back("downPosition"); // position in the format (leftPosition.getRow(), leftPosition.getColumn())->
        return true;
    }

    return false;
}

pathfinder::pathfinder(cell* pmap, int inC, int inR) //constructor
{
	map = pmap;
	currentPosition.setColumn(inC);
	currentPosition.setRow(inR);
}

/*void pathfinder::search() //Function for the schmooving
{
	do //Still wrapping my head around this, hopefully we can discuss during the next meeting
	{
		if (currentPosition.getColumn() < *map)
		{
			if (checkCellType(currentPosition.getColumn() + 1) == 0)
			{
				currentPosition.setCellType(3); //Marks it as visited
			}

			else if (checkCellType(currentPosition.getColumn() + 1) == 2)
			{
				break; //Ends the function call to end at the goal
			}

			else if (checkCellType(currentPosition.getColumn() + 1) == 3)
			{
				cout << "We been here cuz."; //Something when the programs goes to an already visted cell
			}
		}
		
	} while(currentPosition.getRow() != 1 || currentPosition.getColumn() != 1); //Stops when met with a wall
}*/


/*int pathfinder::checkCellType(int c) //Function to check what type of cell we're at
{
	switch (c)
	{
	case 0:
		cout << "This cell is empty";
		return 0;
		break;
	case 1:
		cout << "This is a wall";
		return 1;
		break;
	case 2:
		cout << "This is the goal";
		return 2;
		break;
	case 3:
		cout << "I've been here before";
		return 3;
		break;
	}
}*/
