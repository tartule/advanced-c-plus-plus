main: main.o router.o computer.o
	g++ -o main main.o router.o computer.o -Wall
main.o: main.cpp
	g++ -c main.cpp -Wall
router.o: router.cpp
	g++ -c router.cpp -Wall
computer.o:
	g++ -c computer.cpp -Wall
clean:
	rm -rf *.o main