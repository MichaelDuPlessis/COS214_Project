all:
	g++ -c *.cpp
	g++ -c Factories/*.cpp
	g++ -o main *.o

run:
	./main

clean:
	rm *.o main
