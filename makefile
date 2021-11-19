all:
	g++ -c *.cpp
	g++ -c Factories/*.cpp
	g++ -o main *.o

run: all
	./main

clean:
	rm *.o main
