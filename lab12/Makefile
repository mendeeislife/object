all:main

planet.o: main.h planet.cpp
	g++ -c planet.cpp -o planet.o
vector.o: main.h vector.cpp
	g++ -c vector.cpp -o vector.o
functions.o: main.h functions.cpp
	g++ -c functions.cpp -o functions.o -lncurses
main.o: main.cpp main.h
	g++ -c main.cpp -o main.o
main: main.o vector.o planet.o functions.o
	g++ main.o vector.o planet.o functions.o -o main -lncurses
clean: 
	rm -v *.o main