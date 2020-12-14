output: main.o cell.o pathfinder.o position.o
	g++ main.o cell.o pathfinder.o position.o -o output
main.o: main.cpp
	g++ -c main.cpp
cell.o: cell.cpp cell.h
	g++ -c cell.cpp cell.h
pathfinder.o: pathfinder.cpp pathfinder.h
	g++ -c pathfinder.cpp pathfinder.h
position.o: position.cpp position.h
	g++ -c position.cpp position.h
clean:
	rm *.o *.gch output
