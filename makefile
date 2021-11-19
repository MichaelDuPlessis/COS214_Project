<<<<<<< HEAD
all:
	g++ -c *.cpp
	g++ -o main *.o

run: all
	./main

clean:
	rm *.o main
=======
all: *.o
	g++ -o all *.o

*.o: *.cpp
	g++ -c -g *.cpp

run:
	./all

clean:
	rm *.o all
>>>>>>> Satellites
