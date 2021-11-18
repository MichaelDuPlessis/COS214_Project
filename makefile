all:
	g++ -c *.cpp

run: all
	./main

clean:
	rm *.o main