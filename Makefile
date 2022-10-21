main: main.o router.o computer.o
	g++ -o main main.o router.o computer.o -Wall -std=c++17
main.o: main.cpp router.h computer.h
	g++ -c main.cpp -Wall -std=c++17
router.o: router.cpp router.h equipment.h
	g++ -std=c++11 -c router.cpp -Wall -std=c++17
computer.o: computer.cpp computer.h equipment.h
	g++ -c computer.cpp -Wall -std=c++17
clean:
	rm -rf *.o main

