all: *.o
	g++ -o all *.o

*.o: *.cpp
	g++ -c *.cpp

run:
	./all

clean:
	rm *.o all
