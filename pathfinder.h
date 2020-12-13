//#pragma once
#include <vector>
#include <string>
#include "cell.h"
#include "position.h"

class pathfinder {
    private:
        cell* map;
        position currentPosition;
        void display();
        bool dfs(position p, std::vector<std::string>& v);
    public:
        void search();
        pathfinder(cell* pmap, int initialColumn, int initialRow); //constructor
};
