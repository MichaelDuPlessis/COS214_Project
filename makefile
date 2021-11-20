all:
	g++ -std=c++11 -c *.cpp
	g++ -std=c++11 -c Factories/*.cpp
	g++ -lgtest -std=c++11 -o main *.o

run:
	./main

clean:
	rm *.o main
