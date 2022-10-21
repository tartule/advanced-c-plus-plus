main: main.o router.o computer.o
	g++ -o main main.o router.o computer.o -Wall
main.o: main.cpp router.h computer.h
	g++ -c main.cpp -Wall
router.o: router.cpp router.h equipment.h
	g++ -std=c++11 -c router.cpp -Wall
computer.o: computer.cpp computer.h equipment.h
	g++ -c computer.cpp -Wall
clean:
	rm -rf *.o main

