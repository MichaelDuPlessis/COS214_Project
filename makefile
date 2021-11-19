all: *.o
	g++ -o all *.o

*.o: *.cpp
	g++ -c -g *.cpp

run:
	./all

clean:
	rm *.o all
