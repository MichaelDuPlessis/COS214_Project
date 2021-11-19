main.out: main.o network.o aggregate.o iterator.o satelliteIterator.o starlinkSatellite.o
	g++ -g main.o network.o aggregate.o iterator.o satelliteIterator.o starlinkSatellite.o \
		-o main.out

main.o: main.cpp
	g++ -g -c main.cpp

network.o: network.cpp network.h
	g++ -g -c network.cpp

aggregate.o: aggregate.cpp aggregate.h
	g++ -g -c aggregate.cpp

iterator.o: iterator.cpp iterator.h
	g++ -g -c iterator.cpp 

satelliteIterator.o: satelliteIterator.cpp satelliteIterator.h
	g++ -g -c satelliteIterator.cpp

startlinkSatellite.o: starlinkSatellite.cpp startlinkSatellite.h
	g++ -g -c starlinkSatellite.cpp

run:
	./main.out

clean:
	rm *.o